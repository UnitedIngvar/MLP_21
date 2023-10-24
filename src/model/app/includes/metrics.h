#ifndef METRICS_H
#define METRICS_H

#include "time.h"

namespace s21 {
typedef struct metrics {
  float average_accuracy;
  float average_precision;
  float average_recall;
  float average_f_measure;
  time_t time_elapsed;
} metrics;
}  // namespace s21

#endif