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
		next = NULL;
	}
};
class pol {
	monom *head;
	unsigned int size;
public:
	pol();
	~pol();

	
	void insert(monom m);
	void show();
	void clear();

	pol operator+ (pol sec);
	pol operator- (pol sec);
	pol operator* (pol sec);	
	pol& operator= (pol const &sec);

	pol operator* (double con) const;

	bool operator== (const pol &sec) const;
	bool operator!= (const pol &sec) const;
};