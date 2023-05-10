#ifndef MATRIX_CALCULUS_HPP
#define MATRIX_CALCULUS_HPP

#include <vector>

namespace s21 {
  class Matrix {
  private:
    size_t _rowNumber;
    size_t _colNumber;

    std::vector<std::vector<int>> _matrix;

  public:
  Matrix(std::initializer_list<std::initializer_list<int>> const &matrix);
  Matrix(Matrix const &other);
  explicit Matrix(size_t rowNumber, size_t colNumber);

  int &operator()(std::size_t x, std::size_t y);
  const int operator()(std::size_t x, std::size_t y) const;

  // scalar functions
  void scalarAdd(int value) const;
  void scalarMultiply(int value) const;

  // elementwise functions
  void elemtwiseAdd(Matrix const &matrix) const;
  void elemtwiseMultiply(Matrix const &matrix) const;

  Matrix operator =(Matrix const &other);
  Matrix operator ==(Matrix const &other);
  };
}

#endif
