#include <iostream>
#include <cstdlib>
#include <array>

// Usually wouldn't use std::string, just for example
using std::cout, std::string, std::cin;

int main()
{
  // first version full - playing rock paper scissors
  // choices = available choices for both computer and player
  const std::array<string,3> choices = {"rock", "paper", "scissors"};
  // if above gives error - you need 17

  // select random value (using cstdlib)
  string computer = choices[rand() % 3];
  cout << computer << "\n";
  string player = "";

  // Get player choice (keep looping until valid choice or player exits)
  while (true) {
      // Give user all choices
      // Have to define leave here because see line 33 or so
      string pchoice = "";
      for (const auto choice : choices) {
          cout << "Do you choose " + choice + "? (y/n)";
          cin >> pchoice;

          // Check if answer starts with Y or y: exit loop & assign
          if (pchoice[0] == 'y' or pchoice[0] == 'Y') {
              player = choice;
              break;
          }
      }
      // Now we check if leave is still set
      if (pchoice[0] == 'y' or pchoice[0] == 'Y') {
          break;
      }

      // Client did not make valid choice so ask if want to leave
      string leave {}; // new scope so need new definition
      cout << "\nYou didn't select a choice - do you want to exit? (y/n)";
      cin >> leave;

      // or use .tolower() function
      if (leave[0] == 'y' or leave[0] == 'Y') {
        cout << "\nOkay, goodbye.";
        exit(0);
      }
  }
  
  // Check if we won: just check wining for now (students add ties/loss)
  if (computer == "rock") {
      if (player == "paper") {
          cout << "You Win!\n";
      }
  } else if (computer == "paper") {
      if (player == "scissors") {
          cout << "You win!\n";
      }
  } else {
      if (player == "rock") {
          cout << "You win!\n";
      }
  }
}
