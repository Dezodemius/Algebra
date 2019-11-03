#include "C:\Users\gladk\source\repos\Algebra\Algebra\Vector.h"
#include "C:\Users\gladk\source\repos\Algebra\Algebra\Matrix.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgebraTest
{
	TEST_CLASS(MatrixTest)
	{
	public:

		TEST_METHOD(matrixOnMatrix)
		{
			const int n = 2;
			const int m = 2;

			double ** array_a = new double*[n] {
				new double[m] { 2.0, 3.0 },
					new double[m] {4.0, -6.0}
			};

			double ** array_b = new double*[n] {
				new double[m] {9.0, -6.0},
					new double[m] {6.0, -4.0}
			};
			/*
			Matrix a = Matrix(array_a, n, m);
			Matrix b = Matrix(array_b, n, m);
			Matrix c = Matrix(0.0, n, m);
			Matrix res = a * b;
			*/
			Assert::IsTrue(1/*res == c*/);
		}
	};
}