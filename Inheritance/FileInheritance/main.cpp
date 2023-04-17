#include <iostream>
#include "BookFiles.hpp"
#include "CSVFile.hpp"

int main() {
    // The simple homework (without printing)
    BookFiles book = BookFiles();
    book.load_file();

    for (const auto& b : book.books) {
        std::cout << b << "\n";
    }

    book.write_file("booksfixed");

    std::cout << "\n\n\n\n";

    // Handling CSV Files with our other inherited library
    CSVFile csv = CSVFile();
    csv.load_file();

    std::cout << csv.to_string();
    csv.write_file("journal_formatted.txt");

    return 0;
}
