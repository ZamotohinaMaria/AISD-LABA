#include <iostream>
#include <algorithm>
#include <stdio.h>
#include "Vectors-2.h"

using namespace std;

template <class T>
double Vectors<T>::MIN_D = 0.00000001;

template <class T>
Vectors<T>::Vectors(unsigned size) : size(size)
{
	//cout << "create vector" << endl;
	if (size == 0)
		vector = NULL;
	else
	{
		vector = new T[size];
		for (int i = 0; i < size; i++)
		{
			vector[i] = 0;
		}
	}
}

template <class T>
Vectors<T>::Vectors(const Vectors& v)
{
	size = v.size;
	vector = new T[size];
	for (int i = 0; i < size; i++)
	{
		vector[i] = v.vector[i];
	}
}

template <class T>
Vectors<T>::~Vectors()
{
	delete[] vector;
}

template <class T>
unsigned Vectors<T>::GetSize() const
{
	return size;
}

template <class T>
void Vectors<T>::SetVector()
{
	cout << "Input vector size" << endl;
	unsigned v_size;
	cin >> v_size;
	size = v_size;
	if (vector != NULL)
		delete[] vector;
	vector = new T[size];
	cout << "Input vector values" << endl;
	T x;
	for (int i = 0; i < size; i++)
	{
		cin >> x;
		vector[i] = x;
	}
}

template <class T>
void Vectors<T>::PrintVector() const
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

template <class T>
Vectors<T> Vectors<T>:: operator = (const Vectors& v)
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
		vector = new T[v.size];
	}
	for (int i = 0; i < v.size; i++)
	{
		vector[i] = v.vector[i];
	}
	size = v.size;
	return *this;
}

template <class T>
T& Vectors<T>:: operator [] (const unsigned& i) const
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

template <class T>
Vectors<T> Vectors<T>:: operator + (const Vectors& v)
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

template <class T>
Vectors<T> Vectors<T>:: operator - (const Vectors& v)
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
//скалярное произведение векторов
template <class T>
T Vectors<T>:: operator * (const Vectors& v)
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

template <class T>
Vectors<T> Vectors<T>:: operator * (int c)
{
	Vectors res(size);
	for (int i = 0; i < size; i++)
	{
		res.vector[i] = vector[i] * c;
	}
	return res;
}

template <class T>
Vectors<T> Vectors<T>:: operator / (int c)
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

template <class T>
bool Vectors<T>:: operator == (const Vectors& v) const
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

template <class T>
bool Vectors<T>:: operator != (const Vectors& v) const
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

template class Vectors<int>;
template class Vectors<float>;
template class Vectors<double>;
//template class Vectors<complex<float>>;
//template class Vectors<complex<double>>;