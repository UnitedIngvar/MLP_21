#include "timer.h"

using namespace s21;
using namespace std;

void Timer::start() {
  _end = timep_t{};
  start_ = chrono::steady_clock::now();
}

time_t Timer::stop() {
  _end = chrono::steady_clock::now();
  return chrono::duration_cast<chrono::milliseconds>(_end - start_).count();
}