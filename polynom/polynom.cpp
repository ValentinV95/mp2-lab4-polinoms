#include "polynom.h"

Polynom::Polynom()
{
	head = NULL;
}

Polynom::Polynom(const Polynom& a) : Polynom()
{
	Monom* temp = a.head;
	while (temp != NULL)
	{
		insert(temp->coef, temp->exp);
		temp = temp->next;
	}
}

Polynom::Polynom(vector <pair<double, unsigned int>> a)
{
	for (auto it = a.begin();it != a.end();it++)
	{
		insert(it->first, it->second);
	}
}

Polynom::~Polynom()
{
	clear();
}

Monom* Polynom::find_monom(double coef_, unsigned int exp_) const
{
	if (abs(coef_) < EPS)
	{
		return NULL;
	}
	if (exp_ > 999)
	{
		throw (string)"Incorrect exponent";
	}
	else
	{
		Monom* temp = head;
		while (temp != NULL)
		{
			if (abs(temp->coef - coef_) < EPS && temp->exp == exp_)
			{
				return temp;
			}
			else
			{
				temp = temp->next;
			}
		}
		return NULL;
	}
}

bool Polynom::isEmpty() const
{
	return head == NULL;
}

bool Polynom::find(double coef_,unsigned int exp_) const
{
	return find_monom(coef_, exp_) != NULL;
}

void Polynom::insert(double coef_, unsigned int exp_) 
{
	if (abs(coef_) < EPS)
	{
		return;
	}
	if (exp_ > 999)
	{
		throw (string)"Incorrect exponent";
	}
	if (head == NULL)
	{
		Monom* temp = new Monom();
		temp->coef = coef_;
		temp->exp = exp_;
		temp->prev = NULL;
		temp->next = NULL;
		head = temp;
	}
	else
	{
		Monom* temp = head;
		while (temp->next != NULL && temp->exp < exp_)
		{
			temp = temp->next;
		}
		if (temp->exp == exp_)
		{
			if (abs(temp->coef + coef_) < EPS)
			{
				del(temp->coef, temp->exp);
			}
			else
			{
				temp->coef += coef_;
			}
			return;
		}
		if (temp->exp < exp_) // Вставка в конец : temp->next == NULL
		{
			temp->next = new Monom();
			temp->next->coef = coef_;
			temp->next->exp = exp_;
			temp->next->next = NULL;
			temp->next->prev = temp;
			return;
		}
		if (temp->exp> exp_)
		{
			if (temp->prev == NULL) // temp->prev == head
			{
				temp->prev = new Monom();
				temp->prev->coef = coef_;
				temp->prev->exp = exp_;
				temp->prev->next = temp;
				temp->prev->prev = NULL;
				head = temp->prev;
			}
			else
			{
				temp->prev->next = new Monom();
				temp->prev->next->coef = coef_;
				temp->prev->next->exp = exp_;
				temp->prev->next->next = temp;
				temp->prev->next->prev = temp->prev;
				temp->prev = temp->prev->next;
				return;
			}
		}
	}
}

void Polynom::del(double coef_, unsigned int exp_) 
{
	if (abs(coef_) < EPS)
	{
		return;
	}
	if (exp_ > 999)
	{
		throw (string)"Incorrect exponent";
	}
	if (find(coef_, exp_))
	{
		Monom* temp = find_monom(coef_, exp_);
		if (temp->prev != NULL && temp->next != NULL)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			return;
		}
		if (temp->prev == NULL && temp->next != NULL)
		{
			head = temp->next;
			temp->next->prev = NULL;
			delete temp;
			return;
		}
		if (temp->prev != NULL && temp->next == NULL)
		{
			temp->prev->next = NULL;
			delete temp;
			return;
		}
		if (temp->prev == NULL && temp->next == NULL)
		{
			head = NULL;
			delete temp;
			return;
		}
	}
	else
	{
		return;
	}
}

void Polynom::clear()
{
	while (head != NULL)
	{
		del(head->coef, head->exp);
	}
}

Polynom& Polynom::operator = (const Polynom& a)
{
	if (head != a.head)
	{
		clear();
		Monom* temp = a.head;
		while (temp != NULL)
		{
			insert(temp->coef, temp->exp);
			temp = temp->next;
		}
	}
	return *this;
}

bool Polynom::operator == (const Polynom& a) 
{
	if (head == a.head)
	{
		return true;
	}
	else
	{
		Monom* temp_1 = head;
		Monom* temp_2 = a.head;
		while (temp_1 != NULL && temp_2 != NULL)
		{
			if (abs(temp_1->coef - temp_2->coef) > EPS || temp_1->exp != temp_2->exp)
			{
				return false;
			}
			temp_1 = temp_1->next;
			temp_2 = temp_2->next;
		}
		if (temp_1 != NULL || temp_2 != NULL)
		{
			return false;
		}
		else
		{
			return true;
		}		
	}
}

bool Polynom::operator != (const Polynom& a) 
{
	return !((*this) == a);
}

Polynom Polynom::operator + (const Polynom& a) 
{
	Polynom* b = new Polynom();
	Monom* temp_1 = head;
	Monom* temp_2 = a.head;
	while (temp_1 != NULL && temp_2 != NULL)
	{
		if (temp_1->exp < temp_2->exp)
		{
			b->insert(temp_1->coef, temp_1->exp);
			temp_1 = temp_1->next;
			continue;
		}
		if (temp_1->exp > temp_2->exp)
		{
			b->insert(temp_2->coef, temp_2->exp);
			temp_2 = temp_2->next;
			continue;
		}
		if (temp_1->exp == temp_2->exp)
		{
			if (abs(temp_1->coef + temp_2->coef) > EPS)
			{
				b->insert(temp_1->coef + temp_2->coef, temp_1->exp);
			}
			temp_1 = temp_1->next;
			temp_2 = temp_2->next;
			continue;
		}
	}
	if (temp_1 != NULL)
	{
		while (temp_1 != NULL)
		{
			b->insert(temp_1->coef, temp_1->exp);
			temp_1 = temp_1->next;
		}
	}
	if (temp_2 != NULL)
	{
		while (temp_2 != NULL)
		{
			b->insert(temp_2->coef, temp_2->exp);
			temp_2 = temp_2->next;
		}
	}
	return *b;
}

Polynom Polynom::operator - (const Polynom& a) 
{
	Polynom* b = new Polynom(); // Проблемы с константным идентификатором.
	*b = a;
	return *this + *b * (-1.0);
}

Polynom Polynom::operator * (double multiplier) 
{
	if (head != NULL)
	{
		Monom* temp = head;
		while (temp != NULL)
		{
			if (abs(temp->coef* multiplier) < EPS)
			{
				del(temp->coef, temp->exp);
			}
			else
			{
				temp->coef *= multiplier;
			}
			temp = temp->next;
		}
	}
	return *this;
}

Polynom Polynom::operator * (const Polynom& a)
{
	Polynom* b = new Polynom();
	Monom* temp_1 = head;
	Monom* temp_2 = a.head;
	unsigned int remainder_1,remainder_2,num_1,num_2;
	while (temp_1 != NULL)
	{
		while (temp_2 != NULL)
		{
			num_1 = temp_1->exp;
			num_2 = temp_2->exp;
			for (int i = 0;i < 3;i++)
			{
				remainder_1 = num_1 % 10;
				remainder_2 = num_2 % 10;
				num_1 /= 10;
				num_2 /= 10;
				if (remainder_1 + remainder_2 >= 10)
				{
					throw (string)"Multiplication overflow";
				}
			}
			b->insert(temp_1->coef * temp_2->coef, temp_1->exp + temp_2->exp);
			temp_2 = temp_2->next;
		}
		temp_1 = temp_1->next;
		temp_2 = a.head;
	}
	return *b;
}

ostream& operator << (ostream& os, const Polynom& output)
{
	Monom* temp = output.head;
	vector <unsigned int> t(3);
	unsigned int num;
	while (temp != NULL)
	{
		num = temp->exp;
		for (int i = 0;i < 3;i++)
		{
			t[2 - i] = num % 10;
			num /= 10;
		}
		cout << temp->coef << "x^" << t[0] << "y^" << t[1] << "z^" << t[2] << " ";
		if (temp->next != NULL)
		{
			if (temp->next->coef > 0)
			{
				cout << " + ";
			}
		}
		temp = temp->next;
	}
	return os;
}

istream& operator >> (istream& is, Polynom& input)
{
	unsigned int exp,num;
	double coef;
	cout << "Enter amount of monoms: ";
	is >> num;
	for (int i = 0;i < num;i++)
	{
		cout << "Enter monom's coefficient: ";
		is >> coef;
		cout << "Enter monom's exponent: ";
		is >> exp;
		input.insert(coef, exp);
	}
	return is;
}



