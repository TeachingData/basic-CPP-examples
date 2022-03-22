#include <string>
#include <iostream>
#include <random>
#include <cmath>

using std::string;

class Mobile {
private:
    string OS {"Android"};
    int year;
    int month;
    int day;
    int storage = 64;
    string simtype = "physical"; // physical or esim

public:
    long sim_id;
    long IMEI;
    string serialnum = "0000";

    // default constructor for class
    Mobile() {
        std::mt19937 gen32;
        IMEI = abs(gen32());
        sim_id = abs(gen32());
    }

    // getter and setters for private functions

    // setter for date a virtual member - composed of 3 ints (year, month, day)
    void setdate(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    // will return string of date (US style)
    // add UK style on Thursday
    string getdate() {
        return std::to_string(month) + "/" + std::to_string(day) +
                "/" + std::to_string(year);
    }

    // set and getter for simtype can only be esim or physical
    void setsimtype(string st) {
        if (st == "ESIM" || st == "esim" || st == "eSim") {
            simtype = st;
        }
    }
    string getsimtype() { return simtype; }

    // setter and getter for storage (must be multiple of 8)
    void setstorage(int storage) {
        if (storage % 8 == 0) {
            // Mobile::storage = storage;
            this->storage = storage;
        }
    }
    int getstorage() { return storage; }

    bool connect_wifi(string wifiname, string pass) {
        // Connect to provided wifi with password
        std::cout << "We connected!\n";
        return true;
    }

    void send_text(string txt) {
        // send the message to someone and return if worked
        std::cout << "You: " << txt << "\n";
    }
};
