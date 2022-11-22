// variant 1(2)
#include <iostream>
#include <complex>
#include <stdlib.h>
#include <cmath>
#include "Vectors-2.h"
#include <conio.h>

using namespace std;

template <class T>
ostream& operator << (ostream& out, const Vectors<T> &v)
{
	out << "Vector: ";
	for (unsigned i = 0; i < v.GetSize(); i++)
	{
		out << v[i] << " ";
	}
	return out;
}

template <class T>
Vectors<T> operator * (const T& c, const Vectors<T>& v)
{
	Vectors<T> res(v.GetSize());
	for (int i = 0; i < v.GetSize(); i++)
	{
		res[i] = v[i] * c;
	}
	return res;
}

int getkey()
{
	int key = getch();
	if ((key == 0) || (key == 224)) key = getch();
	return key;
}

int menu1()
{
	cout << endl << "This is main menu" << endl;
	cout << "Press 1, if you want to check that all overloaded statements are executed correctly" << endl;
	cout << "Press 2 to complete the task: find the angle bisector" << endl;
	cout << "Press Esc to to choose new type" << endl;
	while (true)
	{
		int key = getkey();
		if ((key == 49) || (key == 50) || (key == 27)) return key;
	}
}

int menu2()
{
	cout << "Choose operator:" << endl;
	cout << "Press 1 to check operator =" << endl;
	cout << "Press 2 to check operator [] for reading" << endl;
	cout << "Press 3 to check operator [] for writing" << endl;
	cout << "Press 4 to check operator +" << endl;
	cout << "Press 5 to check operator -" << endl;
	cout << "Press 6 to check operator * (a * c, where c = const)" << endl;
	cout << "Press 7 to check operator * (c * a, where c = const)" << endl;
	cout << "Press 8 to check operator * (scalar multiplication)" << endl;
	cout << "Press 9 to check operator /" << endl;
	cout << "Press Tab to check operator ==" << endl;
	cout << "Press Bacspace to check operator !=" << endl;
	cout << "Press Esc to return to the main menu" << endl;
	while (true)
	{
		int key = getkey();
		if ((key == 27) || ((key >= 49) || (key <= 57)) || (key == 9) || (key == 32)) return key;
	}
}

template <class T>
double Length(Vectors<T> v)
{
	double len = v * v;
	return sqrt(len);
}


int Choosing()
{
	cout << "Choose vector a(press A) or b(press B)" << endl;
	while (true)
	{
		int choise = getkey();
		if ((choise == 65) || (choise == 66)) return choise;
	}
}

template <class T>
unsigned SelectCoordinate(Vectors<T> v)
{
	int coordinate;
	cout << "Select the vector coordinate (from 0 to " << v.GetSize() - 1 << ") to display on the screen" << endl;
	cin >> coordinate;
	while (coordinate < 0 || coordinate >= v.GetSize())
	{
		cout << "input correct coordinate" << endl;
		cin >> coordinate;
	}
	return coordinate;
}

double InputValue()
{
	double value;
	cout << "Input new value" << endl;
	cin >> value;
	return value;
}

int IntegerConstant()
{
	int constant;
	cout << "Input the integer constant" << endl;
	cin >> constant;
	return constant;
}
template <class T>
void MainTask(Vectors<T> a, Vectors<T> b)
{
	double a_length = Length(a);
	double b_length = Length(b);
	double lambda = a_length / b_length;
	unsigned max_len = max(a.GetSize(), b.GetSize());
	unsigned min_len = min(a.GetSize(), b.GetSize());
	Vectors<T> bisector(max_len);
	for (int i = 0; i < min_len; i++)
	{
		bisector[i] = (a[i] + b[i] * T(lambda)) / T((lambda + 1));
	}
	if (a.GetSize() < b.GetSize())
	{
		for (int i = 0; i < max_len - min_len; i++)
		{
			bisector[i + min_len] = (a[i] + b[i + min_len] * T(lambda)) / T((lambda + 1));
		}
	}

	if (a.GetSize() > b.GetSize())
	{
		for (int i = 0; i < max_len - min_len; i++)
		{
			bisector[i + min_len] = (a[i + min_len] + b[i] * T(lambda)) / T((lambda + 1));
		}
	}
	cout << "Bisector vector: " << bisector << endl;
}

template <class T> 
void MainProgramm()
{
	cout << "Hello, my programm works with two vectors, please, enter their size and values" << endl;
	Vectors<T> a;
	Vectors<T> b;
	Vectors<T> c;
	a.SetVector();
	b.SetVector();
	unsigned coordinate = 0;
	int choise = 0;
	T constant = 0;
	while (true)
	{
		system("cls");
		cout << "vector a:";
		cout << a << endl;
		cout << "vector b:";
		cout << b << endl;
		int m1 = menu1();
		if (m1 == 27) break;
		switch (m1)
		{
		case 49:
			while (true)
			{
				system("cls");
				cout << "vector a:";
				cout << a << endl;
				cout << "vector b:";
				cout << b << endl;
				int m2 = menu2();
				if (m2 == 27) break;
				switch (m2)
				{
				case 49:
					c = a;
					cout << "operator =" << endl << "c = " << c << endl;
					cout << endl;
					break;
				case 50:
					cout << "operator [] for reading" << endl;
					choise = Choosing();
					switch (choise)
					{
					case 65:
						coordinate = SelectCoordinate(a);
						cout << "a[" << coordinate << "] = "  << a[coordinate] << endl;
						break;
					case 66:
						coordinate = SelectCoordinate(b);
						cout << "b[" << coordinate << "] = " << b[coordinate] << endl;
						break;
					}
					break;
				case 51:
					cout << "operator [] for writing" << endl;
					choise = Choosing();
					switch (choise)
					{
					case 65:
						coordinate = SelectCoordinate(a);
						a[coordinate] = InputValue();
						cout << "a[" << coordinate << "] = " << a[coordinate] << endl;
						break;
					case 66:
						coordinate = SelectCoordinate(b);
						b[coordinate] = InputValue();
						cout << "b[" << coordinate << "] = " << b[coordinate] << endl;
						break;
					}
					break;
				case 52:
					cout << "operator +" << endl << "a + b = " << a + b << endl;
					cout << endl;
					break;
				case 53:
					cout << "operator -" << endl << "a - b = " << a - b << endl;
					cout << endl;
					break;
				case 54:
					cout << "operator * (vector * c, where c = const)" << endl;
					choise = Choosing();
					constant = IntegerConstant();
					switch (choise)
					{
					case 65:
						cout << "a * " << constant << " = " << a * constant << endl;
						break;
					case 66:
						cout << "b * " << constant << " = " << b * constant << endl;
						break;
					}
					break;
				case 55:
					cout << "operator * (c * vector, where c = const)" << endl;
					choise = Choosing();
					constant = IntegerConstant();
					switch (choise)
					{
					case 65:
						cout << constant << " * a = " << constant * a << endl;
						break;
					case 66:
						cout << constant << " * b = " << constant * b << endl;
						break;
					}
					break;
				case 56:
					cout << "operator * (scalar multiplication)" << endl << "a * b = " << a * b << endl;
					cout << endl;
					break;
				case 57:
					cout << "operator /" << endl;
					choise = Choosing();
					constant = IntegerConstant();
					switch (choise)
					{
					case 65:
						try
						{
							cout << "a / " << constant << " = " << a / constant << endl;
						}
						catch (const char* exp)
						{

							cout << endl << exp << endl;
						}
						break;
					case 66:
						try
						{
							
							cout << "b / " << constant << " = " << b / constant << endl;
						}
						catch (const char* exp)
						{
							cout << endl << exp << endl;
						}
						break;
					}
					break;
				/*case 32:
					cout << "operator != " << endl << "(a != b) = " << (a != b) << endl;
					cout << endl;
					break;
				case 9:
					cout << "operator == " << endl << "(a == b) = " << (a == b) << endl;
					cout << endl;
					break;*/
				}
				system("pause");
			}
			break;
		case 50:
			try
			{
				MainTask(a, b);
			}
			catch (const char* exp)
			{
				cout << endl << exp << endl;
			}

			break;
		}
		system("pause");
	}
}

int main()
{
	while (true)
	{
		system("cls");
		cout << "Please, choose type:" << endl;
		cout << "Press 1 for int" << endl;
		cout << "Press 2 for float" << endl;
		cout << "Press 3 for double" << endl;
		cout << "Press 4 for complex (float)" << endl;
		cout << "Press 5 for complex (double)" << endl;
		cout << "Press Esc to finish the program" << endl;
		int choise;
		while (true)
		{
			choise = getkey();
			if ((choise >= 49 && choise <= 53) || choise == 27) break;
		}
		
		system("cls");
		if (choise == 27) break;
		switch (choise)
		{
		case 49:
			cout << "tupe - int" << endl;
			MainProgramm <int>();
			break;
		case 50:
			cout << "tupe - float" << endl;
			MainProgramm <float>();
			break;
		case 51:
			cout << "tupe - double" << endl;
			MainProgramm <double>();
			break;
		case 52:
			cout << "tupe - complex (float)" << endl;
			MainProgramm <complex<float>>();
			break;
		case 53:
			cout << "tupe - complex (double)" << endl;
			MainProgramm <complex<double>>();
			break;
		}
	}
	
	cout << endl << "program laba-2 is finished";
	return 0;
}