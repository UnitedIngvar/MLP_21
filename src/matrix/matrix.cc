#include "matrix.h"
#include "iostream"

using namespace s21;
using namespace std;

void Matrix::EnsureCapacity(int row_index, int col_index) const {
  // std::cout << row_index << " >= " << GetRowNumber() << " || " 
  //   << col_index << " >= " << GetColNumber() << std::endl;
  
  if (row_index >= GetRowNumber() || col_index >= GetColNumber()) {
    throw invalid_argument("Index exceeds matrix dimensions");
  }
}

Matrix::Matrix() {
}

Matrix::Matrix(initializer_list<initializer_list<float>> const &matrix) {
  int i = 0;

  data_ = vector<vector<float>>(matrix.size());

  for (auto row_it = matrix.begin(); row_it < matrix.end(); i++, row_it++) {
    size_t row_size = row_it->size();

    if (i > 0 && row_size != row_it->size()) {
      throw std::invalid_argument("matrix rows should have the same size");
    }

    data_.at(i) = vector<float>(row_it->begin(), row_it->end());
  }
}

Matrix::Matrix(Matrix const &other) :
  data_(other.data_) {
}

Matrix::Matrix(int row_number, int col_number) {
  if (row_number <= 0 || col_number <= 0) {
    throw invalid_argument("Matrix size cant be <= 0");
  }

  data_ = vector<vector<float>>(row_number);
  for (int i = 0; i < row_number; i++) {
    data_.at(i) = vector<float>(col_number);
  }
}

Matrix::~Matrix() {}
int Matrix::GetRowNumber() const {
  return data_.size();
}

int Matrix::GetColNumber() const {
  return data_[0].size();
}

float &Matrix::operator()(int row, int col) {
  EnsureCapacity(row, col);

  return data_[row][col];
}

float Matrix::operator()(int row, int col) const {
  EnsureCapacity(row, col);

  return data_[row][col];
}

// scalar functions
Matrix Matrix::ScalarAdd(float value) const {
  Matrix result(GetRowNumber(), GetColNumber());

  for (int row = 0; row < GetRowNumber(); row++) {
    for (int col = 0; col < GetColNumber(); col++) {
      result(row, col) = (*this)(row, col) + value;
    }
  }

  return result;
}

Matrix Matrix::ScalarMultiply(float value) const {
  Matrix result(GetRowNumber(), GetColNumber());

  for (int row = 0; row < GetRowNumber(); row++) {
    for (int col = 0; col < GetColNumber(); col++) {
      result(row, col) = (*this)(row, col) * value;
    }
  }

  return result;
}

// elementwise functions
Matrix Matrix::Add(Matrix const &other) const {
  if (other.GetColNumber() != GetColNumber() ||
      other.GetRowNumber() != GetRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  Matrix result(GetRowNumber(), GetColNumber());

  for (int row = 0; row < GetRowNumber(); row++) {
    for (int col = 0; col < GetColNumber(); col++) {
      result(row, col) = (*this)(row, col) + other(row, col);
    }
  }

  return result;
}

Matrix Matrix::Subtract(Matrix const &other) const {
  if (other.GetColNumber() != GetColNumber() ||
      other.GetRowNumber() != GetRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  Matrix result(GetRowNumber(), GetColNumber());

  for (int row = 0; row < GetRowNumber(); row++) {
    for (int col = 0; col < GetColNumber(); col++) {
      result(row, col) = (*this)(row, col) - other(row, col);
    }
  }

  return result;
}

Matrix Matrix::Multiply(Matrix const &other) const {
  if (other.GetColNumber() != GetColNumber() ||
      other.GetRowNumber() != GetRowNumber()) {
        throw invalid_argument("Matrices should have the same dimensionality");
  }

  Matrix result(GetRowNumber(), GetColNumber());

  for (int row = 0; row < GetRowNumber(); row++) {
    for (int col = 0; col < GetColNumber(); col++) {
      result(row, col) = (*this)(row, col) * other(row, col);
    }
  }

  return result;
}

Matrix Matrix::GetMatrixProduct(Matrix const &other) const {
  if (GetColNumber() != other.GetRowNumber()) {
    throw invalid_argument(
      "First matrix's column number must be equal to "
      "second matrix's row number");
  }

  Matrix result(GetRowNumber(), other.GetColNumber());

  // TODO: надо подумать, как это можно оптимизировать, если будет время. Кажется, можно
  for (int leftRow = 0; leftRow < GetRowNumber(); leftRow++) {
    for (int rightCol = 0; rightCol < other.GetColNumber(); rightCol++) {
      float product = 0;

      for (int k = 0; k < GetColNumber(); k++) {
        product += (*this)(leftRow, k) * other(k, rightCol);
      }

      result(leftRow, rightCol) = product;
    }
  }

  return result;
}

Matrix Matrix::Transpose() const {
  Matrix result(GetColNumber(), GetRowNumber());

  for (int row = 0; row < GetRowNumber(); row++) {
    for (int col = 0; col < GetColNumber(); col++)
    {
      result(col, row) = (*this)(row, col);
    }
  }

  return result;
}

void Matrix::operator=(Matrix const &other) {
  this->data_ = other.data_;
}

bool Matrix::operator==(Matrix const &other) {
  return this->data_ == other.data_;
}

Matrix Matrix::Randomize(int row_number, int col_number) {
  Matrix m(row_number, col_number);

  for (int row = 0; row < row_number; row++) {
    for (int col = 0; col < col_number; col++) {
      m(row, col) = rand() / (RAND_MAX + 1.);
    }
  }

  return m;
}

ostream &s21::operator<<(ostream &os, Matrix const &m) {
  os << "row number: " << m.GetRowNumber() << std::endl;
  os << "col number: " << m.GetColNumber() << std::endl;

  for (int row = 0; row < m.GetRowNumber(); row++) {
    for (int col = 0; col < m.GetColNumber(); col++) {
      os << m(row, col) << " ";
    }

    std::cout << std::endl;
  }

  os << std::endl;

  return os;
}