#include "TimeFiles.hpp"

void TimeFiles::gettimes() {
  std::string line;

  timefile.open("times2.txt", std::ios::in);
  // use our handy getline to read input line by line (source of input, place to put it)
  if (timefile.is_open()) {
    while(std::getline(timefile, line)) {
      // print out file (ignoring commented out lines)
      if (line[0] != '#') {
        lines.push_back(line);
      }
    }
    timefile.close();
  } else {
    std::cout << "Could not open file, exiting on fatal error!\n";
    exit(-1);
  }  
}

void TimeFiles::set_ids() {
  for (const auto& l : lines) {
    ids.push_back(std::stol(l.substr(0, l.find(" "))));
  }
}

void TimeFiles::set_times() {
  for (const auto& l : lines) {
    times.push_back(l.substr(l.find(" ")+4));
  }
}

void TimeFiles::add_line(std::string line) {
  // open & write our line with ending & close
  timefile.open("times2.txt", std::ios::app);
  // no newline at end of file so need to add that first
  timefile << "\n" << line;
  timefile.close(); 
}

void TimeFiles::print_times() {
  for (const auto& l : lines) {
    std::cout << l.substr(l.find(" ")+4) << "\n";
  }
}

void TimeFiles::print_ids() {
  for (const auto& l : lines) {
    std::cout << l.substr(0, l.find(" ")) << "\n";
  }
}

void TimeFiles::print_all() {
  for (const auto& l : lines) {
    std::string emp_id = l.substr(0, l.find(" "));
    std::string last_clock = l.substr(l.find(" ")+4);
    std::cout << emp_id << ", " << last_clock << "\n";
  }
}
