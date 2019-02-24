#ifndef _LIST_H_
#define _LIST_H_

#include "stdlib.h"
#include "iostream"

template <typename T>
class Node
{
public:

	Node<T>* prev;
	Node<T>* next;
	T data;

	Node();
	Node(T);
	~Node();
};

template < typename T>
Node<T>::Node()
{
	prev = next = NULL;
}

template < typename T>
Node<T>::Node(T _data)
{
	prev = next = NULL;
	data = _data;
}

template < typename T>
Node<T>::~Node()
{
}

template <typename T>
class List
{
protected:

	Node<T>* head;
	Node<T>* end;

public:

	List();
	List(Node<T>*);
	List(List<T>&);
	~List();
	bool IsEmpty();
	void Clear();
	void Delete(Node<T>*);
	void Insert(T);
	List<T> Merge(List<T>);
	List<T>& operator= (List<T>&);
	bool operator== (const List<T>&) const;
	virtual void Print();
};

template<typename T>
List<T>::List()
{
	head = end = NULL;
}

template<typename T>
List<T>::List(Node<T>* _head)
{
	head = _head;
	Node<T>* cur = head;

	while (cur->next != NULL)
		cur = cur->next;

	end = cur;
}
template<typename T>
List<T>::List(List<T>& lst)
{
	if (lst.IsEmpty())
	{
		head = end = NULL;
	}
	else
	{
		Node<T>* cur = lst.head;
		Node<T> fk_head;
		Node<T>* last;

		last = &fk_head;

		while (cur != NULL)
		{
			Node<T>* temp = new Node<T>;
			temp->data = cur->data;

			last->next = temp;
			temp->prev = last;
			last = temp;
			cur = cur->next;
		}

		head = fk_head.next;
		head->prev = NULL;
		end = last;
	}

}

template<typename T>
List<T>::~List()
{
	Clear();
}

template<typename T>
bool List<T>::IsEmpty()
{
	if (head == NULL && end == NULL)
		return(true);
	else
		return(false);
}

template<typename T>
void List<T>::Clear()
{
	Node<T>* cur = head;
	Node<T>* temp;

	while (cur != NULL)
	{
		temp = cur->next;
		delete cur;
		cur = temp;
	}

	head = end = NULL;
}

template<typename T>
List<T>& List<T>::operator= (List<T>& lst)
{
	if ((*this) == lst)
		return(*this);

	Clear();
	Node<T>* cur = lst.head;
	Node<T>* last;

	if (cur == NULL)
	{
		return (*this);
	}
	else 
	{
		Node<T>* temp = new Node<T>;
		temp->data = cur->data;

		last = head = temp;
		cur = cur->next;

		while (cur != NULL)
		{
			Node<T>* temp = new Node<T>;
			temp->data = cur->data;

			last->next = temp;
			temp->prev = last;
			last = temp;

			cur = cur->next;
		}
	}
	end = last;

	return(*this);
}

template<typename T>
bool List<T>::operator== (const List<T>& lst) const
{
	Node<T>* cur1 = head;
	Node<T>* cur2 = lst.head;

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data != cur2->data)
			return(false);

		cur1 = cur1->next;
		cur2 = cur2->next;
	}

	if (cur1 == NULL && cur2 == NULL)
		return(true);
	else
		return(false);
}

template<typename T>
void List<T>::Insert(T _data) //считаем что данные приходят правильные
{
	Node<T>* temp = new Node<T>;
	temp->data = _data;

	Node<T>* cur = head;
	bool insrt = false;

	if (cur == NULL)
	{
		head = end = temp;
	}
	else
	{
		if (cur->data < _data)
		{
			temp->next = cur;
			cur->prev = temp;
			head = temp;
			cur = cur->next;

			insrt = true;
		}

		while (cur != NULL && insrt == false)
		{
			if (cur->data < _data)
			{
				temp->next = cur;
				temp->prev = cur->prev;
				cur->prev = temp;
				cur = temp->prev;
				cur->next = temp;
				cur = temp->next;

				insrt = true;
			}
			else
			{
				cur = cur->next;
			}
		}

		if (!insrt)
		{
			temp->prev = end;
			end->next = temp;
			end = temp;
		}
	}
}

template< typename T>
List<T> List<T>::Merge(List<T> lst)
{
	List<T>res;
	Node<T>*cur1 = head;
	Node<T>*cur2 = lst.head;
	Node<T>*last;
	Node<T>* b_dat, *s_dat;
	Node<T>* no_empty;

	Node<T> fk_head;
	last = &(fk_head);

	if (cur1 == NULL && cur2 == NULL)
	{
		return(res);
	}

	while (cur1 != NULL && cur2 != NULL)
	{
		Node<T>* temp = new Node<T>;

		if (cur1->data >= cur2->data)
		{
			b_dat = cur1;
			s_dat = cur2;
			cur1 = cur1->next;
		}
		else
		{
			b_dat = cur2;
			s_dat = cur1;
			cur2 = cur2->next;
		}
			temp->data = b_dat->data;
			last->next = temp;
			temp->prev = last;
			last = temp;
	}

	if (cur1 == NULL)
	{
		no_empty = cur2;
	}
	else
	{
		no_empty = cur1;
	}

	while (no_empty != NULL)
	{
		Node<T>* temp = new Node<T>;
		temp->data = no_empty->data;
		last->next = temp;
		temp->prev = last;
		last = temp;
		no_empty = no_empty->next;
	}

	res.head = fk_head.next;
	res.head->prev = NULL;
	res.end = last;

	return(res);
}

template<typename T>
void List<T>::Delete(Node<T>* elem)
{
	Node<T>* cur;

	if (elem == head)
		head = elem->next;

	if(elem == end)
		end = elem->prev;

	if (elem->prev != NULL)
	{
		cur = elem->prev;
		cur->next = elem->next;
	}

	if (elem->next != NULL)
	{
		cur = elem->next;
		cur->prev = elem->prev;
	}

	delete elem;//или (*elem)
}

template <typename T>
void List<T>::Print()
{
	Node<T>* cur = head;

	while (cur != NULL)
	{
		std::cout << cur->data << ' ';
		cur = cur->next;
	}

	std::cout << std::endl;
}

#endif // !_LIST_H_