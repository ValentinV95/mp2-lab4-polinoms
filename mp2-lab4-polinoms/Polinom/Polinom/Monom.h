#pragma once
#include <iostream>

class Monom {
private:
	double coeff; //Коэффициент монома
	unsigned short int degs; //Степени от 0 до 999
public:
	Monom() {
		this->coeff = 0;
		this->degs = 0;
	}

	Monom(const double _coeff, const unsigned short int _degs) {
		this->coeff = _coeff;
		this->degs = _degs;
	}

	double getCoeff() {
		return coeff;
	}

	unsigned short int getDegs() {
		return degs;
	}

	void setCoeff(const double value) {
		this->coeff = value;
	}

	void setDegs(const unsigned short int value) {
		this->degs = value;
	}

	bool operator< (const Monom& v) {
		return v.degs < this->degs;
	}

	bool operator> (const Monom& v) {
		return v.degs > this->degs;
	}
	bool operator== (const Monom& v) {
		return v.degs == this->degs;
	}

	friend std::ostream& operator<<(std::ostream& os, Monom& m)
	{
		// Вывод коэффициента (если все степени нулевые, выводится только коэффициент)
		os << m.getCoeff();

		if (m.getDegs() != 0)
		{
			os << " * ";

			// Получение степеней x, y, z
			unsigned short int degs = m.getDegs();
			unsigned short int x = degs / 100;
			unsigned short int y = (degs / 10) % 10;
			unsigned short int z = degs % 10;

			if (x == 1)
				os << "x";
			else if (x > 1)
				os << "x^" << x;

			if (x > 0 && (y > 0 || z > 0))
				os << "*";

			if (y == 1)
				os << "y";
			else if (y > 1)
				os << "y^" << y;

			if (y > 0 && z > 0)
				os << "*";

			if (z == 1)
				os << "z";
			else if (z > 1)
				os << "z^" << z;
		}

		return os;
	}
};