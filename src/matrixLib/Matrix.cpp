#include "Matrix.h"
using namespace s21;
using namespace std;

void Matrix::ensureCapacity(int x, int y) const {
  if (x >= getRowNumber() || y >= getColNumber()) {
    throw invalid_argument("Index exceeds matrix dimensions");
  }
}

Matrix::Matrix(initializer_list<initializer_list<float>> const &matrix) {
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

explicit Matrix::Matrix(int rowNumber, int colNumber) {
  if (rowNumber <= 0 || colNumber <= 0) {
    throw invalid_argument("Matrix size cant be <= 0");
  }

  _data = vector<vector<float>>(rowNumber);
  for (int i = 0; i < rowNumber; i++) {
    _data.at(i) = vector<float>(colNumber);
  }
}

int Matrix::getRowNumber() const {
  return _data.size();
}

int Matrix::getColNumber() const {
  return _data.at(0).size();
}

float &Matrix::operator()(int x, int y) {
  ensureCapacity(x, y);

  return _data[x][y];
}

const float Matrix::operator()(int x, int y) const {
  ensureCapacity(x, y);

  return _data[x][y];
}

// scalar functions
Matrix Matrix::scalarAdd(float value) const {
  Matrix result(getRowNumber(), getColNumber());

  for (int i = 0; i < getRowNumber(); i++) {
    for (int j = 0; j < getColNumber(); j++) {
      result(i, j) = (*this)(i, j) + value;
    }
  }

  return result;
}

Matrix Matrix::scalarMultiply(float value) const {
  Matrix result(getRowNumber(), getColNumber());

  for (int i = 0; i < getRowNumber(); i++) {
    for (int j = 0; j < getColNumber(); j++) {
      result(i, j) = (*this)(i, j) * value;
    }
  }

  return result;
}

// elementwise functions
Matrix Matrix::add(Matrix const &other) const {
  if (other.getColNumber() != getColNumber() ||
      other.getRowNumber() != getRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  Matrix result(getColNumber(), getRowNumber());

  for (int i = 0; i < getRowNumber(); i++) {
    for (int j = 0; j < getColNumber(); j++) {
      result(i, j) = (*this)(i, j) + other(i, j);
    }
  }

  return result;
}

Matrix Matrix::subtract(Matrix const &other) const {
  if (other.getColNumber() != getColNumber() ||
      other.getRowNumber() != getRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  Matrix result(getColNumber(), getRowNumber());

  for (int i = 0; i < getRowNumber(); i++) {
    for (int j = 0; j < getColNumber(); j++) {
      result(i, j) = (*this)(i, j) - other(i, j);
    }
  }

  return result;
}

Matrix Matrix::multiply(Matrix const &other) const {
  if (other.getColNumber() != getColNumber() ||
      other.getRowNumber() != getRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  Matrix result(getColNumber(), getRowNumber());

  for (int i = 0; i < getRowNumber(); i++) {
    for (int j = 0; j < getColNumber(); j++) {
      result(i, j) = (*this)(i, j) * other(i, j);
    }
  }

  return result;
}

Matrix Matrix::getMatrixProduct(Matrix const &other) const {
  if (getColNumber() != other.getRowNumber()) {
    throw invalid_argument(
      "First matrix's column number must be equal to "
      "second matrix's row number");
  }

  Matrix result(getRowNumber(), other.getColNumber());

  // TODO: надо подумать, как это можно оптимизировать, если будет время. Кажется, можно
  for (int i = 0; i < getRowNumber(); i++) {
    for (int j = 0; j < other.getColNumber(); j++) {
      int product = 0;

      for (int k = 0; k < getRowNumber(); k++) {
        product += (*this)(i, k) * other(k, j);
      }

      result(i, j) = product;
    }
  }
}

Matrix Matrix::transpose() const {
  Matrix result(getColNumber(), getRowNumber());

  for (int i = 0; i < getColNumber(); i++) {
    for (int j = 0; j < getRowNumber(); j++)
    {
      result(i, j) = (*this)(j, i);
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
