#ifndef FILEINHERITANCE_BOOKFILES_HPP
#define FILEINHERITANCE_BOOKFILES_HPP

#include "Files.hpp"

class BookFiles : public Files {
private:
    static std::string validate_filename(const std::string&);
    std::fstream bookfile;
public:
    std::vector<std::string> books;

    BookFiles();

    // use an overloaded book class to setup name at instance (wrapper)
    explicit BookFiles(const std::string&);

    void change_filename(std::string new_name) override;
    void load_file() override;
    void write_file(std::string) override;
};


#endif
