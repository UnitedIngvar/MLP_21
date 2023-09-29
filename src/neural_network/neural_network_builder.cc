#include "neural_network_builder.h"

using namespace s21;
using namespace std;

NeuralNetworkBuilder::NeuralNetworkBuilder() {}

NeuralNetworkBuilder::~NeuralNetworkBuilder() {}

NeuralNetworkBuilder NeuralNetworkBuilder::BuildNeuralNetwork(){
    return NeuralNetworkBuilder();
}

NeuralNetworkBuilder &NeuralNetworkBuilder::WithInputNodesCount(int count) {
    input_nodes_count_ = count;
    return *this;
}

NeuralNetworkBuilder &NeuralNetworkBuilder::WithOutputNodesCount(int count) {
    output_nodes_count_ = count;
    return *this;
}

NeuralNetworkBuilder &NeuralNetworkBuilder::AddHiddenLayerWithNodeCount(int count) {
    hidden_nodes_count_.push_back(count);
    return *this;
}

NeuralNetwork NeuralNetworkBuilder::Build() {
    return NeuralNetwork(
      input_nodes_count_,
      hidden_nodes_count_,
      output_nodes_count_);
}