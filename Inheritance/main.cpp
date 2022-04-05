#include <iostream>
#include "Person.cpp"

int main() {
    Student s = Student("bob minion", 748726);

    // Private = only in class
    // Public = anybody
    // Protected = only in namespace (includes derived classes!)

    std::cout << s.uid << "\n";
    std::cout << s.get_full_name() << "\n";
    s.set_dob(11, 11, 2018);
    std::cout << s.get_dob();
    return 0;
}
