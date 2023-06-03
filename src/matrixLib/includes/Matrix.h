#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <functional>

using namespace std;

namespace s21 {
  class Matrix {
  private:
    std::vector<std::vector<float>> _data;

    void ensureCapacity(int x, int y) const;

  public:
    Matrix(std::initializer_list<std::initializer_list<float>> const &matrix);
    Matrix(Matrix const &other);
    explicit Matrix(int rowNumber, int colNumber);

    int getRowNumber() const;
    int getColNumber() const;

    float &operator()(int x, int y);
    const float operator()(int x, int y) const;

    Matrix scalarAdd(float value) const;
    Matrix scalarMultiply(float value) const;
    Matrix add(Matrix const &other) const;
    Matrix subtract(Matrix const &other) const;
    Matrix multiply(Matrix const &other) const;
    Matrix getMatrixProduct(Matrix const &other) const;
    Matrix transpose() const;

    template <typename T, typename K>
    Matrix Matrix::map(std::function<T(K)> func) const;

    void operator=(Matrix const &other);
    bool operator==(Matrix const &other);
  };

  // Template functions
  template <typename T, typename K>
  Matrix Matrix::map(std::function<T(K)> func) const {
    Matrix result(getRowNumber(), getColNumber());

    for (int i = 0; i < getRowNumber(); i++) {
      for (int j = 0; j < getColNumber(); j++)
      {
        result(i, j) = func((*this)(j, i));
      }
    }

    return result;
  }
}

#endif
