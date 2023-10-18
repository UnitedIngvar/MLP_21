#include "neural_network.h"

#include <unistd.h>

#include <cmath>
#include <iostream>

using namespace s21;
using namespace std::placeholders;
using namespace std;

NeuralNetwork::NeuralNetwork(int input_nodes_count,
                             vector<int> hidden_nodes_count,
                             int output_nodes_count, float learning_rate) {
  if (hidden_nodes_count.size() <= 0) {
    throw invalid_argument("Нельзя создать нейронную сеть без скрытых слоев");
  }
  if (input_nodes_count <= 0 || output_nodes_count <= 0) {
    throw invalid_argument("У каждого слоя нейронной сети должны быть нейроны");
  }
  for (size_t i = 0; i < hidden_nodes_count.size(); i++) {
    if (hidden_nodes_count[i] <= 0) {
      throw invalid_argument(
          "У каждого слоя нейронной сети должны быть нейроны");
    }
  }

  if (learning_rate_ > 1) {
    throw invalid_argument(
        "Коэффициент скорости обучения должен иметь значение от 0 до 1");
  }

  learning_rate_ = learning_rate;

  weights_hidden_.push_back(
      Matrix::Randomize(hidden_nodes_count[0], input_nodes_count));
  bias_hidden_.push_back(Matrix::Randomize(hidden_nodes_count[0], 1));

  hidden_layers_count_ = hidden_nodes_count.size();
  for (int i = 1; i < hidden_layers_count_; i++) {
    weights_hidden_.push_back(
        Matrix::Randomize(hidden_nodes_count[i], hidden_nodes_count[i - 1]));
    bias_hidden_.push_back(Matrix::Randomize(hidden_nodes_count[i], 1));
  }

  bias_output_ = Matrix::Randomize(output_nodes_count, 1);
  weights_output_ = Matrix::Randomize(
      output_nodes_count, hidden_nodes_count[hidden_layers_count_ - 1]);
}

NeuralNetwork::~NeuralNetwork() {}

float NeuralNetwork::Sigmoid(int x) const { return 1 / (1 + exp(-x)); }

float NeuralNetwork::SigmoidDerivative(float sigmoidResult) const {
  return sigmoidResult * (1 - sigmoidResult);
}

Matrix NeuralNetwork::Feedforward(Matrix const &inputs) const {
  function<float(int)> sigmoid_func =
      std::bind(&NeuralNetwork::Sigmoid, *this, _1);

  // Input passed to the first hidden layer
  Matrix input_hidden_output = weights_hidden_[0]
                                   .GetMatrixProduct(inputs)
                                   .Add(bias_hidden_[0])
                                   .Map(sigmoid_func);

  // Hidden layers feeding each one's output forward
  Matrix hidden_layers_output = input_hidden_output;
  for (int i = 1; i < hidden_layers_count_; i++) {
    hidden_layers_output = weights_hidden_[i]
                               .GetMatrixProduct(hidden_layers_output)
                               .Add(bias_hidden_[i]);
  }

  // Getting the output from
  Matrix outputs = weights_output_.GetMatrixProduct(hidden_layers_output)
                       .Add(bias_output_)
                       .Map(sigmoid_func);

  return outputs;
}

float NeuralNetwork::Train(Matrix const &inputs,
                           Matrix const &expected_outputs) {
  function<float(float)> sigmoid_derivative_func =
      std::bind(&NeuralNetwork::SigmoidDerivative, *this, _1);
  function<float(int)> sigmoid_func =
      std::bind(&NeuralNetwork::Sigmoid, *this, _1);

  /* Feedforward algorithm with saving itermediate hidden layer calculation
   * results */
  // Input passed to the first hidden layer
  vector<Matrix> hidden_calc_results(hidden_layers_count_);
  hidden_calc_results[0] = weights_hidden_[0]
                               .GetMatrixProduct(inputs)
                               .Add(bias_hidden_[0])
                               .Map(sigmoid_func);

  // Hidden layers feeding each one's output forward
  for (int i = 1; i < hidden_layers_count_; i++) {
    hidden_calc_results[i] = weights_hidden_[i]
                                 .GetMatrixProduct(hidden_calc_results[i - 1])
                                 .Add(bias_hidden_[i]);
  }

  // Getting output from neural network
  Matrix hidden_calcs_output = hidden_calc_results[hidden_layers_count_ - 1];
  Matrix outputs = weights_output_.GetMatrixProduct(hidden_calcs_output)
                       .Add(bias_output_)
                       .Map(sigmoid_func);
  /* The end of feedforward algorithm */

  /* Backpropogation algorithm */
  Matrix output_errors = expected_outputs.Subtract(outputs);

  Matrix output_gradients = outputs.Map(sigmoid_derivative_func)
                                .Multiply(output_errors)
                                .ScalarMultiply(learning_rate_);

  Matrix hidden_output_weight_deltas =
      output_gradients.GetMatrixProduct(hidden_calcs_output.Transpose());

  weights_output_ = weights_output_.Add(hidden_output_weight_deltas);
  bias_output_ = bias_output_.Add(output_gradients);

  Matrix hidden_errors =
      weights_output_.Transpose().GetMatrixProduct(output_errors);
  for (int i = hidden_layers_count_ - 1; i >= 0; i--) {
    Matrix hidden_gradient = hidden_calc_results[i]
                                 .Map(sigmoid_derivative_func)
                                 .Multiply(hidden_errors)
                                 .ScalarMultiply(learning_rate_);

    Matrix transposed_inputs =
        i != 0 ? hidden_calc_results[i - 1].Transpose() : inputs.Transpose();
    Matrix input_hidden_weight_deltas =
        hidden_gradient.GetMatrixProduct(transposed_inputs);

    weights_hidden_[i] = weights_hidden_[i].Add(input_hidden_weight_deltas);
    bias_hidden_[i] = bias_hidden_[i].Add(hidden_gradient);

    hidden_errors =
        weights_hidden_[i].Transpose().GetMatrixProduct(hidden_errors);
  }

  float error_summ = 0.0;
  for (int i = 0; i < output_errors.GetRowNumber(); i++) {
    error_summ += output_errors(i, 0);
  }

  float avg_error = error_summ / output_errors.GetRowNumber();
  return avg_error;
  /* The end of backpropagation algorithm */
}
