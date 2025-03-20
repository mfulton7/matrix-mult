// matrix-mult.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "matrix.h"
#include <vector>

int main()
{
    std::cout << "Hello World!\n";

    //test vectors
    std::vector<int> v1 = { 1, 2 };
    std::vector<int> v2 = { 3, 4 };
    std::vector<int> v3 = { 5, 6 };
    std::vector<std::vector<int>> vv;
    vv.push_back(v1);
    vv.push_back(v2);

    std::cout << vv.size() << std::endl;

    // create test matrix
    matrix test_matrix = matrix(vv);
    matrix empty_matrix = matrix(2, 2);
    
    std::cout << "Test matrix (with items)" << std::endl;
    test_matrix.print();
    std::cout << "Empty Matrix" << std::endl;
    empty_matrix.print();

    // test addition
    matrix add_result = test_matrix + empty_matrix;
    add_result.print();
    matrix add_result2 = test_matrix + test_matrix;
    add_result2.print();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
