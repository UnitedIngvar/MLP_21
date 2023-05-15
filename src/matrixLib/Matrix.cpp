#include "Matrix.h"
using namespace s21;
using namespace std;

void Matrix::ensureCapacity(size_t x, size_t y) const {
  if (x >= getRowNumber() || y >= getColNumber()) {
    throw invalid_argument("Index exceeds matrix dimensions");
  }
}

Matrix::Matrix(initializer_list<initializer_list<int>> const &matrix) {
  size_t i, j = 0;
  for (auto row_it = matrix.begin(); row_it < matrix.end(); i++, row_it++) {
    for (auto col_it = row_it->begin(); col_it < row_it->end(); j++, col_it++) {
      _matrix.at(i).at(j) = *col_it;
    }
  }
}

Matrix::Matrix(Matrix const &other) :
  _matrix(other._matrix) {
}

explicit Matrix::Matrix(size_t rowNumber, size_t colNumber) {
  if (rowNumber <= 0 || colNumber <= 0) {
    throw invalid_argument("matrix size cant be <= 0");
  }

  _matrix = vector<vector<int>>(rowNumber);
  for (size_t i = 0; i < rowNumber; i++) {
    _matrix.at(i) = vector<int>(colNumber);
  }
}

size_t Matrix::getRowNumber() const {
  return _matrix.size();
}

// TODO: Под вопрсом.
// Всегда ли матрицы имеют равное кол-во колонок в каждом ряду?
size_t Matrix::getColNumber() const {
  return _matrix.at(0).size();
}

int &Matrix::operator()(size_t x, size_t y) {
  ensureCapacity(x, y);

  return _matrix.at(x).at(y);
}

const int Matrix::operator()(size_t x, size_t y) const {
  ensureCapacity(x, y);

  return _matrix.at(x).at(y);
}

// scalar functions
void Matrix::scalarAdd(int value) {
  for (auto i = 0; i < getRowNumber(); i++) {
    for (size_t j = 0; j < getColNumber(); j++) {
      _matrix.at(i).at(j) += value;
    }
  }
}

void Matrix::scalarMultiply(int value) {
  for (auto i = 0; i < getRowNumber(); i++) {
    for (size_t j = 0; j < getColNumber(); j++) {
      _matrix.at(i).at(j) *= value;
    }
  }
}

// elementwise functions
void Matrix::elemtwiseAdd(Matrix const &matrix) {
  if (matrix.getColNumber() != getColNumber() ||
      matrix.getRowNumber() != getRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  for (auto i = 0; i < getRowNumber(); i++) {
    for (auto j = 0; j < getColNumber(); j++) {
      _matrix.at(i).at(j) += matrix(i, j);
    }
  }
}

void Matrix::elemtwiseMultiply(Matrix const &matrix) {
  if (matrix.getColNumber() != getColNumber() ||
      matrix.getRowNumber() != getRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  for (auto i = 0; i < getRowNumber(); i++) {
    for (auto j = 0; j < getColNumber(); j++) {
      _matrix.at(i).at(j) *= matrix(i, j);
    }
  }
}

void Matrix::matrixMultiply(Matrix const &matrix) {
  if (getColNumber() != matrix.getRowNumber()) {
    throw invalid_argument("First matrix's column number must equal second matrix's row number");
  }


}

Matrix Matrix::operator =(Matrix const &other) {

}

bool Matrix::operator ==(Matrix const &other) {

}
