#include "picture_shifter.h"

#include <vector>

using namespace s21;
using namespace std;

void PictureShifter::ShiftPictureToTopLeftCorner(Picture *picture) const {
  int height = picture->GetHeight();
  int width = picture->GetWidth();
  int topmost_index = height;
  int leftmost_index = width;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if ((*picture)(i, j) != 0) {
        if (i < topmost_index) {
          topmost_index = i;
        }
        if (j < leftmost_index) {
          leftmost_index = j;
        }
      }
    }
  }

  if (topmost_index == 0 && leftmost_index == 0) {
    return;
  }
  if (topmost_index == height) {
    return;
  }

  vector<Pixel> shifted(static_cast<size_t>(height * width), 0);
  for (int i = topmost_index; i < height; i++) {
    for (int j = leftmost_index; j < width; j++) {
      shifted[(i - topmost_index) * width + (j - leftmost_index)] =
          (*picture)(i, j);
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      (*picture)(i, j) = shifted[i * width + j];
    }
  }
}