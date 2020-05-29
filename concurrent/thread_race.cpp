/***
 * 今晚直播 9:00 开始
 *
 * 主题:C++多线程编程入门及基本概念,线程安全,锁,原子操作,时间测量
 * VS Code
 * by CodeTalks
 * 微信公众号: 代码会说话
 *
 */

#include <pthread.h>  /* for pthread_self */
#include <sys/time.h> /* for clock_gettime */
#include <unistd.h>   /* for getpid */

#include <atomic>
#include <chrono> /* for seconds */
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "./stopwatch.hpp"

using std::cout;
using std::endl;
using std::string;
using std::thread;

using namespace std::chrono_literals;
using std::vector;
namespace this_thread = std::this_thread;

std::mutex cout_lock;

// static std::atomic<long> counter{0};  // = 0;
static long counter{0};  // = 0;
std::mutex counter_lock;

void doit() {
  // LWP light weight process thread
  // posix thread  linux long  gcc libc
  // Thread model: posix
  // 进程,线程,协程
  // COW  c++ 14/17
  // linux clone()
  //   this_thread::sleep_for(100ms);
  //   // time#sleep()
  //   // rip eip   pc  register
  //   std::lock_guard<std::mutex> g(cout_lock);
  //   cout << "当前进程 ID " << getpid() << "," << pthread_self()
  //        << " 当前线程ID: " << this_thread::get_id() << endl;
  // clock time()  getimeofday timeval  us
  std::lock_guard<std::mutex> g(counter_lock);
  for (int i = 0; i < 1000; i++) {
    // 内存
    counter++;
  }
}

static std::once_flag init_once_flag;
static std::atomic<long> init1_flag;
static long init_flag = 0;
static void init_token() {
  init_flag++;
}

void init() {
  this_thread::sleep_for(1s);
  //
  std::call_once(init_once_flag, init_token);
  // PV
}

int main(int argc, char const* argv[]) {
  // doit();  // main thread
  // no detach go swift 5. micropython
  // swift struct
  // class
  // kotlin
  // vim 编辑思想
  const unsigned thread_cnt = thread::hardware_concurrency();
  const unsigned max_thread_cnt = thread_cnt * 2 + 1;
  StopWatch stopwatch;
  stopwatch.start();
  vector<thread> workers;
  for (int i = 0; i < max_thread_cnt; i++) {
    thread t1{init};
    // mov pure rvalue
    workers.push_back(std::move(t1));
  }
  for (auto& t : workers) {
    t.join();
  }
  double ms = stopwatch.get_ms();
  cout << "线程数:" << max_thread_cnt << " init_flag = " << init_flag << " 耗时"
       << ms << " ms" << endl;
  return 0;
  // WSL 2, Ubuntu
  // Java -> C++ (JVM) -> C -> assemble
}
