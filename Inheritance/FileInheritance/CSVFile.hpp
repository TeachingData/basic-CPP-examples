#ifndef FILEINHERITANCE_CSVFILE_HPP
#define FILEINHERITANCE_CSVFILE_HPP

#include "Files.hpp"
#include <algorithm>

class CSVFile : public Files {
private:
    struct row {
        std::string name;
        std::string publisher;
        bool reputable;

    };

    std::fstream csvfile;
    static std::string validate_filename(const std::string&);
    void splitdata(const std::string&, char delim);
public:
    std::string filename;
    std::vector<row> journals;

    CSVFile();

    // use an overloaded book class to setup name at instance (wrapper)
    explicit CSVFile(const std::string&);

    void change_filename(std::string) override;
    void load_file() override;
    void write_file(std::string) override;

    std::string to_string();
};


#endif
