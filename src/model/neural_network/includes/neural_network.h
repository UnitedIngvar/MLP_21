#pragma once

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "matrix.h"

namespace s21 {
typedef enum nnType { kMatrix = 0, kGraph = 1 } nnType;

class NeuralNetwork {
 private:
  // TODO: Поменять в будущем или сделать конфигурируемым (посмотреть в задание)
  const float kLearningRate = 0.1;

  int hidden_layers_count_;

  std::vector<Matrix> weights_hidden_;
  Matrix weights_output_;

  std::vector<Matrix> bias_hidden_;
  Matrix bias_output_;

  float Sigmoid(int x) const;
  float SigmoidDerivative(float sigmoid_result) const;

 public:
  NeuralNetwork(int input_nodes_count, std::vector<int> hidden_nodes_count,
                int output_nodes_count);
  ~NeuralNetwork();

  Matrix Feedforward(Matrix const &input) const;
  void Train(Matrix const &inputs, Matrix const &expected_outputs);
};
}  // namespace s21

#endif  // NEURAL_NETWORK_H
