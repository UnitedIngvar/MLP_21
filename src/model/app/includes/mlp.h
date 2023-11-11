#ifndef MLP
#define MLP

#include <map>

#include "metrics.h"
#include "metrics_aggregator.h"
#include "neural_network.h"
#include "picture.h"
#include "settings.h"

namespace s21 {
typedef struct trainingPair {
  Matrix inputs;
  Matrix expected_output;
} trainingPair;

class Mlp {
 private:
  // TODO: заменить на интерфейс
  NeuralNetwork *perceptron_ = NULL;
  std::vector<Picture *> train_pictures_;
  std::vector<Picture *> test_pictures_;
  const int kInputNodesCount_ = 784;
  const int kOutputNodesCount_ = 26;

  PicLabel DetermineGuess(Matrix const &output) const;
  Matrix PictureToInput(Picture const *picture) const;
  std::vector<Matrix> PicturesToInputs(std::vector<Picture *> pictures,
                                       int test_count) const;
  std::vector<trainingPair> GetTrainingData(
      std::vector<Picture *> const &training_pictures) const;

 public:
  Mlp();
  ~Mlp();

  void CreateNewNeuralNetwork(Settings settings, nnType type);
  void PassDatasets(std::string train_filename, std::string test_filename);
  std::map<int, double> StartTraining(int epoch_count);
  metrics RunExperiment(double test_percentage);
  char GuessBmpFile(std::string filename);
  char GuessHandwritten(std::vector<int> picture);
  void StartTrainingWithCrossValidation(int group_count);
  void SaveNeuralNetwork(std::string filename);
  void LoadNeuralNetwork(std::string filename);
  void SetLearningRate(double learning_rate);
};
}  // namespace s21

#endif
