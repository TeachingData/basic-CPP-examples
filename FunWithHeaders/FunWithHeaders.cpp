// FunWithHeaders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "math.h"

int main()
{
    int foo = 8;
    std::cout << factorial(foo);

    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(1);
    std::cout << "Your sum is " << summation(nums) << ".\n";
}