#include <iostream>
#include <vector>
#include "la.h"

int main() {

  std::cout << "Starting linear algebra test program.\n";
  std::cout << "\n";

  const std::vector<long double> empty;

  std::vector<std::vector<long double>> matrix_a_vec;
  matrix_a_vec.push_back(empty);
  matrix_a_vec.at(0).push_back(7);
  matrix_a_vec.at(0).push_back(19);
  matrix_a_vec.push_back(empty);
  matrix_a_vec.at(1).push_back(6);
  matrix_a_vec.at(1).push_back(-9);
  matrix_a_vec.push_back(empty);
  matrix_a_vec.at(2).push_back(-5);
  matrix_a_vec.at(2).push_back(3);
  LA_Matrix matrix_a(3, 2, matrix_a_vec);
  std::cout << "Matrix A:\n";
  std::cout << matrix_a.getString(1) << "\n";
  std::cout << "\n";

  std::vector<std::vector<long double>> matrix_b_vec;
  matrix_b_vec.push_back(empty);
  matrix_b_vec.at(0).push_back(9);
  matrix_b_vec.at(0).push_back(4);
  matrix_b_vec.at(0).push_back(2);
  matrix_b_vec.push_back(empty);
  matrix_b_vec.at(1).push_back(3);
  matrix_b_vec.at(1).push_back(-2);
  matrix_b_vec.at(1).push_back(17);
  LA_Matrix matrix_b(2, 3, matrix_b_vec);
  std::cout << "Matrix B:\n";
  std::cout << matrix_b.getString(1) << "\n";
  std::cout << "\n";

  std::vector<std::vector<long double>> matrix_c_vec;
  matrix_c_vec.push_back(empty);
  matrix_c_vec.at(0).push_back(9);
  matrix_c_vec.at(0).push_back(4);
  matrix_c_vec.at(0).push_back(2);
  matrix_c_vec.push_back(empty);
  matrix_c_vec.at(1).push_back(3);
  matrix_c_vec.at(1).push_back(-2);
  matrix_c_vec.at(1).push_back(17);
  matrix_c_vec.push_back(empty);
  matrix_c_vec.at(2).push_back(1);
  matrix_c_vec.at(2).push_back(-8);
  matrix_c_vec.at(2).push_back(-3);
  LA_Matrix matrix_c(3, 3, matrix_c_vec);
  std::cout << "Matrix C:\n";
  std::cout << matrix_c.getString(1) << "\n";
  std::cout << "\n";

  LA_Matrix product = matrix_a * matrix_b;
  std::cout << "A x B:\n";
  std::cout << product.getString(1) << "\n";
  std::cout << "\n";

  product = 2 * product;
  std::cout << "2 x A x B:\n";
  std::cout << product.getString(1) << "\n";
  std::cout << "\n";

  long double det = matrix_c.getDeterminant();
  std::cout << "|C|: " << det << "\n";
  std::cout << "\n";

  LA_Matrix inv = matrix_c.getInverse();
  std::cout << "C^-1:\n";
  std::cout << inv.getString(5) << "\n";
  std::cout << "\n";

  std::cout << "Exiting linear algebra test program.\n";
  std::cout << "\n";

  return 0;
}
