#ifndef _POLINOM_H_
#define _POLINOM_H_

#include "list.h"

class Monom
{
public:

	double coef;
	int deg;

	Monom();
	Monom(double, int);
	~Monom();
	int RetSum();
	bool operator>= (Monom&);
	bool operator< (Monom&);
	bool operator!= (const Monom&)const;
	friend std::ostream& operator<< (std::ostream& os, const Monom& v);
};

class Polinom : public List<Monom>
{
public:

	Polinom();
	~Polinom();
	void ToStandartView();
	Polinom& operator= (Polinom&);
	Polinom& operator= (List<Monom>&);
	Polinom operator+ (Polinom&);
	Polinom operator- (Polinom&);
	Polinom operator* (double);
	Polinom operator* (Monom&);
	Polinom operator* (Polinom&);
	void Print();
};

#endif // !_POLINOM_H_