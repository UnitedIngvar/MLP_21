#include "train_picture_reader.h"

#include <ostream>
#include <sstream>

using namespace s21;
using namespace std;

TrainPictureReader::TrainPictureReader() {}
TrainPictureReader::~TrainPictureReader() {}

vector<Picture *> TrainPictureReader::ReadPictures(
    std::istream &picture_stream) {
  string line;
  char delimiter = ',';

  vector<Picture *> result;
  for (string line; getline(picture_stream, line);) {
    istringstream ss(std::move(line));

    string value;
    getline(ss, value, delimiter);
    PicLabel label = stoi(value) + LABEL_MAP_SHIFT;
    vector<Pixel> row(kPixelCount_);
    int i = 0;
    for (string value; getline(ss, value, delimiter);) {
      if (i >= kPixelCount_) {
        for (size_t j = 0; j < result.size(); j++) {
          delete &result[j];
        }
        throw invalid_argument(
            "Training set should contain only images with 784 pixels (28x28)");
      }
      row[i] = stoi(value);
      i++;
    }

    if (i < kPixelCount_) {
      for (size_t j = 0; j < result.size(); j++) {
        delete &result[j];
      }
      throw invalid_argument(
          "Training set should contain only images with 784 pixels (28x28)");
    }

    Picture *picture = new Picture(label, 28, 28, row);
    picture_shifter_.ShiftPictureToTopLeftCorner(picture);
    result.push_back(picture);
  }

  return result;
}