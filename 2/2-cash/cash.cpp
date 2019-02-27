#include <iostream>
#include <vector>

int main() {
  std::cout << "Visszajaro: ";

  int vissza;
  std::cin >> vissza;

  if (vissza < 0 || vissza % 5 != 0) {
    std::cerr << "Csak 5-tel oszthato pozitiv szam lehet." << std::endl;
    return 1;
  }

  std::vector<int> cimlet { 20000, 10000, 5000, 2000, 1000, 500,
                            200, 100, 50, 20, 10, 5 };

  int darab = 0;
  int i = 0;
  while (vissza != 0) {
    if (vissza - cimlet[i] >= 0) {
      vissza -= cimlet[i];
      ++darab;
    } else {
      ++i;
    }
  }

  std::cout << darab << std::endl;
  return 0;
}

