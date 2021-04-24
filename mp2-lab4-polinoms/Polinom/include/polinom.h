

class Monom
{
public:
	unsigned short int deg; // max width = 1000
	double coefficient;

	Monom() {}

	Monom(const unsigned short int _deg, double coef)
	{
		this->deg = _deg;
		this->coefficient = coef;
	}
};

class Polinom
{
private:
	Monom *head;

public:
	Polinom() {}
};