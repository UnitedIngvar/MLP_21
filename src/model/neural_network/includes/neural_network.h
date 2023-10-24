#pragma once

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "matrix.h"

namespace s21 {
typedef enum nnType { kMatrix = 0, kGraph = 1 } nnType;

class NeuralNetwork {
 private:
  float learning_rate_;

  int hidden_layers_count_;

  std::vector<Matrix> weights_hidden_;
  Matrix weights_output_;

  std::vector<Matrix> bias_hidden_;
  Matrix bias_output_;

  float Sigmoid(int x) const;
  float SigmoidDerivative(float sigmoid_result) const;

 public:
  NeuralNetwork(int input_nodes_count, std::vector<int> hidden_nodes_count,
                int output_nodes_count, float learning_rate);
  NeuralNetwork();
  ~NeuralNetwork();

  Matrix Feedforward(Matrix const& input) const;
  float Train(Matrix const& inputs, Matrix const& expected_outputs);

  float GetLearningRate() const;
  void SetLearningRate(float rate);

  NeuralNetworkMessage ToMessage() const;
  static NeuralNetwork* FromMessage(NeuralNetworkMessage const& message);
};
}  // namespace s21

#endif  // NEURAL_NETWORK_H
