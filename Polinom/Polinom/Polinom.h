#pragma once

#include "List.h"
#include "Monom.h"
#include <string>

#define EPS 1E-15

bool isMulty(unsigned short int a, unsigned short int b) {
	if (a < 0 || a > 999)
		throw std::exception("a must be 0 < a < 999");

	if (b < 0 || b > 999)
		throw std::exception("b must be 0 < b < 999");

	if (a > 9 && a < 99)
		b = b % 100;
	else if (a < 9)
		b = b % 10;

	while (a > 0)
	{
		if (a % 10 + b % 10 > 9)
			return false;
		a = a / 10;
		b = b / 10;
	}

	return true;
}

class Polynom {
private:
	List<Monom>* monoms;

	void arrange()
	{
		monoms->sort();
	}

	void castingSimilarTerms()
	{
		arrange();
		Node<Monom>* a = monoms->getHead();
		if (a != nullptr)
			while (a->next != nullptr)
			{
				Node<Monom>* b = a->next;
				if (a->data.getDegs() == b->data.getDegs())
				{
					a->data.setCoeff(a->data.getCoeff() + b->data.getCoeff());
					if (b == this->monoms->getTail())
					{
						b = b->prev;
						b->next = nullptr;
					}
					else
					{
						b->prev->next = b->next;
						b->next->prev = b->prev;
					}
				}
				a = b;
			}

		a = monoms->getHead();
		// Удаление возникших нулей (если есть только ноль, то не удаляется)
		while (a != nullptr)
		{
			if (abs(a->data.getCoeff()) < EPS)
			{
				// Если голова
				if (a == this->monoms->getHead())
				{
					if (a->next == nullptr)
						break;
					a = a->next;
					a->prev = nullptr;
				}
				// Если хвост
				else if (a == this->monoms->getTail())
				{
					a = a->prev;
					a->next = nullptr;
				}
				// Иначе
				else
				{
					a->prev->next = a->next;
					a->next->prev = a->prev;
				}
			}
			a = a->next;
		}
	}

public:

	Polynom() {
		monoms = new List<Monom>();
	}

	Polynom(const List<Monom>& _monoms) {
		this->monoms = new List<Monom>(_monoms);
	}

	Polynom(std::string s)
	{
		monoms = new List<Monom>();
		
		
	}

	List<Monom>* getMonoms() {
		return monoms;
	}

	void addMonom(const Monom& m) {
		monoms->pushBack(m);
	}

	// Перегрузка арифметических операторов


	Polynom operator+(const Polynom& rv) {
		Node<Monom>* a = monoms->getHead(),
			* b = rv.monoms->getHead();
		Polynom c;

		while (a != nullptr && b != nullptr)
		{
			if (a->data > b->data)
			{
				c.addMonom(a->data);
				a = a->next;
			}
			else if (a->data < b->data)
			{
				c.addMonom(b->data);
				b = b->next;
			}
			else // Если равны
			{
				double cCoeff = a->data.getCoeff() + b->data.getCoeff();
				if (cCoeff != 0)
					c.addMonom(Monom(cCoeff, a->data.getDegs()));
				a = a->next;
				b = b->next;
			}
		}
		c.castingSimilarTerms();
		return c;
	}

	Polynom operator-(const Polynom& rv) {
		Node<Monom>* a = monoms->getHead(),
			* b = rv.monoms->getHead();
		Polynom c;

		while (a != nullptr && b != nullptr)
		{
			if (a->data > b->data)
			{
				c.addMonom(a->data);
				a = a->next;
			}
			else if (a->data < b->data)
			{
				c.addMonom(b->data);
				b = b->next;
			}
			else // Если равны
			{
				double cCoeff = a->data.getCoeff() - b->data.getCoeff();
				if (cCoeff != 0)
					c.addMonom(Monom(cCoeff, a->data.getDegs()));
				a = a->next;
				b = b->next;
			}
		}
		c.castingSimilarTerms();
		return c;
	}

	Polynom operator*(const double constant) {
		Node<Monom>* a = this->getMonoms()->getHead();
		Polynom b;
		if (constant != 0)
		{
			while (a != nullptr)
			{
				b.addMonom(Monom(a->data.getCoeff() * constant,
					a->data.getDegs()));
				a = a->next;
			}
			b.castingSimilarTerms();
			return b;
		}
		else
			return Polynom();
	}

	Polynom operator*(const Polynom& rv) {
		Node<Monom>* a = this->monoms->getHead();
		Polynom c;

		while (a != nullptr)
		{
			Node<Monom>* b = rv.monoms->getHead();
			while (b != nullptr)
			{
				if (!isMulty(a->data.getDegs(), b->data.getDegs()))
					throw std::overflow_error("Overflow!");
				c.addMonom(Monom(a->data.getCoeff() * b->data.getCoeff(),
					a->data.getDegs() + b->data.getDegs()));
				b = b->next;
			}
			a = a->next;
		}

		c.castingSimilarTerms();
		return c;
	}

	friend std::ostream& operator<<(std::ostream& os, const Polynom& p)
	{
		Node<Monom>* i = p.monoms->getHead();
		if (i != nullptr) 
			while (i->next != nullptr)
			{
				i = i->next;
			}
		else
			os << 0;
		if (i != nullptr)
			os << i->data;
		return os;
	}

	
};