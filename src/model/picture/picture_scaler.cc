#include "picture_scaler.h"

#include <vector>

using namespace s21;
using namespace std;

// Bilenear interpolation algorithm
Picture PictureScaler::ScalePicture(Picture const &picture, int new_width,
                                    int new_height) const {
  vector<vector<Pixel>> result_pic(new_height);

  int old_width = picture.GetWidth();
  int old_height = picture.GetHeight();

  if (old_width == new_width)
    for (int y = 0; y < new_height; y++) {
      result_pic[y] = vector<Pixel>(new_width);

      for (int x = 0; x < new_width; x++) {
        double source_x = (x * old_width) / static_cast<double>(new_width);
        double source_y = (y * old_height) / static_cast<double>(new_height);

        int x0 = static_cast<int>(source_x);
        int x1 = std::min(x0 + 1, old_width - 1);
        int y0 = static_cast<int>(source_y);
        int y1 = std::min(y0 + 1, old_height - 1);

        double tx = source_x - x0;
        double ty = source_y - y0;

        int interpolatedValue = (1 - tx) * (1 - ty) * picture(y0, x0) +
                                tx * (1 - ty) * picture(y0, x1) +
                                (1 - tx) * ty * picture(y1, x0) +
                                tx * ty * picture(y1, x1);

        result_pic[y][x] = interpolatedValue;
      }
    }

  return Picture(result_pic);
}