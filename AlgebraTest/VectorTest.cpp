#include "C:\Users\gladk\source\repos\Algebra\Algebra\Vector.h"
#include "CppUnitTest.h"
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgebraTest
{		
	TEST_CLASS(VectorTest)
	{
	public:
		
		TEST_METHOD(aDotB)
		{
			const int m = 4;
			double array_a[m] = { 1, 2, -5, 2 };
			double array_b[m] = { 4, 8, 1, -2 };
			
			Vector a = Vector(array_a, m);
			Vector b = Vector(array_b, m);
			
			Assert::AreEqual(a * b, 11.0);
		}
		TEST_METHOD(dotCommunicative)
		{
			const int m = 4;
			double array_a[m] = { 1, 2, -5, 2 };
			double array_b[m] = { 4, 8, 1, -2 };

			Vector a = Vector(array_a, m);
			Vector b = Vector(array_b, m);

			Assert::AreEqual(a * b, b * a);
		}
		TEST_METHOD(adotASquare)
		{
			const int m = 4;
			double array_a[m] = { 1, 2, -5, 2 };

			Vector a = Vector(array_a, m);

			double square = sqrt(a * a);

			Assert::AreEqual(square, a.GetNorm());
		}
		TEST_METHOD(alphaMultiplyAdotB)
		{
			const int m = 4;
			double alpha = 2.0;
			double array_a[m] = { 1, 2, -5, 2 };
			double array_b[m] = { 4, 8, 1, -2 };

			Vector a = Vector(array_a, m);
			Vector b = Vector(array_b, m);

			Vector tempA = a * alpha;

			Assert::AreEqual(tempA * b, a * b * alpha);
		}
		TEST_METHOD(aDotBMoreOrEqualZero)
		{
			const int m = 4;
			double array_a[m] = { 1, 2, -5, 2 };
			double array_b[m] = { 4, 8, 1, -2 };

			Vector a = Vector(array_a, m);
			Vector b = Vector(array_b, m);

			Assert::IsTrue(a * b >= 0);
		}
		TEST_METHOD(zeroDotBMoreOrEqualZero)
		{
			const int m = 4;
			double array_b[m] = { 4, 8, 1, -2 };

			Vector a = Vector(0.0, m);
			Vector b = Vector(array_b, m);

			Assert::IsTrue(a * b >= 0);
		}
		TEST_METHOD(zeroDotZeroEqualZero)
		{
			const int m = 4;
			Vector a = Vector(0.0, m);
			Assert::IsTrue(a * a == 0);
		}
		TEST_METHOD(aPlusB)
		{
			const int m = 4;
			double array_a[m] = { 1, 2, -5, 2 };
			double array_b[m] = { 4, 8, 1, -2 };

			Vector a = Vector(array_a, m);
			Vector b = Vector(array_b, m);
			Vector c = a + b;
			
			double res[m] = { 5, 10, -4, 0 };

			double* tempC = c.GetVector();

			for (int i = 0; i < m; i++)
			{
				Assert::AreEqual(tempC[i], Vector(res, m).GetVector()[i]);
			}
		}
		TEST_METHOD(scalarMultiplication)
		{
			const int m = 4;
			double array_a[m] = { 1, 2, -5, 2 };
			double array_b[m] = { 4, 8, 1, -2 };
			double array_c[m] = { 2, 5, 1, 6 };

			Vector a = Vector(array_a, m);
			Vector b = Vector(array_b, m);
			Vector c = Vector(array_c, m);

			Assert::AreEqual(Vector(a + b) * c, a * c, b * c);
		}
		TEST_METHOD(aMinusB)
		{
			const int m = 4;
			double array_a[m] = { 1, 2, -5, 2 };
			double array_b[m] = { 4, 8, 1, -2 };

			Vector a = Vector(array_a, m);
			Vector b = Vector(array_b, m);
			Vector c = a - b;

			double res[m] = { -3, -6, -6, 4 };

			double* tempC = c.GetVector();

			for (int i = 0; i < m; i++)
			{
				Assert::AreEqual(tempC[i], Vector(res, m).GetVector()[i]);
			}				
		}
		TEST_METHOD(alphaMultiplyA)
		{
			const int m = 4;
			double array_a[m] = { 1, 2, -5, 2 };

			Vector a = Vector(array_a, m);
			Vector c = a * 2.0;

			double res[m] = { 2, 4, -10, 4 };

			double* tempC = c.GetVector();

			for (int i = 0; i < m; i++)
			{
				Assert::AreEqual(tempC[i], Vector(res, m).GetVector()[i]);
			}
		}
		TEST_METHOD(zeros)
		{
			const int m = 4;

			double alpha = 0.0;

			Vector a = Vector(alpha, m);

			double res[m] = { 0.0, 0.0, 0.0, 0.0 };

			double* tempA = a.GetVector();

			for (int i = 0; i < m; i++)
			{
				Assert::AreEqual(tempA[i], Vector(res, m).GetVector()[i]);
			}
		}
	};	
}