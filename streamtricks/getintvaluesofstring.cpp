#include <iostream>
#include <sstream>

// This shows how to get the int (char as int) values of a string
// note this is just outputing the string but the standard use-case is to use it later
// If you just want to output the string use ostringstream: https://cplusplus.com/reference/sstream/ostringstream/

using std::string;
using std::cout;
using std::stringstream;
using std::

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

  cout << "The integer representation of the string is " << numbers.rdbuf() << "\n";  
  // using .rdbuf() to flush the buffer (basically) and output it
  //       it returns a pointer to the held data for output
  //       see: https://cplusplus.com/reference/ios/ios/rdbuf/
  // prints '9811198' which are the ascii values of 'b' 'o' 'b'
  // if you just want the string representation (i.e. convert it to a string) you'd use .str()
  // functionally equivlent but rdbuf is made for output over str() which is made for getting the string for copy/move operations
  cout << "Or I could print you with str " << numbers.str() << "\n";
}
