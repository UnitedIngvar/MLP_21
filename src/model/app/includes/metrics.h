#ifndef METRICS_H
#define METRICS_H

#include "time.h"

namespace s21 {
typedef struct metrics {
  double average_accuracy;
  double average_precision;
  double average_recall;
  double average_f_measure;
  time_t time_elapsed;
} metrics;
}  // namespace s21

#endif