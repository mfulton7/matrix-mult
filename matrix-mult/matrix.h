#include <array>
#include <iostream>
#include <vector>
#include <string>

#pragma once
class matrix
{
public:
	// constructor
	matrix(const std::vector<std::vector<int>>& data);

	// allows for visualizing data in matrix
	void print();

};

