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

  // Convert argument to integer.
  int number;
  try {
    number = std::stoi(argv[1]); // "stoi" stands for "string to int".
  } catch (std::invalid_argument) {
    // "std::invalid_argument" is a type of exception "std::stoi" is known to
    // throw if it cannot convert its argument to an integer. Such information
    // about standard functions can be found on their CppReference page.
    std::cerr << "Second argument is not a number!" << std::endl;
    return 2;
  }
  std::cout << "Number: " << number << std::endl;

  return 0;
}
