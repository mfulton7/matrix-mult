// matrix-mult.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "matrix.h"
#include <vector>

int main()
{
    std::cout << "Startup!\n";

    // generate random matrix
    matrix test_1(1000, 1000, true);
    matrix test_2(1000, 1000, true);

    matrix result = test_1 * test_2;
    //matrix result = test_1 + test_2;
    std::cout << "End Execution...";
}

