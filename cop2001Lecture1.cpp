
#include <iostream>

// Quick test of compiler
// Print out uid and greeting
// print out current gpa
int main() {

  int uid=125496;
  std::cout << "Hello student " << uid << "\n";
  printf("Hello student %d\n", uid);

  double gpa = 3.7;
  bool passing = true;
  std::cout << "You have " << gpa << ". You are passing: "
    << passing << "\n";
  printf("You have %f. You are passing: %d\n", gpa, passing);
  /*
   * To fix the printf 1 issue you'd need:
   * printf("You have %f. You are passing: %s\n", gpa, passing ? "true" : "false");
   * Which uses a ternary operator as an if/else (if true print true else false)
   */
} 
