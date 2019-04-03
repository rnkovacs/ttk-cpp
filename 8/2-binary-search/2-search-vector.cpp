#include <algorithm>
#include <iostream>
#include <vector>

int binary_search_vector(const std::vector<int> &v, int x) {
  auto left = v.begin();
  auto right = v.end();
  
  while (left <= right) {
    auto mid = left + (right - left) / 2;

    if (*mid == x)
      return mid - v.begin();

    if (*mid < x)
      left = mid + 1;

    if (*mid > x)
      right = mid - 1;
  }

  return -1;
}

int main() {
  std::vector<int> v = {-11, -2, 0, 4, 13, 42, 67};
  for (int element : v)
    std::cout << element << ' ';
  std::cout << '\n';

  int x = 67;
  std::cout << "Looking for: " << x << '\n';
  std::cout << "Found at: " << binary_search_vector(v, x) << '\n';

  // Alternatively, using STL algorithms:
  auto pos = std::lower_bound(v.begin(), v.end(), x);
  std::cout << "Found at: " << std::distance(v.begin(), pos) << '\n';

  return 0;
}
