#include <iostream>
#include <fstream>
#include <vector>

using dmatrix = std::vector<std::vector<double>>;

int main() {
  // Lifetime of the file handler is bound to the ofstream object 'out'.
  // Calls open() automatically.
  std::ofstream out("data/out_matrix.data");
  
  if (!out) {
    std::cout << "Cannot open file." << std::endl;
    return 1;
  }

  dmatrix m = { {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9} };

  for (auto row : m) {
    for (double col : row) {
      out << col << ' ';
    }
    out << '\n';
  }

  return 0;

  // File handler is destroyed automatically when 'out' goes out of scope.
  // Calls close() automatically.
}
