#include <sstream>
#include "CSVFile.hpp"

CSVFile::CSVFile() {
    filename = "../data/journals.csv";
}

CSVFile::CSVFile(const std::string &name) { filename = validate_filename(name); }

void CSVFile::change_filename(const std::string new_name) {
    filename = validate_filename(new_name);
}

void CSVFile::load_file() {
    // hold each row or line and all rows or lines to split
    std::vector<std::string> lines;
    std::string line;

    csvfile.open(filename, std::ios::in);

    // skip first line
    if (csvfile.is_open())
        getline(csvfile, line);

    if (std::count(line.begin(), line.end(), ',') == 0) {
        // no fields found (should be 2) so just exit function before processing more
        if (csvfile.is_open())
            csvfile.close();
        return;
    }

    if (csvfile.is_open()) {
        while(getline(csvfile, line)) {
            // first lets get all the lines
            lines.push_back(line);
        }
        csvfile.close();
    }
    // TODO: exceptions and error handling

    // now let's split the data
    for (const auto& l : lines) {
        splitdata(l, ',');
    }
}

void CSVFile::write_file(std::string new_file) {
    new_file = "../data/" + new_file;
    csvfile.open(new_file, std::ios::out);

    csvfile << to_string();

    csvfile.close();

}

std::string CSVFile::validate_filename(const std::string &raw_name) {
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
        return "../data/" + sanitized + ".csv";
    // explicitly set it back to name because too short or long
    return "../data/journals.csv";
}

void CSVFile::splitdata(const std::string& record, char delim) {
    std::vector<std::string> result;
    std::stringstream recordstream (record);
    std::string item;

    // use counter to decide on what we do
    // journal for each row of journals (no pointer cause we gonna overwrite it each time)
    int counter = 0;
    row journal;

    while (getline (recordstream, item, delim)) {
        switch(counter) {
            case 0:
                counter++;
                journal.name = item;
                break;
            case 1:
                counter++;
                journal.publisher = item;
                break;
            case 2:
                counter = 0;
                journal.reputable = std::stoi(item);
                journals.push_back(journal);
                break;
        }

    }
}

std::string CSVFile::to_string() {
    std::string to_print;

    for (const auto& j : journals) {
        if (j.reputable) {
            to_print.append("\nReputable Journal: ");
        } else {
            to_print.append("\nPopular Journal: ");
        }
        to_print.append(j.name);
        to_print.append("\n\t\tpublished by ");
        to_print.append(j.publisher);
    }
    return to_print;
}
