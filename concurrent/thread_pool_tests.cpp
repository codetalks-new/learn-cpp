#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <unistd.h> /* for sysconf */

#include <atomic> /* for atomic */
#include <cassert>
#include <chrono>             /* for chrono_literals */
#include <condition_variable> /* for condition_variable */
#include <deque>
#include <functional> /* for bind */
#include <functional>
#include <future>
#include <iomanip> /* for put_time */
#include <iostream>
#include <mutex> /* for mutext lock*/
#include <set>
#include <string>
#include <thread>

using namespace std::chrono_literals;
using std::atomic;
using std::cout;
using std::endl;
using std::function;
using std::mutex;
using std::shared_ptr;
using std::string;
using std::thread;
using std::unique_lock;

/// Work 接口
class Work {
 public:
  virtual void execute() = 0;
};

class SimpleWork : public Work {
 private:
 public:
  std::function<void()> _fn;
  explicit SimpleWork(std::function<void()> fn) : _fn{fn} {}
  void execute() override {
    this->_fn();
  }
};

class ThreadPool {
 private:
  std::deque<SimpleWork> _work_queue;
  std::shared_ptr<std::thread> _work_thread;
  std::vector<std::shared_ptr<std::thread>> _threads;
  std::atomic<bool> _done;
  unsigned _numberOfThreads;
  void worker() {
    while (!_done) {
      while (!hasWork()) {
        ;
      }
      if (_done) {
        break;
      }
      auto w = pullWork();
      w.execute();
    }
  }

 public:
  ThreadPool(unsigned numberOfThreads = 0) {
    if (numberOfThreads < 1) {
      _numberOfThreads = std::thread::hardware_concurrency();
    } else {
      _numberOfThreads = numberOfThreads;
    }
  }
  bool hasWork() const noexcept {
    return !_work_queue.empty();
  }
  void addWork(SimpleWork work) noexcept {
    _work_queue.push_front(work);
  }
  SimpleWork pullWork() {
    auto work = _work_queue.back();
    _work_queue.pop_back();
    return work;
  }

  void start() {
    for (int i = 0; i < _numberOfThreads; i++) {
      auto t = std::make_shared<std::thread>(&ThreadPool::worker, this);
      this->_threads.push_back(t);
    }
  }
  void stop() {
    _done = true;
    for (const auto &t : _threads) {
      if (t->joinable()) {
        t->join();
      }
    }
  }
  virtual ~ThreadPool() {
    stop();
  }
};

// class ThreadPool {
//  public:
//   template <typename Fn, typename... Args>
//   auto submit(Fn &&fn, Args &&... args) {}
// };

TEST(WorkTestSuite, SimpleWork) {
  int called = false;
  SimpleWork w1([&] { called = true; });
  w1.execute();
  EXPECT_EQ(called, true);
}

TEST(ThreadPoolTestSuite, HasWork) {
  ThreadPool p1;
  EXPECT_FALSE(p1.hasWork());
  SimpleWork w1([] {

  });
  p1.addWork(w1);
  EXPECT_TRUE(p1.hasWork());
}

TEST(ThreadPoolTestSuite, PullWork) {
  ThreadPool p1;
  bool called = false;
  SimpleWork w1([&called] { called = true; });
  p1.addWork(w1);
  SimpleWork r1 = p1.pullWork();
  EXPECT_FALSE(p1.hasWork());
  r1.execute();
  EXPECT_TRUE(called);
}

TEST(ThreadPoolTestSuite, WorkExecuteInAsync) {
  ThreadPool pool;
  pool.start();
  std::mutex m;
  std::condition_variable called_cond;
  bool called{false};
  SimpleWork w1([&] {
    std::unique_lock<std::mutex> lock(m);
    called = true;
    called_cond.notify_all();
  });
  pool.addWork(w1);
  std::unique_lock<std::mutex> lock(m);
  bool check_called = called_cond.wait_for(lock, 100ms, [&] { return called; });
  EXPECT_TRUE(check_called);
}

TEST(ThreadPoolTestSuite, AllWorkExecuted) {
  ThreadPool pool;
  pool.start();
  unsigned count = 0;
  const unsigned workItems = 6;
  std::mutex m;
  std::condition_variable called_cond;
  bool called{false};
  SimpleWork w1([&] {
    std::unique_lock<std::mutex> lock(m);
    count++;
    called_cond.notify_all();
  });
  for (int i = 0; i < workItems; i++) {
    pool.addWork(w1);
  }
  std::unique_lock<std::mutex> lock(m);
  bool checked =
      called_cond.wait_for(lock, 100ms, [&] { return count == workItems; });
  EXPECT_TRUE(checked);
}

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}