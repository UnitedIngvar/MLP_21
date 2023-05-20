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
      _data.at(i).at(j) = *col_it;
    }
  }
}

Matrix::Matrix(Matrix const &other) :
  _data(other._data) {
}

explicit Matrix::Matrix(size_t rowNumber, size_t colNumber) {
  if (rowNumber <= 0 || colNumber <= 0) {
    throw invalid_argument("Matrix size cant be <= 0");
  }

  _data = vector<vector<int>>(rowNumber);
  for (size_t i = 0; i < rowNumber; i++) {
    _data.at(i) = vector<int>(colNumber);
  }
}

size_t Matrix::getRowNumber() const {
  return _data.size();
}

size_t Matrix::getColNumber() const {
  return _data.at(0).size();
}

int &Matrix::operator()(size_t x, size_t y) {
  ensureCapacity(x, y);

  return _data[x][y];
}

const int Matrix::operator()(size_t x, size_t y) const {
  ensureCapacity(x, y);

  return _data[x][y];
}

// scalar functions
Matrix Matrix::scalarAdd(int value) {
  Matrix result(getRowNumber(), getColNumber());

  for (auto i = 0; i < getRowNumber(); i++) {
    for (size_t j = 0; j < getColNumber(); j++) {
      result(i, j) = (*this)(i, j) + value;
    }
  }

  return result;
}

Matrix Matrix::scalarMultiply(int value) {
  Matrix result(getRowNumber(), getColNumber());

  for (auto i = 0; i < getRowNumber(); i++) {
    for (size_t j = 0; j < getColNumber(); j++) {
      result(i, j) = (*this)(i, j) * value;
    }
  }

  return result;
}

// elementwise functions
Matrix Matrix::elemtwiseAdd(Matrix const &other) {
  if (other.getColNumber() != getColNumber() ||
      other.getRowNumber() != getRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  Matrix result(getColNumber(), getRowNumber());

  for (auto i = 0; i < getRowNumber(); i++) {
    for (auto j = 0; j < getColNumber(); j++) {
      result(i, j) = (*this)(i, j) + other(i, j);
    }
  }

  return result;
}

Matrix Matrix::elemtwiseMultiply(Matrix const &other) {
  if (other.getColNumber() != getColNumber() ||
      other.getRowNumber() != getRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  Matrix result(getColNumber(), getRowNumber());

  for (auto i = 0; i < getRowNumber(); i++) {
    for (auto j = 0; j < getColNumber(); j++) {
      result(i, j) = (*this)(i, j) * other(i, j);
    }
  }

  return result;
}

Matrix Matrix::getMatrixProduct(Matrix const &other) {
  if (getColNumber() != other.getRowNumber()) {
    throw invalid_argument(
      "First matrix's column number must be equal to "
      "second matrix's row number");
  }

  Matrix result(getRowNumber(), other.getColNumber());

  // TODO: надо подумать, как это можно оптимизировать, если будет время. Кажется, можно
  for (size_t i = 0; i < getRowNumber(); i++) {
    for (size_t j = 0; j < other.getColNumber(); j++) {
      int product = 0;

      for (size_t k = 0; k < getRowNumber(); k++) {
        product += (*this)(i, k) * other(k, j);
      }

      result(i, j) = product;
    }
  }
}

Matrix Matrix::transpose() {
  Matrix result(getColNumber(), getRowNumber());

  for (size_t i = 0; i < getColNumber(); i++) {
    for (size_t j = 0; j < getRowNumber(); j++)
    {
      result(i, j) = (*this)(j, i);
    }
  }

  return result;
}

Matrix Matrix::map(std::function<int(int)> func) {
  Matrix result(getRowNumber(), getColNumber());

  for (size_t i = 0; i < getRowNumber(); i++) {
    for (size_t j = 0; j < getColNumber(); j++)
    {
      result(i, j) = func((*this)(j, i));
    }
  }

  return result;
}

void Matrix::operator=(Matrix const &other) {
  this->_data = other._data;
}

bool Matrix::operator==(Matrix const &other) {
  return this->_data == other._data;
}
