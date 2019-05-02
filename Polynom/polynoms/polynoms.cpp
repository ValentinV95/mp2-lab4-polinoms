#include "Polynoms.h"
#define eps 0.00000001

Monom::Monom(double _coef, int _exp)
{
	if (_exp > 999 || _exp < 0) {
		throw (string)"Wrong monom exp";
	}
	coef = _coef;
	exp = _exp;
	next = nullptr;
}

Monom::Monom(double _coef, int _exp, Monom* _next)
{
	coef = _coef;
	exp = _exp;
	next = _next;
}

Monom::Monom(const Monom& monom)
{
	coef = monom.coef;
	exp = monom.exp;
	next = monom.next;
}

bool Monom::operator==(const Monom &right)
{
	if (exp == right.exp && abs(coef - right.coef) < eps) return true;
	else return false;
}

Polynom::Polynom()
{
	size = 0;
	head = nullptr;
}

Polynom::Polynom(const Polynom& polynom)
{
	head = polynom.head;
	size = polynom.size;
}

Polynom::~Polynom()
{
}

inline void Polynom::clear()
{
	while (size && head != nullptr) {
		pop_front();
	}
}

void Polynom::merge(const Polynom &pol)
{
	Polynom tmp;

	Monom *curr1 = (this)->head;
	Monom *curr2 = pol.head;

	while (curr1 != nullptr && curr2 != nullptr) {
		if (curr1->exp <= curr2->exp) {
			Monom newMonom(*curr1);
			newMonom.next = nullptr;
			tmp.push_back(newMonom);
			curr1 = curr1->next;
		}
		else {
			Monom newMonom(*curr2);
			newMonom.next = nullptr;
			tmp.push_back(newMonom);
			curr2 = curr2->next;
		}
	}
	while (curr1 != nullptr) {
		Monom newMonom(*curr1);
		newMonom.next = nullptr;
		tmp.push_back(newMonom);
		curr1 = curr1->next;
	}
	while (curr2 != nullptr) {
		Monom newMonom(*curr2);
		newMonom.next = nullptr;
		tmp.push_back(newMonom);
		curr2 = curr2->next;
	}
	*this = tmp;

	tmp.head = NULL;  
	tmp.size = 0;  

inline void Polynom::pop_front()
{
	Monom *tmp = head;
	head = head->next;
	delete tmp;
	size--;
}

inline void Polynom::push_front(Monom monom)
{
	head = new Monom(monom.coef, monom.exp, head);
	size++;
}

void Polynom::push_back(Monom monom)
{
	if (head == nullptr) {
		head = new Monom(monom);
	}
	else {
		Monom* curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = new Monom(monom);
	}
	size++;
}

void Polynom::insert(Monom monom)
{
	if (head == nullptr || head->exp > monom.exp) {
		push_front(monom);
		return;
	}

	Monom *curr = head;
	while (curr->next != nullptr && curr->next->exp <= monom.exp && curr->exp <= monom.exp) {
		curr = curr->next;
	}
	if (curr->exp == monom.exp) {
		curr->coef += monom.coef;
		if (abs(curr->coef) < eps) {
			del(*curr);
		}
		return;
	}
	Monom *newObject = new Monom(monom);
	newObject->next = curr->next;
	curr->next = newObject;
	size++;
}

void Polynom::insert(double coef, int exp)
{
	Monom monom(coef, exp);
	if (head == nullptr || head->exp > monom.exp) {
		push_front(monom);
		return;
	}

	Monom *curr = head;
	while (curr->next != nullptr && curr->next->exp <= monom.exp && curr->exp <= monom.exp) {
		curr = curr->next;
	}
	if (curr->exp == monom.exp) {
		curr->coef += monom.coef;
		if (abs(curr->coef) < eps) {
			del(*curr);
		}
		return;
	}
	Monom *newObject = new Monom(monom);
	newObject->next = curr->next;
	curr->next = newObject;
	size++;
}

void Polynom::del(Monom monom)
{
	Monom *curr = head;
	if (curr->exp == monom.exp && abs(curr->coef-monom.coef) < eps) {
		pop_front();
		return;
	}
	while (curr->next != nullptr && curr->next->exp != monom.exp) {
		curr = curr->next;
	}
	Monom *tmp = curr->next->next;
	delete curr->next;
	curr->next = tmp;
	size--;
}

bool Polynom::find(double coef, int exp)
{
	Monom *curr = head;
	Monom a(coef, exp);
	while (curr != nullptr) {
		if (*curr == a) {
			return true;
		}
		curr = curr->next;
	}
	return false;
}

Polynom Polynom::operator*(const double &val) const
{
	Polynom tmp;
	Monom *a = this->head;
	while (a != nullptr) {
		tmp.insert(a->coef, a->exp);
		a = a->next;
	}
	Monom *temp = tmp.head;
	while (temp != NULL) {
		temp->coef = temp->coef * val;
		temp = temp->next;
	}
	return tmp;
}

const Polynom& Polynom::operator = (const Polynom &right)
{
	if (this->head != right.head) {
		clear();
		Monom *tmp = right.head;
		while (tmp != nullptr) {
			insert(tmp->coef, tmp->exp);
			tmp = tmp->next;
		}

	}
	return *this;
}

Polynom Polynom::operator + (const Polynom &right) const
{
	Polynom curr;
	Monom *thisHead = this->head;
	while (thisHead != nullptr) {
		curr.insert(thisHead->coef, thisHead->exp);
		thisHead = thisHead->next;
	}

	Monom *rightHead = right.head;
	while (rightHead != nullptr) {
		curr.insert(rightHead->coef, rightHead->exp);
		rightHead = rightHead->next;
	}
	return curr;
}

Polynom Polynom::operator * (const Polynom &right) 
{
	Polynom curr;
	Monom *f = head;
	Monom *s = right.head;
	while (f != NULL) {
		s = right.head;
		while (s != NULL) {
			int x, y, z;

			x = s->exp / 100 + f->exp / 100;
			y = s->exp / 10 % 10 + f->exp / 10 % 10;
			z = s->exp % 10 + f->exp % 10;

			if ((x > 9) || (y > 9) || (z > 9)) {
				throw (string)"Exp is higher than it can be";
			}

			double coef = s->coef * f->coef;
			int exp = x * 100 + y * 10 + z;
			curr.insert(coef, exp);

			s = s->next;
		}
		f = f->next;
	}
	return curr;
}

Polynom Polynom::operator-(Polynom & right)
{
	Polynom c = right * (-1.);
	return *this + c;
}

ostream& operator << (ostream& os, const Polynom& object)
{
	if (object.head == nullptr) {
		os << 0;
		return os;
	}
	Monom *temp = object.head;
	while (temp != NULL)
	{
		int x, y, z;
		x = temp->exp / 100;
		y = temp->exp / 10 % 10;
		z = temp->exp % 10;
		if (temp->coef > 0) {
			os << temp->coef << " ";
		}
		else {
			os << "(" << temp->coef << ") ";
		}
		if (x != 0) {
			os << "* x^" << x << " ";
		}
		if (y != 0) {
			os << "* y^" << y << " ";
		}
		if (z != 0) {
			os << "* z^" << z << " ";
		}
		if (temp->next != NULL) {
			os << "+ " << endl;
		}
		temp = temp->next;
	}
	return os;
}