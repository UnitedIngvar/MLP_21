#ifndef METRICS_AGGREGATOR_H
#define METRICS_AGGREGATOR_H

#include <chrono>
#include <map>

#include "metrics.h"
#include "picture.h"
#include "timer.h"

namespace s21 {
class MetricsAggregator {
 private:
  std::map<PicLabel, int> true_positives_map_;
  std::map<PicLabel, int> false_positives_map_;
  std::map<PicLabel, int> true_negatives_map_;
  std::map<PicLabel, int> false_negatives_map_;
  Timer timer_;

 public:
  MetricsAggregator();
  ~MetricsAggregator();
  void Insert(PicLabel expected, PicLabel fact);
  metrics CalculateMetrics();
};
}  // namespace s21

#endif