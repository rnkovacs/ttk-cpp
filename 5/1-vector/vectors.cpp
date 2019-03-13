#include <iostream>
#include <vector>

using std::vector;
using std::string;

int main() {
  vector<int> ivec;          // holds integers
  vector<string> svec;       // holds strings
  vector<vector<int>> i2vec; // holds vectors of integers
  // vector<MyType> mvec;    // holds instances of MyType


  // ----------------------- //
  // Forms of initialization //
  // ----------------------- //
  
  vector<string> months1 = {"Jan", "Feb", "Mar"}; // list initialization
  vector<string> months2{"Jan", "Feb", "Mar"};    // list initialization
  // use CURLY braces!
  // vector<string> months3("Jan", "Feb", "Mar"); // error
  
  vector<string> svec2(months1);   // copy elements of months1 to svec2
  vector<int> ivec2 = ivec;        // copy elements of ivec to ivec2
  // vectors must hold elements of the same TYPE when copying!
  // vector<string> svec3(ivec2);  // error: ivec holds ints
  
  vector<int> ivec3(10, -1);       // 10 ints, each is -1
  vector<string> svec3(10, "zup"); // 10 strings, each is "zup"
  
  vector<int> ivec4(10);     // 10 ints, each is 0
  vector<string> svec4(10);  // 10 strings, each is ""
  
  // list initializer or element count?
  vector<int> v1(10);     // parens -> 10 elements with value 0
  vector<int> v2{10};     // curly -> one element with value 10
  vector<int> v3(10, 1);  // parens -> 10 elements with value 1
  vector<int> v4{10, 1};  // curly -> 2 elements with values 10 and 1


  // --------------- //
  // Adding elements //
  // --------------- //
  
  vector<int> vN;
  for (int i = 0; i != 100; ++i)
    vN.push_back(i);
  // vN has 100 elements: 0, 1, 2, ..., 99
  
  string word;
  vector<string> text;
  while (std::cin >> word)
    text.push_back(word);
  
  // vectors grow efficiently
  // you usually don't want to create a vector with fixed size
  // exception: if all elements need to be the same
  // otherwise: empty vector + add elements at run time


  // ---------------- //
  // Other operations //
  // ---------------- //

  vector<int> v5 {1, 2, 3, 4, 5};

  // use reference to modify elements
  for (auto &e : v5)
    e *= e;
  
  // use copy if elements are small and you don't want to modify them
  for (auto e : v5)
    std::cout << e << ' ';
  std::cout << std::endl;
  
  // use const reference if elements are big and you don't want to modify them
  for (const auto &e : v5)
    std::cout << e << ' ';
  std::cout << std::endl;

  // test if vector is empty
  bool is_empty = v5.empty();
  
  // get size; these two are equivalent:
  vector<int>::size_type size1 = v5.size();
  auto size2 = v5.size();
  
  // subscripting
  for (auto i = 0; i != v5.size(); ++i)
    v5[i] = 42;

  return 0;
}
