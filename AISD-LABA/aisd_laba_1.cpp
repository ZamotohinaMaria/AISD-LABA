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
	cout << "Press Esc to return to the main menu" << endl;
	while (true)
	{
		int key = getkey();
		if ((key == 27) || ((key >= 49) || (key <= 57))) return key;
	}
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
		

		int m1 = menu1();
		if (m1 == 27) break;
		switch (m1)
		{
		case 49:
			try {
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
						int choise = 0;
						while (true)
						{
							choise = getkey();
							if ((choise == 65) || (choise == 66)) break;
						}
						switch (choise)
						{
						case 65:
							cout << "Select the vector coordinate (from 0 to %d) to display on the screen" << a.GetSize() << endl;
							int coordinate;
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
							int coordinate;
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
						int choise = 0;
						while (true)
						{
							choise = getkey();
							if ((choise == 65) || (choise == 66)) break;
						}
						switch (choise)
						{
						case 65:
							cout << "Select the vector coordinate (from 0 to %d) to replace it" << a.GetSize() << endl;
							int coordinate;
							cin >> coordinate;
							while (coordinate < 0 || coordinate >= a.GetSize())
							{
								cout << "input correct coordinate" << endl;
								cin >> coordinate;
							}
							cout << "Input new value" << endl;
							int value;
							cin >> value;
							a[coordinate] = value;
							cout << "a[%d] = %lf" << coordinate << a[coordinate] << endl;
							break;
						case 66:
							cout << "Select the vector coordinate (from 0 to %d) to replace it" << b.GetSize() << endl;
							int coordinate;
							cin >> coordinate;
							while (coordinate < 0 || coordinate >= b.GetSize())
							{
								cout << "input correct coordinate" << endl;
								cin >> coordinate;
							}
							cout << "Input new value" << endl;
							int value;
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
						cout << "operator * (a * c, where c = const)" << endl;
						cout << "Input the integer constant" << endl;
						int constant;
						cin >> constant;
						cout << "a * %d = " << a * 3 << endl;
						break;
					case 55:
						break;
					case 56:
						cout << "operator * (scalar multiplication)" << endl << "a * b = " << a * b << endl;
						cout << endl;
						break;
					case 57:
						break;
					}
				}
				c = a;
				
				cout << "operator *" << endl << "a * b = " << a * b << endl;
				cout << endl;
				cout << "operator *" << endl << "a * 3 = " << a * 3 << endl;
				cout << endl;
				cout << "operator *" << endl << "3 * a = " << 3 * a << endl;
				cout << endl;
				cout << "operator *" << endl << "a * 0.5 = " << a * 0.5 << endl;
				cout << endl;
				cout << "operator /" << endl << "a / 2 = " << a / 2 << endl;
				try
				{
					cout << a / 0;
				}
				catch (const char* exp)
				{
					cout << endl << exp << endl;
				}
				cout << endl;
				cout << "operator == " << endl << "(a == b) = " << (a == b) << endl;
				cout << endl;
				cout << "operator != " << endl << "(a != b) = " << (a != b) << endl;
				cout << endl;
			}
			catch (const char* exp)
			{
				cout << endl << exp << endl;
			}
			break;
		case 50:
			try
			{
				c = (a + b) * 0.5;
			}
			catch (const char* exp)
			{
				cout << endl << exp << endl;
			}
			cout << "vector a:";
			cout << a << endl;
			cout << "vector b:";
			cout << b << endl;
			cout << "vector c:";
			cout << c << endl;
			break;
		}

		int finish = 0;
		cout << endl;
		cout << "If you want to finish the programm press Ecs" << endl << "If you want to continue witn two new vectors, press Enter" << endl;
		while (true)
		{
			finish = getkey();
			if ((finish == 13) || (finish == 27)) break;
		}
		if (finish == 27) break;
	}
	cout << endl << "program is finished";
	return 0;
}