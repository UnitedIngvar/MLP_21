#pragma once

#ifndef MATRIX_H
#define MATRIX_H

#include <functional>
#include <iostream>
#include <vector>

#include "neural_network.pb.h"

namespace s21 {
class Matrix {
 private:
  std::vector<std::vector<float>> data_;

  void EnsureCapacity(int x, int y) const;

 public:
  Matrix();
  Matrix(std::initializer_list<std::initializer_list<float>> const &matrix);
  Matrix(Matrix const &other);
  explicit Matrix(int row_number, int col_number);

  void operator=(Matrix const &other);

  ~Matrix();

  int GetRowNumber() const;
  int GetColNumber() const;

  Matrix ScalarAdd(float value) const;
  Matrix ScalarMultiply(float value) const;
  Matrix Add(Matrix const &other) const;
  Matrix Subtract(Matrix const &other) const;
  Matrix Multiply(Matrix const &other) const;
  Matrix GetMatrixProduct(Matrix const &other) const;
  Matrix Transpose() const;

  template <typename T, typename K>
  Matrix Map(std::function<T(K)> func) const;

  bool operator==(Matrix const &other);
  float &operator()(int x, int y);
  float operator()(int x, int y) const;

  static Matrix Randomize(int row_number, int col_number);

  MatrixMessage ToMatrixMessage() const;
  static Matrix FromMatrixMessage(MatrixMessage const &message);
};

// Template functions
template <typename T, typename K>
Matrix Matrix::Map(std::function<T(K)> func) const {
  Matrix result(GetRowNumber(), GetColNumber());

  for (int row = 0; row < GetRowNumber(); row++) {
    for (int col = 0; col < GetColNumber(); col++) {
      result(row, col) = func((*this)(row, col));
    }
  }

  return result;
}

std::ostream &operator<<(std::ostream &os, Matrix const &m);
}  // namespace s21

#endif
