#ifndef PICTURE_H
#define PICTURE_H

#include <vector>

namespace s21 {
typedef enum PicLabel {
  Unknown = 0,
  A = 1,
  B = 2,
  C = 3,
  D = 4,
  E = 5,
  F = 6,
  G = 7,
  H = 8,
  I = 9,
  J = 10,
  K = 11,
  L = 12,
  M = 13,
  N = 14,
  O = 15,
  P = 16,
  Q = 17,
  R = 18,
  S = 19,
  T = 20,
  U = 21,
  V = 22,
  W = 23,
  X = 24,
  Y = 25,
  Z = 26
} PicLabel;

typedef unsigned char pixel;

class Picture {
 private:
  PicLabel label_;
  std::vector<pixel> data_;
  int width_;
  int height_;

 public:
  Picture(PicLabel label, int width, int height,
          std::vector<pixel> flattenedData);
  Picture(std::vector<std::vector<pixel>> data);
  Picture(Picture const &other);

  void SetLabel(PicLabel label);
  PicLabel GetLabel() const;
  int GetHeight() const;
  int GetWidth() const;
  vector<pixel> Picture::GetFlattenedMap();

  pixel operator()(int x, int y) const;
  pixel &operator()(int x, int y);

  void operator=(Picture const &other);
};
}  // namespace s21
#endif