#ifndef PICTURE_READER_H
#define PICTURE_READER_H

#include <istream>
#include <vector>

#include "picture.h"

namespace s21 {
class PictureReader {
 public:
  PictureReader();
  ~PictureReader();

  std::vector<Picture> ReadPicture(std::istream &picture_stream);
};
}  // namespace s21
#endif