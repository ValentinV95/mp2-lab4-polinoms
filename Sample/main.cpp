#include "Polynoms.h"
#include <iostream>
using namespace std;
int main() {
	cout << "Primer vvoda mnogochlena:" << endl;
	cout << "A=2x1y2z1; B=1x4y5z1+4x2y2z3" << endl;
	cout << "Esli net coef pered monom, to monom=0(x1y4z3=0)" << endl;
	cout << "Vvedite mnogochlen A:" << endl;
	string t;
	cin >> t;
	Polynom A(t);
	cout << "Vvedite mnogochlen B:" << endl;
	cin >> t;
	Polynom B(t);
	Polynom C;
	//сумма
	cout << "A+B=" << endl;
	C = A + B;
	C.Print();
	cout << endl;
	//////вычитание
	cout << "A-B=" << endl;
	C = A - B;
	C.Print();
	cout << endl;
	cout << "B-A=" << endl;
	C = B - A;
	C.Print();
	cout << endl;
	////умножение 
	cout << "A*B=" << endl;
	C = A*B;
	C.Print();
	cout << endl;
	return 0;
}