#pragma once
#ifndef _TPOLINOM_H
#define _TPOLINOM_H
#include <iostream>
#include "TMonom.h"
using namespace std;
const double EPS = 0.00000001;
class TPolinom
{
protected:
	pMonom pFirst;
public:
	TPolinom();
	void InsMonom(double coef, int deg);
	int DelMonom(int deg);
	void Transformation();
	TPolinom SUMMA1(TPolinom &op2);
	void SUMMA2(TPolinom &op2);
	friend istream& operator >> (istream &is, TPolinom &pol);
};
#endif



