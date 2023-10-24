#include <unistd.h>

#include <fstream>
#include <iostream>

#include "mlp.h"

using namespace s21;
using namespace std;

typedef struct input {
  vector<float> inputs;
  float target;
} input;

//  Нужно будет нормализовать данные (перевести значения пикселей в диапозон 1 -
// 0)
int main(void) {
  //   vector<input> trainingData({
  //       input{.inputs = {0.0, 1.0}, .target = 1.0},
  //       input{.inputs = {0.0, 0.0}, .target = 0.0},
  //       input{.inputs = {1.0, 0.0}, .target = 1.0},
  //       input{.inputs = {0.0, 0.0}, .target = 0.0},
  //   });
  //   NeuralNetwork nn = NeuralNetworkBuilder::BuildNeuralNetwork()
  //                          .WithInputNodesCount(2)
  //                          .AddHiddenLayerWithNodeCount(3)
  //                          .AddHiddenLayerWithNodeCount(2)
  //                          .WithOutputNodesCount(1)
  //                          .Build();

  //   std::cout << "Before training: " << std::endl;
  //   for (size_t i = 0; i < trainingData.size(); i++) {
  //     Matrix inputs = {{trainingData[i].inputs[0]},
  //     {trainingData[i].inputs[1]}}; Matrix target =
  //     {{trainingData[i].target}};

  //     Matrix result = nn.Feedforward(inputs);

  //     std::cout << "inputs: " << std::endl << inputs << std::endl;
  //     std::cout << "The result is: " << result(0, 0)
  //               << ", The expected is: " << target(0, 0) << std::endl;
  //   }

  //   std::cout << "training..." << std::endl;
  //   for (size_t i = 0; i < 10000; i++) {
  //     for (size_t j = 0; j < trainingData.size(); j++) {
  //       Matrix inputs = {{trainingData[j].inputs[0]},
  //                        {trainingData[j].inputs[1]}};
  //       Matrix targets = {{trainingData[j].target}};

  //       nn.Train(inputs, targets);
  //     }
  //   }

  //   std::cout << "After training: " << std::endl;
  //   for (size_t i = 0; i < trainingData.size(); i++) {
  //     Matrix inputs = {{trainingData[i].inputs[0]},
  //     {trainingData[i].inputs[1]}}; Matrix target =
  //     {{trainingData[i].target}};

  //     Matrix result = nn.Feedforward(inputs);

  //     std::cout << "inputs: " << std::endl << inputs << std::endl;
  //     std::cout << "The result is: " << result(0, 0)
  //               << ", The expected is: " << target(0, 0) << std::endl;
  //   }
  // }

  Mlp mlp;
  mlp.CreateNewNeuralNetwork(0.01, 2, nnType::kMatrix);
  mlp.PassDatasets("../emnist-letters-train.csv", "../emnist-letters-test.csv");
  auto result = mlp.StartTraining(1);

  metrics metric = mlp.RunExperiment(0.1);
  std::cout << "accuracy: " << metric.average_accuracy << std::endl;
  std::cout << "precision: " << metric.average_precision << std::endl;
  std::cout << "recall: " << metric.average_recall << std::endl;
  std::cout << "f measure: " << metric.average_f_measure << std::endl;
  std::cout << "time elapsed: " << metric.time_elapsed << std::endl;
}
