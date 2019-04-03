#include <iostream>
#include <cstring>

// Homework: Write your own version of
//   int strlen(const char *str) { ... }
//   void strcpy(char *dest, const char *src) { ... }

char *reverse_const_string_indexes(char *dest, const char *src) {
  // Copy src to the target location.
  strcpy(dest, src);

  // Starting from the two ends, swap characters until we reach
  // the middle of the string. (Working with indexes.)
  // Watch out for ',' and ';' differences!!
  for (int i = 0, j = strlen(src) - 1; // declarations,
                                       // only executed once at the beginning
       i < j;    // executed at the beginning of each step (loop condition)
       ++i, --j) // executed at the end of each step
  {
    std::swap(dest[i], dest[j]);
  }

  // Return a pointer to the reversed string.
  return dest;
}

char *reverse_const_string_pointers(char *dest, const char *src) {
  strcpy(dest, src);
  
  // Alternatively, we can use pointers instead of indexes.
  // The declarations are too long, so I pull them out before the loop.
  // The disadvantage is that begin and end are now accessible after the loop.
  char *begin = dest; // The star is part of the pointer declaration.
  char *end = dest + strlen(dest) - 1;
  for ( ; begin < end; ++begin, --end) {
    std::swap(*begin, *end); // These stars are dereference operators.
  }

  return dest;
}

int main() {
  const char *s = "AbcdefG";
  std::cout << "Original string: " << s << '\n';

  // Version 1:
  // Allocate a writable char array for the result on the stack.
  // Its length is the length of 's' + 1 for the closing '\0' character.
  char d1[strlen(s) + 1];
  std::cout << "Reversed 1: " << reverse_const_string_indexes(d1, s) << '\n';

  // Version 2:
  // Allocate a writable char array for the result on the heap.
  // It is the caller/driver code's responsibility to manage the memory!
  char *d2 = new char[strlen(s) + 1];
  std::cout << "Reversed 2: " << reverse_const_string_pointers(d2, s) << '\n';
 
  // 'd2' will not be deallocated at the end of the function!!
  // To avoid a memory leak, we need to deallocate it by hand.
  delete d2;

  return 0;
} // 'd1' is destroyed automatically at the closing brace.
