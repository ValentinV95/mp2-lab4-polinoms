#ifndef _POLINOM_H_
#define _POLINOM_H

#include <iostream>

struct Monom {
	double coef;
	int pow;
	Monom *next;
	Monom *prev;
};

class Polinom {
public:
	Monom* pol;
	Polinom();
	void ins(double coef, int pow);
	void del(double coef, int pow);
	void ins_at_end(double coef, int pow);
	void del_dublicate();
	Polinom operator*(double v) const;
	Polinom operator+(const Polinom& p) const;
	Polinom operator-(const Polinom& p) const;
	Polinom operator*(const Polinom& p) const;

	friend std::ostream& operator << (std::ostream& os, const Polinom& p);
	friend std::istream& operator >> (std::istream& is, Polinom& p);
};


#endif
