#include <iostream>

#include "tictactoe.h"
#include "utils.h"

int main() {
  std::system("cls");

  Player white("Alice", 'O');
  Player black("Bob", 'X');
  Game g(white, black);

  init_die();
  int round = 1;
  while (true) {
    std::cout << " +-------------+\n |   Round " << round 
              << "   |\n +-------------+\n\n";

    g.move(guess());
    g.show();
    
    if (round == 9) {
      g.announce_winner();
      return 0;
    }

    ++round;
    proceed();
  }

  return 0;
}
