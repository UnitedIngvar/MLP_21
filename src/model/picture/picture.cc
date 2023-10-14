#include "picture.h"

using namespace std;
using namespace s21;

Picture::Picture(PicLabel label, int width, int height,
                 std::vector<pixel> flattenedData) {
  if (width <= 0 || height <= 0) {
    throw std::invalid_argument("Picture width and height should be > 0");
  }
  if (flattenedData.size() != width * height) {
    throw std::invalid_argument("Inconsistent width and height of picture");
  }

  width_ = width;
  height_ = height;

  data_ = flattenedData;
}

Picture::Picture(std::vector<std::vector<pixel>> data) {
  if (data.size() <= 0 || data.at(0).size()) {
    throw std::invalid_argument("Picture width and height should be > 0");
  }

  height_ = data.size();
  width_ = data[0].size();
  data_ = vector<pixel>(height_ * width_);

  for (size_t i = 0; i < height_; i++) {
    if (data[i].size() != width_) {
      throw std::invalid_argument("Inconsistent width of picture");
    }

    for (size_t j = 0; j < width_; j++) {
      data_[i * width_ + j] = data[i][j];
    }
  }
}

Picture::Picture(Picture const &other) { *this = other; }

void Picture::SetLabel(PicLabel label) { label_ = label; }

PicLabel Picture::GetLabel() const { return label_; }

int Picture::GetHeight() const { return height_; }

int Picture::GetWidth() const { return width_; }

vector<pixel> Picture::GetFlattenedMap() { return data_; };

pixel Picture::operator()(int x, int y) const { return data_[x * width_ + y]; }

pixel &Picture::operator()(int x, int y) { return data_[x * width_ + y]; }

void Picture::operator=(Picture const &other) {
  label_ = other.label_;
  data_ = other.data_;
  height_ = other.height_;
  width_ = other.width_;
}