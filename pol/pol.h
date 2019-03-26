
#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H
#include <iostream>
using namespace std;
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
	List();
	bool Isempty();
	void Insert_end(int val1, double val2);
	void Insert_begin(int val1, double val2);
	void Del(int k);
	void Print(int k);
	List operator=(List a);
};

class pol
{
public:
	List a;
	pol();
	pol(List b);
	pol operator=(pol b);
	pol(int pow, double c);
	pol& Mull(double k);
	void DelDups();
	void DelZero();
	pol& operator+(pol b);
	pol& operator*(pol b);
	pol& operator-(pol b);
};
#endif UNTITLED_LIST_H
