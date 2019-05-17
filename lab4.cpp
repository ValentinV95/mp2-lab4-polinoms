#include <iostream>
using namespace std;
struct Monom
{
	int st;
	int con;
	Monom(int _st = 0, int _con = 0) : st(_st), con(_con) {};


	int getX() const
	{
		return st/100;
	}
	int getY() const
	{
		return (st/10)%10;
	}
	int getZ() const
	{
		return st%10;
	}
	bool operator>(const Monom& second) const
	{
		return this->st > second.st;
	}
	bool operator<(const Monom& second) const
	{
		return this->st < second.st;
	}
	bool operator>=(const Monom& second) const
	{
		return this->st >= second.st;
	}
	bool operator<=(const Monom& second) const
	{
		return this->st <= second.st;
	}
	bool operator==(const Monom& second) const
	{
		return this->st == second.st;
	}

	Monom operator*(const Monom& second) const
	{
		Monom res;
		int x,y,z;
		z = this->getZ()+ second.getZ();
		if(z > 9)
		{
			throw std::string("Z  > 9");
		}
		y = (this->getY()+ second.getY());
		if(y > 9)
		{
			throw std::string("Y  > 9");
		}
		x =(this->getX()+ second.getX());
		if(x > 9)
		{
			throw std::string("X  > 9");
		}
		res.st = x*100+y*10+z;
		res.con = this->con*second.con;
		return res;
	}
};


class Polynom
{
	friend Monom;
	struct Node
	{
		Monom value;
		Node* next;
		Node(Monom _val = Monom(0,0), Node* _next = NULL) : value(_val), next(_next) {};
	};
	int size = 0;
	Node m_Head;

	Node* &m_Begin = m_Head.next;

public:
	Polynom(){};
	void push(Monom val)
	{
		Node** tmp = &m_Begin;
		Node* next = NULL;
		for( ; (*tmp)!=NULL;tmp=&((*tmp)->next))
		{
			if((*tmp)->value >= val)
				{
					Monom swap = (*tmp)->value;
					next = (*tmp)->next;
					(*tmp)->value = val;
					val = swap;
					tmp = &((*tmp)->next);
					break;
				}
		}
		++size;
		*tmp = new Node(val,next);
	}
	void clear()
	{
		Node* deleteLater;
		for(Node* tmp = m_Begin; tmp!=NULL; delete deleteLater)
		{
			deleteLater = tmp;
			tmp=tmp->next;
		}
	}
	void norm()
	{

		for(Node* tmp = m_Begin; tmp!=NULL; )
		{
			if(tmp->next)
			{
				if(tmp->value == tmp->next->value)
				{
					tmp->value.con += tmp->next->value.con;
					Node* deleteLayter = tmp->next;
					tmp->next = deleteLayter->next;
					--size;
					delete deleteLayter;
				}
				else
				{
					tmp=tmp->next;
				}
			}
			else
			{
				break;
			}
		}
		for(Node** tmp = &m_Begin; (*tmp)!=NULL;tmp = &((*tmp)->next) )
		{
			if((*tmp)->value.con == 0)
			{
				Node* deleteLayter = *tmp;
				(*tmp) = (*tmp)->next;
				delete deleteLayter;
			}
		}
		out();
	}
	void out()
	{
		cout <<"MONOM"<< endl;
		for(Node* tmp = m_Begin; tmp!=NULL;tmp = tmp->next )
		{
			cout << tmp->value.con << "*x^" <<tmp->value.getX() <<"*y^" << tmp->value.getY() <<"*z^" << tmp->value.getZ() <<endl;
		}
	}
	void mult(int multi)
	{
		for(Node* tmp = m_Begin; tmp!=NULL; tmp=tmp->next)
		{
			tmp->value.con*=multi;
		}
		norm();
	}
	bool operator==(const Polynom& second) const
	{
		if(this->size != second.size)
		{
			return false;
		}
		Node* tmp1 = this->m_Begin;
		Node* tmp2 = second.m_Begin;
		while(tmp1 != NULL)
		{
			if(tmp1->value.st != tmp2->value.st && tmp1->value.con != tmp2->value.con)
			{
				return false;
			}
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		return true;
	}
	 Monom at(int index) const
	{
		Node* tmp = m_Begin;
		for(int i = 0; i !=index; ++i)
		{
			tmp=tmp->next;
		}
		return tmp->value;
	}
	int Size() const
	{
		return size;
	}
	~Polynom()
	{
		clear();
	}
};
Polynom* createPolynom()
{
	cout << "Vvedite polynom\n";
	cout << "Vvedite kol monomv\n";
	int n;
	cin >> n;
	Polynom* pol = new Polynom;
	Monom element;
	for(int i = 0; i < n; ++i)
	{
		cout << "Vvedite stepen'" << endl;
		cin >> element.st;
		cout << "Vvedite const" << endl;
		cin >> element.con;
		pol->push(element);
	}
	return pol;
}
Polynom* sum(Polynom* first, Polynom* second)
{
	Polynom* result = new Polynom();
	int i = 0, j = 0, n = first->Size(), m = second->Size();
	int size = n + m;

	while(i < n && j < m)
		{
			if(first->at(i) >= second->at(j))
			{
				result->push(second->at(j));
				++j;
			}
			else
			{
				result->push(first->at(i));
				++i;
			}
		}
		while(i < n)
		{
			result->push(first->at(i));
			++i;
		}
		while(j < n)
		{
			result->push(second->at(j));
			++j;
		}
/*	delete first;
	delete second;*/
	result->norm();

	return result;
}

Polynom* mins(Polynom* first, Polynom* second)
{
	second->mult(-1);
	return sum(first,second);
}
Polynom* mult(Polynom* first, Polynom* second)
{
	Polynom* res = new Polynom();
	for(unsigned i = 0; i < first->Size(); ++i)
	{
		for(unsigned j = 0; j < second->Size(); ++j)
		{
			try
			{
				res->push(first->at(i) * second->at(j));
			}catch(std::string &st)
			{
				cout << st << endl << "Exit: -1" <<endl;
				exit(-1);
			}
		}
	}
	res->norm();
	return res;
}

int main(int argc, char *argv[])
{

	Polynom* pol1 = createPolynom();
	pol1->out();
	bool quit = false;
	do
	{
		cout << "vibirite deistvie" << endl;
		cout << "1-SUM" << endl;
		cout << "2-MINUS" << endl;
		cout << "3-MULT" << endl;
		cout << "4-MULT CONST" << endl;
		cout << "5-Exit" << endl;
		int action;

		cin >> action;
		quit = true;

		switch(action)
		{
			case 1:
			{
				Polynom* pol2 = createPolynom();
				pol1 = sum(pol1,pol2);
				break;
			}
			case 2:
			{
				Polynom* pol2 = createPolynom();
				pol1 = mins(pol1,pol2);
				break;
			}
			case 3:
			{
				Polynom* pol2 = createPolynom();
				pol1 = mult(pol1,pol2);
				break;
			}
			case 4:
			{
				cout << "Vvedite konstanty" << endl;
				int n;
				cin >> n;
				pol1->mult(n);
				break;
			}
			case 5:
			{
				quit = false;
				break;
			}
		}
	}while(quit);
	delete pol1;
}
