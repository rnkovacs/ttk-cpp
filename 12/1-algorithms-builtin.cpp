#include <algorithm>
#include <iostream>
#include <vector>

void print(const std::vector<int> &v);

bool is_six(int i) { return i == 6; }
bool is_even(int i) { return i % 2 == 0; }
bool sort_backwards(int a, int b) { return a > b; }

int accumulate_odd(int sum_so_far, int new_element) {
  if (!is_even(new_element))
    return sum_so_far + new_element;
  return sum_so_far;
}

int main() {
  std::vector<int> v = {4, 2, 9, 5, 5, 5, -3, 0};
  print(v);

  // Find an element that satisfies some criteria in a container.
  auto six1 = std::find(v.begin(), v.end(), 6);
  std::cout << "found 6 in v: "
            << ( ( six1 != v.end() ) ? "true" : "false" )
            << std::endl;

  auto six2 = std::find_if(v.begin(), v.end(), is_six);
  std::cout << "found the same 6? "
            << ( ( six1 == six2 ) ? "true" : "false" )
            << std::endl;

  // Count the number of elements that satisfy some criteria.
  int five = std::count(v.begin(), v.end(), 5);
  std::cout << "number of 5's in v: " << five << std::endl;

  int even = std::count_if(v.begin(), v.end(), is_even);
  std::cout << "number of even elements in v: " << even << std::endl;

  // Remove all elements that satisfy some criteria.
  auto start_of_stuff_to_be_removed = std::remove(v.begin(), v.end(), 5);
  v.erase(start_of_stuff_to_be_removed, v.end());
  std::cout << "after removing all 5's: ";
  print(v);

  start_of_stuff_to_be_removed = std::remove_if(v.begin(), v.end(), is_even);
  v.erase(start_of_stuff_to_be_removed, v.end());
  std::cout << "after removing all even elements: ";
  print(v);

  v.push_back(1);
  v.push_back(2);
  v.push_back(7);
  print(v);

  // Sort elements according to some criteria.
  std::sort(v.begin(), v.end());
  std::cout << "after sorting: ";
  print(v);

  std::sort(v.begin(), v.end(), sort_backwards);
  std::cout << "after sorting backwards: ";
  print(v);

  // Sum the elements that satisfy some criteria.
  int sum = std::accumulate(v.begin(), v.end(), 0);
  std::cout << "sum of elements: " << sum << std::endl;

  int sum_odd = std::accumulate(v.begin(), v.end(), 0, accumulate_odd);
  std::cout << "sum of odd elements: " << sum_odd << std::endl;
}

void print(const std::vector<int> &v) {
  for (int i : v) 
    std::cout << i << ' ';
  std::cout << std::endl;
}
