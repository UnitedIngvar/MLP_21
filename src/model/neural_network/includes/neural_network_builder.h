#ifndef NEURAL_NETWORK_BUILDER_H
#define NEURAL_NETWORK_BUILDER_H

#include "neural_network.h"

namespace s21 {
class NeuralNetworkBuilder {
 private:
  int input_nodes_count_;
  std::vector<int> hidden_nodes_count_;
  int output_nodes_count_;
  float learning_rate_ = 0.1;
  nnType type_;

  NeuralNetworkBuilder();

 public:
  ~NeuralNetworkBuilder();

  static NeuralNetworkBuilder BuildNeuralNetwork();
  NeuralNetworkBuilder &WithInputNodesCount(int count);
  NeuralNetworkBuilder &WithOutputNodesCount(int count);
  NeuralNetworkBuilder &AddHiddenLayerWithNodeCount(int count);
  NeuralNetworkBuilder &OfType(nnType type);
  NeuralNetworkBuilder &WithLearningRate(float learning_rate);
  NeuralNetwork *Build();
};
}  // namespace s21

#endif