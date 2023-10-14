#ifndef MLP
#define MLP

#include <map>

#include "neural_network.h"
#include "picture.h"

namespace s21 {
typedef enum actions {
  kCreate = 0,
  kPassData = 1,
  kLearn = 2,
  kUse = 3,
  kSave = 4
} actions;

typedef struct metrics {
  float avarage_accuracy;
  float precision;
  float recall;
  float f_measure;
  time_t time_elapsed;
} metrics;

class Mlp {
 private:
  // TODO: заменить на интерфейс
  NeuralNetwork *perceptron_;
  std::vector<Picture> train_pictures_;
  std::vector<Picture> test_pictures_;
  const int kInputNodesCount_ = 784;
  const int kOutputNodesCount_ = 28;

 public:
  Mlp();
  ~Mlp();

  void CreateNewNeuralNetwork(float learning_rate, int hidden_layer_count,
                              nnType type);
  void PassDatasets(std::string learning_filename,
                    std::string testing_filename);
  std::map<int, float> StartTraining(int epoch_count);
  metrics RunExperiment(float test_percentage);
  char GuessBmpFile(std::string filepath);
  char GuessHandwritten(std::vector<int> picture);
  void LearnWithCrossValidation(int group_count);
  void SaveNeuralNetwork(std::string filename);
  void LoadNeuralNetwork(std::string filename);
};
}  // namespace s21

#endif
