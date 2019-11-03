#include "pch.h"
#include "Vector.h"
#include <cmath>
#include <iostream>


Vector::Vector()
{
}

Vector::Vector(double* array, int valueDim)
{
	SetDim(valueDim);
	SetVector(array);
	SetNorm();
}

Vector::Vector(double alpha, int valueDim)
{
	SetDim(valueDim);

	double *tempArray = new double[valueDim];

	for (int i = 0; i < valueDim; i++)
	{
		tempArray[i] = alpha;
	}
	
	SetVector(tempArray);
}

void Vector::SetDim(int valueDim)
{
	this->_dim = valueDim;
}

int Vector::GetDim()
{
	return _dim;
}

void Vector::SetVector(double* array)
{
	_vector = array;
}

double* Vector::GetVector()
{
	return _vector;
}

const Vector operator+(Vector& left, Vector& right)
{
	if (left.GetDim() == right.GetDim())
	{
		int tempArrayDim = left.GetDim();

		double *tempArray = new double[tempArrayDim];

		for (int i = 0; i < tempArrayDim; i++)
		{
			tempArray[i] = left._vector[i] + right._vector[i];
		}

		return Vector(tempArray, tempArrayDim);
	}
	else {
		std::cout << "Vector sizes do not match." << std::endl;

		return Vector(0.0, 0);
	}
}

const Vector operator+(Vector & left, double right)
{
	int tempArrayDim = left.GetDim();

	double *tempArray = new double[tempArrayDim];

	for (int i = 0; i < tempArrayDim; i++)
	{
		tempArray[i] = left._vector[i] + right;
	}

	return Vector(tempArray, tempArrayDim);
}

const Vector operator+(double left, Vector& right)
{
	int tempArrayDim = right.GetDim();

	double *tempArray = new double[tempArrayDim];

	for (int i = 0; i < tempArrayDim; i++)
	{
		tempArray[i] = right._vector[i] + left;
	}

	return Vector(tempArray, tempArrayDim);
}

const Vector operator-(Vector& left, Vector& right)
{
	if (left.GetDim() == right.GetDim())
	{
		int tempArrayDim = left.GetDim();

		double *tempArray = new double[tempArrayDim];

		for (int i = 0; i < tempArrayDim; i++)
		{
			tempArray[i] = left._vector[i] - right._vector[i];
		}

		return Vector(tempArray, tempArrayDim);
	}
	else {
		std::cout << "Dimensions do not match!" << std::endl;

		return Vector(0.0, 0);
	}
}

const Vector operator-(Vector& left, double right)
{
	int tempArrayDim = left.GetDim();

	double *tempArray = new double[tempArrayDim];

	for (int i = 0; i < tempArrayDim; i++)
	{
		tempArray[i] = left._vector[i] - right;
	}

	return Vector(tempArray, tempArrayDim);
}

const Vector operator-(double left, Vector& right)
{
	int tempArrayDim = right.GetDim();

	double *tempArray = new double[tempArrayDim];

	for (int i = 0; i < tempArrayDim; i++)
	{
		tempArray[i] = left - right._vector[i];
	}

	return Vector(tempArray, tempArrayDim);
}

const Vector operator*(Vector& left, double right)
{
	int tempArrayDim = left.GetDim();

	double *tempArray = new double[tempArrayDim];

	for (int i = 0; i < tempArrayDim; i++)
	{
		tempArray[i] = left._vector[i] * right;
	}

	return Vector(tempArray, tempArrayDim);
}

const Vector operator*(double left, Vector& right)
{
	int tempArrayDim = right.GetDim();

	double *tempArray = new double[tempArrayDim];

	for (int i = 0; i < tempArrayDim; i++)
	{
		tempArray[i] = right._vector[i] * left;
	}

	return Vector(tempArray, tempArrayDim);
}

const double operator*(Vector& left, Vector& right)
{
	if (left.GetDim() == right.GetDim())
	{
		double sum = 0;

		int dim = left.GetDim();

		for (int i = 0; i < dim; i++)
		{
			sum += left._vector[i] * right._vector[i];
		}

		return sum;
	}
	else {
		std::cout << "Dimensions do not match!" << std::endl;

		return 0;
	}

	return 0.0;
}

void Vector::SetNorm()
{	
	double sum = 0.0;

	int dim = GetDim();

	for (int i = 0; i < dim; i++)
	{
		sum += _vector[i] * _vector[i];
	}

	_norm = sqrt(sum);	
}

double Vector::GetNorm()
{
	return _norm;
}

void Vector::Print()
{
	double *tempArray = GetVector();

	for (int i = 0; i < GetDim(); i++)
	{
		std::cout << tempArray[i] << "\t";
	}

	std::cout << std::endl;
}

Vector::~Vector()
{
}