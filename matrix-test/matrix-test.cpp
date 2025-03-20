#include "pch.h"
#include "CppUnitTest.h"
#include "../matrix-mult/matrix.h"
#include "../matrix-mult/matrix.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<>
			std::wstring ToString<matrix>(const matrix& obj) {
				return (L"test");
			}
		}
	}
}


namespace matrixtest
{



	TEST_CLASS(matrixtest)
	{
	public:

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
			matrix empty_matrix = matrix(2, 2);

			matrix add_a = test_matrix + empty_matrix;
			matrix add_b = test_matrix + test_matrix;
			
			Assert::AreEqual(add_a, add_b);

		}
	};
}
