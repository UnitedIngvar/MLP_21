#ifndef MATRIX_CALCULUS_HPP
#define MATRIX_CALCULUS_HPP

#include <vector>

namespace s21 {
  class MatrixCalculus {
  private:
    int _rowNumber;
    int _colNumber;

    std::vector<std::vector<int>> _matrix;

  public:
  MatrixCalculus(std::initializer_list<std::initializer_list<int>> const &matrix);
  MatrixCalculus(MatrixCalculus const &other);
  explicit MatrixCalculus()


  MatrixCalculus operator =(MatrixCalculus const &other);
  MatrixCalculus operator ==(MatrixCalculus const &other);
  };
}

#endif
