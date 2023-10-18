#include "picture_normalizer.h"

using namespace s21;
using namespace std;

PictureNormalizer::PictureNormalizer() {}
PictureNormalizer::~PictureNormalizer() {}

Picture PictureNormalizer::Normalize(Picture const &picture) {
  int height = picture.GetHeight();
  int width = picture.GetWidth();

  Picture scaled_picture =
      picture_scaler_.ScalePicture(picture, kNormalWidth_, kNoramlHeight_);

  picture_shifter_.ShiftPictureToTopLeftCorner(&scaled_picture);

  return scaled_picture;
}