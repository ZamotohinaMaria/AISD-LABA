#include <iostream>
#include <stdio.h>
#include "Vectors.h"

using namespace std;

double Vectors:: MIN_D = 0.00000001;

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
	cout << "Input vector size" << endl;
	int x;
	cin >> x;
	size = x;
	cout << "Input vector values" << endl;
	if (vector != NULL)
		delete[] vector;
	vector = new double[size];
	for (int i = 0; i < size; i++)
	{
		cin >> x;
		vector[i] = x;
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
	if (size != v.size)
	{
		throw "sizes of vectors are different";
	}
	Vectors res(size);
	for (int i = 0; i < size; i++)
	{
		res.vector[i] = vector[i] + v.vector[i];
	}
	return res;
}

Vectors Vectors:: operator - (const Vectors& v)
{
	if (size != v.size)
	{
		throw "sizes of vectors are different";
	}
	Vectors res(size);
	for (int i = 0; i < size; i++)
	{
		res.vector[i] = vector[i] - v.vector[i];
	}
	return res;
}
//скалярное произведение векторов
double Vectors:: operator * (const Vectors& v)
{
	if (size != v.size)
	{
		throw "sizes of vectors are different";
	}
	double res = 0;
	for (int i = 0; i < size; i++)
	{
		res += vector[i] * v.vector[i];
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

Vectors Vectors:: operator * (const double& c)
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