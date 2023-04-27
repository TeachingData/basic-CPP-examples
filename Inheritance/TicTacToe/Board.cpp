#include "Board.hpp"

void Board::display_board() {
  for (const auto &rows : board) {
    for (const auto &column : rows) {
      std::cout << column;
    }
    std::cout << "\n";
  }
}
