#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace matrixtest
{
	TEST_CLASS(matrixtest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// temp just to check test exec works
			int a = 5;
			int b = 8;
			int c = a + b;
			Assert::AreEqual(c, 13);
		}
	};
}
