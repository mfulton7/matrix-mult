#include <array>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#ifndef MATRIX_H
#define MATRIX_H



class matrix
{
public:

	// threads to be used
	int max_threads = 4;

	std::vector<std::vector<int>> data;
	// constructors
	matrix();
	matrix(int rows, int columns, bool random);
	matrix(const std::vector<std::vector<int>>& passed_data);

	// allows for visualizing data in matrix
	void print();

	// function to be passed to be invoked by a thread during addition operator
	void addition_thread();

	matrix operator+(matrix const& obj);

	bool operator==(matrix const& obj) const;
	
	std::ostream& operator<<(std::ostream& os);

	void multiplication_thread(int thread_row, matrix& result_matrix);

	matrix operator*(matrix const& obj);


};

#endif


