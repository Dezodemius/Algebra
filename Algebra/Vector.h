#ifndef VECTOR_H
#define VECTOR_H

// Creates a Vector using an array or a real number.
class Vector
{
public:
	// Default constuctor.
	Vector();
	// Creates vector using array.
	Vector(double* array, int valueDim);
	 
	// Creates vector using real number.
	// Params:
	//		alpha: A real number.
	//		valueDim: A vector size.
	Vector(double alpha, int valueDim);
	
	// Returns vector`s dimension.
	int GetDim();
	// Returns vector`s array.
	double* GetVector();
	// Returns the norm of a vector.
	double GetNorm();

	/// Print vectors to console.
	void Print();

	friend const Vector operator+(Vector& left, Vector& right);
	friend const Vector operator+(Vector& left, double right);
	friend const Vector operator+(double left, Vector& right);
	friend const Vector operator-(Vector& left, Vector& right);
	friend const Vector operator-(Vector& left, double right);
	friend const Vector operator-(double left, Vector& right);
	friend const double operator*(Vector& left, Vector& right);
	friend const Vector operator*(double left, Vector& right);
	friend const Vector operator*(Vector& left, double right);

	// Class destructor.
	~Vector();

private:
	// Set vector.
	// Params:
	//		array: vector`s array.
	void SetVector(double* array);
	// Set the dimension of a vector.
	// Params:
	//		valueDim: dimension of a vector.
	void SetDim(int valueDim);
	// Set the norm of a vector.
	void SetNorm();

private:
	// Stored vector`s array.
	double *_vector;
	// The norm of a vector.
	double _norm;
	// Dimension of a vector.
	int _dim;
};

#endif //VECTOR_H