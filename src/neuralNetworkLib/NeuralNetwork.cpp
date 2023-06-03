#include "NeuralNetwork.h"
#include <cmath>

using namespace s21;
using namespace std::placeholders;

NeuralNetwork::NeuralNetwork(
  int inputNodesCount,
  int hiddenNodesCount,
  int outputNodesCount) :
  _inputNodesCount(inputNodesCount),
  _hiddenNodesCount(hiddenNodesCount),
  _outputNodesCount(outputNodesCount),
  _weightsHiddenOutput(inputNodesCount, hiddenNodesCount),
  _weightsInputHidden(hiddenNodesCount, outputNodesCount),
  _biasHidden(hiddenNodesCount, 1),
  _biasOutput(outputNodesCount, 1) {
  }

float NeuralNetwork::sigmoid(int x) const {
  return 1 / (1 + exp(-x));
}

float NeuralNetwork::sigmoidDerivative(float sigmoidResult) const {
  return sigmoidResult * (1 - sigmoidResult);
}

Matrix NeuralNetwork::feedforward(Matrix const &inputs) const {
  function<float(int)> sigmoidFunc =
    std::bind(NeuralNetwork::sigmoid, *this, _1);

  Matrix hiddens = _weightsInputHidden
    .getMatrixProduct(inputs)
    .add(_biasHidden)
    .map(sigmoidFunc);

  Matrix outputs = _weightsHiddenOutput
    .getMatrixProduct(hiddens)
    .add(_biasOutput)
    .map(sigmoidFunc);

  return outputs;
}

// TODO: оптимизировать этот ужас потом. От многих действий можно избавиться, кое-что "вынести за скобки"
void NeuralNetwork::train(Matrix inputs, Matrix expectedOutputs) {
  function<float(float)> sigmoidDerivativeFunc =
    std::bind(NeuralNetwork::sigmoidDerivative, *this, _1);
  function<float(int)> sigmoidFunc =
    std::bind(NeuralNetwork::sigmoid, *this, _1);

  /* Feedforward algorithm */

  Matrix hiddens = _weightsInputHidden
    .getMatrixProduct(inputs)
    .add(_biasHidden)
    .map(sigmoidFunc);

  Matrix outputs = _weightsHiddenOutput
    .getMatrixProduct(hiddens)
    .add(_biasOutput)
    .map(sigmoidFunc);
  /* The end of feedforward algorithm */

  // TODO: Добавить bias
  /* Backpropogation algorithm */
  Matrix outputErrors = expectedOutputs
    .subtract(outputs);

  Matrix outputGradients = outputs
    .map(sigmoidDerivativeFunc)
    .multiply(outputErrors)
    .scalarMultiply(_kLearningRate);
  Matrix transposedHiddens = hiddens
    .transpose();
  Matrix hiddenOutputWeightDeltas = outputGradients
    .getMatrixProduct(transposedHiddens);
  _weightsHiddenOutput = _weightsHiddenOutput
    .add(hiddenOutputWeightDeltas);

  // TODO: доработать. Нужно сделать цикл, который высчитывал бы ошибку
  // для каждого hidden слоя. Вероятно, создать вектор матриц, где для вычисления
  // каждого следующего элемента нужно взять последний добавленный элемент и
  // получить matrix product от него и следующего hidden слоя. Для этого
  // нужно обновить _weightsHiddenOutput - сделать его так же вектором матриц.
  Matrix hiddenErrors = _weightsHiddenOutput
    .transpose()
    .getMatrixProduct(outputErrors);

  Matrix hiddenGradient = hiddens
    .map(sigmoidDerivativeFunc)
    .multiply(hiddenErrors)
    .scalarMultiply(_kLearningRate);
  Matrix transposedInputs = inputs
    .transpose();
  Matrix inputHiddenWeightDeltas = hiddenGradient
    .getMatrixProduct(transposedInputs);
  _weightsInputHidden = _weightsInputHidden
    .add(inputHiddenWeightDeltas);

  /* The end of backpropagation algorithm */

}
