#ifndef MATRIX_CALCULUS_HPP
#define MATRIX_CALCULUS_HPP

#include <vector>

namespace s21 {
  class Matrix {
  private:
    std::vector<std::vector<int>> _matrix;

    void ensureCapacity(size_t x, size_t y) const;

  public:
    Matrix(std::initializer_list<std::initializer_list<int>> const &matrix);
    Matrix(Matrix const &other);
    explicit Matrix(size_t rowNumber, size_t colNumber);

    size_t getRowNumber() const;
    size_t getColNumber() const;

    int &operator()(std::size_t x, std::size_t y);
    const int operator()(std::size_t x, std::size_t y) const;

    // scalar functions
    void scalarAdd(int value);
    void scalarMultiply(int value);

    // elementwise functions
    void elemtwiseAdd(Matrix const &matrix);
    void elemtwiseMultiply(Matrix const &matrix);

    // matrix functions
    void matrixMultiply(Matrix const &matrix);

    Matrix operator =(Matrix const &other);
    bool operator ==(Matrix const &other);
  };
}

#endif
