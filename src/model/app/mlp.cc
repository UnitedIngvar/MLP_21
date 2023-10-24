#include "mlp.h"

#include <unistd.h>

#include <algorithm>
#include <fstream>
#include <ostream>
#include <random>
#include <utility>

#include "bmp_reader.h"
#include "metrics_aggregator.h"
#include "neural_network_builder.h"
#include "picture_normalizer.h"
#include "picture_shifter.h"
#include "train_picture_reader.h"

using namespace s21;
using namespace std;

Mlp::Mlp() {}

Mlp::~Mlp() {
  if (perceptron_ != NULL) {
    delete perceptron_;
  }

  for (size_t i = 0; i < train_pictures_.size(); i++) {
    delete train_pictures_[i];
  }
  for (size_t i = 0; i < test_pictures_.size(); i++) {
    delete test_pictures_[i];
  }
}

PicLabel Mlp::DetermineGuess(Matrix const &output) const {
  int answer_index = 0;
  float biggest_value = 0;

  for (int i = 0; i < output.GetRowNumber(); i++) {
    if (biggest_value < output(i, 0)) {
      biggest_value = output(i, 0);

      answer_index = i + 1;
    }
  }

  return answer_index + LABEL_MAP_SHIFT;
}

Matrix Mlp::PictureToInput(Picture const *picture) const {
  vector<Pixel> pixels = picture->GetFlattenedMap();

  Matrix inputs(pixels.size(), 1);
  for (size_t j = 0; j < pixels.size(); j++) {
    inputs(j, 0) = pixels[j] / 255;
  }

  return inputs;
}

vector<Matrix> Mlp::PicturesToInputs(vector<Picture *> pictures,
                                     int count) const {
  vector<Matrix> all_inputs(count);

  for (int i = 0; i < count; i++) {
    all_inputs[i] = PictureToInput(pictures[i]);
  }

  return all_inputs;
}

vector<trainingPair> Mlp::GetTrainingData(
    vector<Picture *> const &training_pictures) const {
  vector<trainingPair> result(training_pictures.size());

  for (size_t i = 0; i < training_pictures.size(); i++) {
    Picture current_pic = *training_pictures[i];
    vector<Pixel> pixels = current_pic.GetFlattenedMap();

    Matrix inputs(pixels.size(), 1);
    for (size_t j = 0; j < pixels.size(); j++) {
      inputs(j, 0) = pixels[j] / 255;
    }

    Matrix expected_outputs(kOutputNodesCount_, 1);
    expected_outputs(current_pic.GetLabel() - LABEL_MAP_SHIFT - 1, 0) = 1;

    result[i] =
        trainingPair{.expected_output = expected_outputs, .inputs = inputs};
  }

  return result;
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
  for (int i = 0; i < hidden_layer_count; i++) {
    int node_count = previos_layer_node_count * 0.66;
    builder.AddHiddenLayerWithNodeCount(node_count);
    previos_layer_node_count = node_count;
  }

  if (perceptron_ != NULL) {
    delete perceptron_;
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

  // TODO: распараллелить
  TrainPictureReader reader;
  train_pictures_ = reader.ReadPictures(train_stream);
  test_pictures_ = reader.ReadPictures(test_stream);
}

map<int, float> Mlp::StartTraining(int epoch_count) {
  if (perceptron_ == NULL) {
    throw invalid_argument("Нейросеть не инициализована!");
  }

  map<int, float> error_map;

  vector<trainingPair> train_data = GetTrainingData(train_pictures_);

  for (int epoch = 0; epoch < epoch_count; epoch++) {
    auto rng = std::default_random_engine{};
    std::shuffle(std::begin(train_data), std::end(train_data), rng);

    float error_sum = 0.0;
    std::cout << "starting epoch " << epoch << std::endl;
    for (size_t i = 0; i < 2500; i++) {
      float error = perceptron_->Train(train_data[i].inputs,
                                       train_data[i].expected_output);
      if (i % 100 == 0) {
        std::cout << "i = " << i << ", current error: " << error << std::endl;
      }

      error_sum += error;
    }

    float avg_error = error_sum / train_data.size();
    error_map.emplace(make_pair(epoch, avg_error));
  }

  return error_map;
}

metrics Mlp::RunExperiment(float test_percentage) {
  if (perceptron_ == NULL) {
    throw invalid_argument("Нейросеть не инициализована!");
  }

  MetricsAggregator metrics_aggregator;

  auto rng = std::default_random_engine{};
  std::shuffle(std::begin(test_pictures_), std::end(test_pictures_), rng);
  int test_count = test_pictures_.size() * test_percentage;
  for (int i = 0; i < test_count; i++) {
    Matrix intput = PictureToInput(test_pictures_[i]);
    Matrix outputs = perceptron_->Feedforward(intput);

    PicLabel current_label = test_pictures_[i]->GetLabel();
    PicLabel guess = DetermineGuess(outputs);

    metrics_aggregator.Insert(current_label, guess);
  }

  return metrics_aggregator.CalculateMetrics();
}

char Mlp::GuessBmpFile(string filename) {
  if (perceptron_ == NULL) {
    throw invalid_argument("Нейросеть не инициализована!");
  }

  fstream bmp_stream(filename);
  if (!bmp_stream) {
    throw invalid_argument("Не удалось открыть файл " + filename);
  }

  BmpReader bmp_reader;
  Picture picture = bmp_reader.ReadPictureToBlackAndWhite(bmp_stream);

  PictureNormalizer picture_normalizer;
  Picture normalized_picture = picture_normalizer.Normalize(picture);

  Matrix input = PictureToInput(&normalized_picture);
  Matrix output = perceptron_->Feedforward(input);

  return DetermineGuess(output);
}

// TODO: надо подумать, надо ли это вообще
char Mlp::GuessHandwritten(vector<int> picture) {
  (void)picture;
  return 'A';
}

void Mlp::StartTrainingWithCrossValidation(int group_count) {
  (void)group_count;
}

void Mlp::SaveNeuralNetwork(string filename) {
  if (perceptron_ == NULL) {
    throw invalid_argument("Нейросеть не инициализована!");
  }

  ofstream file(filename, ofstream::trunc);
  if (!file) {
    throw invalid_argument("Не удалось открыть файл " + filename);
  }

  NeuralNetworkMessage message = perceptron_->ToMessage();
  message.SerializeToOstream(&file);
  file.close();
}

void Mlp::LoadNeuralNetwork(string filename) {
  ifstream file(filename);
  if (!file) {
    throw invalid_argument("Не удалось открыть файл " + filename);
  }

  NeuralNetworkMessage perceptron_message;
  perceptron_message.ParseFromIstream(&file);

  std::cout << "balls 1" << std::endl;
  if (perceptron_ != NULL) {
    delete perceptron_;
  }

  std::cout << "balls 2" << std::endl;
  perceptron_ = NeuralNetwork::FromMessage(perceptron_message);
  file.close();
}