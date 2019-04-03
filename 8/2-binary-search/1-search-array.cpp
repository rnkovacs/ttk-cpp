#include <cstring>
#include <iostream>

// An alternative parameter list could be:
//   (int *arr, int left, int right, int x)
// where left and right are the same indexes that we
// now calculate at the beginning of the function.
//
// It is the caller/driver code's responsibility to
// hand over valid values for these parameters.
int binary_search_indexes(int *arr, int length, int x) {
  int left = 0;
  int right = length - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] < x)
      left = mid + 1;
    
    if (arr[mid] > x)
      right = mid - 1;
  }

  // If we reach this point, the search failed.
  return -1;
}

int binary_search_pointers(int *left, int *right, int x) {
  // Let's save the beginning of the array (left will change).
  int *begin = left;

  while (left <= right) {
    int *mid = left + (right - left) / 2;
    
    if (*mid == x)
      return std::distance(begin, mid);

    if (*mid < x)
      left = mid + 1;

    if (*mid > x)
      right = mid - 1;
  }

  return -1;
}

int main() {
  int a[] = {-3, 1, 5, 6, 9, 12, 34};
  int len = sizeof(a) / sizeof(a[0]);

  for (int element : a)
    std::cout << element << ' ';
  std::cout << '\n';

  int x = 9;
  std::cout << "Looking for " << x << '\n';

  std::cout << "Found at: " << binary_search_indexes(a, len, x) << '\n';
  std::cout << "Found at: " << binary_search_pointers(a, a+len-1, x) << '\n';

  // Alternatively, our array can be allocated on the heap.
  std::cout << "--------" << '\n';

  int *b = new int[len];
  std::copy(a, a + len, b);

  for (int i=0; i<len; ++i)
    std::cout << b[i] << ' ';
  std::cout << '\n';

  std::cout << "Looking for " << x << '\n';
  
  std::cout << "Found at: " << binary_search_indexes(b, len, x) << '\n';
  std::cout << "Found at: " << binary_search_pointers(b, b+len-1, x) << '\n';
  
  return 0;
}
