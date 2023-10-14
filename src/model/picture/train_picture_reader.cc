#include "train_picture_reader.h"

#include <ostream>
#include <sstream>

using namespace s21;
using namespace std;

TrainPictureReader::TrainPictureReader() {}
TrainPictureReader::~TrainPictureReader() {}

vector<Picture> TrainPictureReader::ReadPictures(std::istream &picture_stream) {
  string line;
  char delimiter = ',';

  vector<Picture> result;
  for (string line; getline(picture_stream, line);) {
    istringstream ss(std::move(line));

    string value;
    getline(ss, value, delimiter);
    PicLabel label = (PicLabel)stoi(value);
    vector<pixel> row(kPixelCount_);
    int i = 0;
    for (string value; getline(ss, value, delimiter);) {
      if (i >= kPixelCount_) {
        throw invalid_argument(
            "Training set should contain only images with 784 pixels (28x28)");
      }
      row[i] = stoi(value);
      i++;
    }

    if (i < kPixelCount_) {
      throw invalid_argument(
          "Training set should contain only images with 784 pixels (28x28)");

      result.push_back(Picture(label, 28, 28, row));
    }

    return result;
  }

  return result;
}