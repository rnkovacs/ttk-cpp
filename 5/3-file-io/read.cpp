#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::ifstream in("zup.txt"); // open() is called automatically
  
  if (!in) {
    std::cout << "Cannot open file." << std::endl;
    return 1;
  }

  double x;
  std::vector<double> v;
  while (in >> x) {
    v.push_back(x);
  }

  for (const double e : v)
    std::cout << e << ' ';
  std::cout << std::endl;

  return 0;
}
