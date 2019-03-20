#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Number of arguments: " << argc << '\n'
            << "And they are: " << std::endl;

  for (int i = 0; i < argc; ++i)
    std::cout << argv[i] << ' ';
  std::cout << std::endl;

  return 0;
}
