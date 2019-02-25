
#include "List.h"

Poly::Poly()
{
	Mon*n = new Mon;
	n->coef = 0.0;
	n->next = NULL;
	n->prev = NULL;
	n->pow = -1;
	head = n;
}
Poly::Poly(const Poly &A):Poly()
{
	Mon*temp = A.head->next;
	while (temp != NULL) {
		Insert(temp->coef, temp->pow);
		temp = temp->next;
	}
}

Poly::~Poly()
{
	while (head->next != NULL)
		Del(head->next->pow);
	delete head;
}
Poly::Poly(double* cf, int* pow, int size):Poly()
{
	for (int i = 0; i < size; i++)
	{
		if ((pow[i] > 0) && (pow[i] <= 999))
			Insert(cf[i], pow[i]);
		else
			throw("Uncorrect pow");
	}
}


void Poly::Insert(double icoef, int ipow)
{
	if ((ipow < 0) || (ipow>999))
		throw ("Uncorrect pow");
	else if (abs(icoef) > MAXC)
		throw("Very big coef");
	else
	{
		if (head->next == NULL)
		{
			Mon*n = new Mon;
			n->coef = icoef;
			n->next = NULL;
			n->prev = head;
			n->pow = ipow;
			head->next = n;
		}
		else
		{
			Mon*temp = head;
			while ((temp->next != NULL) && (temp->next->pow < ipow)) 
				temp = temp->next;
			if (temp->next != NULL)
			{
				if (temp->next->pow != ipow)
				{
					Mon*n1 = new Mon;
					n1->coef = icoef;
					n1->next = temp->next;
					n1->prev = temp;
					n1->pow = ipow;
					temp->next->prev = n1;
					temp->next = n1;
				}
				else 
				{
					if (abs(temp->next->coef + icoef) < MAXC)
						temp->next->coef += icoef;
					else throw ("Summ of coefs more than maximum");
						
				}
			}
			else 
			{
				Mon*n1 = new Mon;
				n1->coef = icoef;
				n1->next = NULL;
				n1->prev = temp;
				n1->pow = ipow;
				temp->next = n1;
			}
		}
	}
}

void Poly::Del(int ipow)
{
	if ((ipow > 0) && (ipow < 999) && (head->next!=NULL))
	{
		Mon*temp = head->next;
		while ((temp->next != NULL) && (temp->pow != ipow))
			temp = temp->next;
		if (temp->pow == ipow)
		{
			if (temp->next != NULL)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			if (temp->next == NULL)
				temp->prev->next = NULL;
			delete temp;
		}

	}
	else throw ("You choose wrong nuber or use empty list");
}
Poly& Poly::operator=(const  Poly& A)
{
	if (head != A.head)
	{
		while (head->next != NULL)
			Del(head->next->pow);
		Mon*temp = A.head->next;
		while (temp != NULL)
		{
			Insert(temp->coef, temp->pow);
			temp = temp->next;
		}
	}
	return *this;

}
bool Poly::operator==(const Poly& A) const
{
	Mon* pt1 = head->next;
	Mon* pt2 = A.head->next;
	while ((pt1 != NULL) || (pt2 != NULL))
	{
		if ((pt1->coef != pt2->coef) || (pt1->pow != pt2->pow))
			return false;
		pt1 = pt1->next;
		pt2 = pt2->next;
	}
	if ((pt1 != NULL) || (pt2 != NULL))
		return false;
	return true;

}

Poly Poly::operator*(double c)
{
	Poly Con(*this);
	Mon*temp = Con.head->next;
	while (temp != NULL)
	{
		temp->coef = temp->coef*c;
		temp = temp->next;
	}
	return Con;
}
Poly Poly::operator+(Poly & A)
{
	Poly Con;
	Mon*pt1 = head->next;
	Mon*pt2 = A.head->next;
	while ((pt1 != NULL) && (pt2 != NULL))
	{
		if (pt1->pow < pt2->pow) 
		{
			Con.Insert(pt1->coef, pt1->pow);
			pt1 = pt1->next;
		}
		else
		{
			Con.Insert(pt2->coef, pt2->pow);
			pt2 = pt2->next;
		}
	}

	while (pt1 != NULL)
	{
		Con.Insert(pt1->coef, pt1->pow);
		pt1 = pt1->next;
	}
	while (pt2 != NULL)
	{
		Con.Insert(pt2->coef, pt2->pow);
		pt2 = pt2->next;
	}
	return Con;
}
Poly Poly::operator-(Poly & A)
{
	Poly C;
	C = (*this) + A*(-1);
	return C;
}
Poly Poly::operator*(Poly & A)
{
	int d1, d2, d3, sum;
	Poly Con;
	Mon*pt1 = head->next;
	Mon*pt2 = A.head->next;
	while (pt1 != NULL)
	{
		d1=(int)pt1->pow/ 100 + (int)pt1->pow % 100 / 10 + (int)pt1->pow % 10;
		Mon*pt2 = A.head->next;

		while (pt2 != NULL)
		{
			d2 = (int)pt2->pow / 100 + (int)pt2->pow % 100 / 10 + (int)pt2->pow % 10;
			sum = (int)(pt1->pow+pt2->pow) / 100 + (int)(pt1->pow+pt2->pow) % 100 / 10 + (int)(pt1->pow+pt2->pow) % 10;
			d3 = d1 + d2;
			if (d3 == sum)
				Con.Insert((pt1->coef)*(pt2->coef), (pt1->pow) + (pt2->pow));
			else throw ("wrong monom pow");
			pt2 = pt2->next;
		}
		pt1 = pt1->next;
	}
	return Con;
}
ostream& operator<<(ostream& out, Poly &A)
{
	bool fl = false;
	int x, y, z, pow;
	Mon*temp = A.head->next;
	while (temp != NULL)
	{
		pow = temp->pow;
		z = pow % 10;
		y = pow % 100/10;
		x = pow/100;
		out << (double)temp->coef;
		if (x != 0)
			out << "x^" << x;
		if (y != 0)
			out << "y^" << y;
		if (z != 0)
			out << "z^" << z;
		if (temp->next != NULL)
			out << "+";
		temp = temp->next;
		fl = true;
	}
	if (!fl)
		out << "0";
	return out;
}

