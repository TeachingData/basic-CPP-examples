#include <iostream>
#include <sstream>

// This shows how to get the int (char as int) values of a string

using std::string;
using std::cout;
using std::stringstream;

int main() {
  // change the string to whatever you want
  // the stringstream opens a buffer stream to be used to store strings
  // This allows an auto-conversion of int values to string in the manner of cout
  string name = "bob";
  stringstream numbers;  

  // Now we just loop over each letter and cast it to int to get the ascii value
  // and direct the output (<< & >> are called redirect operators for a reason) to our buffer
  for (const auto& letter : name) {
    numbers << (int) letter;  
  }

  cout << "The integer representation of the string is " << numbers.str() << "\n";  
  // using .str() to flush the buffer (convert it to string basically) and output it
  // prints '9811198' which are the ascii values of 'b' 'o' 'b'
}
