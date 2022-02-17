#include <iostream>
#include <array>

// seperating just as example of header file with cpp
// would eventually have multiple ui functions

bool check_for_exit(std::string question) {
    // Ask if they want to leave and leave on "n"
    // Returns true if they want to exit, false if still want to continue
    std::string leave = "n"; // Leave flag - checked at end, "n" leaves loop

    std::cout << "\n" << question;
    std::cin >> leave;
    if (leave[0] == 'n' || leave[0] == 'N') {
        return true;
    }
    return false;
}

int get_menu_choice(std::array<std::string, 5> choices) {
    // This will print and return the menu choice
    int choice = 3;

    for (int i=0; i<choices.size(); i++) {
        std::cout << "[" << i << "] " << choices[i] << "\n";
    }
    std::cout << "Please select your action from the menu [ ]\b\b";
    std::cin >> choice;
    return choice;
}
