#ifndef PICTURE_NORMALIZER_H
#define PICTURE_NORMALIZER_H

#include "picture.h"
#include "picture_scaler.h"

namespace s21 {
class PictureNormalizer {
 private:
  const int16_t kNormalWidth_ = 28;
  const int16_t kNoramlHeight_ = 28;
  PictureScaler picture_scaler_;

 public:
  PictureNormalizer();
  ~PictureNormalizer();

  Picture Normalize(Picture const &picture);
};
}  // namespace s21

#endif