#include <iostream>
#include <vector>

int factorial(int stop_num) {
	int total = 1;
	for (int i = 1; i <= stop_num; i++) {
		std::cout << total << "\n";
		total *= i;
	}
	return total;
}

int summation(std::vector<int> nums) {
	int total = 0;
	for (int n : nums) {
		total += n;
	}
	return total;
}