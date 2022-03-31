#include <string>

class Date {
public:
    int month;
    int day;
    int year;

    // setter for date a virtual member - composed of 3 ints (year, month, day)
    void setdate(int year, int month, int day) {
        //this->year = year;
        this->year = year; // line above is same as this
        this->month = month;
        this->day = day;
    }

    void setdate(std::string date, std::string delimiter);

    // create a function (overloaded) for int year, int day, string month - convert the month
    void setdate(int day, int year, std::string month) {
        this->year = year;
        this->day = day;

        // switch doesn't work on string so you could create a char array and then do that or
        // A simple if/else if/else ... or....
        std::string months[] = {"january", "febuary", "march", "april"};
        // and rest of them
        for (int i=0; i<=months->size(); i++) {
            if (month == months[i]) {
                this->month = i+1;
            }
        }

    }

    // will return string of date (US style)
    // add UK style on Thursday
    std::string getdate() {
        return std::to_string(month) + "/" + std::to_string(day) +
               "/" + std::to_string(year);
    }
};

inline void Date::setdate(std::string date, std::string delimiter = "/") {
    // whereas this parses a string and split into numbers by delimiter
    // we'll add it to a struct later
    // "1/1/11" is smallest string so minimum 6 chars
    // Also need to add setdate_uk for european

    if (date.length() > 5) {
        int start = 0;
        int end = date.find(delimiter);
        int dates[] = {0, 0, 0};

        // using 3 over lenght cause it should always be 3
        // Note: could just calculate and then assign month = stoi(date[0] + data[1]); but loop!
        for (int i = 0; i < 3; i++) {
            // using stoi from string library to convert string to int
            dates[i] = stoi(date.substr(start, end = start));
            start = end + delimiter.size(); // i.e. if delimiter is "//"
            end = date.find(delimiter, start);
        }

        month = dates[0];
        day = dates[1];
        year = dates[2];
    }
}
