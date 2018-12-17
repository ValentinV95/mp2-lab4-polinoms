#include <iostream>
#include <math.h>
using namespace std;


template <class Tip>
struct Node {
	int power;
	Tip coef;
	Node<Tip> *next;
};

template <class Tip>
class List {
public:
	Node<Tip> *head;

	List()
	{
		head = nullptr;
	}

	void ClrL()
	{
		head = nullptr;
	}

	void insert(int pow, Tip c)
	{

		if ((pow / 100>9) || ((pow / 10) % 10>9) || (pow % 10>9))
			throw"The polynomial degree is higher than the permissible";

		Node<Tip> *tmp1 = new Node<Tip>;
		tmp1->power = pow;
		tmp1->coef = c;
		Node<Tip> *tmp2 = head;

		if (head == nullptr)
		{
			tmp1->next = nullptr;
			head = tmp1;
			return;
		}
		if (tmp1->power == tmp2->power)
		{
			tmp2->coef += c;
			return;
		}

		if (tmp1->power > tmp2->power)
		{
			tmp1->next = head;
			head = tmp1;
			return;
		}

		while (tmp2->next != nullptr)
		{
			if (tmp1->power == tmp2->next->power)
			{
				tmp2->next->coef += c;
				return;
			}
			if ((tmp1->power < tmp2->power) && (tmp1->power > tmp2->next->power))
			{
				tmp1->next = tmp2->next;
				tmp2->next = tmp1;
				return;
			}
			tmp2 = tmp2->next;
		}
		tmp2->next = tmp1;
		tmp1->next = nullptr;

	}

	void Delete(Tip pow)
	{
		Node<Tip> *tmp = head;

		if (head == nullptr)
			return;

		if (head->power == pow)
		{
			head = head->next;
			return;
		}
		while (tmp->next != nullptr)
		{
			if (tmp->next->power == pow)
			{
				tmp->next = tmp->next->next;
				break;
			}
			tmp = tmp->next;
		}
	}

	
	void Mull(double a)
	{
		Node<Tip> *tmp = head;
		if (a == 0)
			head = nullptr;

		while (tmp != nullptr)
		{
			tmp->coef *= a;
			tmp = tmp->next;
		}

	}

	void print()
	{
		if (head != nullptr)
		{
			Node<Tip> *tmp = head;
			cout << tmp->coef << "*(x^" << tmp->power / 100 << "*y^" << (tmp->power / 10) % 10 << "*z^" << tmp->power % 10 << ")";
			tmp = tmp->next;
			while (tmp != nullptr)
			{
				cout << " + " << tmp->coef << "*(x^" << tmp->power / 100 << "*y^" << (tmp->power / 10) % 10 << "*z^" << tmp->power % 10 << ")";
				tmp = tmp->next;
			}
		}
		else
			cout << 0;
	}

	int get_size()
	{
		Node<Tip> *tmp = head;
		int size = 0;
		while (tmp != nullptr)
		{
			size++;
			tmp = tmp->next;
		}
		return size;
	}


};


template <class Tip>
List<Tip> Clear(List<Tip> R)//delete 0
{
	Node<Tip> *tmp3 = R.head;

	if (tmp3->coef == 0)
		R.Delete(tmp3->power);

	while ((tmp3!=nullptr)&&(tmp3->next != nullptr))
	{
		if (tmp3->next->coef == 0)
			R.Delete(tmp3->next->power);
		tmp3 = tmp3->next;
	}

	return R;
}

template <class Tip>
List<Tip> Turning(List<Tip> R)
{
	Node<Tip> *tmp3 = R.head;
	while (tmp3->next != nullptr)
		if (tmp3->power == tmp3->next->power)
		{
			tmp3->coef += tmp3->next->coef;
			if (tmp3->next->next != nullptr)
				tmp3->next = tmp3->next->next;
			else
				tmp3->next = nullptr;
		}
		else
			tmp3 = tmp3->next;

	return Clear(R);
}

template <class Tip>
List<Tip> Add(List<Tip> A, List<Tip> B)
{
	List<Tip> R;
	Node<Tip> *tmp1 = A.head;
	Node<Tip> *tmp2 = B.head;


	Node<Tip> *tmp = new Node<Tip>;
	if (tmp1->power > tmp2->power)
	{
		tmp->coef = tmp1->coef;
		tmp->power = tmp1->power;
		tmp1 = tmp1->next;
	}
	else
	{
		tmp->coef = tmp2->coef;
		tmp->power = tmp2->power;
		tmp2 = tmp2->next;
	}
	R.head = tmp;


	Node<Tip> *tmp3 = R.head;

	while ((tmp1 != nullptr) && (tmp2 != nullptr))
	{
		if (tmp1->power > tmp2->power)
		{
			tmp = new Node<Tip>;
			tmp->coef = tmp1->coef;
			tmp->power = tmp1->power;
			tmp->next = nullptr;

			tmp3->next = tmp;
			tmp3 = tmp3->next;
			tmp1 = tmp1->next;
		}
		else
		{
			tmp = new Node<Tip>;
			tmp->coef = tmp2->coef;
			tmp->power = tmp2->power;
			tmp->next = nullptr;

			tmp3->next = tmp;
			tmp3 = tmp3->next;
			tmp2 = tmp2->next;
		}
	}
	while (tmp1 != nullptr)
	{
		tmp = new Node<Tip>;
		tmp->coef = tmp1->coef;
		tmp->power = tmp1->power;
		tmp->next = nullptr;

		tmp3->next = tmp;
		tmp3 = tmp3->next;
		tmp1 = tmp1->next;
	}

	while (tmp2 != nullptr)
	{
		Node<Tip> *tmp = new Node<Tip>;
		tmp->coef = tmp2->coef;
		tmp->power = tmp2->power;
		tmp->next = nullptr;

		tmp3->next = tmp;
		tmp3 = tmp3->next;
		tmp2 = tmp2->next;
	}

	return Turning(R);
}

template <class Tip>
List<Tip> Sub(List<Tip> A, List<Tip> B)
{
	List<Tip> R;
	B.Mull(-1); 
	R = Add(A, B); 
	B.Mull(-1);

	return R;
}

template <class Tip>
List<Tip> Mull(List<Tip> A, List<Tip> B)
{
	List<Tip> R;
	Node<Tip> *tmp1 = A.head;
	Node<Tip> *tmp2 = B.head;

	if ((A.head == nullptr) || (B.head == nullptr))
		return R;

	int pow = tmp1->power + tmp2->power;
	if ((pow / 100>9) || ((pow / 10) % 10>9) || (pow % 10>9))
		throw"The polynomial degree is higher than the permissible";



	while (tmp1 != nullptr)
	{
		tmp2 = B.head;
		while (tmp2 != nullptr)
		{
			R.insert(tmp1->power + tmp2->power, tmp1->coef*tmp2->coef);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}



	return R;
}

template <class Tip>
int IsEquel(List<Tip> A, List<Tip> B)
{
	if (A.get_size() != B.get_size())
		return 0;

	Node<Tip> *tmp1 = A.head;
	Node<Tip> *tmp2 = B.head;
	while (tmp1 != nullptr)
	{
		if ((tmp1->coef != tmp2->coef) || (tmp1->power != tmp2->power))
			return 0;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}

	return 1;
}





