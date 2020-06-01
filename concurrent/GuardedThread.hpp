#pragma once
#include <thread>

class GuardedThread : std::thread {
 public:
  using std::thread::thread;
  ~GuardedThread() {
    if (this->joinable()) {
      this->join();
    }
  }
};