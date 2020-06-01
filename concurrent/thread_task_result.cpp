#include <unistd.h> /* for sysconf */

#include <atomic> /* for atomic */
#include <cassert>
#include <chrono>             /* for chrono_literals */
#include <condition_variable> /* for condition_variable */
#include <functional>         /* for bind */
#include <future>
#include <iomanip> /* for put_time */
#include <iostream>
#include <mutex>
#include <set>
#include <string>
#include <thread>
#include <unordered_map>

#include "./GuardedThread.hpp"

using namespace std::chrono_literals;
using std::cout;
using std::endl;
using std::string;

namespace this_thread = std::this_thread;

std::unordered_map<std::__thread_id, int> thread_task1_result_map;
void thread_task1(int a, int b) {
  this_thread::sleep_for(1s);
  auto tid = this_thread::get_id();
  thread_task1_result_map[tid] = a + b;
}

class AsyncTask {
 private:
  int result;
  int a;
  int b;
  bool done;
  std::mutex mtx;
  std::condition_variable cond;
  void execute() {
    this_thread::sleep_for(1s);
    this->result = a + b;
    this->done = true;
    std::lock_guard<std::mutex> lock(mtx);
    cond.notify_one();
  }

 public:
  template <typename Fn, class... Args>
  explicit AsyncTask(Fn&& fn, Args&&... args) {
    std::thread t1{&AsyncTask::execute, this};
    t1.detach();
  }
  int get() {
    std::unique_lock<std::mutex> lock{mtx};
    cond.wait(lock, [this] { return this->done; });
    return result;
  }
};

template <typename Fn, typename... Args>
auto async_task(Fn&& fn, Args&&... args) {
  auto task =
      std::packaged_task<std::remove_reference_t<Fn>>(std::forward<Fn>(fn));
  auto future = task.get_future();
  std::thread t{std::move(task), std::forward<Args>(args)...};
  t.detach();
  return future;
}

int thread_task2(int a, int b) {
  this_thread::sleep_for(1s);
  return a + b;
}

int main(int argc, char const* argv[]) {
  auto r1 = std::async(
      [](int a, int b) {
        this_thread::sleep_for(1s);
        return a + b;
      },
      3, 4);
  r1.valid();
  assert(r1.get() == 7);
  // AsyncTask t1{3, 4};
  // assert(t1.get() == 7);
  // std::thread t2{thread_task1, 4, 5};
  // std::set<std::__thread_id> tids = {t1.get_id(), t2.get_id()};
  // t1.join();
  // t2.join();
  // assert(thread_task1_result_map.size() == 2);
  // std::set<std::__thread_id> result_tids;
  // std::set<int> results;
  // for (const auto& entry : thread_task1_result_map) {
  //   result_tids.insert(entry.first);
  //   results.insert(entry.second);
  // }
  // assert(result_tids.size() == tids.size());
  // assert(result_tids == tids);
  // std::set<int> expected_results{7, 9};
  // assert(results == expected_results);

  return 0;
}