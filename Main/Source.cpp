// ConsoleApplication.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "TPolinom.h"
using namespace std;
int main()
{
	TPolinom P1, P2, P3;
	cin >> P1;
	cout << "MONOM 1 = ";
	P1.Transformation();
	cout << endl;
	cin >> P2;
	cout << "MONOM 2 = ";
	P2.Transformation();
	cout << endl;
	cout << "SUM 1 = ";
	P3 = P1.SUMMA1(P2);
	P3.Transformation();
	cout << endl;
	cout << "MONOM 1 = ";
	P1.Transformation();
	cout << endl;
	cout << "MONOM 2 = ";
	P2.Transformation();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "SUM 2 = ";
	P1.SUMMA2(P2);
	P1.Transformation();
	cout << endl;
	cout << "MONOM 1 = ";
	P1.Transformation();
	cout << endl;
	cout << "MONOM 2 = ";
	P2.Transformation();
	cout << endl;
	system("pause");
	return 0;
};
