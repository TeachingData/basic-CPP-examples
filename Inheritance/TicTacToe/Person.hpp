#include <array>
#include <string>
#include <vector>

class Person {
public:
  // why this? How would you make Human Player? CPU Player?
  // what would you need to add to each?
  std::string name;
  std::vector<std::array<int, 2>> moves;
  char piece;

  virtual void add_move(int, int)=0;
  virtual std::string display_moves()=0;
  // why pure virtual?
};
