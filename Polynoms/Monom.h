#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
class Monom;
typedef Monom* Link; //указатель на моном
class Monom {
	int power; //степень
	int cf;    //коэффициент 
	Link pointer;   //указатель на след.моном
public:
	Monom(int _power = 0, int _cf = 0, Link _pointer = NULL) // конструктор инициализации
	{
		power = _power;
		cf = _cf;
		pointer = _pointer;
	}
	void SetPower(int _power)//установка степени
	{
		power = _power;
	}
	void SetCf(int _cf) //установка коэф
	{
		cf = _cf;
	}
	void SetPointer(Link _pointer) //установка указателя
	{
		pointer = _pointer;
	}
	int GetPower(void) const //получить степень 
	{
		return power;
	}
	int GetCf(void) const //получить коэф
	{
		return cf;
	}
	Monom* GetPointer(void) const  // получить след моном 
	{
		return pointer;
	}
};