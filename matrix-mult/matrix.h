#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#ifndef MATRIX_H
#define MATRIX_H

class matrix
{
public:
	std::vector<std::vector<int>> data;
	// constructors
	matrix();
	matrix(int rows, int columns, bool random);
	matrix(const std::vector<std::vector<int>>& passed_data);

	// allows for visualizing data in matrix
	void print();

	matrix operator+(matrix const& obj);

	bool operator==(matrix const& obj) const;
	
	std::ostream& operator<<(std::ostream& os);

	matrix operator*(matrix const& obj);


};

#endif


