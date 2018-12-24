#pragma once
// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#ifndef _ARITHMETIC_H_
#define _ARITHMETIC_H_
#include <string>
#include <vector>
#include <set>
#include <iostream>
#define eps 0.00000001
using namespace std;



class Monom {
public:
	double coef;
	int deg;
	Monom*Next;
	Monom*Prev;
};
struct m
{
	double c;
	int d;
};

class Polynom
{
private:
	Monom * Fhead;
	//int size;
public:
	Polynom();
	Polynom(struct m *, int);
	Polynom(Polynom &);
	~Polynom();
	void Insert(double, int);
	void Delete(int);
	bool IsEmpty();
	bool operator==(const Polynom &) const;
	/*bool Polynom::operator!=(const Polynom &p) const
	{
	return !(*this == p);
	}*/

	Polynom& operator=(const Polynom &);
	Polynom operator+(Polynom &);
	Polynom operator-(Polynom &);
	Polynom operator*(double);
	Polynom operator*(Polynom &);
	friend ostream& operator<<(ostream&, Polynom &);
	friend istream& operator>>(istream&, Polynom &);
};


#endif _ARITHMETIC_H_
