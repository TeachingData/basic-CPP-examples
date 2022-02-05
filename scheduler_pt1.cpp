// THIS WILL NOT RUN with the switch (until you add the functions)
#include <iostream>
#include <array>
#include <string>

using std::cout;
using std::cin;

// array used for few things
const std::array<std::string,4> choices = {"Display Schedule", "Add Event",
  "Edit Event", "Remove Event"};
// Add vector to hold events here

void print_menu() {
  // prints out our main menu
  cout << "\t\t\tPlease select an option from the menu\n\n";
  for (int i=0; i<=choices.size()-1; i++) {
    cout << "\t[" << i << "] " << choices[i] << "\n";
  }
  cout << "Enter selection [ ]\b\b";
}

int get_verified_choice() {
  // Gets user choice and ensures it is between 0 & max size
  // returns negative if error
  int raw_choice = 0;

  cin >> raw_choice;

  if (raw_choice < 0 || raw_choice > choices.size()-1) {
    return -1;
  }
  return raw_choice;
}

int main() {
  // Quick program to show how to make an old school console window
  // It will offer a menu for:
  // adding events to a schedule, displaying it, edit it, and delete an event
  //
  // Idea is to pracice vectors, arrays, and functions

  // Note this will all probably be added to a while loop
  print_menu();

  // Using a switch statement to run each new option - you create the functions
    int user_choice = get_verified_choice();
  if (user_choice < 0) {
    exit(1);
  }
  cout << "You have selected " << user_choice << "\n";

  switch(user_choice) {
    case 0: display_schedule();
            break;
    case 1: display_schedule();
            add_event(); // my_vector.push_back(add_event());
            break;
    case 2: display_schedule();
            edit_event(); // this may pass something or not
            break;
    case 3: display_schedule();
            remove_event(); // this may also pass something
            break;
    default: display_schedule();
             break;
  }
}
