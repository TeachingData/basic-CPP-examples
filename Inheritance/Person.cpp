//
// Base Class for our inheritance examples.
// Will include several layers of derived classes by end
// Initial Derived: Student, Staff, Academic
//

#include <string>
#include <vector>
#include <array>

using std::string;

class Person {
public:
    // our base demographics for all people
    long long uid = 15131324134;

    // return age by subtracting current year
    int age(int year) { return year - dob.year; }

    // get dob as a string (so dob.tostring())
    string get_dob() {
        return std::to_string(dob.month) + "/"
               + std::to_string(dob.day) + "/"
               + std::to_string(dob.year);
    }

    string get_full_name();
    string get_firstname();
    string get_lastname();

protected:
    // struct for holding name
    struct name {
        string first;
        char m_initial;
        string last;
    };

    // struct for holding date
    struct date {
        int year = 1900;
        int month = 1;
        int day = 1;
    };
    date dob;

    // split passed string into first middle and last and assign to struct
    // return struct to be assigned in derived classes
    name assign_name(string n) {
        // to hold our return values and words
        name to_return;
        std::vector<string> words;
        string word = "";

        // loop through letters and add any with spaces delimiters (and last after)
        for (const auto letter : n) {
            if (letter != ' ') {
                word += letter;
            } else {
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);

        // assign first then last and middle if availalbe - if not null middle
        to_return.first = words[0];
        if (words.size() > 2) {
            to_return.m_initial = words[1][0];
            to_return.last = words[2];
        } else {
            to_return.m_initial = ' ';
            to_return.last = words[1];
        }

        return to_return;

    }
};

class Student: public Person {
private:
    name student_name;
public:

    Student() {}

    Student(string n, long long id) {
        student_name = assign_name(n);
        uid = id;
    }

    // setter for dob
    void set_dob(int day, int month, int year) {
        dob.day = day;
        dob.month = month;
        dob.year = year;
    }

    string get_full_name() { return student_name.first + " " + student_name.m_initial + " " + student_name.last; }
    string get_firstname() { return student_name.first; }
    string get_lastname() { return student_name.last; }
};

// Student's created this in class
class Staff: Person {
private:
    const std::array<string,7> departments = {"admin", "admission", "ITS",
                                              "maintenance", "security", "student services",
                                              "library"};

    name staff_name;
    string department;

    string verify_department(string chosen_d) {
        // if department matches it returns the department else unknown
        for (const auto d: departments) {
            if (d == chosen_d) {
                return d;
            }
        }
        return "unknown";
    }

public:
    Staff() {}

    Staff(string n, long long id) {
        staff_name = assign_name(n);
        uid = id;
    }

    // using a function as a full member (no variable assigned)
    string employee_type() {
        if (department == "ITS" || department == "security" || department == "maintenance") {
            return "support";
        } else if (department == "library" || department == "student services") {
            return "student support";
        } else if (department == "admin" || department == "admission"){
            return "admin";
        } else {
            return "unknown";
        }
    }

    // getter and setters for the private variables

    // setter for dob using string
    void set_dob(string date, string delimiter = "/") {
        // Whereas this parses a string and splits it into its numbers
        // "1/1/11" is smallest date so if smaller just exit
        // note - using Europe style will mess this up - d/m/yy
        if (date.length() > 6) {
            int start = 0;
            int end = date.find(delimiter);
            int dates[] = {0,0,0};

            // so again - one could just loop until demlimiter and use same algo as words
            // but I wanted to show the find/offset version here:
            for (int i = 0; i < 3; i++) {
                // using stoi (from string library) to cast our string to int
                dates[i] = stoi(date.substr(start, end - start));
                start = end + delimiter.size();
                end = date.find(delimiter, start);
            }

            dob.month = dates[0];
            dob.day = dates[1];
            dob.year = dates[2];
        }
    }

    // getter and setter for department (unknown if not a matching department passed)
    void set_department(string d) { department = verify_department(d); }
    string get_department() { return department; }

    // getters for name (setter in Person)
    string get_full_name() { return staff_name.first + " " + staff_name.m_initial + " " + staff_name.last; }
    string get_firstname() { return staff_name.first; }
    string get_lastname() { return staff_name.last; }

};