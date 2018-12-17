#include "polinoms.h"
#include <iostream>
using namespace std;

int main()
{
	int s, Key;
	setlocale(LC_ALL,"Russian");
	cout << "Маленькие правила по вводу полиномов:"<<endl;
	cout << "1: Сначала необходимо ввести число мономов."<<endl;
	cout << "2: Затем необходимо ввести каждый моном отдельно."<<endl;
	cout << "3: При ввобе монома сначала вводится коэффициент перед ним, затем степень Х, У и Z."<<endl;
	cout << "4: Степень каждой из переменных не может быть больше 99!"<<endl;
	cout << "Итак, приступим. Введите базовый полином"<<endl;

f:	Polinoms a;
	cout << "Сколько мономов в вашем полиноме?  ";
	cin >> s;
	while (s>0)
	{
		a.Set();
		s--;
	}
	a.Print();
	cout << endl;
l:	cout << "Что хотите сделать?:"<<endl;
	cout << "1:Прибовить полином"<<endl;
	cout << "2: Вычесть полином"<<endl;
	cout << "3: Умножить на константу"<<endl;
	cout << "4: Умножить на полином"<<endl;
	cin >> Key;
	switch(Key)
	{
	case 1:
		{
			Polinoms b;
			cout << "Сколько мономов в вашем полиноме?  "<< endl;
			cin >> s;
			while (s>0)
			{
				b.Set();
				s--;
			}
			a = a+b;
			a.Print();
		}
		break;
	case 2: 
		{
			Polinoms b;
			cout << "Сколько мономов в вашем полиноме?  "<< endl;
			cin >> s;
			while (s>0)
			{
				b.Set();
				s--;
			}
			b.Print();
			cout << endl;
			a = a-b;
			a.Print();
		}
		break;
	case 3:
		{
			double c;
			cout << "Введите число" << endl;
			cin >>c;
			a = a*c;
			a.Print();
		}
		break;
	case 4:
		{
			Polinoms b;
			cout << "Сколько мономов в вашем полиноме?  "<< endl;
			cin >> s;
			while (s>0)
			{
				b.Set();
				s--;
			}
			b.Print();
			cout << endl;
			a = a*b;
			a.Print();
		}
		break;
	default:
		break;
	}
	cout << endl;
	cout << "И что теперь?  "<< endl;
	cout << "1. Сделать что-то с результатом  "<< endl;
	cout << "2.Сделать что-то с новым полиномом. "<< endl;
	cout << "3. Уйти.  "<< endl;
	cin >> Key;
	switch (Key)
	{
	case 1:
		goto l;
		break;
	case 2:
		goto f;
		break;
	default:
		cout << "Пока пока  ";
		break;
	}
}