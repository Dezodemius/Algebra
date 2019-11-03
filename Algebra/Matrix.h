#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "Vector.h"

// Creates a Matrix using an array, real number or Vector.
class Matrix
{
public:
	// Default constructor.
	Matrix();
	// Create matrix using array.
	Matrix(double ** matrix, int n, int m);
	// Create matrix using real number. 
	Matrix(double alpha, int n, int m);
	// Create diagonal matrix using Vector.
	Matrix(Vector vector);
	
	friend const Vector operator*(Matrix& matrix, Vector& vector);
	friend const Vector operator*(Vector& vector, Matrix& matrix);
	friend const Matrix operator*(Matrix& left, Matrix& right);
	friend const Matrix operator*(double alpha, Matrix& matrix);
	friend const Matrix operator*(Matrix& matrix, double alpha);	
	friend const Matrix operator+(Matrix& left, Matrix& right);
	friend const Matrix operator-(Matrix& left, Matrix& right);
	friend const bool operator==(Matrix& left, Matrix& right);
	friend const bool operator!=(Matrix& left, Matrix& right);
	
	// Print the matrix to the console.
	void Print();

	// Returns determinant of matrix.
	double GetDet();
	// Returns number of rows.
	int GetN();
	// Returns number of columns.
	int GetM();
	// Returns a matrix array.
	double ** GetMatrix();

	// Class destructor.
	~Matrix();

private:
	// Set determinant.
	void SetDet();

private:
	// The number of rows.
	int _n;
	// The number of columns.
	int _m;
	// The default determinat.
	double _det = 42.0;
	// Matrix array.
	double ** _matrix;
};
#endif // !MATRIX_H
