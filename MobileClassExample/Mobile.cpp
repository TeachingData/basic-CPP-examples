//
// Created by JGreenwell on 3/06/2022.
//

#include <string>
#include <iostream>
#include <random>
#include <cmath>

class Mobile {
    // in class we will make all members public then change
private:
    int year;
    int month;
    int day;
    std::string OS; // add this with case

public:
    long IMEI;
    long simid;
    std::string simtype {"physical"}; // esim or physical
    int storage {32}; // by Gb

    // Creating two constructors to introduce overloading (polymorphism)
    Mobile() {
        // as nothing was passed we will just assign random IMEI and simid
        // mt uses the mersenne twister algo to generate a more random num then rand
        // Then we generate two instances of it and get the absolute values (can be negative)
        std::mt19937 gen32;
        IMEI = abs(gen32());
        simid = abs(gen32());
    }

    Mobile(long imei, long simid) {
        // This constructor just uses the passed values and the "this" construct
        this->IMEI = imei;
        this->simid = simid;
    }

    // NOTE: set_date and set_date are considered overloaded functions because they have the same name
    // but different parameters (part of polymorphism). This allows us to use a good descriptive name for 
    // functions which do the same thing but using different input
    void set_date(int month, int day, int year) {
        // Overload pt2: this sets date with ints passed (standard way)
        this->year = year;
        this->month = month;
        this->day = day;
    }
    
    // 1st overload: sets the date with a written month and int day/year: March 03 2022
    void set_date(std::string month, int day, int year);

    // final overloaded - it takes a full string and splits it - and inlined at bottom
    // for "02/13/47" or "8--10--2022" or ...
    void set_date(std::string date, std::string delimiter);

    int get_year() {return year; }
    int get_month() {return month; }
    int get_day() {return day; }

    void setOS(std::string os) {
        // We set the OS to either Android, Apple, Blackberry, or Symbian
        // Symbian ended in 2013 with updates stopped in 2017 but still seen
        // Note: Blackberry was bought out in 2020 and might make a 5G phone soon

        // using if because all doing the same thing
        if (os == "android" || os == "ios" ||
            os == "symbian" || os == "blackberry") {
            OS = os;
        } else {
            OS = "android";
        }
    }

    bool send_message(std::string message, long phonenum) {
        std::cout << "We'd send a message here\n";
        std::cout << "sending: " << message << "\nTo: " << phonenum << "\n";
        return true;
    }

    std::string receive_message() {
        std::cout << "We'd get a message here\n";
        return "And return it";
    }

    bool connect_wifi(std::string accessname, std::string password) {
        std::cout << "We'll connect to wifi: " << accessname << " with pass " << password << "\n";
        return true;
    }

    std::string dial(long phonenum) {
        std::cout << "Dialing " << phonenum << "\n";
        return "Hello?!";
    }
};

inline void Mobile::set_date(std::string month, int day, int year) {
    this->day = day;
    this->year = year;
    
    // run through month appriviations and assign a number as needed
    const std::string months[] = {"jan", "feb", "mar", "apr", "may", 
                                  "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
    for (int i = 0; i <= 12; i++) {
        if (months[i] == month) {
            this->month = i+1;
            // end loop cause we done
            break;
        }
    }
    
}

inline void Mobile::set_date(std::string date, std::string delimiter = "/") {
    // Whereas this parses a string and splits it into its numbers
    // "1/1/11" is smallest date so if smaller just exit
    // note - using Europe style will mess this up - d/m/yy
    if (date.length() > 6) {
        int start = 0;
        int end = date.find(delimiter);
        int dates[] = {0,0,0};

        for (int i = 0; i < 3; i++) {
            // using stoi (from string library) to cast our string to int
            dates[i] = stoi(date.substr(start, end - start));
            start = end + delimiter.size();
            end = date.find(delimiter, start);
        }

        month = dates[0];
        day = dates[1];
        year = dates[2];
    }
}
