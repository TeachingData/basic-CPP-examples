#ifndef INPUTOUTPUT_FILEOPERATIONS_H
#define INPUTOUTPUT_FILEOPERATIONS_H

#include <vector>
#include <string>

// Handles all file operations
std::vector<std::string> get_lines(std::string);
void write_lines(std::vector<std::string>);
void append_lines(std::vector<std::string>);

#endif //INPUTOUTPUT_FILEOPERATIONS_H
