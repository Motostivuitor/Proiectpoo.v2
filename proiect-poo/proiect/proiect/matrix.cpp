#include "matrix.h"
Matrix::Matrix(int rows, int cols)
	:m_rows(rows),
	m_cols(cols)
{
	m = new int *[m_rows];
	for (int i = 0; i < m_rows; i++)
		m[i] = new double[m_cols];
}
Matrix::Matrix(const Matrix & matrix)
	:m_rows(matrix.m_rows),
	m_cols(matrix>m_cols)
{
	m = new double*[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m[i] = new double[m_cols];
	}
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			m[i][j] = matrix.m[i][j];
		}
	}
}
Matrix* citire(istream& cin)
{
	cin >> m_rows;
	cin >> m_cols;
	for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_cols; j++)
	{
				cout << "m[i][j]: " << "\n";
			cin >> m[i][j];
	}
}
Matrix::~Matrix()
{
	for (int i = 0; i < m_rows; i++)
		delete[] m[i];
	delete[] m; 
}
Matrix* afisare(ostream& cout)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
			cout << m[i][j];
		cout << "\n";
	}
}
int Matrix::GetRow()const
{
	return m_rows;
}
int Matrix::GetCol()const
{
	return m_cols;
}
Matrix& Matrix::operator+=(const Matrix& matrix)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
		{
			if (m[i] != matrix.m[j])
				cout << "imposibil";
			else
				m[i][j] += matrix.m[i][j];
		}
	return *this;
}
Matrix& Matrix::operator+=(const double& b)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
	{
				m[i][j] += b;
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& matrix)
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
			if (m[i] != matrix.m[j])
				cout << "imposibil";
			else
				m[i][j] -= matrix.m[i][j];
	}
	return *this;
}
Matrix& Matrix::operator-=(const double& b)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
		{
			m[i][j] -= b;
		}
	return *this;
}
Matrix& Matrix::operator*=(const Matrix& matrix)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if (m[i] != matrix.m[j])
				cout << "imposibil";
			else
			{
				for (int i = 0; i < m_rows; i++)
				{
					for (int j = 0; j < matrix.m_cols; j++)
					{
						for (int k = 0; k < matrix.m_rows; k++)
						{
							m[i][j] += m[i][k] * matrix.m[k][j];
						}
					}
				}
			}
	return *this;
}
Matrix& Matrix::operator*=(const double& b)
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
		{
			m[i][j] *= b;
		}
	return *this;
}
Matrix& Matrix::operator/=(const double& b)
{
	if (b == 0)
		cout << "imposibil!";
	else
	{
		for(int i=0;i<m_rows;i++)
			for (int j = 0; j < m_cols; j++)
			{
				m[i][j] /= b;
			}
		return *this;
	}
}
Matrix operator+(const Matrix& a, const Matrix& b)
{
	if (a != b) cout << "imposibil";
	else
		Matrix rez(a);
	rez += b;
	return rez;
}
Matrix operator+(const Matrix& matrix, const double b)
{
	Matrix rez(matrix);
	rez += b;
	return rez;
}
Matrix operator+(const double b, const Matrix& matrix)
{
	Matrix rez(matrix);
	rez += b;
	return rez;
}
Matrix operator-(const Matrix& a, const Matrix& b)
{
	if (a != b) cout << "imposibil";
	else
		Matrix rez(a);
	rez -= b;
	return rez;
}
Matrix operator-(const Matrix& matrix, const double b)
{
	Matrix rez(matrix);
	rez -= b;
	return rez;
}
Matrix operator-(const double b, const Matrix& matrix)
{
	Matrix rez(matrix);
	rez -= b;
	return rez;
}
Matrix operator*(const Matrix& a,const Matrix& b)
{
	if (a != b) cout << "imposibil";
	Matrix rez(a);
	rez *= b;
	return rez;
}
Matrix operator*(const Matrix& matrix, const double b)
{
	Matrix rez(matrix);
	rez *= b;
	return rez;
}
Matrix operator*(const double b, const Matrix& matrix)
{
	Matrix rez(matrix);
	rez *= b;
	return rez;
}
Matrix operator/(const Matrix& matrix, const double b)
{
	Matrix rez(matrix);
	if (b == 0)	cout << "imposibil";
	else
	rez /= b;
	return rez;
}
Matrix operator/(const double b, const Matrix& matrix)
{
	Matrix rez(matrix);
	if (b == 0)	cout << "imposibil";
	else
		rez /= b;
	return rez;
}
Matrix operator^(const Matrix& matrix, const int n)
{
	int p = 0;
	Matrix rez(matrix);
	if (matrix.m_rows != matrix.m_cols) cout << "imposibil";
	else
		for (int i = 0; i < matrix.m_rows; i++)
		{
			for (int j = 0; j < matrix.m_cols; j++)
				{
					do
					{
						rez *= matrix;
						p++;
					} while (p <= n);
				}
		}
		return rez;
}
double* Matrix::operator[](int rows)
{
	return m[rows];
}
bool operator ==(const Matrix& a, const Matrix& b)
{
	return a.m_rows == b.m_rows && a.m_cols == b.m_cols;
}

bool operator !=(const Matrix& a, const Matrix& b)
{
	return !(a == b);
}
std::istream & operator>>(std::istream & in, const Matrix & matrix)
{
	for (int i = 0; i < matrix.m_rows; i++)
		for (int j = 0; j < matrix.m_cols; j++)
		{
			in >> matrix.m[i][j];
		}
	return in;
}

std::ostream & operator<<(std::ostream & out, const Matrix & matrix)
{
	for (int i = 0; i < matrix.m_rows; i++)
	{
		for (int j = 0; j < matrix.m_cols; j++)
			out << matrix.m[i][j] << " ";
		out << std::endl;
	}

	return out;
}