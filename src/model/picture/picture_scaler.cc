#include "picture_scaler.h"

#include <vector>

using namespace s21;
using namespace std;

// Bilenear interpolation algorithm
Picture PictureScaler::ScalePicture(Picture const &picture, int new_width,
                                    int new_height) const {
  vector<vector<pixel>> result_pic(new_height);

  int oldWidth = picture.GetWidth();
  int oldHeight = picture.GetHeight();

  for (int y = 0; y < new_height; y++) {
    result_pic[y] = vector<pixel>(new_width);

    for (int x = 0; x < new_width; x++) {
      float sourceX = (x * oldWidth) / static_cast<float>(new_width);
      float sourceY = (y * oldHeight) / static_cast<float>(new_height);

      int x0 = static_cast<int>(sourceX);
      int x1 = std::min(x0 + 1, oldWidth - 1);
      int y0 = static_cast<int>(sourceY);
      int y1 = std::min(y0 + 1, oldHeight - 1);

      float tx = sourceX - x0;
      float ty = sourceY - y0;

      int interpolatedValue = (1 - tx) * (1 - ty) * picture(y0, x0) +
                              tx * (1 - ty) * picture(y0, x1) +
                              (1 - tx) * ty * picture(y1, x0) +
                              tx * ty * picture(y1, x1);

      result_pic[y][x] = interpolatedValue;
    }
  }

  return Picture(result_pic);
}