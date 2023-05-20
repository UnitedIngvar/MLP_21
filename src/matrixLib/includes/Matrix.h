#ifndef MATRIX_CALCULUS_HPP
#define MATRIX_CALCULUS_HPP

#include <vector>
#include <functional>

namespace s21 {
  class Matrix {
  private:
    std::vector<std::vector<int>> _data;

    void ensureCapacity(size_t x, size_t y) const;

  public:
    Matrix(std::initializer_list<std::initializer_list<int>> const &matrix);
    Matrix(Matrix const &other);
    explicit Matrix(size_t rowNumber, size_t colNumber);

    size_t getRowNumber() const;
    size_t getColNumber() const;

    int &operator()(std::size_t x, std::size_t y);
    const int operator()(std::size_t x, std::size_t y) const;

    Matrix scalarAdd(int value);
    Matrix scalarMultiply(int value);
    Matrix elemtwiseAdd(Matrix const &other);
    Matrix elemtwiseMultiply(Matrix const &other);
    Matrix getMatrixProduct(Matrix const &other);
    Matrix transpose();
    Matrix map(std::function<int(int)> func);

    void operator=(Matrix const &other);
    bool operator==(Matrix const &other);
  };
}

#endif
