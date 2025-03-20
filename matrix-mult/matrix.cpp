#include "matrix.h"

matrix::matrix()
{
	std::vector<std::vector<int>> blank;
	this->data = blank;
}

matrix::matrix(int rows, int columns)
{
	std::vector<std::vector<int>> zeroed;
	std::vector<int> v1(rows, 0);
	for (int i = 0; i < columns; i++) {
		zeroed.push_back(v1);
	}
	this->data = zeroed;

}

matrix::matrix(const std::vector<std::vector<int>>& passed_data)
{
	this->data = passed_data;
}

void matrix::print()
{
	for (int i = 0; i < this->data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			std::cout << data[i][j] << std::endl;
		}
	}
}

matrix matrix::operator+(matrix const& obj)
{
	// create result matrix of proper size and fill with zeros
	matrix result(this->data.size(), this->data[0].size());

	for (int i = 0; i < this->data.size(); i++) {
		for (int j = 0; j < this->data[i].size(); j++) {
			result.data[i][j] = this->data[i][j] + obj.data[i][j];
		}
	}
	return result;
}
