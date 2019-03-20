#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Number of arguments must be at least 2" << std::endl;
    return 1;
  }

  // Convert argument to string.
  std::string name = argv[0];
  std::cout << "Program name: " << name << std::endl;

  // Convert argument to number.
  int number;
  try {
    number = std::stoi(argv[1]);
  } catch (std::invalid_argument) {
    std::cerr << "Second argument is not a number!" << std::endl;
    return 2;
  }
  std::cout << "Number: " << number << std::endl;

  return 0;
}
