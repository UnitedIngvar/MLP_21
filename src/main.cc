#include "neural_network.h"
#include "neural_network_builder.h"
#include <iostream>
#include <unistd.h>

using namespace s21;
using namespace std;

typedef struct input {
  vector<float> inputs;
  float target;
} input;

//  Нужно будет нормализовать данные (перевести значения пикселей в диапозон 1 - 0)
int main(void) {
  vector<input> trainingData(
  {
    input { .inputs = {0.0, 1.0}, .target = 1.0 },
    input { .inputs = {0.0, 0.0}, .target = 0.0 },
    input { .inputs = {1.0, 0.0}, .target = 1.0 },
    input { .inputs = {0.0, 0.0}, .target = 0.0 },
  });
  NeuralNetwork nn = NeuralNetworkBuilder::BuildNeuralNetwork()
    .WithInputNodesCount(2)
    .AddHiddenLayerWithNodeCount(3)
    .AddHiddenLayerWithNodeCount(2)
    .WithOutputNodesCount(1)
    .Build();

  for (size_t i = 0; i < 10000; i++) {
    for (size_t j = 0; j < trainingData.size(); j++) {
      Matrix inputs = { 
        { trainingData[j].inputs[0] },
        { trainingData[j].inputs[1] }
      };
      Matrix targets = {
        { trainingData[j].target }
      };

      nn.Train(inputs, targets);
    }
  }

  for (size_t i = 0; i < trainingData.size(); i++) {
      Matrix inputs = { 
        { trainingData[i].inputs[0] },
        { trainingData[i].inputs[1] }
      };
      Matrix target = {
        { trainingData[i].target }
      };

    Matrix result = nn.Feedforward(inputs);
    if (!(result == target)) {
      std::cout << "fail! The result is: " << result(0, 0) << ", The expected is: " << target(0, 0) << std::endl;
    }
    else {
      std::cout << "success!" << std::endl;
    }
  }
}
