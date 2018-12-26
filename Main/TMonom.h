#pragma once
#ifndef _TMONOM_H
#define _TMONOM_H
#include <iostream>
using namespace std;
class TMonom;
typedef TMonom* pMonom;
class TMonom
{
protected:
	double coef;
	int deg;
	pMonom pnext;
public:
	TMonom(double _coef = 1, int _deg = 0, pMonom _pnext = NULL);
	double getcoef() const;
	int getdeg() const;
	pMonom getpnext() const;
	void setcoef(double co);
	void setdeg(int de);
	void setpnext(pMonom pn);
};
#endif



