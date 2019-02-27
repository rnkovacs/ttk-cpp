#include <iostream>

void swap(int c, int d) {
  int tmp = c;
  c = d;
  d = tmp;
}

int main() {
  int a = 2;
  int b = 8;

  std::cout << a << ' ' << b << std::endl;
  swap(a, b);
  std::cout << a << ' ' << b << std::endl;

  return 0;
}
