#include <iostream>
#include <vector>

struct Datum {
  friend class Bankszamla;
  Datum(int e, int h, int n) : ev(e), honap(h), nap(n) {
    if (ev < 2000 || ev > 2019 || honap < 1 || honap > 12 ||
        nap < 1 || nap > 31) {
      std::cout << "Hibas datum!" << std::endl;
    }
  }
private:
  int ev;
  int honap;
  int nap;
};

struct Tranzakcio {
  friend class Bankszamla;
  Tranzakcio(double o, std::string n, Datum d)
      : osszeg(o), megnevezes(n), datum(d) {}
private:
  double osszeg;
  std::string megnevezes;
  Datum datum;
};

struct Bankszamla {
  Bankszamla() : egyenleg(0) {}

  // Forbid copy operations. We do not want to write them right now, 
  // but compiler-generated copy operations would cause memory leaks.
  // (Remember that we store heap-allocated objects.)
  Bankszamla(const Bankszamla &other) = delete;
  Bankszamla &operator=(const Bankszamla &other) = delete;

  // It is important to override the compiler-generated destructor 
  // for the same reason. However, this is always used if at least one
  // object is created, so we have to write our own.
  ~Bankszamla() {
    for (Tranzakcio *t: lista) {
      delete t;
    }
  }

  void hozzaad(double osszeg, std::string nev, Datum datum) {
    egyenleg += osszeg;
    Tranzakcio *t = new Tranzakcio(osszeg, nev, datum);
    lista.push_back(t);
  }

  bool levon(double osszeg, std::string nev, Datum datum) {
    if (-osszeg > egyenleg)
      return false;

    egyenleg += osszeg;
    Tranzakcio *t = new Tranzakcio(osszeg, nev, datum);
    lista.push_back(t);
    return true;
  }

  double lekerdez() { return egyenleg; }

  void kivonat(int ev, int honap) {
    std::cout << "Kivonat: \n";
    for (Tranzakcio *t: lista) {
      if ((t->datum).ev == ev && (t->datum).honap == honap) {
        std::cout << (t->datum).ev << "-" << (t->datum).honap << "-"
                  << (t->datum).nap << " " << t->megnevezes << " "
                  << t->osszeg << std::endl;
      }
    }
  }

private:
  std::vector<Tranzakcio *> lista;
  double egyenleg;
};

int main() {
  Bankszamla b;
  std::cout << b.lekerdez() << std::endl;

  b.hozzaad(100000, "munkaber", Datum(2019, 4, 7));
  std::cout << b.lekerdez() << std::endl;

  bool s = b.levon(-50000, "valami", Datum(2019, 4, 7));
  std::cout << "sikeres? " << std::boolalpha << s << std::endl;
  std::cout << b.lekerdez() << std::endl;

  s = b.levon(-60000, "valami2", Datum(2019, 5, 1));
  std::cout << "sikeres? " << std::boolalpha << s << std::endl;
  std::cout << b.lekerdez() << std::endl;
  
  b.kivonat(2019, 4);

  return 0;
}
