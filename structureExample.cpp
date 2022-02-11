// exampleStruct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::string;

struct show {
    string title = "";
    string genre = "";
    string main_actor = "";
    double length = 0.0;
    bool award = false;
    int rating = 5;
    string encoding = "en-US";
};

void awarded(show &fav, bool yes_or_no) {
    fav.award = yes_or_no;
}

int main()
{
    show myfav;
    int rating = 10;

    cout << "This is encoded as " << myfav.encoding << ".\n";

    myfav.title = "Futurama";
    cout << "I love " << myfav.title << "!\n";
    cout << "The average rating is " << myfav.rating << ". Mine is " << rating << "\n";

    cout << myfav.award;
    awarded(myfav, true);
    cout << myfav.award;
}
