#ifndef MATRIX.H
#define MATRIX.H

#include <iostream>
using namespace std;

class Matrix {
	int m_rows, m_cols;
	double **m;
public:
	Matrix(int rows=1, int cols=1);
	Matrix(const Matrix &);
	~Matrix();
	int GetRow()const;
	int GetCol()const;
	Matrix& operator+=(const Matrix& matrix);
	Matrix& operator+=(const double& b);
	Matrix& operator-=(const Matrix& matrix);
	Matrix& operator-=(const double& b);
	Matrix& operator*=(const Matrix& matrix);
	Matrix& operator*=(const double& b);
	Matrix& operator/=(const double& b);
	friend Matrix operator+(const Matrix& a, const Matrix& b);
	friend Matrix operator+(const Matrix& matrix, const double b);
	friend Matrix operator+(const double b,const Matrix& matrix);
	friend Matrix operator-(const Matrix& a, const Matrix& b);
	friend Matrix operator-(const Matrix& matrix, const double b);
	friend Matrix operator-(const double b, const Matrix& matrix);
	friend Matrix operator*(const Matrix& a, const Matrix& b);
	friend Matrix operator*(const Matrix& matrix, const double b);
	friend Matrix operator*(const double b, const Matrix& matrix);
	friend Matrix operator/(const Matrix& matrix, const double b);
	friend Matrix operator/(const double b, const Matrix& matrix);
	friend Matrix operator^(const Matrix& matrix, const int n);
	double* operator[](int rows);
	friend bool operator ==(const Matrix& a, const Matrix& b);
	friend bool operator !=(const Matrix& a, const Matrix& b);
	friend std::istream & operator >>(std::istream& in, const Matrix& matrix);
	friend std::ostream & operator <<(std::ostream& out, const Matrix& matrix);
};
Matrix* citire(istream&);
Matrix* afisare(ostream&);
#endif 