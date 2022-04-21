#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Matrix.h"
#include "functions.h"
using namespace std;

void aboutProject()
{
	cout << "K-15 Nataliia Hrytsyshyn" << endl;
	cout << "Project \"Matrix_lab\"" << endl << endl;
	cout << "Variant 31:" << endl;
	cout << "Calculate the sum of the values of the elements located in its lower sector (diagonal segments included)." << endl << endl;
	cout << "Variant 186:" << endl;
	cout << "Find the first (with the smallest line number, and the equality of line numbers with the smallest ";
	cout << "column number) of the elements that have the largest modulo value in the left ";
	cout << "the lower corner of the square matrix(including boundaries).Remove the stringand from the matrix ";
	cout << "the column to which it belongs." << endl << endl;
}
string getPathIn()
{
	cout << "Enter the input file name:" << endl;
	string pathIn;
	getline(cin, pathIn);
	if (pathIn.length() > 0)
	{
		return pathIn;
	}
	else
	{
		throw 505;
	}
}
string getPathOut()
{
	cout << "Enter the output file name:" << endl;
	string pathOut;
	getline(cin, pathOut);
	if (pathOut.length() > 0)
	{
		return pathOut;
	}
	else
	{
		throw 405;
	}
}
Matrix& readFromFile(Matrix& matrix, istream& fin)
{
	int Rows = matrix.getRows();
	int Colls = matrix.getColls();
	int value;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Colls; j++)
		{
			if (fin.eof())
			{
				throw 404;
			}
			fin >> value;
			matrix.setMij(i, j, value);
		}
	}

	return matrix;
}
void writeInFile(Matrix& matrix, ofstream& fout)
{
	for (int i = 0; i < matrix.getRows(); i++)
	{
		fout << setw(57);
		for (int j = 0; j < matrix.getColls(); j++)
		{
			fout << matrix.getMij(i, j);
			fout << " ";
		}
		fout << endl;
	}
}

int main()
{
	aboutProject();
	ifstream fin;
	string pathIn, fileName;
	do
	{
		try
		{
			pathIn = getPathIn();
			fin.open(pathIn);
			if (fin.is_open())
			{
				fileName = pathIn;
			}
		}
		catch (int)
		{
			fin.open("in.txt");
			fileName = "in.txt";
		}

	} while (!fin.is_open());
	int N, RoCo;
	fin >> N;
	fin >> N;
	if (N >= 3 && N <= 300)
	{
		RoCo = N;
	}
	else
	{
		return 0;
	}
	Matrix matrix(RoCo, RoCo);
	matrix.setColls(RoCo);
	matrix.setRows(RoCo);
	try
	{
		readFromFile(matrix, fin);
	}
	catch (int)
	{
		cerr << fileName << ": INPUT ERROR" << endl;
		return 0;
	}
	fin.close();
	matrix.Print();
	cout << endl;
	cout << "Sum of elements in lower sector = " << findSum31(matrix) << endl;
	findMaxFabsElementAndDelete186(matrix);
	ofstream fout;
	string pathOut;

	try
	{
		do
		{
			pathOut = getPathOut();
			fout.open(pathOut);
		} while (!fout.is_open());
	}
	catch (int)
	{
		fout.open("out.txt");
	}
	writeInFile(matrix, fout);
	fout.close();
	cout << "Thank you! Have a nice day:)" << endl;
	return 0;
}