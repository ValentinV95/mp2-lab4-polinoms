// реализация функций и классов для вычисления арифметических выражений
#include "Polynom.h"
#include<string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <math.h>


using namespace std;


Polynom::Polynom() {
	Monom*temp = new Monom;
	temp->coef = 0.0;
	temp->Next = NULL;
	temp->Prev = NULL;
	temp->deg = -1;
	Fhead = temp;
}
Polynom::Polynom(struct m * a, int N) :Polynom() {

	for (int i = 0; i < N; i++) {
		if ((a[i].d < 0) || (a[i].d > 999))
			throw("The wrong monomial degree");
		else
			Insert(a[i].c, a[i].d);
	}
}
Polynom::Polynom(Polynom &A) : Polynom() {
	Monom*temp = A.Fhead->Next;
	while (temp != NULL) {
		Insert(temp->coef, temp->deg);
		temp = temp->Next;
	}
}
Polynom::~Polynom() {
	while (Fhead->Next != NULL) {
		Delete(Fhead->Next->deg);
	}

	delete Fhead;
}

void Polynom::Insert(double _coef, int _deg) {
	if (abs(_coef)< eps)
		return;
	if ((_deg < 0) || (_deg > 999))
		throw("The wrong monomial degree");

	if (Fhead->Next == NULL) {
		Monom*temp = new Monom;
		temp->coef = _coef;
		temp->deg = _deg;
		temp->Next = NULL;
		temp->Prev = Fhead;
		Fhead->Next = temp;

	}
	else {
		Monom*temp = Fhead;
		while ((temp->Next != NULL) && (temp->Next->deg < _deg)) {
			temp = temp->Next;
		}
		if (temp->Next == NULL) {
			Monom*atemp = new Monom;
			atemp->coef = _coef;
			atemp->deg = _deg;
			temp->Next = atemp;
			atemp->Prev = temp;
			atemp->Next = NULL;
		}
		else {
			if (temp->Next->deg != _deg) {
				Monom*atemp = new Monom;
				atemp->coef = _coef;
				atemp->deg = _deg;
				atemp->Prev = temp; atemp->Next = temp->Next;
				temp->Next->Prev = atemp;
				temp->Next = atemp;
			}
			else {
				temp->Next->coef += _coef;
				if (abs(temp->Next->coef)<eps)
					Delete(_deg);
			}
		}

	}
}
void Polynom::Delete(int _deg) {
	if ((_deg < 0) || (_deg > 999))
		throw("The wrong monomial degree");
	else {
		Monom*temp = Fhead->Next;
		if (temp == NULL)
			return;
		else {
			while ((temp->Next != NULL) && (temp->deg != _deg)) {
				temp = temp->Next;
			}
			if (temp->deg == _deg) {

				if (temp->Next != NULL) {
					temp->Prev->Next = temp->Next;
					temp->Next->Prev = temp->Prev;
					delete temp;
				}
				else {
					temp->Prev->Next = NULL;
					delete temp;
				}

			}
		}
	}
}

bool Polynom::IsEmpty() {//1-Empty
	return (Fhead->Next == NULL);
}


bool Polynom::operator==(const Polynom &A)const {
	bool res = true;
	Monom*temp = Fhead->Next;
	Monom*atemp = A.Fhead->Next;
	while ((temp != NULL) && (atemp != NULL)) {
		if ((abs((temp->coef) - (atemp->coef))) || (temp->deg != atemp->deg))
			res = false;
		atemp = atemp->Next;
		temp = temp->Next;
	}
	if (((temp == NULL) && (atemp != NULL)) || ((temp != NULL) && (atemp == NULL)))
		res = false;
	return res;
}



Polynom& Polynom::operator=(const Polynom &A) {
	if (Fhead != A.Fhead) {
		while (Fhead->Next != NULL) {
			Delete(Fhead->Next->deg);
		}
		Monom*atemp = A.Fhead->Next;
		while (atemp != NULL) {
			Insert(atemp->coef, atemp->deg);
			atemp = atemp->Next;
		}
	}
	return *this;
}




Polynom Polynom:: operator+(Polynom &A) {
	Polynom C;
	Monom*temp = Fhead->Next;
	Monom*atemp = A.Fhead->Next;
	while ((temp != NULL) && (atemp != NULL)) {
		if (temp->deg < atemp->deg) {
			C.Insert(temp->coef, temp->deg);
			temp = temp->Next;
		}
		else {
			C.Insert(atemp->coef, atemp->deg);
			atemp = atemp->Next;
		}
	}
	while (temp != NULL) {
		C.Insert(temp->coef, temp->deg);
		temp = temp->Next;
	}
	while (atemp != NULL) {
		C.Insert(atemp->coef, atemp->deg);
		atemp = atemp->Next;
	}

	
	return C;
}
Polynom Polynom:: operator*(double a) {
	Polynom C(*this);
	Monom*temp = C.Fhead->Next;
	while (temp != NULL) {
		temp->coef = temp->coef * a;
		temp = temp->Next;
	}
	return C;
}
Polynom Polynom:: operator-(Polynom &A) {
	Polynom C;
	C = A * (-1);
	C = *this + C;
	return C;
}
Polynom Polynom:: operator*(Polynom &A) {
	Polynom C;
	int st;
	int s1, s2, s3;
	Monom*temp = Fhead->Next;
	Monom*atemp = A.Fhead->Next;
	while (temp != NULL) {
		s1 = (int)temp->deg / 100 + (int)temp->deg % 100 / 10 + temp->deg % 10;
		Monom*atemp = A.Fhead->Next;
		while (atemp != NULL) {
			s2 = (int)atemp->deg / 100 + (int)atemp->deg % 100 / 10 + atemp->deg % 10;
			st = s1 + s2;
			s3 = (int)((temp->deg) + (atemp->deg)) / 100 + (int)((temp->deg) + (atemp->deg)) % 100 / 10 + ((temp->deg) + (atemp->deg)) % 10;/*s3 = (int)st / 100 + (int)st % 100 / 10 + st % 10;*/
			if ((st > 999) || (s3 != s1 + s2))
				throw("The wrong monomial degree");
			else {
				C.Insert((temp->coef)*(atemp->coef), (temp->deg) + (atemp->deg));
			}
			atemp = atemp->Next;
		}
		temp = temp->Next;
	}
	return C;
}


ostream& operator<<(ostream& out, Polynom &A) {
	int l = 0;
	Monom*temp = A.Fhead->Next;
	while (temp != NULL) {
		if (temp != A.Fhead->Next)
			out << " + ";
		if (abs(temp->coef - 1)>eps)
			out << temp->coef;
		if ((int)temp->deg / 100 != 0)
			out << "x^" << temp->deg / 100;
		if ((int)temp->deg % 100 / 10 != 0)
			out << "*y^" << temp->deg % 100 / 10;
		if (temp->deg % 10 != 0)
			out << "*z^" << temp->deg % 10;
		temp = temp->Next;
		l = 1;
	}
	if (l == 0) out << "0";
	return out;
}
istream& operator>>(istream& in, Polynom& A) {
	int k;

	cout << "Input number of polynomials: ";
	in >> k;
	struct m* pol;
	pol = (struct m*)malloc(k * (sizeof(int) + sizeof(double)));
	for (int i = 0; i < k; i++) {
		int x = -1, y = -1, z = -1;
		cout << "Input a monomial coefficient: ";
		in >> pol[i].c;

		while ((x < 0) || (x > 9)) {
			cout << "Input a degree of x: ";
			in >> x;
		}
		while ((y < 0) || (y > 9)) {
			cout << "Input a degree of y: ";
			in >> y;
		}
		while ((z < 0) || (z > 9)) {
			cout << "Input a degree of z: ";
			in >> z;
		}
		pol[i].d = x * 100 + y * 10 + z;
	}
	Polynom B(pol, k);
	A = B;
	//free(pol);
	return in;
}

