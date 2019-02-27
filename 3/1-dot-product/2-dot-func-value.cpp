#include <iostream>
#include <vector>

int dot(std::vector<int> v1, std::vector<int> v2) { 
  int prod = 0;
  for (auto i = 0; i < v1.size(); ++i) {
    prod += v1[i] * v2[i];
  }
  // v1[0] = 42;
  // std::cout << "v1[0] = " << v1[0] << std::endl;
  return prod;
}

int main() {
  std::vector<int> v1 {1, 2, 3, 4, 5};
  std::vector<int> v2 {1, 1, 1, 1, -1};

  std::cout << dot(v1, v2) << std::endl;
  // std::cout << "v1[0] = " << v1[0] << std::endl;
  
  return 0;
}
