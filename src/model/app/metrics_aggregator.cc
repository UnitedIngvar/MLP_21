#include "metrics_aggregator.h"

using namespace s21;
using namespace std;

MetricsAggregator::MetricsAggregator() {
  timer_.start();

  for (PicLabel label = 'a'; label < 'z'; label++) {
    true_positives_map_[label] = 0;
    false_positives_map_[label] = 0;
    true_negatives_map_[label] = 0;
    false_negatives_map_[label] = 0;
  }
}

MetricsAggregator::~MetricsAggregator() {}

void MetricsAggregator::Insert(PicLabel expected, PicLabel fact) {
  if (fact == expected) {
    true_positives_map_[expected]++;

    for (PicLabel label = 'a'; label < 'z'; label++) {
      if (fact != label) {
        true_negatives_map_[label]++;
      }
    }
  } else {
    false_negatives_map_[expected]++;

    for (PicLabel label = 'a'; label < 'z'; label++) {
      if (fact != label) {
        false_positives_map_[label]++;
      }
    }
  }
}

metrics MetricsAggregator::CalculateMetrics() {
  const int classes_count = 26;

  // Accuracy
  float accuracy_summ;
  float precision_summ;
  float recall_summ;
  float f_measure_summ;
  for (PicLabel label = 'a'; label < 'z'; label++) {
    accuracy_summ +=
        float(true_positives_map_[label]) /
        float(true_positives_map_[label] + true_negatives_map_[label] +
              false_positives_map_[label] + false_negatives_map_[label]);

    float class_precision =
        float(true_positives_map_[label]) /
        float(true_positives_map_[label] + false_positives_map_[label]);
    precision_summ += class_precision;

    float class_recall =
        float(true_positives_map_[label]) /
        float(true_positives_map_[label] + false_negatives_map_[label]);
    recall_summ += class_recall;

    f_measure_summ +=
        2 * (class_precision * class_recall) / (class_precision + class_recall);
  }
  return metrics{.average_accuracy = accuracy_summ / classes_count,
                 .average_precision = precision_summ / classes_count,
                 .average_recall = recall_summ / classes_count,
                 .average_f_measure = f_measure_summ / classes_count,
                 .time_elapsed = timer_.stop()};
}