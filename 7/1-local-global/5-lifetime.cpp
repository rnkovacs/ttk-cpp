#include <iostream>

int a = 5;

int main() {
  std::cout << "1: " 
            << a << ' ' 
            //<< b << ' ' 
            //<< c 
            << std::endl;

  int b = 10;
  std::cout << "2: " 
            << a << ' ' 
            << b << ' ' 
            //<< c 
            << std::endl;

  {
    int c = -7;
    std::cout << "3: " 
              << a << ' ' 
              << b << ' ' 
              << c 
              << std::endl;
  }
  
  std::cout << "4: " 
            << a << ' ' 
            << b << ' ' 
            //<< c
            << std::endl;
}
