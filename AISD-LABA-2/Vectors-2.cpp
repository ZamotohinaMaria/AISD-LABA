#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <complex>
#include "Vectors-2.h"

using namespace std;

template <class T>
double Vectors<T>::MIN_D = 0.00000001;

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

template <class T>
T CorrectValueInput()
{
	T number = 0;
	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\nIncorrect value...\n";
	}

	return number;
}


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
	cout << "Input vector size > 0" << endl;
	size = unsigned(CorrectSizeInput());

	cout << "Vector size = " << size << endl;
	if (vector != NULL)
		delete[] vector;
	vector = new T[size];
	cout << "Input vector values" << endl;
	for (int i = 0; i < size; i++)
	{
		vector[i] = CorrectValueInput<T>();
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
double Vectors<T>:: operator * (const Vectors& v)
{
	double res = 0;
	if (size < v.size)
	{
		for (int i = 0; i < size; i++)
		{
			res += double(vector[i] * v.vector[i]);
		}
		for (int i = 0; i < v.size - size; i++)
		{
			res += double(vector[i] * v.vector[i + size]);
		}
	}
	if (size > v.size)
	{
		for (int i = 0; i < v.size; i++)
		{
			res += double(vector[i] * v.vector[i]);
		}
		for (int i = 0; i < size - v.size; i++)
		{
			res += double(vector[i + v.size] * v.vector[i]);
		}
	}
	if (size == v.size)
	{
		for (int i = 0; i < size; i++)
		{
			res += double(vector[i] * v.vector[i]);
		}
	}
	return res;
}

template <>
double Vectors<complex<float>>:: operator * (const Vectors& v)
{
	double res = 0;
	Vectors<complex<float>> vv = v;
	for (int i = 0; i < vv.size; i++)
	{
		vv.vector[i] = complex<float>(real(vv.vector[i]), -imag(vv.vector[i]));
	}
	if (size < v.size)
	{
		for (int i = 0; i < size; i++)
		{
			res += double(real(vector[i] * vv.vector[i]));
		}
		for (int i = 0; i < vv.size - size; i++)
		{
			res += double(real(vector[i] * vv.vector[i + size]));
		}
	}
	if (size > vv.size)
	{
		for (int i = 0; i < vv.size; i++)
		{
			res += double(real(vector[i] * vv.vector[i]));
		}
		for (int i = 0; i < size - vv.size; i++)
		{
			res += double(real(vector[i + vv.size] * vv.vector[i]));
		}
	}
	if (size == vv.size)
	{
		for (int i = 0; i < size; i++)
		{
			res += double(real(vector[i] * vv.vector[i]));
		}
	}
	return res;
}

template <>
double Vectors<complex<double>>:: operator * (const Vectors& v)
{
	double res = 0;
	Vectors<complex<double>> vv = v;
	for (int i = 0; i < v.size; i++)
	{
		vv.vector[i] = complex<double>(real(vv.vector[i]), -imag(vv.vector[i]));
	}
	if (size < vv.size)
	{
		for (int i = 0; i < size; i++)
		{
			res += double(real(vector[i] * vv.vector[i]));
		}
		for (int i = 0; i < vv.size - size; i++)
		{
			res += double(real(vector[i] * vv.vector[i + size]));
		}
	}
	if (size > vv.size)
	{
		for (int i = 0; i < vv.size; i++)
		{
			res += double(real(vector[i] * vv.vector[i]));
		}
		for (int i = 0; i < size - vv.size; i++)
		{
			res += double(real(vector[i + vv.size] * vv.vector[i]));
		}
	}
	if (size == vv.size)
	{
		for (int i = 0; i < size; i++)
		{
			res += double(real(vector[i] * vv.vector[i]));
		}
	}
	return res;
}

template <class T>
Vectors<T> Vectors<T>:: operator * (T c)
{
	Vectors res(size);
	for (int i = 0; i < size; i++)
	{
		res.vector[i] = vector[i] * c;
	}
	return res;
}

template <class T>
Vectors<T> Vectors<T>:: operator / (T c)
{
	if (c == T(0))
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

//template <class T>
//bool Vectors<T>:: operator == (const Vectors& v) const
//{
//	if (size == v.size)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (T(abs(v.vector[i] - vector[i])) < T(MIN_D))
//			{
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//
//template <class T>
//bool Vectors<T>:: operator != (const Vectors& v) const
//{
//	if (size != v.size)
//	{
//		return 0;
//	}
//	else
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (T(abs(v.vector[i] - vector[i])) > T(MIN_D))
//			{
//				return 0;
//			}
//		}
//	}
//
//	return 1;
//}
////for complex
//template <>
//bool Vectors<complex<float>>:: operator == (const Vectors& v) const
//{
//	if (size == v.size)
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (float(fabs(real(v.vector[i] - vector[i]))) < float(MIN_D) and float(fabs(imag(v.vector[i] - vector[i]))) < float(MIN_D))
//			{
//				return 1;
//			}
//		}
//	}
//	return 0;
//}
//
//template <>
//bool Vectors<complex<double>>:: operator != (const Vectors& v) const
//{
//	if (size != v.size)
//	{
//		return 0;
//	}
//	else
//	{
//		for (int i = 0; i < size; i++)
//		{
//			if (double(fabs(real(v.vector[i] - vector[i]))) < double(MIN_D) and double(fabs(imag(v.vector[i] - vector[i]))) < double(MIN_D))
//			{
//				return 0;
//			}
//		}
//	}
//
//	return 1;
//}



template class Vectors<int>;
template class Vectors<float>;
template class Vectors<double>;
template class Vectors<complex<float>>;
template class Vectors<complex<double>>;

