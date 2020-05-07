/*
 * Details in la_matrix.h
 */

#include <sstream>
#include <iomanip>
#include <stdexcept>
#include "la_matrix.h"

// ------------------------------------------------------------

LA_Matrix::LA_Matrix(unsigned int row_count, unsigned int col_count) {

  std::vector<long double> row;
  for(unsigned int col_idx = 0; col_idx < col_count; col_idx++) {
    row.push_back(0);
  }
  for(unsigned int row_idx = 0; row_idx < row_count; row_idx++) {
    this->elements.push_back(row);
  }

  this->row_count = row_count;
  this->col_count = col_count;

}

// ------------------------------------------------------------

LA_Matrix::LA_Matrix(unsigned int row_count, unsigned int col_count,
const std::vector<std::vector<long double>> &elements) {

  // Verify that argument elements has correct dimensions
  if(elements.size() != row_count) {
    // Error
    throw std::invalid_argument("Invalid dimensions for elements vector.");
  }
  for(unsigned int row_idx = 0; row_idx < row_count; row_idx++) {
    if(elements.at(row_idx).size() != col_count) {
      // Error
      throw std::invalid_argument("Invalid dimensions for elements vector.");
    }
  }

  this->elements = elements;

  this->row_count = row_count;
  this->col_count = col_count;

}

// ------------------------------------------------------------

LA_Matrix::LA_Matrix(unsigned int row_count, unsigned int col_count,
const std::vector<long double> &elements) {

  // Verify that argument elements has correct size
  if(elements.size() != row_count * col_count) {
    // Error
    throw std::invalid_argument("Invalid size for elements vector.");
  }

  const std::vector<long double> empty;

  for(unsigned int row_idx = 0; row_idx < row_count; row_idx++) {
    this->elements.push_back(empty);
    for(unsigned int col_idx = 0; col_idx < col_count; col_idx++) {
      this->elements.at(row_idx)
      .push_back(elements.at(row_idx * col_count + col_idx));
    }
  }

  this->row_count = row_count;
  this->col_count = col_count;

}

// ------------------------------------------------------------

unsigned int LA_Matrix::getRowCount() const {

  return this->row_count;

}

// ------------------------------------------------------------

unsigned int LA_Matrix::getColCount() const {

  return this->col_count;

}

// ------------------------------------------------------------

long double LA_Matrix::getElement(unsigned int row_idx, unsigned int col_idx)
const {

  // Verify that indices are in-bounds
  if(row_idx >= this->row_count) {
    // Error
    throw std::invalid_argument("Out-of-bounds row index.");
  }
  if(col_idx >= this->col_count) {
    // Error
    throw std::invalid_argument("Out-of-bounds column index.");
  }

  return this->elements.at(row_idx).at(col_idx);

}

// ------------------------------------------------------------

void LA_Matrix::setElement(unsigned int row_idx, unsigned int col_idx,
long double element) {

  // Verify that indices are in-bounds
  if(row_idx >= this->row_count) {
    // Error
    throw std::invalid_argument("Out-of-bounds row index.");
  }
  if(col_idx >= this->col_count) {
    // Error
    throw std::invalid_argument("Out-of-bounds column index.");
  }

  this->elements.at(row_idx).at(col_idx) = element;

}

// ------------------------------------------------------------

void LA_Matrix::setElements(
const std::vector<std::vector<long double>> &elements) {

  // Verify correct dimensions
  if(elements.size() != this->row_count) {
    // Error
    throw std::invalid_argument("Invalid dimensions for elements vector.");
  }
  for(unsigned int row_idx = 0; row_idx < this->row_count; row_idx++) {
    if(elements.at(row_idx).size() != this->col_count) {
      // Error
      throw std::invalid_argument("Invalid dimensions for elements vector.");
    }
  }

  this->elements = elements;

}

// ------------------------------------------------------------

void LA_Matrix::setElements(const std::vector<long double> &elements) {

  // Verify correct dimensions
  if(elements.size() != this->row_count * this->col_count) {
    // Error
    throw std::invalid_argument("Invalid size for elements vector.");
  }

  for(unsigned int row_idx; row_idx < this->row_count; row_idx++) {
    for(unsigned int col_idx; col_idx < this->col_count; col_idx++) {
      this->elements.at(row_idx).at(col_idx)
      = elements.at(row_idx * this->col_count + col_idx);
    }
  }

}

// ------------------------------------------------------------

long double LA_Matrix::getDeterminant() const {

  return 0;

}

// ------------------------------------------------------------

LA_Matrix LA_Matrix::getInverse() const {

  LA_Matrix inverse(1, 1);
  return inverse;

}

// ------------------------------------------------------------

std::string LA_Matrix::getString(unsigned int precision) const {

  std::string output;

  // Determine the largest number of digits in non-decimal places
  unsigned long longest = 1;
  for(unsigned int i = 0; i < this->row_count; i++) {
    for(unsigned int j = 0; j < this->col_count; j++) {
      long long rounded = static_cast<long long>(this->elements.at(i).at(j));
      unsigned long length = 0;
      while(rounded != 0) {
        length++;
        rounded /= 10;
      }
      longest = length > longest ? length : longest;
    }
  }

  // Generate string
  for(unsigned int i = 0; i < this->row_count; i++) {
    output += "|  ";
    for(unsigned int j = 0; j < this->col_count; j++) {
      std::ostringstream ss;
      ss << std::fixed << std::setprecision(precision)
      << this->elements.at(i).at(j);
      std::string converted = ss.str();
      if(converted.length() - (precision + 1) < longest) {
        std::string temp;
        for(unsigned int k = 0;
        k < longest - converted.length() + precision + 1; k++) {
          temp += " ";
        }
        converted = temp + converted;
      }
      output += converted + "  ";
    }
    output += "|";
    if(i != this->row_count - 1) {
      output += "\n";
    }
  }

  return output;

}

// ------------------------------------------------------------

LA_Matrix la_scaleMatrix(const LA_Matrix &matrix, long double scalar) {

  unsigned int row_count = matrix.getRowCount();
  unsigned int col_count = matrix.getColCount();

  LA_Matrix result(row_count, col_count);
  for(unsigned int row_idx = 0; row_idx < row_count; row_idx++) {
    for(unsigned int col_idx = 0; col_idx < col_count; col_idx++) {
      result.setElement(row_idx, col_idx,
      matrix.getElement(row_idx, col_idx) * scalar);
    }
  }

  return result;

}

// ------------------------------------------------------------

LA_Matrix la_scaleMatrix(long double scalar, const LA_Matrix &matrix) {

  return la_scaleMatrix(matrix, scalar);

}

// ------------------------------------------------------------

LA_Matrix operator* (const LA_Matrix &matrix, long double scalar) {

  return la_scaleMatrix(matrix, scalar);

}

// ------------------------------------------------------------

LA_Matrix operator* (long double scalar, const LA_Matrix &matrix) {

  return la_scaleMatrix(matrix, scalar);

}

// ------------------------------------------------------------

LA_Matrix la_multiplyMatrices(const LA_Matrix &matrix_a,
const LA_Matrix &matrix_b) {

  // Verify that matrices' dimensions are valid for multiplication
  if(matrix_a.getColCount() != matrix_b.getRowCount()) {
    // Error
    throw std::invalid_argument("Matrices' dimensions don't align for "
    "multiplication.");
  }

  unsigned int row_count = matrix_a.getRowCount();
  unsigned int col_count = matrix_b.getColCount();
  unsigned int add_count = matrix_a.getColCount();

  LA_Matrix result(row_count, col_count);
  for(unsigned int row_idx = 0; row_idx < row_count; row_idx++) {
    for(unsigned int col_idx = 0; col_idx < col_count; col_idx++) {
      long double sum = 0;
      for(unsigned int i = 0; i < add_count; i++) {
        sum += matrix_a.getElement(row_idx, i)
        * matrix_b.getElement(i, col_idx);
      }
      result.setElement(row_idx, col_idx, sum);
    }
  }

  return result;

}

// ------------------------------------------------------------

LA_Matrix operator* (const LA_Matrix &matrix_a, const LA_Matrix &matrix_b) {

  return la_multiplyMatrices(matrix_a, matrix_b);

}
