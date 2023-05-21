#ifndef MATRIX_HPP
#define MATRIX_HPP

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

    Matrix scalarAdd(int value) const;
    Matrix scalarMultiply(int value) const;
    Matrix elemtwiseAdd(Matrix const &other) const;
    Matrix elemtwiseMultiply(Matrix const &other) const;
    Matrix getMatrixProduct(Matrix const &other) const;
    Matrix transpose() const;

    template <typename T>
    Matrix map(std::function<T(int)> func) const;

    void operator=(Matrix const &other);
    bool operator==(Matrix const &other);
  };

  // Template functions
  template <typename T>
  Matrix Matrix::map(std::function<T(int)> func) const {
    Matrix result(getRowNumber(), getColNumber());

    for (size_t i = 0; i < getRowNumber(); i++) {
      for (size_t j = 0; j < getColNumber(); j++)
      {
        result(i, j) = func((*this)(j, i));
      }
    }

    return result;
  }
}

#endif
