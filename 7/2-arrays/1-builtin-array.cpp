#include <iostream>

int main() {
  int a[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
    std::cout << a[i] << ' ';
  std::cout << '\n';

  double b[10];
  b[3] = 42.;
  for (double bb : b)
    std::cout << bb << ' ';
  std::cout << '\n';

  bool c[5] = {true, false, true};
  c[4] = true;
  for (bool cc : c)
    std::cout << std::boolalpha << cc << ' ';
  std::cout << '\n';

  char d[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  d[0] = 'H';
  for (char dd : d)
    std::cout << dd << ' ';
  std::cout << std::endl;

  std::cout << d << std::endl;

  char e[] = "world";
  e[0] = 'W';
  for (char ee : e)
    std::cout << ee << ' ';
  std::cout << std::endl;

  std::cout << e << std::endl;
}
