#ifndef PICTURE_SCALER_H
#define PICTURE_SCALER_H

#include "picture.h"

namespace s21 {
class PictureScaler {
 public:
  Picture ScalePicture(Picture const &picture, int new_width,
                       int new_height) const;
};
}  // namespace s21

#endif