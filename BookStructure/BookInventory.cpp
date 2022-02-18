// BookInventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "ui.h"
#include "book.h"

using std::array;
using std::string;

int main()
{
    bool exit_check = true;
    const array<string, 4> choices = {"Add a book", "Edit a title", "Display Inventory", "Exit"};

    std::cout << "Enter the inventory items:\n\n";
    do {
        // vector should push_back in function (this is a void)
        switch (get_menu_choice(choices)) {
        case 0:
            add_book();
            break;
        case 1:
            change_title();
            break;
        case 2:
            print_books();
            break;
        default:
            exit_check = false;
            break;
        }
    } while (exit_check);
    

}