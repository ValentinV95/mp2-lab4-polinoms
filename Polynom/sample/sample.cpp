#include <iostream>
#include <string>
#include "Polynoms.h"

using namespace std;

void inputPolynom(Polynom &a, int _number);

int main() {
start:
	try {
		cout << "Information about first polynom: " << endl;
		cout << "Input number of monoms: ";
		int number_of_monoms1;
		cin >> number_of_monoms1;
		Polynom a;
		inputPolynom(a, number_of_monoms1);

		cout << "Information about second polynom: " << endl;
		cout << "Input number of monoms: ";
		int number_of_monoms2;
		cin >> number_of_monoms2;
		Polynom b;
		inputPolynom(b, number_of_monoms2);
		cout << "A + B: " << a + b << endl;
		cout << "A - B: " << a - b << endl;
		cout << "A * B: " << a * b << endl;
		cout << endl;
	}
	catch (string s) {
		cout << s << endl;
	}
	cout << "Do You want to continue?" << endl;
	cout << " 1. Yes" << endl;
	cout << " 2. No" << endl;
	int choice2;
	cin >> choice2;
	switch (choice2) {
	case 1:
		system("cls");
		goto start;
	default:
		return 0;
	}
}

void inputPolynom(Polynom &a, int _number)
{
	for (int i = 0; i < _number; i++) {
		cout << "Input " << i + 1 << "'s monom coef and exp: ";
		double coef;
		int exp;
		cin >> coef >> exp;
		a.insert(coef, exp);
	}
}