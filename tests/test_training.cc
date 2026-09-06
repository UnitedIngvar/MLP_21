#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "mlp.h"
#include "neural_network.h"
#include "picture.h"
#include "picture_scaler.h"
#include "picture_shifter.h"
#include "settings.h"

using namespace s21;

namespace {

void Fail(const std::string& message) {
  std::cerr << "FAIL: " << message << std::endl;
  std::exit(1);
}

void ExpectTrue(bool condition, const std::string& message) {
  if (!condition) {
    Fail(message);
  }
}

void TestIntegerPixelNormalization() {
  Pixel pixel = 200;
  double broken = pixel / 255;
  double fixed = static_cast<double>(pixel) / 255.0;

  ExpectTrue(broken == 0.0,
             "unsigned char / 255 must be integer division (documents the bug)");
  ExpectTrue(fixed > 0.7 && fixed < 0.8,
             "training inputs must keep intermediate gray values");
  std::cout << "ok: pixel normalization (" << fixed << ")\n";
}

void TestLearningRateValidation() {
  try {
    NeuralNetwork nn(2, {2, 2}, 1, 0.0);
    Fail("learning rate 0 must be rejected");
  } catch (const std::invalid_argument&) {
  }

  try {
    NeuralNetwork nn(2, {2, 2}, 1, 1.5);
    Fail("learning rate > 1 must be rejected");
  } catch (const std::invalid_argument&) {
  }

  NeuralNetwork nn(2, {2, 2}, 1, 0.1);
  ExpectTrue(std::abs(nn.GetLearningRate() - 0.1) < 1e-12,
             "valid learning rate must be stored");
  std::cout << "ok: learning rate validation\n";
}

void TestXorLearns() {
  NeuralNetwork nn(2, {4}, 1, 0.5);
  std::ofstream log("/dev/null");

  const std::vector<std::pair<Matrix, Matrix>> data = {
      {Matrix({{0.0}, {0.0}}), Matrix({{0.0}})},
      {Matrix({{0.0}, {1.0}}), Matrix({{1.0}})},
      {Matrix({{1.0}, {0.0}}), Matrix({{1.0}})},
      {Matrix({{1.0}, {1.0}}), Matrix({{0.0}})},
  };

  double last_error = 1.0;
  for (int epoch = 0; epoch < 8000; ++epoch) {
    double error_sum = 0.0;
    for (const auto& sample : data) {
      error_sum += nn.Train(sample.first, sample.second, log, false);
    }
    last_error = error_sum / data.size();
  }

  std::cout << "xor mse after training: " << last_error << "\n";
  ExpectTrue(last_error < 0.01, "XOR network must converge");

  for (const auto& sample : data) {
    Matrix output = nn.Feedforward(sample.first);
    double expected = sample.second(0, 0);
    bool correct = expected > 0.5 ? output(0, 0) > 0.7 : output(0, 0) < 0.3;
    if (!correct) {
      Fail("XOR prediction failed: expected " + std::to_string(expected) +
           ", got " + std::to_string(output(0, 0)));
    }
  }
  std::cout << "ok: XOR training\n";
}

void TestPictureConstructorAndShifter() {
  std::vector<std::vector<Pixel>> pixels(4, std::vector<Pixel>(4, 0));
  pixels[2][3] = 255;
  Picture picture(pixels);

  ExpectTrue(picture.GetHeight() == 4 && picture.GetWidth() == 4,
             "2D picture constructor must accept a valid image");
  ExpectTrue(picture(2, 3) == 255, "source pixel must be preserved");

  PictureShifter shifter;
  shifter.ShiftPictureToTopLeftCorner(&picture);
  ExpectTrue(picture(0, 0) == 255, "ink must move to the top-left corner");
  ExpectTrue(picture(2, 3) == 0, "original pixel must be cleared after shift");
  std::cout << "ok: picture constructor and shifter\n";
}

void TestPictureScaler() {
  std::vector<std::vector<Pixel>> pixels(2, std::vector<Pixel>(2, 0));
  pixels[0][0] = 255;
  Picture source(pixels);

  PictureScaler scaler;
  Picture scaled = scaler.ScalePicture(source, 4, 4);
  ExpectTrue(scaled.GetWidth() == 4 && scaled.GetHeight() == 4,
             "scaler must change both dimensions");
  ExpectTrue(scaled(0, 0) > 0, "scaled image must keep source ink");
  std::cout << "ok: picture scaler\n";
}

void WriteSyntheticCsv(const std::string& path, int samples_per_class) {
  std::ofstream out(path);
  for (int label = 1; label <= 2; ++label) {
    for (int n = 0; n < samples_per_class; ++n) {
      out << label;
      for (int i = 0; i < 28; ++i) {
        for (int j = 0; j < 28; ++j) {
          bool horizontal = label == 1 && i < 8;
          bool vertical = label == 2 && j < 8;
          out << ',' << ((horizontal || vertical) ? 220 : 0);
        }
      }
      out << '\n';
    }
  }
}

void TestMlpLearnsSyntheticLetters() {
  const std::string train_path = "/tmp/mlp_train.csv";
  const std::string test_path = "/tmp/mlp_test.csv";
  WriteSyntheticCsv(train_path, 20);
  WriteSyntheticCsv(test_path, 10);

  Mlp mlp;
  Settings settings{.learning_rate = 0.3, .hidden_layers_count = {32, 16}};
  mlp.CreateNewNeuralNetwork(settings, nnType::kMatrix);
  mlp.PassDatasets(train_path, test_path);
  std::map<int, double> errors = mlp.StartTraining(8);

  std::cout << "synthetic mse epoch 0: " << errors[0] << "\n";
  std::cout << "synthetic mse epoch 7: " << errors[7] << "\n";
  ExpectTrue(errors[7] < errors[0] / 2.0,
             "full MLP pipeline must reduce training MSE");
  ExpectTrue(errors[7] < 0.02,
             "full MLP pipeline must fit a trivial two-letter dataset");

  metrics result = mlp.RunExperiment(1.0);
  std::cout << "synthetic accuracy: " << result.average_accuracy << "\n";
  for (int epoch = 0; epoch < 8; ++epoch) {
    std::remove(("experiment_epoch_" + std::to_string(epoch)).c_str());
  }
  std::remove("log");
  std::cout << "ok: synthetic letter training\n";
}

}  // namespace

int main() {
  TestIntegerPixelNormalization();
  TestLearningRateValidation();
  TestPictureConstructorAndShifter();
  TestPictureScaler();
  TestXorLearns();
  TestMlpLearnsSyntheticLetters();
  std::cout << "all training tests passed\n";
  return 0;
}
