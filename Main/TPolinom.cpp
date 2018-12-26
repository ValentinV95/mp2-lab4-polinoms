#include <iostream>
#include <cstdio>
#include "TPolinom.h"
#include "TMonom.h"
using namespace std;
TPolinom::TPolinom()
{
	pMonom p = new TMonom(0, -1, NULL);
	pFirst = p;
	p->setpnext(pFirst);
}
void TPolinom::InsMonom(double coef, int deg)
{
	pMonom next, present;
	next = present = pFirst;
	if (coef != 0)
	{
		if (next->getpnext() != pFirst)
		{
			next = next->getpnext();
			while (next->getdeg() > deg)
			{
				present = next;
				next = next->getpnext();
			}
		}
		if (next->getdeg() == deg)
		{
			double CurrentCoef;
			CurrentCoef = next->getcoef() + coef;
			if (CurrentCoef <= EPS && CurrentCoef >= -EPS)
				DelMonom(deg);
			else
				next->setcoef(CurrentCoef);
		}
		else
		{
			pMonom pm = new TMonom(coef, deg, next);
			present->setpnext(pm);
		}
	}
}
int TPolinom::DelMonom(int deg)
{
	pMonom next, present;
	int result = -1;
	next = present = pFirst;
	if (next->getpnext() == pFirst)
		return result;
	else
	{
		next = next->getpnext();
		while (next->getdeg() != deg && next->getdeg() != -1)
		{
			present = next;
			next = next->getpnext();
		}
		if (next->getdeg() == -1)
			return result;
		else
		{
			present->setpnext(next->getpnext());
			result = next->getdeg();
			delete next;
			next = NULL;
		}
	}
	return result;
}
void TPolinom::Transformation()
{
	int i = 0, flag = 1, flag2 = 1, beginflag = 1;
	pMonom p;
	p = pFirst;
	if (p->getpnext() != pFirst)
	{
		p = p->getpnext();
		while (p->getdeg() != -1)
		{
			flag = 0;
			flag2 = 0;
			if (p->getcoef() > 0 && (abs(p->getcoef()) != 1 || (p->getdeg() / 100
				== 0 && (p->getdeg() % 100) / 10 == 0 && (p->getdeg() % 10) == 0)))
			{
				if (!beginflag) cout << " +";
				beginflag = 0;
				cout << p->getcoef();
			}
			else
				if (p->getcoef() > 0 && abs(p->getcoef()) == 1)
				{
					if (!beginflag) cout << " +";
					beginflag = 0;
					flag = 1;
				}
				else
					if (p->getcoef() < 0 && (abs(p->getcoef()) != 1 || (p ->getdeg() / 100 == 0 && (p->getdeg() % 100) / 10 == 0 && (p->getdeg() % 10) == 0)))
					{
						beginflag = 0;
						cout << " " << p->getcoef();
					}
					else
					{
						beginflag = 0;
						cout << " -";
						flag = 1;
					}
			if (p->getdeg() / 100 != 0)
			{
				if (!flag) cout << "*";
				else flag = 0;
				if (p->getdeg() / 100 == 1)
					cout << "x";				else
					cout << "x^" << p->getdeg() / 100;
				flag2 = 1;
			}
			if ((p->getdeg() % 100) / 10 != 0)
			{
				if (!flag) cout << "*";
				else flag = 0;
				if ((p->getdeg() % 100) / 10 == 1)
					cout << "y";
				else
					cout << "y^" << (p->getdeg() % 100) / 10;
				flag2 = 1;
			}
			if ((p->getdeg() % 10) != 0)
			{
				if (!flag) cout << "*";
				else flag = 0;
				if ((p->getdeg() % 10) == 1)
					cout << "z";
				else
					cout << "z^" << (p->getdeg() % 10);
				flag2 = 1;
			}
			p = p->getpnext();
		}
	}
	else
		cout << "Zero" << endl;
}
TPolinom TPolinom::SUMMA1(TPolinom &op2)
{
	TPolinom res;
	pMonom Previous1, Current1, Previous2, Current2;
	double SumCoef;
	Previous1 = Current1 = pFirst;
	Previous2 = Current2 = op2.pFirst;
	if (Current1->getpnext() != pFirst && Current2->getpnext() != op2.pFirst)
	{
		Current1 = Current1->getpnext();
		Current2 = Current2->getpnext();
		while (Current1->getdeg() != -1 && Current2->getdeg() != -1)
		{
			if (Current1->getdeg() > Current2->getdeg())
			{
				res.InsMonom(Current1->getcoef(), Current1->getdeg());
				Previous1 = Current1;
				Current1 = Current1->getpnext();
			}
			else
				if (Current1->getdeg() < Current2->getdeg())
				{
					res.InsMonom(Current2->getcoef(), Current2->getdeg());
					Previous2 = Current2;
					Current2 = Current2->getpnext();
				}
				else {
					SumCoef = Current1->getcoef() + Current2->getcoef();
					if (SumCoef)
						res.InsMonom(SumCoef, Current1->getdeg());
					Previous1 = Current1;
					Current1 = Current1->getpnext();
					Previous2 = Current2;
					Current2 = Current2->getpnext();
				}
		}
	}
	else
	{
		Current1 = Current1->getpnext();
		Current2 = Current2->getpnext();
	}
	while (Current1->getdeg() != -1)
	{
		res.InsMonom(Current1->getcoef(), Current1->getdeg());
		Current1 = Current1->getpnext();
	}
	while (Current2->getdeg() != -1)
	{
		res.InsMonom(Current2->getcoef(), Current2->getdeg());
		Current2 = Current2->getpnext();
	}
	return res;
}
void TPolinom::SUMMA2(TPolinom &op2)
{
	pMonom Previous1, Current1, Previous2, Current2;
	double SumCoef;
	Previous1 = Current1 = pFirst;
	Previous2 = Current2 = op2.pFirst;
	if (Current1->getpnext() != pFirst && Current2->getpnext() != op2.pFirst)
	{
		Current1 = Current1->getpnext();
		Current2 = Current2->getpnext();
		while (Current2->getdeg() != -1)
		{
			if (Current1->getdeg() > Current2->getdeg())
			{
				Previous1 = Current1;
				Current1 = Current1->getpnext();
			}
			else
				if (Current1->getdeg() < Current2->getdeg())
				{
					Previous1->setpnext(Current2);
					Previous2->setpnext(Current2->getpnext());
					Current2->setpnext(Current1);
					Previous1 = Current2;
					Current2 = Previous2->getpnext();
				}
				else
				{
					SumCoef = Current1->getcoef() + Current2->getcoef();
					if (SumCoef)
					{
						Current1->setcoef(SumCoef);
						Previous1 = Current1;
						Current1 = Current1->getpnext();
					}
					else
					{
						Current1 = Current1->getpnext();
						DelMonom(Current2->getdeg());
					}
					Previous2 = Current2;
					Current2 = Current2->getpnext();
				}
		}
	}
	else
		if (Current1->getpnext() == pFirst && Current2->getpnext() != op2.pFirst)
		{
			while (Previous2->getpnext() != pFirst)
				Previous2 = Previous2->getpnext();
			Previous2->setpnext(pFirst);
			pFirst->setpnext(op2.pFirst->getpnext());
			op2.pFirst->setpnext(op2.pFirst);
		}
}
istream& operator >> (istream &is, TPolinom &pol)
{
	int i, choise = 1, degX, degY, degZ, deg;
	double coef;
	do {
		cout << "Input the coefficient before monomial: ";
		do { is >> coef; } while (coef == 0);
		cout << "Input the degree of X: ";
		do { is >> degX; } while (degX < 0 || degX > 9);
		cout << "Input the degree of Y: ";
		do { is >> degY; } while (degY < 0 || degY > 9);
		cout << "Input the degree of Z: ";
		do { is >> degZ; } while (degZ < 0 || degZ > 9);
		deg = degX * 100 + degY * 10 + degZ;
		pol.InsMonom(coef, deg);
		cout << "If you want to add more, press 1. If not - 0;" << endl;
		is >> choise;
	} while (choise != 0);
	return is;
};
