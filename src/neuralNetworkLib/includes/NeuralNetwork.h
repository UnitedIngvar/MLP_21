#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "Matrix.h"

// TODO: внимательно почитать google style и поправить все. АААААААААААААААА
namespace s21 {
  class NeuralNetwork {
  private:
    // TODO: Поменять в будущем или сделать конфигурируемым (посмотреть в задание)
    const float _kLearningRate = 0.1;

    int _inputNodesCount;
    int _hiddenNodesCount;
    int _outputNodesCount;

    Matrix _weightsInputHidden;
    Matrix _weightsHiddenOutput;
    Matrix _biasHidden;
    Matrix _biasOutput;

    float sigmoid(int x) const;
    float sigmoidDerivative(float sigmoidResult) const;

  public:
    NeuralNetwork(
      int inputNodesCount,
      int hiddenNodesCount,
      int outputNodesCount);

      Matrix feedforward(Matrix const &input) const;

      void train(Matrix inputs, Matrix expectedAnswer);
  };
}

#endif
