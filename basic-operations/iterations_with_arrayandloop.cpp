#include <iostream>
// version: pre_release 0.25 - we add a summation and split out the prints but
// we don't need the 0 adds (adding 0 is nothing)

int main() {
  int choice = 0;

  // Explaination of options using multiline cout
  std::cout
      << "The options are as follows\n"
      << "\tcoffee=1\n\ttea=2\n\tsoda=3\n\tmilk=4\n"
      << "\tmaccichiato=5\n\tsports drink=6\n\tenergy drink=7\n\twater=8\n\n"
      << "Please enter your choice[ ]\b\b";

  std::cin >> choice;

  // total is not really needed here but we will use in later iterations
  int total_hydration = 0;

  // switch value to see if case found
  // don't have to exit here cause we just ignore (add zero)
  switch (choice) {
  case 1:
  case 2:
  case 3:
    total_hydration += 1;
    break;
  case 5:
  case 7:
    total_hydration += 2;
    break;
  case 8:
    total_hydration += -1;
    break;
  }

  if (total_hydration < 0) {
    std::cout << "You might have overdone it\n";
  } else if (total_hydration == 0) {
    std::cout << "You are perfectly hydrated.\n";
  } else if (total_hydration > 0 && total_hydration <= 4) {
    std::cout << "You're at a good hydration level.\n";
  } else if (total_hydration > 4 && total_hydration <= 8) {
    std::cout << "You're okay but drink a bit of water.\n";
  } else {
    std::cout << "Drink some water!\n";
  }
}
