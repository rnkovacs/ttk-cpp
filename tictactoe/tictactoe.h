#include <iostream>
#include <vector>

struct Pos {
  int x, y;
  Pos(int a, int b) : x(a), y(b) {}
};

class Player {
  friend class Game;
  std::string name;
  char sign;
public:
  Player(std::string n, char s) : name(n), sign(s) {}
  bool operator==(const Player &other) {
    if (name == other.name && sign == other.sign)
      return true;
    return false;
  }
};

class Game {
  std::vector<std::vector<char>> grid;
  Player *player1;
  Player *player2;
  Player *next;

public:
  Game(Player &p1, Player &p2) : player1(&p1), player2(&p2), next(player1) {
    grid = std::vector<std::vector<char>>(3);
    for (std::vector<char> &row : grid) {
      row = std::vector<char>(3);
      row[0] = row[1] = row[2] = ' ';
    }
  }

  void show() {
    std::string line = "   +---+---+---+\n";
    std::cout << "     0   1   2\n" << line
              << " 0 | " << grid[0][0]
                << " | " << grid[0][1]
                << " | " << grid[0][2]
                << " |\n" << line
              << " 1 | " << grid[1][0]
                << " | " << grid[1][1]
                << " | " << grid[1][2]
                << " |\n" << line
              << " 2 | " << grid[2][0]
                << " | " << grid[2][1]
                << " | " << grid[2][2]
                << " |\n" << line
              << std::endl;
  }

  void move(Pos p) {
    std::cout << next->name << "'s move: (" << p.x << ", " << p.y << ").\n\n";
    grid[p.x][p.y] = next->sign;
    
    if (next == player1) {
      next = player2;
      return;
    }

    next = player1;
  }
  
  void announce_winner() {
    Player *winner;
    char sign = ' ';
    if ((grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) ||
        (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0])) {
      sign = grid[0][0];
    }
    if ((grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) ||
        (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2])) {
      sign = grid[2][2];
    }
    if ((grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) ||
        (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) ||
        (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) ||
        (grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2])) {
      sign = grid[1][1];
    }
    if (sign == ' ') {
      std::cout << "It's a tie!" << std::endl;
      return;
    }

    if (sign == player1->sign)
      winner = player1;
    else
      winner = player2;
    
    std::cout << "The winner is " << winner->name << "!" << std::endl;
  }
};
