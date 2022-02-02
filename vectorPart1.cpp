#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>

using std::cout;
using std::string;
using std::cin;

int main()
{
    // second version get's multiple choices from computer then generates a whole game
    // choices = available choices for both computer and player, pchoices = player's choices
    const std::array<string, 3> choices{ "rock", "paper", "scissors" };
    std::vector<string> pchoices;

    // Get player choice (keep looping until valid choice or start game selected)
    while (true) {
        // Give user all choices
        string confirm = "";
        for (const auto choice : choices) {
            cout << "Do you choose " + choice + "? (y/n)";
            cin >> confirm;

            // Check if answer starts with Y or y: 
            // If so: add to vector of choices and exit for
            if (confirm[0] == 'y' or confirm[0] == 'Y') {
                pchoices.push_back(choice);
                break;
            }
        }

        // Ask player if want to start games because choice made (or no choice made)
        string start{};
        cout << "\nAre you ready to play the games? (y/n)";
        cin >> start;

        // If they want to leave we just exit not break (cause done)
        if (start[0] == 'y' or start[0] == 'Y') {
            cout << "\nOkay, Starting games\n";
            break;
        }
    }
    
    // Loop through choices and compare with our computer's random choice
    for (auto p : pchoices) {
        // randomly generate choice and print current game
        string computer = choices[rand() % 3];
        cout << "\n\nCPU chooses " << computer << " vs. " << p << "\n";

        // Check CPU vs. Player choice and display win/tie/loss message
        if (p == computer) {
            // Check tie first (to reduce number of if/elses)
            cout << "TIE!\n";
        } else if (p == "rock") {
            if (computer == "paper") {
                cout << "you lose!\n";
            } else {
            cout << "you win\n";
            }
        } else if (p == "paper") {
            if (computer == "scissors") {
                cout << "you lose!\n";
            } else {
                cout << "you win\n";
            }
        } else { // Don't need if scissors as only choice left
            if (computer == "rock") {
                cout << "you lose!\n";
            } else {
                cout << "you win\n";
            }
        }
    }
}
