#include <iostream>

int main() {
  int n;
  std::cin >> n;

  for (int i = 1; i < n; ++i) {
    if (i % 3 == 0 && i % 5 == 0) {
      std::cout << "fizzbuzz" << std::endl;
    } else if (i % 5 == 0) {
      std::cout << "buzz" << std::endl;
    } else if (i % 3 == 0) {
      std::cout << "fizz" << std::endl;
    } else {
      std::cout << i << std::endl;
    }
  }

  return 0;
}
