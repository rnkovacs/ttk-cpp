#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1 {1, 2, 3, 4, 5};
  std::vector<int> v2 {1, 1, 1, 1, -1};

  int prod = 0;
  for (auto i = 0; i < v1.size(); ++i) {
    prod += v1[i] * v2[i];
  }

  std::cout << prod << std::endl;
  return 0;
}
