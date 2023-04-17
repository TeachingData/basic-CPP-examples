#include "BookFiles.hpp"

BookFiles::BookFiles() {
    filename = "../data/books.txt";
}

BookFiles::BookFiles(const std::string& name) { filename = validate_filename(name); }

void BookFiles::change_filename(std::string new_name) {
    filename = validate_filename(new_name);
}

std::string BookFiles::validate_filename(const std::string& raw_name) {
    std::string sanitized{};

    // need to sanitize the input to remove any special chars (ignorethem)
    for (const auto letter : raw_name) {
        // cctype's isalnum says "is it alpha or numeric"?
        if (std::isalnum(letter)) {
            // using push_back to handle any weird conversion issues (like ints)
            sanitized.push_back(letter);
        }
    }

    // usually would use {} and else explicitly but want to show this works
    if (raw_name.length() < 20 && raw_name.length() > 2)
        return "../data/" + sanitized + ".txt";
    // explicitly set it back to name because too short or long
    return "../data/books.txt";
}

void BookFiles::load_file() {
    std::string title_author;
    std::string author;

    bookfile.open(filename, std::ios::in);
    if (bookfile.is_open()) {
        while(getline(bookfile, title_author)) {
            // this assumes the file is perfect - which is a bad assumption
            // better is to get everyline and then push into 2 seperate vectors
            //      to combine when needed
            title_author.append(" by ");
            std::getline(bookfile, author);
            title_author.append(author);
            books.push_back(title_author);
        }
        bookfile.close();
    }
    // TODO: exceptions and error handling
}

void BookFiles::write_file(std::string outfile) {
    outfile = validate_filename(outfile);
    bookfile.open(outfile, std::ios::out);
    for (const auto& b : books) {
        bookfile << "\n" << b;
    }
    bookfile.close();
}
