// variant 1(2)
#include <iostream>
#include <cmath>
#include "Vectors.h"
#include <conio.h>

using namespace std;

ostream& operator<< (ostream& out, const Vectors& v)
{
	out << "Vector: ";
	for (int i = 0; i < v.size; i++)
	{
		out << v.vector[i] << " ";
	}
	return out;
}

template <class T>
Vectors operator * (const T& c, const Vectors& v)
{
	Vectors res(v.GetSize());
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
	cout << "Press 0 to check operator !=" << endl;
	cout << "Press Esc to return to the main menu" << endl;
	while (true)
	{
		int key = getkey();
		if ((key == 27) || ((key >= 49) || (key <= 58)) || (key == 9)) return key;
	}
}

double Length(Vectors v)
{
	double len = 0;
	for (int i = 0; i < v.GetSize(); i++)
	{
		len += pow(v[i], 2);
	}
	return sqrt(len);
}

int main()
{
	while (true) {
		system("cls");
		cout << "Hello, my programm works with two vectors, please, enter their size and values" << endl;
		Vectors a, b, c;
		a.SetVector();
		b.SetVector();

		system("cls");
		int coordinate = 0;
		int choise = 0;
		int value = 0;
		int constant = 0;

		int m1 = menu1();
		if (m1 == 27) break;
		switch (m1)
		{
		case 49:
			while (true)
			{
				system("cls");
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
					cout << "Choose vector a(press a) or b(press b)" << endl;
					while (true)
					{
						choise = getkey();
						if ((choise == 65) || (choise == 66)) break;
					}
					switch (choise)
					{
					case 65:
						cout << "Select the vector coordinate (from 0 to %d) to display on the screen" << a.GetSize() << endl;
						cin >> coordinate;
						while (coordinate < 0 || coordinate >= a.GetSize())
						{
							cout << "input correct coordinate" << endl;
							cin >> coordinate;
						}
						cout << "a[%d] = %lf" << coordinate << a[coordinate] << endl;
						break;
					case 66:
						cout << "Select the vector coordinate (from 0 to %d) to display on the screen" << b.GetSize() << endl;
						cin >> coordinate;
						while (coordinate < 0 || coordinate >= b.GetSize())
						{
							cout << "input correct coordinate" << endl;
							cin >> coordinate;
						}
						cout << "a[%d] = %lf" << coordinate << b[coordinate] << endl;
						break;
					}
					break;
				case 51:
					cout << "operator [] for writing" << endl;
					cout << "Choose vector a(press a) or b(press b)" << endl;
					while (true)
					{
						choise = getkey();
						if ((choise == 65) || (choise == 66)) break;
					}
					switch (choise)
					{
					case 65:
						cout << "Select the vector coordinate (from 0 to %d) to replace it" << a.GetSize() << endl;
						cin >> coordinate;
						while (coordinate < 0 || coordinate >= a.GetSize())
						{
							cout << "input correct coordinate" << endl;
							cin >> coordinate;
						}
						cout << "Input new value" << endl;
						cin >> value;
						a[coordinate] = value;
						cout << "a[%d] = %lf" << coordinate << a[coordinate] << endl;
						break;
					case 66:
						cout << "Select the vector coordinate (from 0 to %d) to replace it" << b.GetSize() << endl;
						cin >> coordinate;
						while (coordinate < 0 || coordinate >= b.GetSize())
						{
							cout << "input correct coordinate" << endl;
							cin >> coordinate;
						}
						cout << "Input new value" << endl;
						cin >> value;
						b[coordinate] = value;
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
					cout << "Choose vector a(press a) or b(press b)" << endl;
					while (true)
					{
						choise = getkey();
						if ((choise == 65) || (choise == 66)) break;
					}
					switch (choise)
					{
					case 65:
						cout << "Input the integer constant" << endl;
						cin >> constant;
						cout << "a * %d = " << a * constant << endl;
						break;
					case 66:
						cout << "Input the integer constant" << endl;
						cin >> constant;
						cout << "b * %d = " << b * constant << endl;
						break;
					}
					break;
				case 55:
					cout << "operator * (c * vector, where c = const)" << endl;
					cout << "Choose vector a(press a) or b(press b)" << endl;
					while (true)
					{
						choise = getkey();
						if ((choise == 65) || (choise == 66)) break;
					}
					switch (choise)
					{
					case 65:
						cout << "Input the integer constant" << endl;
						cin >> constant;
						cout << "%d * a = " << constant * a << endl;
						break;
					case 66:
						cout << "Input the integer constant" << endl;
						cin >> constant;
						cout << "%d * b = " << constant * b << endl;
						break;
					}
					break;
				case 56:
					cout << "operator * (scalar multiplication)" << endl << "a * b = " << a * b << endl;
					cout << endl;
					break;
				case 57:
					cout << "operator /" << endl;
					cout << "Choose vector a(press a) or b(press b)" << endl;
					while (true)
					{
						choise = getkey();
						if ((choise == 65) || (choise == 66)) break;
					}
					switch (choise)
					{
					case 65:
						cout << "Input the integer constant" << endl;
						cin >> constant;
						try
						{
							cout << "a / %d = " << a / constant << endl;
						}
						catch (const char* exp)
						{
							cout << endl << exp << endl;
						}
						break;
					case 66:
						cout << "Input the integer constant" << endl;
						cin >> constant;
						try
						{
							cout << "b / %d = " << b / constant << endl;
						}
						catch (const char* exp)
						{
							cout << endl << exp << endl;
						}
						break;
					}
					break;
				case 9:
					cout << "operator == " << endl << "(a == b) = " << (a == b) << endl;
					cout << endl;
					break;
				case 58:
					cout << "operator != " << endl << "(a != b) = " << (a != b) << endl;
					cout << endl;
					break;
				}
				break;
			}
		case 50:
			try
			{
				double a_length = Length(a);
				double b_length = Length(b);
				double lambda = a_length / b_length;
				Vectors bisector(a.GetSize());
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
	}
	cout << endl << "program is finished";
	return 0;
}