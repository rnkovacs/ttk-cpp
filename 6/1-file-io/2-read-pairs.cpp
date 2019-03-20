#include <iostream>
#include <fstream>

int main() {
  // Lifetime of the file handler is bound to the ifstream object 'in'.
  // Calls open() automatically.
  std::ifstream in("data/pairs.data");
  
  if (!in) {
    std::cout << "Cannot open file." << std::endl;
    return 1;
  }

  double x, y, dot_product;
  // We know that the input file contains pairs.
  // We interpret them as elements of two vectors.
  while (in >> x >> y) {
    dot_product += x * y;
  }

  std::cout << "Dot product: " << dot_product << std::endl;

  return 0;

  // File handler is destroyed automatically when 'in' goes out of scope.
  // Calls close() automatically.
}
