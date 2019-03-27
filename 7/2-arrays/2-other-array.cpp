#include <iostream>

int main() {
  std::string s[3];
  s[0] = "zero";
  s[2] = "two";

  for (std::string i : s)
    std::cout << i << '\n';
}
