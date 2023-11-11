#include "matrix.h"

#include <iostream>
#include <random>

#include "neural_network.pb.h"

using namespace s21;
using namespace std;

void Matrix::EnsureCapacity(int row_index, int col_index) const {
  // std::cout << row_index << " >= " << GetRowNumber() << " || "
  //   << col_index << " >= " << GetColNumber() << std::endl;

  if (row_index >= GetRowNumber() || col_index >= GetColNumber()) {
    throw invalid_argument("Index exceeds matrix dimensions");
  }
}

Matrix::Matrix() {}

Matrix::Matrix(initializer_list<initializer_list<double>> const &matrix) {
  int i = 0;

  data_ = vector<vector<double>>(matrix.size());

  for (auto row_it = matrix.begin(); row_it < matrix.end(); i++, row_it++) {
    size_t row_size = row_it->size();

    if (i > 0 && row_size != row_it->size()) {
      throw std::invalid_argument("matrix rows should have the same size");
    }

    data_.at(i) = vector<double>(row_it->begin(), row_it->end());
  }
}

Matrix::Matrix(Matrix const &other) : data_(other.data_) {}

Matrix::Matrix(int row_number, int col_number) {
  if (row_number <= 0 || col_number <= 0) {
    throw invalid_argument("Matrix size cant be <= 0");
  }

  data_ = vector<vector<double>>(row_number);
  for (int i = 0; i < row_number; i++) {
    data_.at(i) = vector<double>(col_number);
  }
}

Matrix::~Matrix() {}
int Matrix::GetRowNumber() const { return data_.size(); }

int Matrix::GetColNumber() const { return data_[0].size(); }

double &Matrix::operator()(int row, int col) {
  EnsureCapacity(row, col);

  return data_[row][col];
}

double Matrix::operator()(int row, int col) const {
  EnsureCapacity(row, col);

  return data_[row][col];
}

// scalar functions
Matrix Matrix::ScalarAdd(double value) const {
  Matrix result(GetRowNumber(), GetColNumber());

  for (int row = 0; row < GetRowNumber(); row++) {
    for (int col = 0; col < GetColNumber(); col++) {
      result(row, col) = (*this)(row, col) + value;
    }
  }

  return result;
}

Matrix Matrix::ScalarMultiply(double value) const {
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

Matrix Matrix::GetHadamardProduct(Matrix const &other) const {
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

Matrix Matrix::Multiply(Matrix const &other) const {
  if (GetColNumber() != other.GetRowNumber()) {
    throw invalid_argument(
        "First matrix's column number must be equal to "
        "second matrix's row number");
  }

  Matrix result(GetRowNumber(), other.GetColNumber());

  for (int leftRow = 0; leftRow < GetRowNumber(); leftRow++) {
    for (int rightCol = 0; rightCol < other.GetColNumber(); rightCol++) {
      double product = 0;

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
    for (int col = 0; col < GetColNumber(); col++) {
      result(col, row) = (*this)(row, col);
    }
  }

  return result;
}

void Matrix::operator=(Matrix const &other) { this->data_ = other.data_; }

bool Matrix::operator==(Matrix const &other) {
  return this->data_ == other.data_;
}

Matrix Matrix::Randomize(int row_number, int col_number) {
  Matrix result(row_number, col_number);
  // Calculate the standard deviation based on Xavier formula
  float sd = 2.0 / (row_number + col_number);

  // Create a random number generator with a normal distribution
  std::random_device rd;
  std::mt19937 gen(rd());
  std::normal_distribution<float> distribution(0.0, sd);

  // Initialize each element in the matrix with random values
  for (int i = 0; i < row_number; i++) {
    for (int j = 0; j < col_number; j++) {
      result.data_[i][j] = distribution(gen);
    }
  }

  return result;
}

MatrixMessage Matrix::ToMatrixMessage() const {
  MatrixMessage message;

  for (int i = 0; i < GetRowNumber(); i++) {
    Vector vec;
    for (int j = 0; j < GetColNumber(); j++) {
      vec.add_data_(data_[i][j]);
    }

    *(message.add_data_()) = vec;
  }

  return message;
}

Matrix Matrix::FromMatrixMessage(MatrixMessage const &message) {
  Matrix result(message.data__size(), message.data_(0).data__size());

  for (int i = 0; i < message.data__size(); i++) {
    for (int j = 0; j < message.data_(i).data__size(); j++) {
      result.data_[i][j] = message.data_(i).data_(j);
    }
  }

  return result;
}

ostream &s21::operator<<(ostream &os, Matrix const &m) {
  // os << "row number: " << m.GetRowNumber() << std::endl;
  // os << "col number: " << m.GetColNumber() << std::endl;

  for (int row = 0; row < m.GetRowNumber(); row++) {
    for (int col = 0; col < m.GetColNumber(); col++) {
      os << m(row, col) << " ";
    }

    std::cout << std::endl;
  }

  os << std::endl;

  return os;
}