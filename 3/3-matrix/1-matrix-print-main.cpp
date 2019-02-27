#include <iostream>
#include <vector>

int main() {
  const std::vector<std::vector<int>> m {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  for (auto row : m) {
    for (auto col : row) {
      std::cout << col << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
