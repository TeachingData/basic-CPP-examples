#include <iostream>
#include <array>
 

// iteration 1 - very limited and bad
int main()
{
    
    /*std::array<std::array<char, 3>, 3> board = {{ {'X', 'O', 'O'}, 
                                                 {'O', 'X', 'X'}, 
                                                 {'X', 'X', 'O'} }};*/
    
    std::array<std::array<char, 3>, 3> board;
    
    int ctr = 0;
    
    for (auto& rows : board) {
        for (auto& column : rows) {
            // fake user input below
            if (ctr % 2) {
                column = 'X';
            } else {
                column = 'O';
            }
            ctr++;
        }
        
    }
    
    // could use for loop or while to keep asking for a space until ....
    // 9 items filled out (3x3)
    // area = length x width (so size of main board * size of one row)
    std::cout << board.size() * board.at(0).size() << "\n";

    for (int i=0; i<board.size()*board.at(0).size(); i++) {
      int x, y;
      
      std::cout << "Please select a grid location x (0-2): ";
      std::cin >> x;
      std::cout << "Please select a grid location y (0-2): ";
      std::cin >> y;
      if (i % 2) {
        board[x][y] = 'O';
      } else {
        board[x][y] = 'X';
      }
    }
    
    for (const auto& rows : board) {
        for (const auto& column : rows) {
            std::cout << column;
        }
        std::cout << "\n";
    }
}
