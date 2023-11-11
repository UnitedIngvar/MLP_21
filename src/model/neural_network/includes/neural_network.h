#pragma once

#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include <fstream>

#include "matrix.h"

namespace s21 {
typedef enum nnType { kMatrix = 0, kGraph = 1 } nnType;

class NeuralNetwork {
 private:
  double learning_rate_;

  int hidden_layers_count_;

  std::vector<Matrix> weights_hidden_;
  Matrix weights_output_;

  std::vector<Matrix> bias_hidden_;
  Matrix bias_output_;

  double Sigmoid(double x) const;
  double SigmoidDerivative(double sigmoid_result) const;

 public:
  NeuralNetwork(int input_nodes_count, std::vector<int> hidden_nodes_count,
                int output_nodes_count, double learning_rate);
  NeuralNetwork();
  ~NeuralNetwork();

  Matrix Feedforward(Matrix const& input) const;
  double Train(Matrix const& inputs, Matrix const& expected_outputs,
               std::ofstream& log, bool debug);

  double GetLearningRate() const;
  void SetLearningRate(double rate);

  NeuralNetworkMessage ToMessage() const;
  static NeuralNetwork* FromMessage(NeuralNetworkMessage const& message);
};
}  // namespace s21

#endif  // NEURAL_NETWORK_H
