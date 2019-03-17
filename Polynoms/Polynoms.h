#include "stdafx.h"
#include "Monom.h"
#include <iostream>
#include <string>
using namespace std;

class Polynom: public Monom{
	Link Head;
	void init();
public:
	Polynom();
	Polynom(string str); 
	void loadString(string str);
	void Add(int power, double cf);
	Polynom& operator+(Polynom op2);
	Polynom& operator-(Polynom op2);
	Polynom& operator*(Polynom op2);
	bool operator==(const Polynom &op2) const;
	double calc(double x, double y, double z);
	void Print();
};

