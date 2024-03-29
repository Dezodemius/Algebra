// Algebra.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
// Conjugate gradient method.
void CGMethod(Matrix A, Vector b, int nRows);
// Standart entry point.
int main()
{
	double ** matrixArray = new double*[3] {
		new double[3] {2.0, 0.0, 1.0},
		new double[3] {0.0, 1.0, -1.0},
		new double[3] {1.0, -1.0, 2.0}
	};

	double * vectorArray = new double[3]{1.0, 2.0, -2.0};

	Matrix A = Matrix(matrixArray, 3, 3);
	Vector b = Vector(vectorArray, 3);
	A.GetDet();
	CGMethod(A, b, 3);
}

void CGMethod(Matrix A, Vector b, int nRows) 
{
	double eps = 1e-5;
	Vector x0 = Vector(0.0, nRows);
	Vector x = x0;
	Vector c = A * x0;
	Vector ksi0 = b - c;
	Vector ksi = ksi0;
	Vector p = ksi0;

	bool isEnough = false;

	while(!isEnough)
	{
		Vector q = A * p;
		double alpha = (ksi * p) / (q * p);
		Vector tempP = alpha * p;
		Vector xK = x + tempP;
		x = xK;
		Vector tempQ = alpha * q;
		Vector ksiK = ksi - tempQ;
		ksi = ksiK;
		if (ksi.GetNorm() <= eps)
		{
			isEnough = true;
			xK.Print();
		}
		double beta = (ksiK * q) / (p * q);
		Vector tempBetaP = beta * p;
		Vector pK = ksiK - tempBetaP;
		p = pK;
	}	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
