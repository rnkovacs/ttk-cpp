#include <iostream>

int x = 8;

int main() {
  std::cout << "x at the beginning of main(): " << x << std::endl;

  {
    int x = 33;
    std::cout << "x inside curly braces: " << x << std::endl;
  }

  int x = -2;
  std::cout << "x at the end of main(): " << x << std::endl;
}
