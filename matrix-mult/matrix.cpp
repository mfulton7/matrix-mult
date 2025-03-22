#include "matrix.h"

matrix::matrix()
{
	std::vector<std::vector<int>> blank;
	this->data = blank;
}

// if random true, then populate matrix of size r, c, with random ints, if false then zeros
matrix::matrix(int rows, int columns, bool random)
{
	std::srand(std::time(0));
	if (!random) {
		std::vector<std::vector<int>> zeroed;
		std::vector<int> v1(rows, 0);
		for (int i = 0; i < columns; i++) {
			zeroed.push_back(v1);
		}
		this->data = zeroed;
	}
	else{
		std::vector<std::vector<int>> randed;
		
		for (int i = 0; i < columns; i++) {
			std::vector<int> v1;
			for (int j = 0; j < rows; j++) {
				int rNum = std::rand() % 101;
				v1.push_back(rNum);
			}
			randed.push_back(v1);
		}
		this->data = randed;
	}

}

matrix::matrix(const std::vector<std::vector<int>>& passed_data)
{
	this->data = passed_data;
}

void matrix::print()
{
	std::cout << "__________________________________" << std::endl;
	for (int i = 0; i < this->data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			std::cout << data[i][j] << '|';
		}
		std::cout << std::endl;
	}
	std::cout << "__________________________________" << std::endl;
}

matrix matrix::operator+(matrix const& obj)
{
	auto start_exec = std::chrono::high_resolution_clock::now();
	// create result matrix of proper size and fill with zeros
	matrix result(this->data.size(), this->data[0].size(), false);

	for (int i = 0; i < this->data.size(); i++) {
		for (int j = 0; j < this->data[i].size(); j++) {
			result.data[i][j] = this->data[i][j] + obj.data[i][j];
		}
	}
	auto end_exec = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_exec - start_exec);
	std::cout << "Execution time for addition is " << duration.count() << " ms" << std::endl;
	return result;
}

bool matrix::operator==(matrix const& obj) const
{
	for (int i = 0; i < this->data.size(); i++) {
		for (int j = 0; j < this->data[i].size(); j++) {
			if (this->data[i][j] == obj.data[i][j]) {
				continue;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

std::ostream& matrix::operator<<(std::ostream& os)
{
	for (int i = 0; i < this->data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			os << data[i][j];
		}
		os << std::endl;
	}
	return os;
}

matrix matrix::operator*(matrix const& obj)
{
	// initial check to see if matrices can be multiplied
	// number of columns in LHS needs to be the same as rows in RHS
	if (this->data[0].size() != obj.data[0].size()) {
		throw std::invalid_argument("matrix multiplication cannot occur if columns of LHS is different than rows of RHS");
	}

	// create empty matrix to store result
	// result of multiplication will have the rows of LHS, and the columns in the RHS
	matrix result(this->data.size(), obj.data[0].size(), false);

	int offset = 0;
	for (int i = 0; i < this->data.size(); i++) {
		for (int k = 0; k < this->data.size(); k++) {
			int tmp = 0;
			for (int j = 0; j < this->data[i].size(); j++) {

				tmp += this->data[i][j] * obj.data[j][k];

			}
			result.data[i][k] = tmp;
		}
	}

	return result;
}
