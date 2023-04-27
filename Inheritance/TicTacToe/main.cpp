#include "Board.hpp"
#include <iostream>

int main() {

  // Now we add a class and setup the basic classes - students will build from here
  Board b;

  int ctr = 0;

  for (int i = 0; i < b.board.size() * b.board.at(0).size(); i++) {
    int x, y;

    std::cout << "Please select a grid location x (0-2): ";
    std::cin >> x;
    try {
      if (std::cin.fail()) {
        throw "error";
      }
    } catch (const char *error) {
      std::cout << error << "\n";
      exit(-1);
    }

    std::cout << "Please select a grid location y (0-2): ";
    std::cin >> y;
    if (i % 2) {
      b.board[x][y] = 'O';
    } else {
      b.board[x][y] = 'X';
    }

    b.display_board();
  }
}
