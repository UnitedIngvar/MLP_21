#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "Matrix.h"

namespace s21 {
  class NeuralNetwork {
  private:
    int _inputNodesCount;
    int _hiddenNodesCount;
    int _outputNodesCount;

    Matrix &_weightsInputHidden;
    Matrix &_weightsHiddenOutput;
    Matrix &_biasHidden;
    Matrix &_biasOutput;

    float sigmoid(int x);
  public:
    NeuralNetwork(
      int inputNodesCount,
      int hiddenNodesCount,
      int outputNodesCount);

      Matrix feedforward(Matrix const &input);
  };
}

#endif
