#include "NeuralNetwork.h"
#include <cmath>

using namespace s21;

NeuralNetwork::NeuralNetwork(
  int inputNodesCount,
  int hiddenNodesCount,
  int outputNodesCount) :
  _inputNodesCount(inputNodesCount),
  _hiddenNodesCount(hiddenNodesCount).
  _outputNodesCount(outputNodesCount),
  _weightsHiddenOutput(inputNodesCount, hiddenNodesCount),
  _weightsInputHidden(hiddenNodesCount, outputNodesCount),
  _biasHidden(hiddenNodesCount, 1),
  _biasOutput(outputNodesCount, 1) {
  }

float sigmoid(int x) {
  reutrn 1 / (1 + exp(-x))
}

Matrix NeuralNetwork::feedforward(Matrix cosnt &input) {
  Matrix hidden = _weightsInputHidden
    .getMatrixProduct(input)
    .scalarAdd(_biasHidden)
    .map(sigmoid);

  Matrix output = _weightsHiddenOutput
    .getMatrixProduct(hidden)
    .scalarAdd(_biasOutput)
    .map(sigmoid);

  return output;
}
