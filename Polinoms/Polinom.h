#pragma once
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

struct Monom
{
	double coeff;
	int deg;
	Monom() {};
	void init(double a, int b)
	{
		if ((b > 999) || (b < 0))
			throw "impossible create monom with deg>999 or deg<0";
		else
		{
			coeff = a;
			deg = b;
		}
	}
	Monom operator +(const Monom& a)
	{
		if (this->deg==a.deg) 
		{
			Monom res;
			res.init(this->coeff + a.coeff, this->deg);
			return res;
		}
		else throw"impossible add monom with not equal deg";
	}
	Monom operator *(const Monom& m)
	{
		Monom res;
		int a, b, c;
		res.coeff = this->coeff*m.coeff;
		res.deg = this->deg + m.deg;

		a = deg / 100 + m.deg / 100;
		b = deg % 100 / 10 + m.deg % 100 / 10;
		c = deg % 10 + m.deg % 10;
		/*невалидное значение степени, показывающее что при умножении мономов получено некорректное значение степени*/
		if ((a > 9) || (b > 9) || (c > 9))
			res.deg = 1000;
		return res;
	}
	bool operator !=(Monom a)
	{
		if (a == *this)
			return false;
		else return true;
	}
	//операторы >=, >,< для монома перегружены относительно степени
	bool operator ==(const Monom& a)const
	{
		if (a.deg == deg)
			return true;
		else return false;
	}
	bool operator >=(Monom a)
	{
		if (deg >= a.deg)
			return true;
		else return false;
	}
	bool operator >(Monom a)
	{
		if (deg > a.deg)
			return true;
		else return false;
	}
	bool operator <(Monom a)
	{
		if (deg < a.deg)
			return true;
		else return false;
	}
};

class Polinom 
{
private:
	List<Monom> P;
	friend class List<Monom>;
public:
	//Конструктор без параметров
	Polinom();
	//Деструктор
	~Polinom();
	//Конструтор копирования
	Polinom(const Polinom & A);
	//Инициализация полинома
	void init(Monom M);
	//Ввод полинома пользователем
	void Input();
	//Вывод полинома на консоль
	void Print();
	//Приведение подобных
	void Delete_Similar();
	//Старшая степень полинома
	int Highest_Degree();
	//логический оператор тождества
	bool operator ==(const Polinom& A) const;
	//Оператор присваивания полиномов 
	Polinom& operator =(const Polinom& A);
	//Оператор сложения полиномов
	Polinom operator +(const Polinom& A);
	//Оператор умножения полинома на число
	Polinom operator *(double q);
	//Оператор вычитания
	Polinom operator -(Polinom& A);
	//Оператор умножения полиномов
	Polinom operator *(Polinom& A);
};

