#include"pol.h"
#include <iostream>
using namespace std;
double eps = 0.00000000001;
	List::List()
	{
		n = 0;
		head = NULL;
		tail = head;
	}
	bool List::Isempty()
	{
		return(head == NULL);
	}

	void List::Insert_end(int val1, double val2)
	{
		n++;
		Node* c = new Node();
		c->p = val1;
		c->c = val2;
		c->next = NULL;
		if (Isempty())
			head = c;
		else
			tail->next = c;
		tail = c;

	}
	void List::Insert_begin(int val1, double val2)
	{
		n++;
		Node* tmp = new Node();
		tmp->p = val1;
		tmp->c = val2;
		tmp->next = head;
		if (head == NULL)
			tail = tmp;
		head = tmp;
	}
	void  List::Del(int k)
	{
		Node* f = head;
		Node*b = head;
		if (head == nullptr)
			return;

		if (head->p == k)
		{
			head = head->next;
			n--;
			return;
		}
		while (f->next != NULL)
		{
			if (f->next->p == k)
			{
				b = f->next;
				f->next = f->next->next;
				delete b;
				n--;
				break;
			}
			f = f->next;
		}
		b = head;
		while ((b != NULL) && (b->next != NULL))
			b = b->next;
		tail = b;
	}
	void List::Print(int k)
	{
		if (k >= n) {
			std::cout << "Large number" << std::endl;
			return;
		}
		Node* c = head;
		for (int i = 0; i < k; i++)
			c = c->next;
		std::cout << c->c << '(' << c->p << ')';
	}
	List List::operator=(List a)
	{
		head = a.head;
		tail = a.tail;
		n = a.n;
		return(*this);
	}


	pol::pol()
	{
		a.n = 0;
		a.head = NULL;
		a.tail = a.head;
	}
	pol::pol(List b)
	{
		a = b;
	}
	pol pol::operator=(pol b)
	{
		a = b.a;
		return(*this);
	}
	pol::pol(int pow, double c)
	{
		a.Insert_begin(pow, c);
	}
	pol& pol::Mull(double k)
	{
		pol b;
		b = (*this);
		Node* tmp = b.a.head;
		while (tmp->next != NULL)
		{
			tmp->c *= k;
			tmp = tmp->next;
		}
		tmp->c *= k;
		b.DelDups();
		b.DelZero();
		return(b);
	}
	void pol::DelDups()
	{
		int k;
		Node* tmp = a.head;
		Node* tmp1;
		while (tmp->next != NULL)
		{
			//cout << 'e' << endl;
			tmp1 = tmp->next;
			while (tmp1 != NULL)
			{
				k = 0;
				if (tmp->p == tmp1->p)
				{
					tmp1->c += tmp->c;
					k = tmp->p;
					tmp = tmp->next;
					//cout << k << endl;
					a.Del(k);
					break;
				}
				tmp1 = tmp1->next;
			}
			//cout << k << endl;
			if (!k)
				tmp = tmp->next;
		}
	}
	void pol::DelZero()
	{
		int k = 0;
		Node* tmp = a.head;
		Node* tmp1 = tmp;
		while (tmp1->next != NULL)
		{
			if (abs(tmp1->c) < eps)
				k++;
			tmp1 = tmp1->next;
		}
		if (abs(tmp1->c) < eps)
			k++;
		while ((a.head != NULL) && (abs(a.head->c) < eps))
		{
			a.head = a.head->next;
			a.n--;
			k--;
		}
		while (k != 0)
		{

			tmp = a.head;

			while ((tmp != NULL) && (tmp->next != NULL))
			{
				if (abs(tmp->next->c) < eps)
				{
					a.n--;
					k--;
					tmp->next = tmp->next->next;
					break;
				}
				tmp = tmp->next;
			}
		}
		tmp = a.head;
		while ((tmp != NULL) && (tmp->next != NULL))
			tmp = tmp->next;
		a.tail = tmp;
	}
	pol& pol::operator+(pol b)
	{

		Node* tmp1 = a.head;
		Node* tmp2 = b.a.head;
		a.tail->next = b.a.head;
		a.tail = b.a.tail;

		a.n += b.a.n;
		DelDups();
		DelZero();
		return(*this);
	}
	pol& pol::operator*(pol b)
	{
		pol c;
		Node* tmp1 = a.head;
		Node* tmp2 = b.a.head;
		while (tmp1->next != NULL)
		{
			tmp2 = b.a.head;
			while (tmp2->next != NULL)
			{
				if ((((tmp1->p) / 100 + (tmp2->p) / 100) > 9) || ((((tmp1->p) % 100) / 10 + ((tmp2->p) % 100) / 10) > 9) || (((tmp1->p) % 10 + (tmp2->p) % 10) > 9))
					throw "Incorrect power";
				c.a.Insert_end(tmp1->p + tmp2->p, tmp1->c*tmp2->c);
				tmp2 = tmp2->next;
			}
			if ((((tmp1->p) / 100 + (tmp2->p) / 100) > 9) || ((((tmp1->p) % 100) / 10 + ((tmp2->p) % 100) / 10) > 9) || (((tmp1->p) % 10 + (tmp2->p) % 10) > 9))
				throw "Incorrect power";
			c.a.Insert_end(tmp1->p + tmp2->p, tmp1->c*tmp2->c);
			tmp1 = tmp1->next;
		}
		tmp2 = b.a.head;
		while (tmp2->next != NULL)
		{
			if ((((tmp1->p) / 100 + (tmp2->p) / 100) > 9) || ((((tmp1->p) % 100) / 10 + ((tmp2->p) % 100) / 10) > 9) || (((tmp1->p) % 10 + (tmp2->p) % 10) > 9))
				throw "Incorrect power";
			c.a.Insert_end(tmp1->p + tmp2->p, tmp1->c*tmp2->c);
			tmp2 = tmp2->next;
		}
		if ((((tmp1->p) / 100 + (tmp2->p) / 100) > 9) || ((((tmp1->p) % 100) / 10 + ((tmp2->p) % 100) / 10) > 9) || (((tmp1->p) % 10 + (tmp2->p) % 10) > 9))
			throw "Incorrect power";
		c.a.Insert_end(tmp1->p + tmp2->p, tmp1->c*tmp2->c);
		c.DelDups();
		c.DelZero();
		return(c);
	}
	pol& pol::operator-(pol b)
	{
		pol c;
		c = b;
		c.Mull(-1);
		return(*this + c);
	}