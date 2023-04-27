#include <array>
#include <iostream>

void display_board(std::array<std::array<char, 3>, 3> &to_display) {
  for (const auto &rows : to_display) {
    for (const auto &column : rows) {
      std::cout << column;
    }
    std::cout << "\n";
  }
}

int main() {

  /*std::array<std::array<char, 3>, 3> board = {{ {' ', ' ', ' '},
                                               {' ', ' ', ' '},
                                               {' ', ' ', ' '} }};*/

  std::array<std::array<char, 3>, 3> board; // horrible use the above instead

  int ctr = 0;

  for (int i = 0; i < board.size() * board.at(0).size(); i++) {
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
      board[x][y] = 'O';
    } else {
      board[x][y] = 'X';
    }

    display_board(board);
  }
}
