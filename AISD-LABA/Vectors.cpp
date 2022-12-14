#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "Vectors.h"

using namespace std;

double Vectors:: MIN_D = 0.00000001;

//unsigned CorrectSizeInput()
//{
//	char symbol[10] = { '.', '+', '-','0', 0 };
//	char str[10] = {};
//
//	while (true)
//	{
//		cin >> str;
//		if (strchr(symbol, str[0]) != NULL or isalpha(str[0]))
//		{
//			cout << "Input coorect value" << endl;
//		}
//		else
//		{
//			break;
//		}
//	}
//	cout << "VARNING: the vector is of type unsigned, so the size will have a dimension equal to the number up to the first non-number characters" << endl;
//	return atoi(str);
//}
//
//double CorrectValueInput()
//{
//	char symbol[10] = { '.', '+', '-', 0};
//	char str[10] = {};
//	int j = 0;
//
//	while (true)
//	{
//		cin >> str;
//		while (j < strlen(str))
//		{
//			if (strchr(symbol, str[j]) != NULL)
//			{
//				j += 1;
//			}
//			else break;
//		}
//		if (strlen(str) or isalpha(str[j]))
//		{
//			cout << "Input coorect value" << endl;
//		}
//		else
//		{
//			break;
//		}
//	}
//	char res[10] = {};
//	for (int i = 0; i <strlen(str); i++)
//	{
//		if (isdigit(str[i]) or strchr(symbol, str[i]) != NULL)
//			res[i] = str[i];
//		else
//			break;
//	}
//	return atof(res);
//}

int CorrectSizeInput()
{
	int number = 0;
	while (number <= 0)
	{
		while (!(cin >> number) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Input correct value" << endl;
		}
		if (number <= 0) cout << "Input correct value" << endl;

	}
	return number;
}

double CorrectValueInput()
{
	double number = 0;
	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nIncorrect value...\n";
	}

	return number;
}


Vectors::Vectors(unsigned size ) : size(size)
{
	//cout << "create vector" << endl;
	if (size == 0)
		vector = NULL;
	else
	{
		vector = new double[size];
		for (int i = 0; i < size; i++)
		{
			vector[i] = 0;
		}
	}
}

Vectors::Vectors(const Vectors& v)
{
	size = v.size;
	vector = new double[size];
	for (int i = 0; i < size; i++)
	{
		vector[i] = v.vector[i];
	}
}

Vectors::~Vectors()
{
	delete[] vector;
}

unsigned Vectors:: GetSize() const
{
	return size;
}

void Vectors::SetVector()
{
	cout << "Input vector size > 0" << endl;
	size = unsigned(CorrectSizeInput());

	cout << "Vector size = " << size << endl;
	if (vector != NULL)
		delete[] vector;
	vector = new double[size];
	cout << "Input vector values" << endl;
	for (int i = 0; i < size; i++)
	{
		vector[i] = CorrectValueInput();
	}
}

void Vectors:: PrintVector() const
{
	cout << "Vector parameters:" << endl;
	cout << "size = " << size << endl;
	cout << "Values:";
	for (int i = 0; i < size; i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl << endl;
}

Vectors Vectors:: operator = (const Vectors& v)
{
	if (this == (&v))
	{
		return *this;
	}
	if (size < v.size)
	{
		if (vector != NULL)
			delete[] vector;
		vector = NULL;
		vector = new double[v.size];
	}
	for (int i = 0; i < v.size; i++)
	{
		vector[i] = v.vector[i];
	}
	size = v.size;
	return *this;
}

double& Vectors:: operator [] (const unsigned& i) const
{
	if (i >= size || i < 0)
	{
		throw "index i is out of range";
	}
	for (int j = 0; j < size; j++)
	{
		if (i == j)
		{
			return vector[i];
		}
	}
}

Vectors Vectors:: operator + (const Vectors& v)
{
	Vectors res(max(v.size, size));
	if (size < v.size)
	{
		for (int i = 0; i < size; i++)
		{
			res.vector[i] = vector[i] + v.vector[i];
		}
		for (int i = 0; i < v.size - size; i++)
		{
			res.vector[i + size] = vector[i] + v.vector[i + size];
		}
	}
	if (size > v.size)
	{
		for (int i = 0; i < v.size; i++)
		{
			res.vector[i] = vector[i] + v.vector[i];
		}
		for (int i = 0; i < size - v.size; i++)
		{
			res.vector[i + v.size] = vector[i + v.size] + v.vector[i];
		}
	}
	if (v.size == size)
	{
		for (int i = 0; i < size; i++)
		{
			res.vector[i] = vector[i] + v.vector[i];
		}
	}
	return res;
}

Vectors Vectors:: operator - (const Vectors& v)
{
	Vectors res(max(v.size, size));
	if (size < v.size)
	{
		for (int i = 0; i < size; i++)
		{
			res.vector[i] = vector[i] - v.vector[i];
		}
		for (int i = 0; i < v.size - size; i++)
		{
			cout << vector[i] << endl << v.vector[i + size] << endl;
			cout << i << endl << i + size << endl;
			res.vector[i + size] = vector[i] - v.vector[i + size];
		}
	}
	if (size > v.size)
	{
		for (int i = 0; i < v.size; i++)
		{
			res.vector[i] = vector[i] - v.vector[i];
		}
		for (int i = 0; i < size - v.size; i++)
		{
			cout << vector[i + v.size] << endl << v.vector[i] << endl;
			cout << i << endl << i + v.size << endl;
			cout << vector[i + v.size] - v.vector[i] << endl;
			res.vector[i + v.size] = vector[i + v.size] - v.vector[i];
		}
	}
	if (size == v.size)
	{
		for (int i = 0; i < size; i++)
		{
			res.vector[i] = vector[i] - v.vector[i];
		}
	}
	
	return res;
}
//????????? ???????????? ????????
double Vectors:: operator * (const Vectors& v)
{
	double res = 0;
	if (size < v.size)
	{
		for (int i = 0; i < size; i++)
		{
			res += vector[i] * v.vector[i];
		}
		for (int i = 0; i < v.size - size; i++)
		{
			res += vector[i] * v.vector[i + size];
		}
	}
	if (size > v.size)
	{
		for (int i = 0; i < v.size; i++)
		{
			res += vector[i] * v.vector[i];
		}
		for (int i = 0; i < size - v.size; i++)
		{
			res += vector[i + v.size] * v.vector[i];
		}
	}
	if (size == v.size)
	{
		for (int i = 0; i < size; i++)
		{
			res += vector[i] * v.vector[i];
		}
	}
	
	return res;
}

Vectors Vectors:: operator * (const int& c)
{
	Vectors res(size);
	for (int i = 0; i < size; i++)
	{
		res.vector[i] = vector[i] * c;
	}
	return res;
}

Vectors Vectors:: operator / (const int& c)
{
	if (c == 0)
	{
		throw "c can not be a 0";
	}
	Vectors res(size);
	for (int i = 0; i < size; i++)
	{
		res.vector[i] = vector[i] / c;
	}
	return res;
}

bool Vectors:: operator == (const Vectors& v) const
{
	if (size == v.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (abs(v.vector[i] - vector[i]) < MIN_D)
			{
				return 1;
			}
		}
	}
	return 0;
}

bool Vectors:: operator != (const Vectors& v) const
{
	if (size != v.size)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (abs(v.vector[i] - vector[i]) > MIN_D)
			{
				return 0;
			}
		}
	}
		
	return 1;
}