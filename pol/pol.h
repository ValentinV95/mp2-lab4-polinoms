
#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H
#include <iostream>
using namespace std;
double eps = 1e-15;
struct Node
{
	double c;
	int p;
	Node* next;

};
class List
{

public:
	Node* head;
	Node* tail;

	int n;
	List()
	{
		n = 0;
		head = NULL;
		tail = head;
	}
	bool Isempty()
	{
		return(head == NULL);
	}

	void Insert_end(int val1, double val2)
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
	void Insert_begin(int val1,double val2)
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
	void Del(int k)
	{
		Node* c = head;
		if (head == nullptr)
			return;

		if (head->p == k)
		{
			head = head->next;
			n--;
			return;
		}
		while (c->next != NULL)
		{
			if (c->next->p == k)
			{
				c->next = c->next->next;
				n--;
				break;
			}
			c = c->next;
		}
		c = head;
		while ((c != NULL)&&(c->next != NULL))
			c = c->next;
		tail = c;

	}
	void Print(int k)
	{
		if (k >= n) {
			std::cout << "Large number" << std::endl;
			return;
		}
		Node* c = head;
		for (int i = 0; i < k; i++)
			c = c->next;
		std::cout << c->c <<'('<< c->p<<')';
	}
	List operator=(List a)
	{
		head = a.head;
		tail = a.tail;
		n = a.n;
		return(*this);
	}

};

class pol
{
public:
	List a;
	pol()
	{
		a.n = 0;
		a.head = NULL;
		a.tail =a.head;
	}
	pol(List b)
	{
		a = b;
	}
	pol operator=(pol b)
	{
		a = b.a;
		return(*this);
	}
	pol(int pow, double c)
	{
		a.Insert_begin(pow, c);
	}
	pol& Mull(double k)
	{
		pol b;
		b = (*this);
		Node* tmp=b.a.head;
		while (tmp->next != NULL)
		{
			tmp->c *= k;
			tmp = tmp->next;
		}
		tmp->c *= k;
		b.DelZero();
		return(b);
	}
	void DelZero()
	{
		int k = 0;
		Node* tmp = a.head;
		Node* tmp1 = tmp;
		while (tmp1->next != NULL)
		{
			if (tmp1->c < eps)
				k++;
			tmp1 = tmp1->next;
		}
		if (tmp1->c == 0)
			k++;
		while ((a.head!=NULL)&&(a.head->c == 0))
		{
			a.head = a.head->next;
			a.n--;
			k--;
		}
		while (k!=0)
		{
			
			tmp = a.head;
		
			while((tmp!=NULL)&& (tmp->next != NULL))
			{
				if (tmp->next->c == 0)
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
	pol& operator+(pol b)
	{
		Node* tmp1 = a.head;
		Node* tmp2 = b.a.head;
		while (tmp1->next != NULL)
		{
			tmp2 = b.a.head;
			while (tmp2->next != NULL)
			{
				if (tmp1->p == tmp2->p)
				{
					tmp1->c += tmp2->c;
					b.a.Del(tmp2->p);
				}
				tmp2 = tmp2->next;
			}
			if (tmp1->p == tmp2->p)
			{
				tmp1->c += tmp2->c;
				b.a.Del(tmp2->p);
			}
			tmp1 = tmp1->next;
		}
		tmp2 = b.a.head;
		while (tmp2->next != NULL)
		{
			if (tmp1->p == tmp2->p)
			{
				tmp1->c += tmp2->c;
				b.a.Del(tmp2->p);
			}
			tmp2 = tmp2->next;
		}
		if (tmp1->p == tmp2->p)
		{
			tmp1->c += tmp2->c;
			b.a.Del(tmp2->p);
		}
		a.tail->next = b.a.head;
		if (b.a.head != NULL)
			a.tail = b.a.tail;
		
		a.n += b.a.n;
		DelZero();
		return(*this);
	}
	pol& operator*(pol b)
	{
		pol c;
		Node* tmp1=a.head;
		Node* tmp2=b.a.head;
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
		c.DelZero();
		return(c);
	}
	pol& operator-(pol b)
	{
		pol c;
		c = b;
		c.Mull(-1);
		return(*this + c);
	}

};
#endif UNTITLED_LIST_H
