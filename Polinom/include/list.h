#include <iostream>

struct Node
{
	int data;
	Node *next;
};

class List
{
private:
	Node *head;

public:
	List()
	{
		head = NULL;
	}
	//метод, добавляющий новый узел в список
	void addNode(int d)
	{
		Node *nd = new Node;
		nd->data = d;
		nd->next = NULL;
		if (head == NULL)
			head = nd;
		else //если узел уже не первый
		{
			Node *current = head;
			while (current->next != NULL)
				current = current->next;
			current->next = nd;
		}
	}
	void printList()
	{
		Node *current = head;
		while (current != NULL)
		{
			std::cout << current->data << std::endl;
			current = current->next;
		}
	}
};