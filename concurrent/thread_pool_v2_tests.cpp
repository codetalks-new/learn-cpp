#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <unistd.h> /* for sysconf */

#include <atomic> /* for atomic */
#include <cassert>
#include <chrono>             /* for chrono_literals */
#include <condition_variable> /* for condition_variable */
#include <deque>              /* for deque */
#include <functional>         /* for bind */
#include <iostream>
#include <mutex> /* for mutext lock*/
#include <string>
#include <thread>

using namespace std::chrono_literals;
using std::atomic;
using std::cout;
using std::deque;
using std::endl;
using std::function;
using std::make_shared;
using std::mutex;
using std::recursive_mutex;
using std::shared_ptr;
using std::string;
namespace this_thread = std::this_thread;
using std::condition_variable;
using std::lock_guard;
using std::thread;
using std::unique_lock;
using std::vector;

class Task {
 public:
  virtual void run() = 0;
};

class SimpleTask : public Task {
 private:
  function<void()> _fn;

 public:
  SimpleTask() {}
  SimpleTask(function<void()> fn) : _fn(fn) {}

  void run() override {
    if (_fn) {
      _fn();
    }
  }
};
class ThreadPool {
 private:
  deque<SimpleTask> _taskQueue;
  unsigned _numOfWorkers;
  vector<thread> _threads;
  atomic<bool> _done{false};
  mutex _mtx;
  condition_variable _queue_cond;
  void worker_run() {
    while (!_done) {
      unique_lock<mutex> lock(_mtx);
      // 如果下面直接使用 hasTask 也会导致死锁
      _queue_cond.wait(
          lock, [this] { return this->_done || !this->_taskQueue.empty(); });
      lock.unlock();
      if (_done) {
        break;
      }
      auto task = getTask();
      task.run();
    }
  }

 public:
  explicit ThreadPool(unsigned workers = 0) {
    _numOfWorkers = workers > 1 ? workers : thread::hardware_concurrency();
  }

  virtual ~ThreadPool() {
    stop();
  }

  void start() {
    for (int i = 0; i < _numOfWorkers; i++) {
      thread t{&ThreadPool::worker_run, this};
      _threads.push_back(std::move(t));
    }
  }
  void stop() {
    if (_done) {
      return;
    }
    {
      lock_guard<mutex> lock(_mtx);
      _done = true;
      _queue_cond.notify_all();
    }
    // 避免跟 t->join 争用锁
    for (auto &t : _threads) {
      if (t.joinable()) {
        t.join();
      }
    }
  }

  void addTask(SimpleTask t) noexcept {
    lock_guard<mutex> lock(_mtx);
    _taskQueue.push_back(t);
    _queue_cond.notify_one();
  }
  bool hasNoTask() noexcept {
    lock_guard<mutex> lock(_mtx);
    return _taskQueue.empty();
  }
  bool hasTask() noexcept {
    lock_guard<mutex> lock(_mtx);
    return !_taskQueue.empty();
  }
  SimpleTask getTask() {
    lock_guard<mutex> lock(_mtx);
    // NOTE: 使用 mutex 如果直接调用 hasTask 会导致死锁
    if (!_taskQueue.empty()) {
      SimpleTask t = _taskQueue.front();
      _taskQueue.pop_front();
      return t;
    } else {
      return SimpleTask{};  // 空 task
    }
  }
};

TEST(TaskTestSuite, SimpleTask) {
  bool called = false;
  SimpleTask task([&called] { called = true; });
  task.run();
  EXPECT_EQ(called, true);
}

TEST(ThreadPoolTestSuite, ThreadPoolAsTaskQueue) {
  int called_count = 0;
  SimpleTask task([&called_count] { called_count++; });
  ThreadPool pool;
  EXPECT_TRUE(pool.hasNoTask());
  EXPECT_FALSE(pool.hasTask());
  constexpr unsigned num_of_tasks = 6;
  for (int i = 0; i < num_of_tasks; i++) {
    pool.addTask(task);
  }
  EXPECT_FALSE(pool.hasNoTask());
  EXPECT_TRUE(pool.hasTask());
  for (int i = 0; i < num_of_tasks; i++) {
    SimpleTask t = pool.getTask();
    t.run();
  }
  EXPECT_TRUE(pool.hasNoTask());
  EXPECT_FALSE(pool.hasTask());
  EXPECT_EQ(called_count, num_of_tasks);
}

TEST(ThreadPoolTestSuite, ThreadPoolTaskRunAsync) {
  atomic<unsigned> called_count{0};
  auto main_thread_id = this_thread::get_id();
  SimpleTask task([&called_count, &main_thread_id] {
    EXPECT_NE(main_thread_id, this_thread::get_id());
    called_count++;
  });
  ThreadPool pool;
  pool.start();
  constexpr unsigned num_of_tasks = 20;
  for (int i = 0; i < num_of_tasks; i++) {
    pool.addTask(task);
  }
  this_thread::sleep_for(60ms);
  EXPECT_EQ(called_count, num_of_tasks);
  pool.stop();
}

TEST(ThreadPoolTestSuite, ThreadPoolMultipleClientAddTasks) {
  atomic<unsigned> called_count{0};
  auto main_thread_id = this_thread::get_id();
  SimpleTask task([&called_count, &main_thread_id] {
    EXPECT_NE(main_thread_id, this_thread::get_id());
    called_count++;
  });
  ThreadPool pool;
  pool.start();
  constexpr unsigned user_thread_cnt = 8;
  constexpr unsigned num_of_tasks = 20;
  vector<thread> user_threads;
  for (int ti = 0; ti < user_thread_cnt; ti++) {
    thread t([&] {
      for (int i = 0; i < num_of_tasks; i++) {
        pool.addTask(task);
      }
    });
    user_threads.push_back(std::move(t));
  }
  for (auto &t : user_threads) {
    t.join();
  }
  this_thread::sleep_for(60ms);
  EXPECT_EQ(called_count, num_of_tasks * user_thread_cnt);
  pool.stop();
}

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}