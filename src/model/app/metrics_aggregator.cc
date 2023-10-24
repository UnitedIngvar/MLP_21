#include "metrics_aggregator.h"

#include <iostream>

using namespace s21;
using namespace std;

MetricsAggregator::MetricsAggregator() {
  timer_.start();

  for (PicLabel label = 'A'; label < 'Z'; label++) {
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

    for (PicLabel label = 'A'; label < 'Z'; label++) {
      if (fact != label) {
        true_negatives_map_[label]++;
      }
    }
  } else {
    false_negatives_map_[expected]++;
    false_positives_map_[fact]++;
  }
}

metrics MetricsAggregator::CalculateMetrics() {
  const int classes_count = 26;

  float accuracy_summ = 0.0;
  float precision_summ = 0.0;
  float recall_summ = 0.0;
  float f_measure_summ = 0.0;
  for (PicLabel label = 'A'; label < 'Z'; label++) {
    std::cout << "for class " << label << ":" << std::endl;
    std::cout << "TP' :" << true_positives_map_[label] << std::endl;
    std::cout << "TN' :" << true_negatives_map_[label] << std::endl;
    std::cout << "FP' :" << false_positives_map_[label] << std::endl;
    std::cout << "FN' :" << false_negatives_map_[label] << std::endl;

    if ((true_positives_map_[label] + true_negatives_map_[label] +
         false_positives_map_[label] + false_negatives_map_[label]) != 0) {
      accuracy_summ +=
          float(true_positives_map_[label]) /
          float(true_positives_map_[label] + true_negatives_map_[label] +
                false_positives_map_[label] + false_negatives_map_[label]);
    }

    float class_precision = 0.0;
    if ((true_positives_map_[label] + false_positives_map_[label]) != 0) {
      class_precision =
          float(true_positives_map_[label]) /
          float(true_positives_map_[label] + false_positives_map_[label]);
    }
    precision_summ += class_precision;

    float class_recall = 0.0;
    if ((true_positives_map_[label] + false_negatives_map_[label]) != 0) {
      class_recall =
          float(true_positives_map_[label]) /
          float(true_positives_map_[label] + false_negatives_map_[label]);
    }
    recall_summ += class_recall;

    if ((class_precision + class_recall) != 0) {
      f_measure_summ += 2 * (class_precision * class_recall) /
                        (class_precision + class_recall);
    }
  }

  return metrics{.average_accuracy = accuracy_summ / classes_count,
                 .average_precision = precision_summ / classes_count,
                 .average_recall = recall_summ / classes_count,
                 .average_f_measure = f_measure_summ / classes_count,
                 .time_elapsed = timer_.stop()};
}