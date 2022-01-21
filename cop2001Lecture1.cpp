#include <iostream>

// Quick test of compiler
// Print out uid and greeting
// print out current gpa
int main() {

  // uid = university id
  int uid=125496;
  std::cout << "Hello student " << uid << "\n";
  printf("Hello student %d\n", uid);

  // passing = "are you passing?" or > 3.0 gpa
  double gpa = 3.7;
  bool passing = true;
  
  // Using std library boolalpha to print (note its not passed as an argument)
  std::cout << "You have " << gpa << ". You are passing: "
     << std::boolalpha << passing << "\n";
  // or using printf with float truncation, its not rounding just cuts it off, and a ternary
  // printf("You have %.1f. You are passing: %s\n", gpa, passing ? "true" : "false");
}
