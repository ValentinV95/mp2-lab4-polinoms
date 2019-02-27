#include <iostream>
#include "pol.h"
using namespace std;
int main() {
	int kol, i=1, s, res= 0;
	double a;
	monom tmp;
	pol A, B;

	setlocale(LC_ALL, "Russian");

	cout << "Правила" << endl;
	cout << "Степень должна быть  не отрицательна и меньше 10 " << endl;
	cout << "Коэффициент монома не должен бть равен 0" << endl;

	cout << "Введите количество мономов первого полинома (А) " << endl;
	cin >> kol;
	while (i <= kol) {
		cout << "Введите коэффициент монома " << i << endl;
		cin >> a;
		cout << "Введите степень x монома " << i << endl;
		cin >> s;
		res += s * 100;
		cout << "Введите степень у монома " << i << endl;
		cin >> s;
		res += s * 10;
		cout << "Введите степень z монома " << i << endl;
		cin >> s;
		res += s ;
		tmp.zapoln(a, res);
		A.insert(tmp);
		i++;
		res = 0;
	}
	A.show();
	i = 1;
	
	cout << "Введите количество мономов второго полинома (В) " << endl;
	cin >> kol;
	while (i <= kol) {
		cout << "Введите коэффициент монома " << i << endl;
		cin >> a;
		cout << "Введите степень x монома " << i << endl;
		cin >> s;
		res += s * 100;
		cout << "Введите степень у монома " << i << endl;
		cin >> s;
		res += s * 10;
		cout << "Введите степень z монома " << i << endl;
		cin >> s;
		res += s;
		tmp.zapoln(a, res);
		B.insert(tmp);
		i++;
		res = 0;
	}
	B.show();
	cout << "Выберите операцию " << endl;

	cout << " 1: A + B " << endl;
	cout << " 2: A - B " << endl;
	cout << " 3: B - A " << endl;
	cout << " 4: A * B " << endl;
	cin >> kol;
	if (kol == 1) {
		(A + B).show();
	}
	else if (kol == 2) {
		(A - B).show();
	}
	else if (kol == 3) {
		(B - A).show();
	}
	else {
		(A * B).show();
	}

	return 0;
}