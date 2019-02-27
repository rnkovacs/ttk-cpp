#include <iostream>
#include <vector>

using intmatrix = std::vector<std::vector<int>>;

void add_ref(intmatrix &sum, const intmatrix &m1, const intmatrix &m2) { 
  for (auto i = 0; i < m1.size(); ++i) {
    for (auto j = 0; j < m1[0].size(); ++j) {
      sum[i][j] = m1[i][j] + m2[i][j];
    }
  }
}

void print(const intmatrix &m) {
  for (auto row : m) {
    for (auto col : row) {
      std::cout << col << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  intmatrix m1 {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  intmatrix m2 {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

  std::cout << "m1:" << '\n';
  print(m1);
  std::cout << "m2:" << '\n';
  print(m2);

  std::cout << "add_ref:" << '\n';
  intmatrix sum_r = m1;
  add_ref(sum_r, m1, m2);
  print(sum_r);

  return 0;
}
