#ifndef FILEINHERITANCE_FILES_HPP
#define FILEINHERITANCE_FILES_HPP

#include <string>
#include <cctype>
#include <fstream>
#include <vector>

class Files {
public:
    std::string filename;

    virtual void change_filename(std::string)=0;
    virtual void load_file()=0;
    virtual void write_file(std::string)=0;
};


#endif
