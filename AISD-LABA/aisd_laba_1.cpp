// variant 1(2)
#include <iostream>
#include <cmath>
#include "Vectors.h"
#include <conio.h>

using namespace std;

std::ostream& operator<< (std::ostream& out, const Vectors& v)
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

int menu()
{
	cout << "Press 1, if you want to check that all overloaded statements are executed correctly" << endl;
	cout << "Press 2 to complete the task: find the angle bisector" << endl;
	while (true)
	{
		int key = getkey();
		if ((key == 49) || (key == 50)) return key;
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
		

		int choice = menu();
		switch (choice)
		{
		case 49:
			try {
				c = a;
				cout << "operator =" << endl << "c " << c << endl;
				cout << endl;
				cout << "operator []" << endl << "a[1] = " << a[1] << endl;
				cout << endl;
				cout << "operator +" << endl << "a + b = " << a + b << endl;
				cout << endl;
				cout << "operator -" << endl << "a - b = " << a - b << endl;
				cout << endl;
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