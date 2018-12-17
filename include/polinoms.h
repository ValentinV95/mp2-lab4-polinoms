#ifndef _POLINOMS_
#define _POLINOMS_

#include <list.h>
#include <iostream>
using namespace std;

struct Mon
{
	double Value;
	int degree;
};

bool operator > (Mon a, Mon b) 
{
	if (a.degree > b.degree)
		return 1;
	else return 0;
};
bool operator < (Mon a, Mon b) 
{
	if (a > b)
		return 0;
	else return 1;
};
bool operator == (Mon a, Mon b) 
{
	if ((b.degree == a.degree) && (b.Value == a.Value))
		return 1;
	else return 0;
};
bool operator != (Mon a, Mon b)
{
	if ((a.degree != b.degree) && (a.Value != b.Value))
		return 1;
	else return 0;
};
Mon operator * (Mon a, Mon b)
{
	Mon res;
	res.Value = a.Value * b.Value;
	res.degree = a.degree + b.degree;
	int d1,d2;
	d1 = a.degree;
	d2 = b.degree;
	int t = d1%10+d2%10;
	if (t < 100)
	{
		d1=d1/100;
		d2=d2/100;
		t = d1%100+d2%100;
		if (t < 100)
		{
			d1=d1/100;
			d2=d2/100;
			t = d1+d2;
			if(t < 100)
			{} else throw "Too Large degree Y in multiply";
		}
		else throw "Too Large degree X in multiply";
	}
	else throw "Too Large degree Z in multiply";
	return res;
};
Mon operator + (Mon a, Mon b)
{
	Mon res;
	if (a.degree == b.degree)
	{
	res.degree = a.degree;
	res.Value = a.Value + b.Value;
	}
	else throw "its not monoms";
	return res;
}

class Polinoms
{
public:
	List <Mon> Polinom;
	Polinoms(){};

	void Print()
	{
		Node <Mon> *tmp;
		int x,y,z,deg;
		tmp = Polinom.head;
		while ( tmp !=nullptr)
		{
			if ( tmp ->data.degree == 0)
			{
				cout << tmp->data.Value ;
				if (tmp->next != nullptr)
					cout << " + ";
			}
			else 
			{
				deg = tmp->data.degree;
				z = deg % 100;
				deg = deg/100;
				y = deg % 100;
				deg = deg/100;
				x = deg;
				cout << tmp->data.Value <<"*x^"<< x << "*y^" << y << "*z^" << z ;
				if (tmp->next != nullptr)
					cout << " + ";
			}
			tmp = tmp->next;
		}
	};

	void Insert (Mon tmp)
	{
		if (tmp.Value != 0)
		{
			Node <Mon> *a = Polinom.head;
			if (a == nullptr)
				Polinom.insert_front(tmp);
			else
			{

				if ( a == Polinom.head)
				{
					if (a->data.degree < tmp.degree)
						Polinom.insert_front(tmp);
					else
						if (a->data.degree == tmp.degree)
						{
							a->data.Value +=tmp.Value;
						}
						else goto e;
				}
				else
e:				while (a != nullptr)
				{
					if (a->next == nullptr)
					{
						Polinom.insert_at_end(tmp);
						break;
					}
					else if ( a->next->data.degree < tmp.degree)
					{
						Polinom.insert_after(a, tmp);
						break;
					}
					else
						if (a->next->data.degree == tmp.degree)
						{
							a->next->data.Value +=tmp.Value;
							break;
						}
						else a = a->next;
				}
			}
		}
	};
	void Set(double k, double x , double y, double z)
	 {
		 Mon n;
		 n.Value = k;
		if ( x > 99) 
			throw "Too large degree of X!";
		else if ( (x != (int)x) || ( x < 0))
			throw "Wrong degree X";
		else
			n.degree = (int)x*10000;
		if ( y > 99) 
			throw "Too large degree of Y!";
		else if ( (y != (int)y) || ( y < 0))
			throw "Wrong degree Y";
		else
			n.degree += (int)y*100;
		if ( z > 99) 
			throw "Too large degree of Z!";
		else if ( (z != (int)z) || ( z < 0))
			throw "Wrong degree Z";
		else
			n.degree +=(int)z;
		Insert(n);
	 };

	void Set()
	{
		Mon tmp;
		double k;
		cout << "Insert Coefficiet" << endl;
		cin >> tmp.Value;
		cout << "Insert degree of X, Y and Z"<< endl;
		cin >> k ;
		if ( k > 99) 
			throw "Too large degree of X!";
		else if ( (k != (int)k) || ( k < 0))
			throw "Wrong degree X";
		else
			tmp.degree = (int)k*10000;
		cin >> k;
		if ( k > 99) 
			throw "Too large degree of Y!";
		else if ( (k != (int)k) || ( k < 0))
			throw "Wrong degree Y";
		else
			tmp.degree += (int)k*100;
		cin >> k;
		if ( k > 99) 
			throw "Too large degree of Z!";
		else if ( (k != (int)k) || ( k < 0))
			throw "Wrong degree Z";
		else
			tmp.degree +=(int)k;
		Insert(tmp);
	};

	bool operator == (const Polinoms a) const
	{
		if (Polinom == a.Polinom)
			return 1;
		else return 0;
	}

	Polinoms operator + (Polinoms a)
	{
		Polinoms res;
		Node <Mon> *x = Polinom.head;
		Node <Mon> *y = a.Polinom.head;

		while((x != nullptr) && (y != nullptr))
		{
			if(x->data > y->data)
			{
				res.Polinom.insert_at_end (x->data);
				x = x->next;
			}
			else if(y->data > x->data)
			{
				res.Polinom.insert_at_end (y->data);
				y = y->next;
			}
			else 
			{
				res.Polinom.insert_at_end(y->data + x->data);
				x = x->next;
				y = y->next;
			}
		}
		if((x == nullptr) && (y != nullptr))
		{
			while (y != nullptr)
			{
				res.Polinom.insert_at_end(y->data);
				y = y->next;
			}
		}
		else if((y == nullptr) && (x != nullptr))
		{
			while (x != nullptr)
			{
				res.Polinom.insert_at_end(x->data);
				x = x->next;
			}
		}

		x= res.Polinom.head;
		while (x != nullptr)
		{
			if (x->data.Value == 0)
			{
				res.Polinom.del(x->data);
			}
			x=x->next;
		}
		return res;
	};

	Polinoms operator - (Polinoms a)
	{
		return (*this + a*(-1));
	};

	Polinoms operator * (Polinoms a)
	{
		Polinoms res;
		Node <Mon> *p1 = Polinom.head;
		Node <Mon> *p2;
		while (p1!= nullptr)
		{
			p2 = a.Polinom.head;
			while(p2!= nullptr)
			{			
				res.Insert (p1->data * p2->data);
				p2 = p2->next;
			}
			p1 = p1->next;
		}
		return res;
	};

	Polinoms operator * (double a)
	{
		Polinoms res;
		Node <Mon> *p;
		p = Polinom.head;
		if (a == 0)
			Polinom.head = nullptr;
		else
		while ( p!= nullptr)
		{
			p->data.Value = p->data.Value *a;
			res.Insert(p->data);
			p=p->next;
		}
		return res;
	};

};

#endif _POLINIMS_
