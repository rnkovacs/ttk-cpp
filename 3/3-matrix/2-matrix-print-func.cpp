#include <iostream>
#include <vector>

void print(const std::vector<std::vector<int>> &m) {
  for (auto row : m) {
    for (auto col : row) {
      std::cout << col << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  const std::vector<std::vector<int>> m {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  print(m);

  return 0;
}
