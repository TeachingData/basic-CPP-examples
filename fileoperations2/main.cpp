#include <vector>
#include <fstream>
#include <iostream>
#include "TimeFiles.hpp"

int main() {
  TimeFiles timefile;
  timefile.gettimes();
  timefile.print_ids();
  timefile.add_line("12345 at 1:00");
}
