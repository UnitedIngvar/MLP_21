#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>

namespace s21 {
typedef struct Settings {
  double learning_rate;
  std::vector<int> hidden_layers_count;
} Settings;
}  // namespace s21

#endif