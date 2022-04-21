#pragma once

class Matrix
{
private:
	int rows;
	int colls;
	int** matrix;// вказівник на перший елемент динамічного масиву вказівників
public:
	Matrix();
	Matrix(int rows, int colls);
	Matrix(Matrix&& m_matrix) noexcept;
	Matrix& operator=(Matrix&& m_matrix) noexcept;
	int& getMij(int i, int j);
	void setMij(int i, int j, int value);
	void Print();
	void deleteRow(int n);
	void deleteColl(int n);
	int getRows()
	{
		return rows;
	}
	int getColls()
	{
		return colls;
	}
	void setRows(int rows)
	{
		this->rows = rows;
	}
	void setColls(int rows)
	{
		this->colls = colls;
	}
	~Matrix();
};


