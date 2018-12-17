#ifndef _LIST_
#define _LIST_

#include <iostream>
using namespace std;

template <class T>

struct Node 
{
    T data;
    Node<T> *next;
};

template <class T>
class List {
public:
    Node<T> *head;
    Node<T> *tail;
    List();
    void insert_front(T x);
    void insert_at_end (T x);
	void insert_after(Node<T> *x, T y);
    void del (T x);
	bool operator == (const List<T> &a) const;
};

template <class T>
List<T>::List() 
{
    head = nullptr;
    tail = nullptr;
}

template <class T>
void List<T>::insert_front(T x) 
{
    Node<T> *a = new Node<T>;
    a->data = x;
    if (head == nullptr)
	{
        a->next = nullptr;
        tail = a;
    }
    else
	{
        a->next = head;
    }
    head = a;
}

template <class T>
void List<T>::insert_at_end(T x)
{
	Node<T> *a = new Node<T>;
    Node<T> *tmp = head;
    a->data = x;
    if (head == nullptr)
	{
        a->next = nullptr;
        head = a;
    }
    else 
	{
        while (tmp->next != nullptr) 
		{
            tmp = tmp->next;
        }
        a->next = nullptr;
        tmp->next = a;
    }
    tail = a;
}

template <class T>
void List<T>::insert_after(Node<T>* x, T y)
{
	Node<T> *tmp = head; 
	while (tmp != nullptr) 
	{ 
		if (tmp->data == x->data) 
		{ 
			Node<T> *a = new Node<T>; 
			a->data = y; 
			a->next = tmp->next; 
			tmp->next= a; 
			return; 
		} 
		tmp = tmp -> next; 
	} 
}

template <class T>
void List<T>::del(T x)
{
    if (head == nullptr)
    {
        return;
    }
	Node<T> *a = head;
	while (a->next != nullptr) 
	{
		 if (head->data == x)
	{
        head = head->next;
    }
		 else if (a->next->data == x)
		{
            a->next = a->next->next;
			if (a -> next == nullptr)
          break;
        }
        a = a->next;
    }
	if (a->data == x)
		del(x);
}

template <class T>
bool List<T>::operator == (const List<T> &a) const
{
	Node <T> *x = head, *y = a.head;
	while( (x != nullptr) && (y != nullptr))
	{
		if (x->data == y->data)
		{
			x = x->next;
			y = y->next;
		}
		else return 0;
	}
	if ((x != nullptr) || (y != nullptr))
		return 0;
	else return 1;
}

#endif _LIST_