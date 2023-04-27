#include <array>
#include <iostream>

class Board {
  public:
  std::array<std::array<char, 3>, 3> board = {{ {' ', ' ', ' '},
                                               {' ', ' ', ' '},
                                               {' ', ' ', ' '} }};

  void display_board();
};
