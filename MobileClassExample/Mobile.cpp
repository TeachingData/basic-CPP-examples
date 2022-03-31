#include <string>
#include <iostream>
#include <random>
#include <cmath>
#include "Date.cpp"

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
    Date date = Date();

    // default constructor for class
    Mobile() {
        std::mt19937 gen32;
        IMEI = abs(gen32());
        sim_id = abs(gen32());
    }

    // Overloaded Constructor
    Mobile(long imei) {
        std::mt19937 gen32;
        IMEI = imei;
        sim_id = abs(gen32());
    }

    // Overloaded Constructor
    Mobile(long imei, long sim) {
        IMEI = imei;
        sim_id = sim;
    }

    // getter and setters for private functions

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
