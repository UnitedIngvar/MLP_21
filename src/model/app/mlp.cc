#include "mlp.h"

#include <fstream>

#include "neural_network_builder.h"
#include "train_picture_reader.h"

using namespace s21;
using namespace std;

Mlp::Mlp() {}

Mlp::~Mlp() {
  if (perceptron_ != NULL) {
    delete perceptron_;
  }
}

void Mlp::CreateNewNeuralNetwork(float learning_rate, int hidden_layer_count,
                                 nnType type) {
  if (hidden_layer_count > 5 || hidden_layer_count < 2) {
    throw invalid_argument(
        "Количество внутренних слоев перецептрона должно быть от 2 до 5");
  }

  NeuralNetworkBuilder builder = NeuralNetworkBuilder::BuildNeuralNetwork()
                                     .WithInputNodesCount(kInputNodesCount_)
                                     .WithOutputNodesCount(kOutputNodesCount_)
                                     .WithLearningRate(learning_rate)
                                     .OfType(type);

  int previos_layer_node_count = kInputNodesCount_;
  for (size_t i = 0; i < hidden_layer_count; i++) {
    int node_count = previos_layer_node_count * 0.66;
    builder.AddHiddenLayerWithNodeCount(node_count);
    previos_layer_node_count = node_count;
  }

  perceptron_ = builder.Build();
}
void Mlp::PassDatasets(string train_filename, string test_filename) {
  fstream train_stream(train_filename);
  fstream test_stream(test_filename);

  if (!train_stream) {
    throw invalid_argument("Не удалось открыть файл " + train_filename);
  }
  if (!test_stream) {
    throw invalid_argument("Не удалось открыть файл " + test_filename);
  }

  TrainPictureReader reader;
  train_pictures_ = reader.ReadPictures(train_stream);
  test_pictures_ = reader.ReadPictures(train_stream);
}

map<int, float> Mlp::StartTraining(int epoch_count) {
  map<int, float> error_map;

  for (size_t epoch = 0; epoch < epoch_count; epoch++) {
  }
}

metrics Mlp::RunExperiment(float test_percentage) { return metrics{}; }

char Mlp::GuessBmpFile(string filepath) { return 'A'; }

char Mlp::GuessHandwritten(vector<int> picture) { return 'A'; }

void Mlp::LearnWithCrossValidation(int group_count) {}

void Mlp::SaveNeuralNetwork(string filename) {}

void Mlp::LoadNeuralNetwork(string filename) {}