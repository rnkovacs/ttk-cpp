#include <algorithm>
#include <chrono>
#include <cstdio>
#include <random>

struct Pos;

std::vector<Pos> opts = { {0, 0}, {0, 1}, {0, 2},
                          {1, 0}, {1, 1}, {1, 2},
                          {2, 0}, {2, 1}, {2, 2} };

void init_die() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine e(seed);
  std::shuffle(opts.begin(), opts.end(), e);
}

Pos guess() {
  Pos n = opts.back();
  opts.erase(opts.end() - 1);
  return n;
}

void proceed() {
  std::cout << "Press enter to continue" << std::endl;
  std::getchar();
  std::system("cls");
}
