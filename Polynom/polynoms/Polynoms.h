#ifndef __POLYNOM_H_
#define __POLYNOM_H_

#include <fstream>
#include <iostream>

using namespace std;


struct Monom {
	double coef;
	int exp;
	Monom* next;
	
	Monom() { coef = 0; exp = 0; next = nullptr; }
	Monom(double _coef, int _exp);
	Monom(double _coef, int _exp, Monom* _next);
	Monom(const Monom& monom);

	bool operator==(const Monom &right);
};

class Polynom {	
private:
	Monom* head;
	size_t size;
public:

	// constructors and destructors
	Polynom();
	Polynom(const Polynom& polynom);
	~Polynom();

	// methods
	size_t getSize() { return size; }
	void clear();
	void insert(Monom monom); // вставка в нужное место, если слагаемые подобные, 
							  // то складываем коэф, если коэф < eps, то удаляем моном из списка
	void insert(double coef, int exp);

	void merge(const Polynom &polynom);
	void pop_front();
	void push_front(Monom monom);
	void push_back(Monom monom);
	void del(Monom monom); // такой моном точно есть в списке
	bool find(double coef, int exp);

	// operators
	Polynom operator + (const Polynom &right) const;
	Polynom operator - (Polynom &right);
	Polynom operator * (const Polynom &right);
	Polynom operator * (const double &val) const;
	const Polynom& operator = (const Polynom &right);
	
	bool operator == (const Polynom &right) const;
	bool operator != (const Polynom &right) const;

	// in/out
	friend istream& operator>>(istream &in, Polynom &object);
	friend ostream& operator << (ostream& os, const Polynom& object);
};

#endif // !__POLYNOM_H_