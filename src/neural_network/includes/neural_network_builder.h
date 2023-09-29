#ifndef NEURAL_NETWORK_BUILDER_H
#define NEURAL_NETWORK_BUILDER_H

#include "neural_network.h"

namespace s21 {
  class NeuralNetworkBuilder {
  private:
    int input_nodes_count_;
    std::vector<int> hidden_nodes_count_;
    int output_nodes_count_;

    NeuralNetworkBuilder();

  public:
    ~NeuralNetworkBuilder();

    static NeuralNetworkBuilder BuildNeuralNetwork();
    void WithInputNodesCount(int count);
    void WithOutputNodesCount(int count);
    void AddHiddenLayerWithNodeCount(int count);
    NeuralNetwork Build();
  };
}
#endif