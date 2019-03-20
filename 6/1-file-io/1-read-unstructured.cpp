#include <iostream>
#include <fstream>
#include <vector>

int main() {
  // Lifetime of the file handler is bound to the ifstream object 'in'.
  // Calls open() automatically.
  std::ifstream in("data/unstructured.data");
  
  if (!in) {
    std::cout << "Cannot open file." << std::endl;
    return 1;
  }

  double x;
  std::vector<double> v;
  while (in >> x) {
    v.push_back(x);
  }

  for (const double e : v)
    std::cout << e << ' ';
  std::cout << std::endl;

  return 0;

  // File handler is destroyed automatically when 'in' goes out of scope.
  // Calls close() automatically.
}
