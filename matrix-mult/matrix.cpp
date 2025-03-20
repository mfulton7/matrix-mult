#include "matrix.h"

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
