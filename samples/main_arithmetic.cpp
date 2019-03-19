
#include <iostream>
#include <math.h>
#include "arithmetic.h"



void main()
{
	int k, coef, x = 0;
	Polynom A, B, C;
	cout << "Input polynom A" << '\n';
	cin >> A;
	cout << "Input polynom B" << '\n';
	cin >> B;

	cout << "Menu:" << endl;
	cout << "1.Polynoms operations: C = A + B" << endl;
	cout << "2.Polynoms operations: C = A - B" << endl;
	cout << "3.Polynoms operations: C = A * B" << endl;
	cout << "4.Polynoms operations: C = coef*A" << endl;
	cout << "5.Exit" << endl;


	while (x == 0) {
		cout << "Input a menu number:" << endl;
		cin >> k;
		switch (k) {

		case 1: {

			cout << "Polynom C = A + B" << endl;
			C = A + B;
			cout << "Polynom C = " << C << endl;

			break;
		}
		case 2: {

			cout << "Polynom C = A - B" << endl;
			C = A - B;
			cout << "Polynom C = " << C << endl;

			break;
		}
		case 3: {
			cout << "Polynom C = A * B" << endl;
			C = A * B;
			cout << "Polynom C = " << C << endl;
			break;
		}
		case 4: {
			cout << "Polynom C = coef * A" << endl;
			cout << "Enter coef: " << endl;
			cin >> coef;
			C = A * coef;
			cout << "Polynom C = " << C << endl;
			break;
		}
		case 5: {
			x = 1;
			break;
		}
		}
	}
}

