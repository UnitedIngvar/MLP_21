#include "timer.h"

#include <iostream>

using namespace s21;
using namespace std;

void Timer::start() {
  end_ = timep_t{};
  start_ = chrono::steady_clock::now();
  std::cout << "start: " << start_.time_since_epoch().count() << std::endl;
}

time_t Timer::stop() {
  end_ = chrono::steady_clock::now();
  std::cout << "end: " << end_.time_since_epoch().count() << std::endl;

  time_t elapsed = (end_ - start_).count();
  std::cout << "elapsed: " << elapsed << std::endl;

  return elapsed;
}