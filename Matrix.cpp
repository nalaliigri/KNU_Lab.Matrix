#include "Matrix.h"
#include <iostream>
using namespace std;
Matrix::Matrix()
{
	rows = colls = 0;
	matrix = nullptr;
}
Matrix::Matrix(int rows, int colls)
{
	this->rows = rows;
	this->colls = colls;
	matrix = (int**) new int* [rows]; // к-сть рядків, к-сть покажчиків
	// Виділити пам'ять для кожного покажчика
	for (int i = 0; i < rows; i++)
		matrix[i] = (int*)new int[colls];
	// Заповнити масив нулями
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colls; j++)
			matrix[i][j] = 0;
}
Matrix::Matrix(Matrix&& m_matrix) noexcept :rows(m_matrix.rows), colls(m_matrix.colls)
{
	matrix = m_matrix.matrix;
	for (int i = 0; i < rows; i++) {

		matrix[i] = m_matrix.matrix[i];
		matrix[i] = nullptr;
	}
	m_matrix.matrix = nullptr;
}
Matrix& Matrix::operator=(Matrix&& m_matrix) noexcept
{
	if (colls > 0)
	{
		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
	}
	if (rows > 0)
	{
		delete[] matrix;
	}
	rows = m_matrix.rows;
	colls = m_matrix.colls;
	matrix = (int**) new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = (int*) new int[colls];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
			matrix[i][j] = m_matrix.matrix[i][j];
	}
	return *this;
}
void Matrix::Print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

}
void Matrix::setMij(int i, int j, int value)
{
	if ((i < 0) || (i >= rows))
		return;
	if ((j < 0) || (j >= colls))
		return;
	matrix[i][j] = value;
}
int& Matrix::getMij(int i, int j)
{
	try
	{
		if ((rows > 0) && (colls > 0) && (i < rows) && (j < colls))
			return  matrix[i][j];
		else
			throw 303;
	}
	catch (int)
	{
		cerr << "[" << i << "," << j << "]: " << "OUT OF RANGE";
	}
}
void Matrix::deleteRow(int n)
{
	try
	{
		if (n > rows)
			throw "B";
	}
	catch (...)
	{
		cout << "[" << n << "]" << ": OUT OF RANGE";
	}
	int rowToDel = n;
	delete[] matrix[rowToDel];
	int** tmp = new int* [rows - 1];
	int tmpI = 0;
	for (int i = 0; i < rows; i++)
		if (i != rowToDel)
			tmp[tmpI++] = matrix[i];
	delete[] matrix;
	matrix = tmp;
	--rows;
}
void Matrix::deleteColl(int n)
{
	try
	{
		if (n > colls)
			throw "A";
	}
	catch (...)
	{
		cout << "[" << n << "]" << ": OUT OF RANGE";
	}
	int** tmp = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		tmp[i] = new int[colls - 1];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0, k = 0; j < colls; j++)
		{
			if (j != n) tmp[i][k++] = matrix[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
	matrix = tmp;
	--colls;

}
Matrix::~Matrix()
{
	if (colls > 0)
	{
		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
	}
	if (rows > 0)
		delete[] matrix;
}