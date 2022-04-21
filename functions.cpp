#include "functions.h"
#include <iostream>
#include <cmath>

using namespace std;

int findSum31(Matrix& matrix)
{
	int sum = 0;
	int Rows = matrix.getRows();
	int k = Rows / 2;
	if (Rows % 2 != 0)
	{
		for (int i = k; i < Rows; i++)
		{
			for (int j = k; j <= i; j++)
			{
				sum += matrix.getMij(i, j);
			}
			k--;
		}
	}
	for (int i = k; i < Rows; i++)
	{
		for (int j = k - 1; j <= i; j++)
		{
			sum += matrix.getMij(i, j);
		}
		k--;
	}
	return sum;
}
void findMaxFabsElementAndDelete186(Matrix& matrix)
{
	int Rows = matrix.getRows();
	int k = Rows / 2;
	int index = 0, max = 0, deleteRow = 0, deleteColl = 0, value;
	for (int i = k; i < matrix.getRows(); i++)
	{
		for (int j = 0; j <= index; j++)
		{
			value = fabs(matrix.getMij(i, j));
			if (value > max)
			{
				max = value;
				deleteRow = i;
				deleteColl = j;
			}
			if (value == max)
			{
				if (deleteRow > i)
				{
					deleteRow = i;
				}
				else if (deleteRow == i)
				{
					if (deleteColl > j)
					{
						deleteColl = j;
					}
				}
			}
		}
		index++;
	}
	matrix.deleteRow(deleteRow);
	matrix.deleteColl(deleteColl);
}