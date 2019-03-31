#define EPS 1e-08
#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

class Monom
{
	public:
		Monom* next;
		Monom* prev;
		unsigned int exp;
		double coef;
};

class Polynom
{
	private:
		Monom* head;
	public:
		Polynom();
		Polynom(const Polynom& a);
		Polynom(vector <pair<double,unsigned int>> a);
		~Polynom();

		Monom* find_monom(double coef_, unsigned int exp_);
		bool isEmpty();
		bool find(double coef_, unsigned int exp_);
		void insert(double coef_, unsigned int exp_);
		void del(double coef_, unsigned int exp_);
		void clear();

		Polynom& operator = (const Polynom& a);
		bool operator == (const Polynom& a);
		bool operator != (const Polynom& a);

		Polynom operator + (const Polynom& a);
		Polynom operator - (const Polynom& a); 
		Polynom operator * (double multiplier);
		Polynom operator * (const Polynom& a);

		friend ostream& operator << (ostream& os, const Polynom& output);
		friend istream& operator >> (istream& is, Polynom& input);
};

// Лучше было сделать итератор, чем миллион раз писать
//	Monom* temp = a.head;
//	while (temp != NULL) {...}


