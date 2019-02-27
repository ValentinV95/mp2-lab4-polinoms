#pragma once
#include <iostream>
using namespace std;
struct monom {
	monom *next;
	double a;
	unsigned int s;
	monom(double a1, unsigned int s1 = 0) { next = NULL; a = a1; s = s1; }
	monom() {};
	void zapoln(double coeff, int pow) {
		a = coeff;
		s = pow;
	}

};
class pol {
	monom *head;
	unsigned int size;
public:
	pol();
	void insert(monom m);
	void show();

	pol& operator= (pol sec);

	pol& operator+ (pol sec);
	pol& operator- (pol sec);
	pol& operator* (pol sec);	

	pol& operator* (double con);

	bool operator== (const pol &sec) const;
	bool operator!= (const pol &sec) const;
};