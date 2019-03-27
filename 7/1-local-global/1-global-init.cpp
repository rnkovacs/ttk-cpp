#include <iostream>

std::ostream &os = std::cout << "global\n";

int main() {
  std::cout << "main()\n";
}
