#include "picture.h"

using namespace std;
using namespace s21;

Picture::Picture(PicLabel label, int width, int height,
                 std::vector<Pixel> flattenedData) {
  if (height <= 0 || width <= 0) {
    throw std::invalid_argument(
        "Высота и ширина изображения должны быть положительным значением");
  }
  if (flattenedData.size() != (size_t)(width * height)) {
    throw std::invalid_argument(
        "Изображение имеет несогласованное кол-во пикселей");
  }

  width_ = width;
  height_ = height;

  data_ = flattenedData;
  label_ = label;
}

Picture::Picture(std::vector<std::vector<Pixel>> data) {
  if (data.size() <= 0 || data.at(0).size()) {
    throw std::invalid_argument(
        "Высота и ширина изображения должны быть положительным значением");
  }
  if (data.size() > 512 || data.at(0).size() > 512) {
    throw std::invalid_argument(
        "Разрешение изображения не должно превышать 512х512");
  }
  if (data.size() <= 0 || data.at(0).size()) {
    throw std::invalid_argument(
        "Высота и ширина изображения должна быть положительным значением");
  }

  height_ = data.size();
  width_ = data[0].size();
  data_ = vector<Pixel>(height_ * width_);

  for (int i = 0; i < height_; i++) {
    if (data[i].size() != (size_t)width_) {
      throw std::invalid_argument("Несогласованное кол-во пикселей в ");
    }

    for (int j = 0; j < width_; j++) {
      data_[i * width_ + j] = data[i][j];
    }
  }
}

Picture::Picture(Picture const &other) { *this = other; }

void Picture::SetLabel(PicLabel label) { label_ = label; }

PicLabel Picture::GetLabel() const { return label_; }

int Picture::GetHeight() const { return height_; }

int Picture::GetWidth() const { return width_; }

vector<Pixel> Picture::GetFlattenedMap() const { return data_; };

Pixel Picture::operator()(int x, int y) const { return data_[x * width_ + y]; }

Pixel &Picture::operator()(int x, int y) { return data_[x * width_ + y]; }

void Picture::operator=(Picture const &other) {
  label_ = other.label_;
  data_ = other.data_;
  height_ = other.height_;
  width_ = other.width_;
}