#include <iostream>
#include <fstream>

int main() {
  // Lifetime of the file handler is bound to the ofstream object 'out'.
  // Calls open() automatically.
  std::ofstream out("data/out_text.data");
  
  if (!out) {
    std::cout << "Cannot open file." << std::endl;
    return 1;
  }

  out << "I'm writing into a file!\n";
  return 0;

  // File handler is destroyed automatically when 'out' goes out of scope.
  // Calls close() automatically.
}
