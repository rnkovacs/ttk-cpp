#include <algorithm>
#include <iostream>

void reverse_string_iterators(std::string &str) {
  // Instead of 'std::string::iterator', we can also write 'auto'.
  // This type is the generalization of a pointer to an element of the string.
  for (std::string::iterator begin = str.begin(), end = str.end() - 1;
       begin < end; ++begin, --end) {
    std::swap(*begin, *end);
  }
}

void reverse_string_indexes(std::string &str) {
  // Alternatively, we can use indexes.
  for (std::string::size_type i = 0, j = str.size() - 1; i < j; ++i, --j) {
    std::swap(str[i], str[j]);
  }
}

int main() {
  std::string s = "AbcdeF";
  std::cout << "Original string: " << s << '\n';

  reverse_string_iterators(s);
  std::cout << "Reversed in-place 1: " << s << '\n';

  reverse_string_indexes(s);
  std::cout << "Reversed in-place 2: " << s << '\n';

  // The most convenient alternative is using an STL algorithm!
  std::reverse(s.begin(), s.end());
  std::cout << "Reversed in-place 3: " << s << '\n';

  return 0;
}
