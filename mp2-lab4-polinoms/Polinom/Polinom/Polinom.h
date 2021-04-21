#pragma once

#include "List.h"
#include "Monom.h"
#include <string>

// Класс "многочлен"
class Polynom{
private:
	List<Monom>* monoms;

public:

	Polynom() {
		monoms = new List<Monom>();
	}

	Polynom(const List<Monom>& _monoms) {
		this->monoms = new List<Monom>(_monoms);
	}

	List<Monom>* getMonoms() {
		return monoms;
	}

	void addMonom(const Monom& m) {
		monoms->pushBack(m);
	}

	// Перегрузка арифметических операторов


	Polynom operator+(const Polynom& rv) const {
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
		return c;
	}

	Polynom operator*(double constant) {
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
			return b;
		}
		else
			return Polynom();
	}

	Polynom operator-(const Polynom& rv) {
		Polynom c = this + (rv * -1.0);
	}

	Polynom operator*(const Polynom& rv);

	// Перегрузка оператора потокового вывода
	friend std::ostream& operator<<(std::ostream& os, const Polynom& p);

	// Текстовое представление многочлена
	std::string to_string();
};