#include <unistd.h> /* for sysconf */

#include <atomic>             /* for atomic */
#include <chrono>             /* for chrono_literals */
#include <condition_variable> /* for condition_variable */
#include <functional>         /* for bind */
#include <iomanip>            /* for put_time */
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
using namespace std::chrono_literals;
using std::cout;
using std::endl;
using std::string;

namespace this_thread = std::this_thread;

class GuardedThread : std::thread {
 public:
  using std::thread::thread;
  ~GuardedThread() {
    if (this->joinable()) {
      this->join();
    }
  }
};

void doit() {
  cout << "Hello multiple thread programming!" << endl;
}

void f1() {
  int lucky_nums[] = {1, 3, 5, 7, 9};
  int arr_len = sizeof(lucky_nums) / sizeof(int);
  std::thread bad{[&] {
    while (true) {
      for (int i = 0; i < arr_len; i++) {
        lucky_nums[i] += 1;
      }
      this_thread::sleep_for(2s);
    }
  }};
  bad.detach();
}

void serve_forever() {
  int lucky_nums[] = {1, 3, 5, 7, 9};
  int arr_len = sizeof(lucky_nums) / sizeof(int);
  for (;;) {
    cout << "LUCKY NUMS:";
    for (int i = 0; i < arr_len; i++) {
      cout << lucky_nums[i];
      if (i < arr_len - 1) {
        cout << ",";
      }
    }
    cout << endl;
    this_thread::sleep_for(1s);
  }
}

std::string cur_time() {
  std::time_t t = std::time(nullptr);
  std::tm tm = *std::localtime(&t);
  char buf[16] = {0};
  std::strftime(buf, 10, "[%T]", &tm);
  return std::string(buf);
}
class CondThread : public std::thread {
 private:
  bool ready;
  bool done;
  std::condition_variable cond_run;
  std::mutex mtx;
  void thread_fun_wrapper() {
    for (;;) {
      std::unique_lock<std::mutex> lock(mtx);
      cond_run.wait(lock, [this] { return this->ready || this->done; });
      lock.unlock();
      if (done) {
        return;
      }
      run();
    }
  }

 protected:
  void run() {
    cout << cur_time() << " 线程[" << this_thread::get_id() << "] 正在运行"
         << endl;
    this_thread::sleep_for(1s);
    if (!this->ready) {
      cout << cur_time() << " 线程[" << this_thread::get_id() << "]  暂停运行"
           << endl;
      return;
    }
    cout << cur_time() << " 线程[" << this_thread::get_id() << "] 继续运行"
         << endl;
  }

 public:
  CondThread()
      : std::thread::thread([this] {
          this->ready = true;
          this->thread_fun_wrapper();
        }) {}
  ~CondThread() {
    if (this->joinable()) {
      this->join();
    }
  }
  void start() {
    std::lock_guard<std::mutex> lock(mtx);
    this->ready = true;
    cond_run.notify_one();
  }
  void stop() {
    std::lock_guard<std::mutex> lock(mtx);
    this->ready = false;
    cond_run.notify_one();
  }

  void exit() {
    std::lock_guard<std::mutex> lock(mtx);
    this->ready = false;
    this->done = true;
    cond_run.notify_one();
  }
};

int main(int argc, char const *argv[]) {
  CondThread t1;
  this_thread::sleep_for(0.5s);
  t1.start();
  this_thread::sleep_for(0.5s);
  t1.stop();
  this_thread::sleep_for(0.5s);
  t1.start();
  this_thread::sleep_for(0.5s);
  t1.stop();
}