#ifndef TRAIN_PICTURE_READER_H
#define TRAIN_PICTURE_READER_H

#include <istream>
#include <vector>

#include "picture.h"

namespace s21 {
class TrainPictureReader {
 private:
  const int kPixelCount_ = 784;

 public:
  TrainPictureReader();
  ~TrainPictureReader();

  std::vector<Picture> ReadPictures(std::istream &picture_stream);
};
}  // namespace s21
#endif