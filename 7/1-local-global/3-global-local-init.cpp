#include <cstdlib>
#include <ctime>
#include <iostream>

int global;

int main() {
  {
    srand(time(NULL));
    int a[36];
    for (int j = 0; j < 36; j++) {
      a[j] = std::rand();
      std::cout << a[j] << ' ';
    }
    std::cout << "\n\n";
  }

  int local;
  std::cout << "local: " << local << '\n';
  std::cout << "global: " << global << '\n';
}
