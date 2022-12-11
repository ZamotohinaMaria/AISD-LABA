#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <complex>
#include "Vectors-3.h"

using namespace std;

template <class T>
double Vectors<T>::MIN_D = 0.00000001;

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
Vectors<T>::Vectors(unsigned size)
{
	if (size >= 0)
		this->size = size;
	else
	{
		delete this;
		throw "Incorrect size of vector";
	}

	values = vector<T>(size);
}

template <class T>
Vectors<T>::Vectors(const Vectors& v)
{
	size = v.size;
	values.resize(v.size);

	auto it = v.cbegin();
	unsigned i = 0;
	for (it; it != v.cend(); it++)
	{
		this->values[i++] = (*it);
	}

	//for (auto it: v)
	//{
	//	this->values.push_back(it);
	//}
}

template <class T>
Vectors<T>::~Vectors()
{
	values.clear();
}

template <class T>
unsigned Vectors<T>::GetSize() const
{
	return size;
}

template <class T>
void Vectors<T>::SetVector()
{
	cout << "Input vector values" << endl;

	auto it = this->begin();
	for (int i =0; i < size; i++)
	{
		values[i]=CorrectValueInput<T>();
	}

	/*for (int i = 0; i < size; i++)
	{
		values.push_back(CorrectValueInput<T>());
	}*/
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
		values.resize(v.size);
	}

	auto v_it = v.cbegin();
	/*for (v_it; v_it != v.cend(); v_it++)
	{
		values.push_back((*v_it));
		cout << (*v_it) << endl;
	}*/

	unsigned i = 0;
	for (v_it; v_it != v.cend(); v_it++)
	{
		values[i++] = (*v_it);
	}


	/*for (auto it : v)
	{
		values.push_back(*it);
	}*/

	size = v.size;
	return *this;
}

template <class T>
T Vectors<T>:: operator [] (const unsigned& i) const
{
	if (i >= size || i < 0)
	{
		throw "index i is out of range";
	}
	for (int j = 0; j < size; j++)
	{
		if (i == j)
		{
			return values.at(i);
		}
	}
}

template <class T>
void Vectors<T>::set(const unsigned& i, T val)
{
	if (i >= size || i < 0)
	{
		throw "index i is out of range";
	}
	auto it = cbegin();
	for (int j = 0; j < size; j++)
	{
		if (i == j)
		{
			values[i] = val;
		}
	}
}

template <class T>
Vectors<T> Vectors<T>:: operator + (const Vectors& v)
{
	Vectors res(max(v.size, size));
	auto res_iter = res.cbegin();
	bool flag = false;
	if (size < v.size)
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{
			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res.values[i + j] = values[j] + v.values[i + j];
			}
			if (flag == true) break;
		}
	}
	else
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{
			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res.values[i + j] = values[i + j] + v.values[j];
			}
			if (flag == true) break;
		}
	}

	return res;
}

template <class T>
Vectors<T> Vectors<T>:: operator - (const Vectors& v)
{
	Vectors res(max(v.size, size));
	auto res_iter = res.cbegin();
	bool flag = false;
	if (size < v.size)
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{
			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res.values[i + j] = values[j] - v.values[i + j];
			}
			if (flag == true) break;
		}
	}
	else
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{
			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res.values[i + j] = values[i + j] - v.values[j];
			}
			if (flag == true) break;
		}
	}

	return res;
}
//скалярное произведение векторов
template <class T>
double Vectors<T>:: operator * (const Vectors& v)
{
	double res = 0;
	bool flag = false;
	if (size < v.size)
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{
			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res += double(values[j] * v.values[i + j]);

			}
			if (flag == true) break;
		}
	}
	else
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{
			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res += double(values[i + j] * v.values[j]);

			}
			if (flag == true) break;
		}
	}
	return res;
}

template <>
double Vectors<complex<float>>:: operator * (const Vectors& v)
{
	double res = 0;
	Vectors<complex<float>> vv = v;
	auto vv_iter = vv.cbegin();
	for (int i = 0; i < vv.size; i++)
	{
		vv.values[i] = complex<float>(real(vv.values[i]), -imag(vv.values[i]));
	}

	bool flag = false;
	if (size < v.size)
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{

			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res += double(real(values[j] * vv.values[i + j]));

			}
			if (flag == true) break;
		}
	}
	else
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{
			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res += double(real(values[i + j] * vv.values[j]));

			}
			if (flag == true) break;
		}
	}
	return res;
}

template <>
double Vectors<complex<double>>:: operator * (const Vectors& v)
{
	double res = 0;
	Vectors<complex<double>> vv = v;
	auto vv_iter = vv.cbegin();
	for (int i = 0; i < vv.size; i++)
	{
		vv.values[i] = complex<double>(real(vv.values[i]), -imag(vv.values[i]));
	}
	bool flag = false;
	if (size < v.size)
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{
			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res += double(real(values[j] * vv.values[i + j]));

			}
			if (flag == true) break;
		}
	}
	else
	{
		for (int i = 0; i < max(v.size, size); i += min(v.size, size))
		{
			for (int j = 0; j < min(v.size, size); j++)
			{
				if (i + j >= max(v.size, size))
				{
					flag = true;
					break;
				}
				res += double(real(values[i + j] * vv.values[j]));

			}
			if (flag == true) break;
		}
	}
	return res;
}

template <class T>
Vectors<T> Vectors<T>:: operator * (T c)
{
	Vectors res(size);
	auto res_iter = res.cbegin();
	for (int i = 0; i < size; i++)
	{
		res.values[i] = values[i] * c;
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
	auto res_iter = res.cbegin();
	for (int i = 0; i < size; i++)
	{
		res.values[i] = values[i] / c;
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
			if (T(abs(v.values[i] - values[i])) < T(MIN_D))
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
			if (T(abs(v.values[i] - values[i])) > T(MIN_D))
			{
				return 0;
			}
		}
	}

	return 1;
}
//for complex
template <>
bool Vectors<complex<float>>:: operator == (const Vectors& v) const
{
	if (size == v.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (float(fabs(real(v.values[i] - values[i]))) < float(MIN_D) and float(fabs(imag(v.values[i] - values[i]))) < float(MIN_D))
			{
				return 1;
			}
		}
	}
	return 0;
}

template <>
bool Vectors<complex<float>>:: operator != (const Vectors& v) const
{
	if (size != v.size)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (double(fabs(real(v.values[i] - values[i]))) < double(MIN_D) and double(fabs(imag(v.values[i] - values[i]))) < double(MIN_D))
			{
				return 0;
			}
		}
	}

	return 1;
}

template <>
bool Vectors<complex<double>>:: operator == (const Vectors& v) const
{
	if (size == v.size)
	{
		for (int i = 0; i < size; i++)
		{
			if (float(fabs(real(v.values[i] - values[i]))) < float(MIN_D) and float(fabs(imag(v.values[i] - values[i]))) < float(MIN_D))
			{
				return 1;
			}
		}
	}
	return 0;
}

template <>
bool Vectors<complex<double>>:: operator != (const Vectors& v) const
{
	if (size != v.size)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (double(fabs(real(v.values[i] - values[i]))) < double(MIN_D) and double(fabs(imag(v.values[i] - values[i]))) < double(MIN_D))
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
template class Vectors<complex<float>>;
template class Vectors<complex<double>>;

