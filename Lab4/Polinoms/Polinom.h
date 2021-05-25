#pragma once
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

struct Monom
{
	double coeff;
	int deg;
	Monom() {};
	void init(double a, int b)
	{
		if ((b > 999) || (b < 0))
			throw "impossible create monom with deg>999 or deg<0";
		else
		{
			coeff = a;
			deg = b;
		}
	}
	Monom operator +(const Monom& a)
	{
		if (this->deg == a.deg)
		{
			Monom res;
			res.init(this->coeff + a.coeff, this->deg);
			return res;
		}
		else throw"impossible add monom with not equal deg";
	}
	Monom operator *(const Monom& m)
	{
		Monom res;
		int a, b, c;
		res.coeff = this->coeff*m.coeff;
		res.deg = this->deg + m.deg;

		a = deg / 100 + m.deg / 100;
		b = deg % 100 / 10 + m.deg % 100 / 10;
		c = deg % 10 + m.deg % 10;

		return res;
	}
	bool operator !=(Monom a)
	{
		if (a == *this)
			return false;
		else return true;
	}
	bool operator ==(const Monom& a)const
	{
		if (a.deg == deg)
			return true;
		else return false;
	}
	bool operator >=(Monom a)
	{
		if (deg >= a.deg)
			return true;
		else return false;
	}
	bool operator >(Monom a)
	{
		if (deg > a.deg)
			return true;
		else return false;
	}
	bool operator <(Monom a)
	{
		if (deg < a.deg)
			return true;
		else return false;
	}
};

class Polinom
{
private:
	List<Monom> P;
	friend class List<Monom>;
public:
	
	Polinom();
	
	~Polinom();
	
	Polinom(const Polinom & A);
	
	void init(Monom M);
	
	void Input();
	
	void Print();
	
	void Delete_Similar();
	
	int Highest_Degree();
	
	bool operator ==(const Polinom& A) const;
	
	Polinom& operator =(const Polinom& A);
	
	Polinom operator +(const Polinom& A);
	
	Polinom operator *(double q);
	
	Polinom operator -(Polinom& A);
	
	Polinom operator *(Polinom& A);
};


