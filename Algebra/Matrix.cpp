#include "Matrix.h"
#include <iostream>

// Default constructor.
Matrix::Matrix()
{
}
// Create matrix using array.
Matrix::Matrix(double ** matrix, int n, int m)
{
	_n = n;
	_m = m;
	_matrix = matrix;
}
// Create matrix using real number. 
Matrix::Matrix(double alpha, int n, int m)
{
	_n = n;
	_m = m;
	
	_matrix = new double* [_n];
	for (int i = 0; i < _n; i++)
	{
		_matrix[i] = new double[_m];
		for (int j = 0; j < _m; j++)
		{
			_matrix[i][j] = alpha;
		}
	}
}
// Create diagonal matrix using Vector.
Matrix::Matrix(Vector vector)
{
	for (int i = 0; i < vector.GetDim(); i++)
	{
		for (int j = 0; j < vector.GetDim(); j++)
		{
			if (i == j)
			{
				_matrix[i][j] = vector.GetVector()[i];
			}
		}
	}
}

double Matrix::GetDet()
{
	if (_det == 42.0)
	{
		SetDet();
	}

	return _det;
}

int Matrix::GetN()
{
	return _n;
}

int Matrix::GetM()
{
	return _m;
}

double ** Matrix::GetMatrix()
{
	return _matrix;
}

void Matrix::SetDet()
{
}

void Matrix::Print()
{
	for (int i = 0; i < _n; i++)
	{
		for (int j = 0; j < _m; j++)
		{
			std::cout << _matrix[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}


const Vector operator*(Matrix & matrix, Vector & vector)
{
	int dim = vector.GetDim();

	Vector resultVector = Vector(0.0, dim);

	double * resultArray = resultVector.GetVector();
	double ** matrixArray = matrix.GetMatrix();
	double * vectorArray = vector.GetVector();

	for (int i = 0; i < matrix.GetN(); i++)
	{
		for (int j = 0; j < vector.GetDim(); j++)
		{
			resultArray[i] += matrixArray[i][j] * vectorArray[j];
		}
	}

	return Vector(resultArray, vector.GetDim());
}

const Vector operator*(Vector & vector, Matrix & matrix)
{
	return matrix * vector;
}

const Matrix operator*(Matrix & left, Matrix & right)
{
	if (right.GetN() != right.GetM())
	{
		std::cout << "Matrix sizes do not match." << std::endl;

		return Matrix(-1.0, 1, 1);
	}

	Matrix resultMatrix= Matrix(0.0, left.GetN(), right.GetM());

	double ** letfArray = left.GetMatrix();
	double ** rightArray = right.GetMatrix();
	double ** resultArray = resultMatrix.GetMatrix();

	for (int i = 0; i < left.GetN(); i++)
	{
		for (int j = 0; j < right.GetM(); j++)
		{
			for (int k = 0; k < right.GetN(); k++)
			{
				resultArray[i][j] += letfArray[i][k] * rightArray[k][j];
			}			
		}
	}

	return Matrix(resultArray, left.GetN(), right.GetM());
}

const Matrix operator*(double alpha, Matrix & matrix)
{
	Matrix alphaMatrix = Matrix(alpha, matrix.GetN(), matrix.GetM());

	return matrix * alphaMatrix;
}

const Matrix operator*(Matrix & matrix, double alpha)
{
	Matrix alphaMatrix = Matrix(alpha, matrix.GetN(), matrix.GetM());

	return matrix * alphaMatrix;
}

const Matrix operator+(Matrix & left, Matrix & right)
{
	if ((left.GetN() != right.GetN()) && (left.GetM() != right.GetM()))
	{
		std::cout << "Matrix sizes do not match." << std::endl;

		return Matrix(-1.0, 1, 1);
	}

	double ** resultMatrix = Matrix(0.0, left.GetN(), left.GetN()).GetMatrix();

	for (int i = 0; i < left.GetN(); i++)
	{
		for (int j = 0; j < left.GetM(); j++)
		{
			resultMatrix[i][j] = left.GetMatrix()[i][j] + right.GetMatrix()[i][j];
		}
	}

	return Matrix(resultMatrix, left.GetN(), left.GetM());
}

const Matrix operator-(Matrix & left, Matrix & right)
{
	Matrix resultMatrix = right * (-1.0);

	return left + right;
}

const bool operator==(Matrix & left, Matrix & right)
{
	if (left.GetN() != right.GetN() && left.GetM() != right.GetM())
	{
		std::cout << "Matrix sizes do not match." << std::endl;

		return false;
	}

	bool isEqual = true;
	double eps = 1e-5;

	for (int i = 0; i < left.GetN(); i++)
	{
		for (int j = 0; j < left.GetM(); j++)
		{
			if ((left.GetMatrix()[i][j] - right.GetMatrix()[i][j]) > eps )
			{
				isEqual = false;
				return isEqual;
			}
		}
	}

	return isEqual;
}

const bool operator!=(Matrix & left, Matrix & right)
{
	return !(left == right);
}

Matrix::~Matrix()
{
	//delete this->_matrix;
}