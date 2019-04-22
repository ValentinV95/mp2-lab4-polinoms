#pragma once
#include <cstdio>
#include <stack>
using namespace std;

template <class ValType>
struct Node
{
	ValType data;
	Node <ValType> * next;
	Node <ValType> * prev;
	Node(): data()
	{
		next = nullptr;
		prev = nullptr;
	}
};

template <class ValType>
class List
{
private:
	Node <ValType> *head;
	int size;
	friend class Polinom;
public:
	//Конструктор
	List() : head(nullptr), size(0) {}
	//Деструктор
	~List() 
	{
		Node <ValType> * ptr = head;
		while (ptr != nullptr)
		{
			head = ptr->next;
			delete ptr;
			ptr = head;
		}
	}
	//Корень списка
	Node<ValType>* Root()
	{
		return head;
	}
	//Размер
	int Size()
	{
		return size;
	}
	//Вставка звена в список
	void Insert(ValType M)
	{
		Node <ValType> *A = new Node<ValType>;
		A->data = M;
		
		if (size==0)
		{			
			head = A;	
		}
		else
		{
			Node<ValType>* pos=nullptr;
			Node<ValType>* ptr=head;
			if (M > head->data)
			{
				head->prev = A;
				A->next=head;
				head = A;
			}
			else
			{
				while ((ptr->data >= M)&&(ptr->next!=nullptr))
				{
					ptr = ptr->next;
				}
				if (ptr->next != nullptr)
				{
					pos=ptr->prev;
					A->next = pos->next;
					pos->next->prev = A;
					pos->next = A;
					A->prev = pos;
				}
				else
				{
					ptr->next = A;
					A->prev = ptr;
				}
			}

		}
		size++;
	}
	//Удаление звена из списка
	void Delete(ValType M)
	{
		int k = 0;
		Node<ValType>* temp;
		Node<ValType>* _temp;
		temp = head;
		while (k < size)
		{
			if (k == 0)
			{
				if (temp->data == M)
				{
					temp->next->prev = nullptr;
					temp = temp->next;
					delete head;
					head = temp;
					size--;
					return;
				}
			}
			else
			{
				if (temp->data == M)
				{
					_temp = temp;
					temp->next->prev = temp->prev;
					temp->prev->next = temp->next;
					delete _temp;
					size--;
					return;
				}
			}
			temp = temp->next;
			k++;
		}
	}
	//Слияние двух соседних звеньев
	void MergerNode(Node<ValType>* p1, Node<ValType>* p2)
	{
		p1->data = p1->data + p2->data;
		p1->next = p2->next;
		if (p2->next != nullptr)
			p2->next->prev = p1;

		delete p2;
		size--;
	}
};



