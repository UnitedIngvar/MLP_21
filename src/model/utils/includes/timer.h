#ifndef TIMER_H
#define TIMER_H

#include <chrono>

namespace s21 {
class Timer {
  using timep_t = typename std::chrono::steady_clock::time_point;
  timep_t start_ = std::chrono::steady_clock::now();
  timep_t _end = {};

 public:
  void start();
  time_t stop();
};
}  // namespace s21

#endif