#ifndef PICTURE_H
#define PICTURE_H

#include <vector>

namespace s21 {

#define LABEL_MAP_SHIFT (unsigned char)64
typedef unsigned char PicLabel;
typedef unsigned char Pixel;

class Picture {
 private:
  PicLabel label_;
  std::vector<Pixel> data_;
  int width_;
  int height_;

 public:
  Picture(PicLabel label, int width, int height,
          std::vector<Pixel> flattenedData);
  Picture(std::vector<std::vector<Pixel>> data);
  Picture(Picture const &other);

  void SetLabel(PicLabel label);
  PicLabel GetLabel() const;
  int GetHeight() const;
  int GetWidth() const;
  std::vector<Pixel> GetFlattenedMap() const;

  Pixel operator()(int x, int y) const;
  Pixel &operator()(int x, int y);

  void operator=(Picture const &other);
};
}  // namespace s21
#endif