#include <iostream>
#include <array>
#include <vector>
#include "ui.h"
#include "fileoperations.h"

using std::array;
using std::string;
using std::vector;
using std::cout;

// Books headers: id,title,author,pages,genre,price,added by
// This will play a bit with input and output and string handling
// Basic makeup: take in our user's full name, print current books, get new books, and write to file
// adding the username to the end of the line's they create

// Get user's full name and title
string get_name() {
    string name = "";
    cout << "Please enter your full name: ";
    std::cin >> name;

    string title = "";
    cout << "Please verify your title (editor, author, reviewer): ";
    std::cin >> title;

    return name;
}

// Display all current books (needs no external library)
void display_books(vector<string> &cur_books) {
    cout << "The current books are: \n\n";
    for (const auto b : cur_books) {
        cout << b;
    }
}

// Now this will "wrap" our fileoperations function
void append_books() {}

// And this will also wrap (this one overwrites)
void overwrite_books() {}

int main() {
    bool exit_check = true;
    const array<string, 4> choices = {"Display Inventory", "Add books", "Overwrite all books", "Exit"};

    // get username and load all current books from our csv
    string name = get_name();
    vector<string> books = get_lines("books.csv");

    std::cout << "Welcome " << name << ". Please Enter your selection:\n\n";
    do {
        switch (get_menu_choice(choices)) {
            case 0:
                display_books(books);
                break;
            case 1:
                append_books();
                break;
            case 2:
                overwrite_books();
                break;
            default:
                exit_check = false;
                break;
        }
    } while (exit_check);
}
