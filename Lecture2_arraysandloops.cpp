#include <iostream>
#include <cstdlib>
#include <array>

using std::cout;
using std::string;
using std::cin;

int main()
{
  // first version only gets player choice - playing rock paper scissors
  // choices = available choices for both computer and player
  const std::array<string,3> choices {"rock", "paper", "scissors"};
  // if above gives error - you need 17

  // select random value (using cstdlib)
  string computer = choices[rand() % 3];
  cout << computer << "\n";

  string player = "";

  // Get player choice (keep looping until valid
  while (true) {
      // Give user all choices
      // Have to define leave here because see line 33 or so
      string confirm = "";
      for (const auto choice : choices) {
          cout << "Do you choose " + choice + "? (y/n)";
          cin >> confirm;

          // Check if answer starts with Y or y: exit loop & assign
          if (confirm[0] == 'y' or confirm[0] == 'Y') {
              player = choice;
              break;
          }
      }
      // Now we check if leave is still set
      // This breaks out of while loop (moving to line 55)
      if (confirm[0] == 'y' or confirm[0] == 'Y') {
          break;
      }

      // Client did not pick any of the valid choices so ask if want to leave
      string leave {}; // new scope so need new definition
      cout << "\nYou didn't select a choice - do you want to exit? (y/n)";
      cin >> leave;

      // If they want to leave we just exit not break (cause done)
      if (leave[0] == 'y' or leave[0] == 'Y') {
        cout << "\nOkay, goodbye.";
        exit(0);
      }
  }

  // for now we are just going to print out our values - students will make if/else on Thurs
  cout << "\n\t\tThe Player choose: " << player;
  cout << "\n\t\tThe CPU choose: " << computer;
}
