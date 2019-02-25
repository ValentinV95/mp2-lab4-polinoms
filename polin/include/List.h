#ifndef _POLINOM_
#define _POLINOM_

#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#define MAXC 99999.99999

using namespace std;
struct Mon
{
	double coef;
	int pow;
	Mon* next;
	Mon* prev;
};


class Poly
{
	Mon*head;
public:
	Poly(); 
	Poly(const Poly&);
	Poly(double*, int*, int);
	void Insert(double coef, int pow);
	void Del(int);
	bool operator==(const Poly&) const;
	Poly& operator=(const  Poly&);
	Poly operator+(Poly &);
	Poly operator-(Poly &);
	Poly operator*(double);
	Poly operator*(Poly &);
	friend ostream& operator<<(ostream&, Poly &);

	~Poly();
};

#endif 
