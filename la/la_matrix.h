/*
 * Matrix
 */

#ifndef LA_MATRIX_H
#define LA_MATRIX_H

#include <vector>
#include <string>

// ------------------------------------------------------------
// Class definition

class LA_Matrix {

private:

  // Number of rows
  unsigned int row_count;
  // Number of columns
  unsigned int col_count;
  // Matrix content
  std::vector<std::vector<long double>> elements;

public:

  /*
   * Constructor
   * Initialize to all 0's.
   */
  LA_Matrix(unsigned int row_count, unsigned int col_count);

  /*
   * Constructor
   * Initialize with specified values.
   * The children vectors must all have lengths equal to col_count. The parent
   * vector must have a length equal to row_count. Otherwise, an error is
   * thrown.
   */
  LA_Matrix(unsigned int row_count, unsigned int col_count,
  const std::vector<std::vector<long double>> &elements);

  /*
   * Constructor
   * Initialize with specified values.
   * Consecutive elements in the vector represent column-adjacent elements. In
   * other words, elements are interpreted one row at a time.
   * Size of provided vector must be (row_count * col_count). Otherwise,
   * an error is thrown.
   */
  LA_Matrix(unsigned int row_count, unsigned int col_count,
  const std::vector<long double> &elements);

  /*
   * Get number of rows (height).
   */
  unsigned int getRowCount() const;

  /*
   * Get number of columns (width).
   */
  unsigned int getColCount() const;

  /*
   * Get the element at the specified row and column indices.
   * An error is thrown for out-of-bounds indices.
   */
  long double getElement(unsigned int row_idx, unsigned int col_idx) const;

  /*
   * Set an element, specified by row and column indices.
   * An error is thrown for out-of-bounds indices.
   */
  void setElement(unsigned int row_idx, unsigned int col_idx,
  long double element);

  /*
   * Replace the entire matrix.
   * The children vectors must all have lengths equal to col_count. The parent
   * vector must have a length equal to row_count. Otherwise, an error is
   * thrown.
   */
  void setElements(const std::vector<std::vector<long double>> &elements);

  /*
   * Replace the entire matrix.
   * Consecutive elements in the vector represent column-adjacent elements. In
   * other words, elements are interpreted one row at a time.
   * Size of provided vector must be (row_count * col_count). Otherwise,
   * an error is thrown.
   */
  void setElements(const std::vector<long double> &elements);

  /*
   * Get the determinant of the matrix, if possible.
   * If a determinant does not exist, an error is thrown.
   */
  long double getDeterminant() const;

  /*
   * Get the inverse of the matrix, if possible.
   * If an inverse does not exist, an error is thrown.
   */
  LA_Matrix getInverse() const;

  /*
   * Get the current state of the matrix in string form.
   * Useful for debugging.
   */
  std::string getString(unsigned int precision) const;

};

// ------------------------------------------------------------
// Non-member functions

/*
 * Multiply a matrix by a scalar.
 */
LA_Matrix la_scaleMatrix(const LA_Matrix &matrix, long double scalar);

/*
 * Multiply a matrix by a scalar.
 */
LA_Matrix la_scaleMatrix(long double scalar, const LA_Matrix &matrix);

/*
 * Multiply a matrix by a scalar.
 */
LA_Matrix operator* (const LA_Matrix &matrix, long double scalar);

/*
 * Multiply a matrix by a scalar.
 */
LA_Matrix operator* (long double scalar, const LA_Matrix &matrix);

/*
 * Multiply two matrices.
 * If the matrices' dimensions don't align for multiplication, an error is
 * thrown.
 */
LA_Matrix la_multiplyMatrices(const LA_Matrix &matrix_a,
const LA_Matrix &matrix_b);

/*
 * Multiply two matrices.
 * If the matrices' dimensions don't align for multiplication, an error is
 * thrown.
 */
LA_Matrix operator* (const LA_Matrix &matrix_a, const LA_Matrix &matrix_b);

#endif
