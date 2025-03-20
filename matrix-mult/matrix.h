#include <array>
#include <iostream>
#include <vector>
#include <string>

#pragma once
class matrix
{
public:
	std::vector<std::vector<int>> data;
	// constructor
	matrix(const std::vector<std::vector<int>>& passed_data);

	// allows for visualizing data in matrix
	void print();

};

