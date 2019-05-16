#include <algorithm>
#include <iostream>
#include <vector>

// My own custom type.
class Custom {
  std::string lang_;
  int num_;
public:
  Custom(std::string l, int n) : lang_(l), num_(n) {}
  std::string lang() const { return lang_; }
  int num() const { return num_; }
  friend std::ostream &operator<<(std::ostream &os, const Custom &c);
};

void print(const std::vector<Custom> &v);

// Comparing to a specific hard-coded value "Java".
bool is_java(const Custom &c) { return c.lang() == "Java"; }

// Comparing to any value that is handed to the constructor of this functor.
struct IsLang {
  IsLang(std::string l) : lang(l) {} // Receives a language and saves it into the
                                     // private "lang" field.
  // This operator takes the same role as the plain function is_java above,
  // only now it is more generic.
  bool operator()(const Custom &c) { return c.lang() == lang; }
private:
  std::string lang; // Holds "Java" in one example and "Python" in the other.
};

struct LangAdder {
  LangAdder(std::string l) : lang(l) {}
  // The signature of the operator() depends on the requirements of the
  // algorithm we are using. The specification of the signature of the 
  // predicate for each algorithm can be found on cppreference.com.
  int operator()(int sum_so_far, const Custom &c) {
    if (c.lang() == lang)
      return sum_so_far + c.num();
    return sum_so_far;
  }
private:
  std::string lang;
};

bool is_cpp(const Custom &c) { return c.lang() == "C++"; }

int main() {
  std::vector<Custom> v;
  v.push_back(Custom("C++", 1));
  v.push_back(Custom("R", 2));
  v.push_back(Custom("Java", 3));
  v.push_back(Custom("Python", 4));
  v.push_back(Custom("R", 99));
  print(v);

  auto isjava = std::find_if(v.begin(), v.end(), is_java);
  std::cout << "found Java in v: "
            << ( ( isjava != v.end() ) ? "true" : "false" ) << std::endl;

  auto isjavageneric = std::find_if(v.begin(), v.end(), IsLang("Java"));
  std::cout << "found the same Java? "
            << ( ( isjavageneric == isjava ) ? "true" : "false" ) << std::endl;

  auto ispython = std::find_if(v.begin(), v.end(), IsLang("Python"));
  std::cout << "also found Python: "
            << ( ( ispython != v.end() ) ? "true" : "false" ) << std::endl;

  int rsum = std::accumulate(v.begin(), v.end(), 0, LangAdder("R"));
  std::cout << "sum of numbers beside Rs: " << rsum << std::endl;

  auto removecppstart = std::remove_if(v.begin(), v.end(), is_cpp);
  v.erase(removecppstart, v.end());
  std::cout << "after having C++ removed: ";
  print(v);
}

std::ostream &operator<<(std::ostream &os, const Custom &c) {
  os << "{" << c.lang_ << ", " << c.num_ << "}";
  return os;
}

void print(const std::vector<Custom> &v) {
  for (const Custom &c : v) {
    std::cout << c << " ";
  }
  std::cout << std::endl;
}
