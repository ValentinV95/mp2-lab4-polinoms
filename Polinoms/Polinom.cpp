#include "Polinom.h"

Polinom::Polinom()
{
}

Polinom::~Polinom()
{
}

Polinom::Polinom (const Polinom & A)
{
	Node<Monom>* temp = A.P.head;
	while (temp != nullptr)
	{
		this->P.Insert(temp->data);
		temp = temp->next;
	}
}

void Polinom::init(Monom M)
{
	if ((M.deg > 999)||(M.deg<0))
		throw "impossible create polinom with deg>999 or deg<0";
	else
	{
		this->P.Insert(M);
		this->Delete_Similar();
	}
}

void Polinom:: Input()
{
	int n, b = 1;
	double a;
	Monom m;
	cout << endl << "Please, enter the number of monoms" << endl;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "Please, enter the coefficient of monom" << endl;
		cin >> a;
		cout << "Please, enter monom degree" << endl;
		cin >> b;
		while ((b > 999) || (b < 0))
		{
			cout << "The value of the degree is incorrect.Please, enter again monom degree" << endl;
			cin >> b;
		}
		if (a != 0)
		{
			m.init(a, b);
			this->P.Insert(m);
		}
	}
	this->Delete_Similar();
}

void Polinom:: Print()
{
	Node<Monom>* temp = this->P.Root();
	if (P.Size()==0)
	{
		cout << 0;
	}
	else {
		while (temp != nullptr)
		{
			if (temp != this->P.Root())
			{
				if (temp->data.coeff > 0)
					cout << " +";
			}
			if(temp->data.coeff!=1)
				cout << temp->data.coeff<<"*";
			if (temp->data.deg / 100 != 0)
				cout << "x^" << temp->data.deg / 100;
			if (temp->data.deg % 100 / 10 != 0)
				cout << " y^" << temp->data.deg % 100 / 10;
			if (temp->data.deg % 10)
				cout << " z^" << temp->data.deg % 10;
			temp = temp->next;
		}
	}
}

void Polinom::Delete_Similar()
{
	Node<Monom>* t = this->P.head;
	Node<Monom>* t1 = t->next;
	while (t1 != nullptr)
	{
		if (t->data.deg == t1->data.deg)
		{

			this->P.MergerNode(t, t1);
			t1 = t->next;
		}
		else
		{
			t = t->next;
			t1 = t1->next;
		}
	}
}

int Polinom::Highest_Degree()
{
	return this->P.head->data.deg;
}

bool Polinom::operator == (const Polinom& A) const
{
	Node<Monom>* t2 = A.P.head;
	Node<Monom>* t1=this->P.head;
	if (A.P.size==this->P.size)
	{
		while (t1 != nullptr)
		{
			if (t1->data!=t2->data)
				return false;
			t1 = t1->next;
			t2 = t2->next;
		}
		return true;
	}
	else return false;
}

Polinom& Polinom::operator =(const Polinom& A)
{
	Node<Monom>* temp = A.P.head;
	while (temp != nullptr)
	{
		this->P.Insert(temp->data);
		temp = temp->next;
	}
	return *this;
}

Polinom Polinom:: operator +(const Polinom& A)
{
	Polinom B;
	Node<Monom>* t2 = A.P.head;
	Node<Monom>* t1 = this->P.head;
	Monom temp;
	while ((t1 != nullptr) && (t2 != nullptr))
	{
		if (t1->data > t2->data)
		{
			B.P.Insert(t1->data);
			t1 = t1->next;
		}
		else
		{
			if (t1->data.deg == t2->data.deg)
			{
				temp = t2->data + t1->data;
				if (temp.coeff != 0)
					B.P.Insert(t2->data + t1->data);
				t1 = t1->next;
				t2 = t2->next;
			}
			else
			{
				B.P.Insert(t2->data);
				t2 = t2->next;
			}
		}
	}
	if ((t1 == nullptr) && (t2 != nullptr))
	{
		while (t2 != nullptr)
		{
			B.P.Insert(t2->data);
			t2 = t2->next;
		}
	}
	if ((t1 != nullptr) && (t2 == nullptr))
	{
		B.P.Insert(t1->data);
		t1 = t1->next;
	}
	return B;
}

Polinom Polinom:: operator *(double q)
{
	Polinom B;
	Node<Monom>* temp = this->P.head;
	Monom a;
	if (q != 0)
	{
		while (temp != nullptr)
		{
			a = temp->data;
			a.coeff *= q;
			B.P.Insert(a);
			temp = temp->next;
		}
	}
	else
	{
		a.init(0, 0);
		B.P.Insert(a);
	}
	return B;
}

Polinom Polinom:: operator -(Polinom& A)
{
	Polinom B;
	B = *this + (A * -1);
	return B;
}

Polinom Polinom:: operator *(Polinom& A)
{
	Polinom B;
	Node<Monom>* t1 = this->P.head;
	Node<Monom>* t2;
	Monom a;
	while (t1 != nullptr)
	{
		a = t1->data;
		t2 = A.P.head;
		while (t2 != nullptr)
		{
			a = a * t2->data;
			B.P.Insert(a);
			t2 = t2->next;
			a = t1->data;
		}
		t1 = t1->next;
	}
	B.Delete_Similar();
	return B;
}