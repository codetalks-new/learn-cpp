#pragma once
#include <sys/time.h> /* for clock_gettime,timespec */

class StopWatch {
  struct timespec start_ts;
  bool is_started;

 public:
  void start() noexcept {
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &this->start_ts);
    this->is_started = true;
  }
  long get_ns() const noexcept {
    if (!this->is_started) {
      return 0;
    }
    struct timespec end_ts;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_ts);
    long s = end_ts.tv_sec - start_ts.tv_sec;
    long ns = s * 1000000000L + end_ts.tv_nsec - start_ts.tv_nsec;
    return ns;
  }
  double get_ms() const noexcept {
    return get_ns() / 1000000.0;
  }
};
