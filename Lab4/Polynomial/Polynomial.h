#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Monom
{
public:
	double coef;
	int exp;
	Monom *next;
	Monom *prev;
};

class Polynom
{
private:
	Monom *f_head;
	void ins_last(double coef, int exp);
	void simplification(Polynom &p) const;
public:
	Polynom();
	Polynom(const Polynom &p);
	Polynom(const vector<pair<double, int>> &p);
	~Polynom();

	Polynom& operator=(const Polynom &p);
	bool isEmpty() const;
	bool operator==(const Polynom &p) const;
	bool operator!=(const Polynom &p) const;

	Monom* find_mon(double coef, int exp) const;
	bool find(double coef, int exp) const;
	void ins(double coef, int exp);
	void del(double coef, int exp);
	void clear();
	
	Polynom operator*(double val) const;
	Polynom operator+(const Polynom &p) const;
	Polynom operator-(const Polynom &p) const;
	Polynom operator*(const Polynom &p) const;

	friend std::ostream& operator << (std::ostream& os, const Polynom& object);
	friend std::istream& operator >> (std::istream& is, Polynom& object);
};

#endif