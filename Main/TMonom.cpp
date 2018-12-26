#include <iostream>
#include "TMonom.h"
using namespace std;
TMonom::TMonom(double _coef, int _deg, pMonom _pnext)
{
	coef = _coef;
	deg = _deg;
	pnext = _pnext;
}
double TMonom::getcoef() const
{
	return coef;
}
int TMonom::getdeg() const
{
	return deg;
}
pMonom TMonom::getpnext() const
{
	return pnext;
}
void TMonom::setcoef(double c)
{
	coef = c;
}
void TMonom::setdeg(int d)
{
	deg = d;
}
void TMonom::setpnext(pMonom pn)
{
	pnext = pn;
};
