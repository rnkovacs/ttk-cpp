#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using intvec = std::vector<int>;
using intmatrix = std::vector<std::vector<int>>;

int main() {
  // Lifetime of the file handler is bound to the ifstream object 'in'.
  // Calls open() automatically.
  std::ifstream in("data/matrix.data");
  
  if (!in) {
    std::cout << "Cannot open file." << std::endl;
    return 1;
  }

  intmatrix matrix; // Will store the matrix.

  std::string line; // Helper: Will store the current line of the file.
  intvec row;       // Helper: Will store the current row of the matrix.
  int element;      // Helper: Will store the current element.

  // While reading into 'line' is successful:
  while (std::getline(in, line)) {
    // Make an input string stream from 'line'.
    std::istringstream iss(line);
    // While extracting integers from the string stream is successful:
    while (iss >> element) {
      row.push_back(element);
    }
    matrix.push_back(row);
    row.clear(); // Erase elements from 'row'. We have already saved them
                 // into 'matrix' and need the storage for the new row.
  }

  for (const auto row : matrix) {
    for (const auto col : row) {
      std::cout << col << ' ';
    }
    std::cout << std::endl;
  }

  return 0;

  // File handler is destroyed automatically when 'in' goes out of scope.
  // Calls close() automatically.
}
