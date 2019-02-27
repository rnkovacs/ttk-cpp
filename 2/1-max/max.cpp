#include <iostream>
#include <limits>
#include <vector>

int main() {
  // 1/a Elemek felhasználótól:
  std::cout << "Numbers: ";
  std::vector<int> v;
  int num;

  while (std::cin >> num) {
    v.push_back(num);
  }

  // 1/b Elemek beégetve:
  // std::vector<int> v {5, -3, 2, 1, 98, -66};

  int max = std::numeric_limits<int>::min();

  // 2/a Iteráció for-each ciklussal:
  for (int element : v) {
    if (element > max)
      max = element;
  }

  // 2/b Iteráció hagyományos for ciklussal:
  // for (auto i = 0; i < v.size(); ++i) {
  //   if (v[i] > max)
  //     max = v[i];
  // }

  std::cout << "Max: " << max << std::endl;

  return 0;
}
