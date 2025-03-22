#include "pch.h"
#include "CppUnitTest.h"
#include "../matrix-mult/matrix.h"
#include "../matrix-mult/matrix.cpp"
#include <vector>
#include <iostream>
#include <chrono>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<>
			std::wstring ToString<matrix>(const matrix& obj) {
				std::wstring result;
				for (int i = 0; i < obj.data.size(); i++) {
					for (int j = 0; j < obj.data[i].size(); j++) {
						result += std::to_wstring(obj.data[i][j]);
						result += ',';
					}
					//result += std::endl;
				}
				return result;
			}
		}
	}
}


namespace matrixtest
{
	void mult_helper() {
		matrix m_a = matrix(3, 3, true);
		matrix m_b = matrix(7, 7, true);
		matrix result = m_a * m_b;
	}

	void matrix_helper(std::vector<std::vector<int>> arg) {
		matrix m = matrix(arg);
	}

	TEST_CLASS(matrixtest)
	{
	public:

		TEST_METHOD(TestMatrixGeneration) 
		{
			matrix random_matrix = matrix(5, 5, true);
			random_matrix.print();
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(TestMatrixAddition)
		{

			std::vector<int> v1 = { 1, 2 };
			std::vector<int> v2 = { 3, 4 };
			std::vector<int> v3 = { 5, 6 };
			std::vector<std::vector<int>> vv;
			vv.push_back(v1);
			vv.push_back(v2);

			// create test matrix
			matrix test_matrix = matrix(vv);
			matrix empty_matrix = matrix(2, 2, false);

			matrix add_a = test_matrix + empty_matrix;
			matrix add_b = test_matrix + test_matrix;
			
			// we added an empty array to a populated one so the result should be equivalent to the original populated matrix
			Assert::AreEqual(add_a, test_matrix);
		}

		TEST_METHOD(TestMatrixMultiplication) 
		{
			std::vector<int> v1 = { 1, 2 };
			std::vector<int> v2 = { 3, 4 };
			std::vector<int> v3 = { 5, 6 };
			std::vector<std::vector<int>> vv;
			vv.push_back(v1);
			vv.push_back(v2);

			std::vector<int> v4 = {7, 10};
			std::vector<int> v5 = { 15, 22 };
			std::vector<std::vector<int>> vx;
			vx.push_back(v4);
			vx.push_back(v5);
			matrix mult_matrix = matrix(vx);

			// create test matrix
			matrix test_matrix = matrix(vv);
			matrix empty_matrix = matrix(2, 2, false);

			matrix mult_a = test_matrix * empty_matrix;
			matrix mult_b = test_matrix * test_matrix;

			Assert::AreEqual(mult_b, mult_matrix);	
			Assert::AreEqual(mult_a, empty_matrix);
		}



		TEST_METHOD(TestInvalidSizeMultiplication) 
		{

			auto lambda_with_exec = [] {mult_helper(); };
			Assert::ExpectException<std::invalid_argument>(lambda_with_exec);

		}

		TEST_METHOD(TestInvalidPassedDataForMatrixGeneration) 
		{
			std::vector<int> v1 = { 1, 2, 3 };
			std::vector<int> v2 = { 4 };
			std::vector<int> v3 = { 5, 6, 7, 8, 9 };
			std::vector<std::vector<int>> vx;
			vx.push_back(v1);
			vx.push_back(v2);
			vx.push_back(v3);

			auto lambda_with_exec = [vx] {matrix_helper(vx); };
			Assert::ExpectException<std::invalid_argument>(lambda_with_exec);
		}
	};
}
