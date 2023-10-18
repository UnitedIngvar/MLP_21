#ifndef PICTURE_SHIFTER
#define PICTURE_SHIFTER

#include "picture.h"

namespace s21 {
class PictureShifter {
 public:
  void ShiftPictureToTopLeftCorner(Picture *picture) const;
};
}  // namespace s21

#endif