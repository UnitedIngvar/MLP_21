#include "picture_shifter.h"

using namespace s21;
using namespace std;

void PictureShifter::ShiftPictureToTopLeftCorner(Picture *picture) const {
  int leftmost_index = INT_MAX;
  int topmost_index = -1;

  int height = picture->GetHeight();
  int width = picture->GetWidth();
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (topmost_index == -1 && (*picture)(i, j) != 0) {
        topmost_index = i;
      }

      if (leftmost_index > j && (*picture)(i, j) != 0) {
        leftmost_index = j;
      }

      if (leftmost_index == 0 && topmost_index == 0) {
        break;
      }
    }
  }

  if (topmost_index != 0 || leftmost_index != 0) {
    for (int i = topmost_index; i < height; i++) {
      for (int j = leftmost_index; j < width; j++) {
        int shifted_i_index = i - topmost_index;
        int shifted_j_index = j - leftmost_index;

        (*picture)(shifted_i_index, shifted_j_index) = (*picture)(i, j);
      }
    }
  }
}