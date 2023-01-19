#include <iostream>
// version: pre_release 0.1


int main() {
  int choice = 0;
  
  // Explaination of options using multiline cout
  std::cout << "The options are as follows\n"
       << "\tcoffee=1\n\ttea=2\n\tsoda=3\n\tmilk=4\n"
       << "\tmaccichiato=5\n\tsports drink=6\n\tenergy drink=7\n\twater=8\n\n"
       << "Please enter your choice[ ]\b\b";

  std::cin >> choice;

  /* could use the below but easier if already using switch to use switch
  if (choice > 8 || choice < 1) {
    std::cout << "This is not a valid choice!\n";
    exit(1);
  }
  */
  
  // switch value to see if case found
  switch(choice) {
    case 1: case 2: case 3:
      std::cout << "you bad\n";
      break;
    case 4: case 6:
      std::cout << "you're okay\n";
      break;
    case 5: case 7:
      std::cout << "you're very bad\n";
      break;
    case 8:
      std::cout << "you good\n";
      break;
    default:
      // see now we validate it here
      std::cout << "That is not a valid option! See ya!\n";
      exit(1);
    }
}
