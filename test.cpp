#include <iostream>
#include <vector>
#include "la.h"

int main() {

  std::cout << "Starting test program.\n";

  const std::vector<long double> empty;

  std::vector<std::vector<long double>> matrix_a_vec;
  matrix_a_vec.push_back(empty);
  matrix_a_vec.at(0).push_back(1);
  matrix_a_vec.at(0).push_back(2);
  matrix_a_vec.push_back(empty);
  matrix_a_vec.at(1).push_back(3);
  matrix_a_vec.at(1).push_back(4);
  matrix_a_vec.push_back(empty);
  matrix_a_vec.at(2).push_back(5);
  matrix_a_vec.at(2).push_back(6);
  LA_Matrix matrix_a(3, 2, matrix_a_vec);
  std::cout << "Matrix A:\n";
  std::cout << matrix_a.getString(1) << "\n";

  std::vector<std::vector<long double>> matrix_b_vec;
  matrix_b_vec.push_back(empty);
  matrix_b_vec.at(0).push_back(1);
  matrix_b_vec.at(0).push_back(2);
  matrix_b_vec.at(0).push_back(3);
  matrix_b_vec.push_back(empty);
  matrix_b_vec.at(1).push_back(4);
  matrix_b_vec.at(1).push_back(5);
  matrix_b_vec.at(1).push_back(6);
  LA_Matrix matrix_b(2, 3, matrix_b_vec);
  std::cout << "Matrix B:\n";
  std::cout << matrix_b.getString(1) << "\n";

  LA_Matrix product = matrix_a * matrix_b;
  std::cout << "A x B:\n";
  std::cout << product.getString(1) << "\n";

  product = 2 * product;
  std::cout << "2 x A x B:\n";
  std::cout << product.getString(1) << "\n";

  product.setElement(0, 0, 20);
  long double det = product.getDeterminant();
  std::cout << "Determinant: " << det << "\n";

  std::cout << "Exiting test program.\n";

  return 0;
}
