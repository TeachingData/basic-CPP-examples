#include <vector>
#include <fstream>
#include <iostream>

class TimeFiles {
  private:
  std::fstream timefile;
  std::vector<std::string> lines{};
  std::vector<std::string> times{};
  std::vector<long> ids;
  void set_ids();
  void set_times();

  public:
  void gettimes();
  void add_line(std::string);
  void print_times();
  void print_ids();
  void print_all();
};
