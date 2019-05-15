#include <algorithm>
#include <numeric>
#include <fstream>
#include <vector>

class Date {
  friend class Product;
  int year, month, day;
public:
  int get_year() { return year; }
  int get_month() { return month; }
  Date(int y, int m, int d): year(y), month(m), day(d) {}
  void print() {
	  std::cout << year << '-' << month << '-' << day;
  }
};

class Product {
  friend class Webstore;
  std::string name;
  std::string code;
  int price;
  Date added;
  Date sold;
public:
  std::string get_name() { return name; }
  std::string get_code() { return code; }
  int get_price() { return price; }
  Date get_sold() { return sold; }
  Product(std::string n, std::string c, int p, Date a, Date s)
    : name(n), code(c), price(p), added(a), sold(s) {}
};

bool sortName(Product p1, Product p2) {
  return p1.get_name() < p2.get_name();
}

bool sortPrice(Product p1, Product p2) {
  return p1.get_price() < p2.get_price();
}

bool sortCode(Product p1, Product p2) {
  return p1.get_code() < p2.get_code();
}

struct RemoveCode {
  RemoveCode(std::string c): code(c) {}
  bool operator()(Product p) {
	  return p.get_code() == code;
  }
private:
  std::string code;
};

struct Income {
  Income(int y, int m): year(y), month(m) {}
  int operator()(int sum_so_far, Product p) {
	  if (p.get_sold().get_year() == year &&
	      p.get_sold().get_month() == month) {
	    return sum_so_far + p.get_price();
	  }
	  return sum_so_far;
  }
private:
  int year, month;
};

class Webstore {
  std::vector<Product> lista;
public:
  void list() {
	  std::cout << "Product list:" << std::endl; 
	  for (Product p: lista) {
      std::cout << p.name << '\t' << p.price << '\t'
                << p.code << '\t';
	    p.added.print();
	    std::cout << '\t';
	    p.sold.print();
	    std::cout << std::endl;
	  }
  }
  
  void add(std::string n, int p, std::string c, Date a, 
           Date s = Date(0, 0, 0)) {
    lista.push_back(Product(n, c, p, a, s));
  }
  
  void readFrom(std::string fname) {
	  std::fstream in(fname);
	  if (!in) {
	    std::cout << "Cannot open file." << std::endl;
	    return;
	  }
	  std::string name, code;
	  int price;
	  int ay, am, ad, sy, sm, sd;
	  while (in >> name >> price >> code >> ay >> am >> ad >> sy >> sm >> sd) {
	    add(name, price, code, Date(ay, am, ad), Date(sy, sm, sd));
	  }
  }
  
  void sort() {
	  std::sort(lista.begin(), lista.end(), sortCode);
	  std::stable_sort(lista.begin(), lista.end(), sortPrice);
	  std::stable_sort(lista.begin(), lista.end(), sortName);
  }
  
  void remove(std::string code) {
    auto i = std::remove_if(lista.begin(), lista.end(), RemoveCode(code));
	  lista.erase(i, lista.end());
  }
  
  int income(int year, int month) {
	  return std::accumulate(lista.begin(), lista.end(), 0, Income(year, month));
  }
};
