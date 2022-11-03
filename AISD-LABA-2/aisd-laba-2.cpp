// variant 1(2)
#include <iostream>
#include <cmath>
#include "Vectors-2.h"
#include <conio.h>

using namespace std;
template <class T>
ostream& operator<< (ostream& out, const Vectors<T>& v)
{
	out << "Vector: ";
	for (int i = 0; i < v.size; i++)
	{
		out << v.vector[i] << " ";
	}
	return out;
}

template <class T, class P>
Vectors<T> operator * (const P& c, const Vectors<T>& v)
{
	Vectors<T> res(v.GetSize());
	for (int i = 0; i < v.GetSize(); i++)
	{
		res.operator[](i) = v.operator[](i) * c;
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
	cout << "This is main menu" << endl;
	cout << "Press 1, if you want to check that all overloaded statements are executed correctly" << endl;
	cout << "Press 2 to complete the task: find the angle bisector" << endl;
	cout << "Press Esc to finish the program" << endl;
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
	double len = 0;
	for (int i = 0; i < v.GetSize(); i++)
	{
		len += pow(v[i], 2);
	}
	return sqrt(len);
}

int Choosing()
{
	cout << "Choose vector a(press a) or b(press b)" << endl;
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
	cout << "Select the vector coordinate (from 0 to %d) to display on the screen" << v.GetSize() << endl;
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

int laba1main()
{
	cout << "Hello, my programm works with two vectors, please, enter their size and values" << endl;
	Vectors<double> a, b, c;
	a.SetVector();
	b.SetVector();
	unsigned coordinate = 0;
	int choise = 0;
	double value = 0;
	int constant = 0;
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
						cout << "a[%d] = %lf" << coordinate << a[coordinate] << endl;
						break;
					case 66:
						coordinate = SelectCoordinate(b);
						cout << "a[%d] = %lf" << coordinate << b[coordinate] << endl;
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
						cout << "a[%d] = %lf" << coordinate << a[coordinate] << endl;
						break;
					case 66:
						coordinate = SelectCoordinate(b);
						b[coordinate] = InputValue();
						cout << "a[%d] = %lf" << coordinate << b[coordinate] << endl;
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
					switch (choise)
					{
					case 65:
						cout << "a * %d = " << a * IntegerConstant() << endl;
						break;
					case 66:
						cout << "b * %d = " << b * IntegerConstant() << endl;
						break;
					}
					break;
				case 55:
					cout << "operator * (c * vector, where c = const)" << endl;
					choise = Choosing();
					switch (choise)
					{
					case 65:
						cout << "%d * a = " << IntegerConstant() * a << endl;
						break;
					case 66:
						cout << "%d * b = " << IntegerConstant() * b << endl;
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
					switch (choise)
					{
					case 65:
						try
						{
							cout << "a / %d = " << a / IntegerConstant() << endl;
						}
						catch (const char* exp)
						{
							cout << endl << exp << endl;
						}
						break;
					case 66:
						try
						{
							cout << "b / %d = " << b / IntegerConstant() << endl;
						}
						catch (const char* exp)
						{
							cout << endl << exp << endl;
						}
						break;
					}
					break;
				case 32:
					cout << "operator != " << endl << "(a != b) = " << (a != b) << endl;
					cout << endl;
					break;
				case 9:
					cout << "operator == " << endl << "(a == b) = " << (a == b) << endl;
					cout << endl;
					break;
				}
				system("pause");
			}
			break;
		case 50:
			try
			{
				double a_length = Length(a);
				double b_length = Length(b);
				double lambda = a_length / b_length;
				Vectors<double> bisector(a.GetSize());
				for (int i = 0; i < a.GetSize(); i++)
				{
					bisector[i] = (a[i] + lambda * b[i]) / (lambda + 1);
				}
				cout << "Bisector vector: " << bisector << endl;
			}
			catch (const char* exp)
			{
				cout << endl << exp << endl;
			}

			break;
		}
		system("pause");
	}
	cout << endl << "program is finished";
	return 0;
}