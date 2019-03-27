#include <iostream>

int f() {
  std::cout << "f()\n";
  return 5;
}

int x = f();

int main() {
  std::cout << "main()\n";
}
