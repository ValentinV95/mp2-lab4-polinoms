// Polynoms.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Polynoms.h"

void Polynom::init() {
	if (Head == nullptr)
	{
		Head = new Monom(-1, 0, NULL);
		Head->SetPointer(Head);
	}
}

Polynom::Polynom() {
	Head = nullptr; // чтобы память не загружалась при бездействии
}

void Polynom::loadString(string str) {
	if (Head != nullptr)
	{
		delete Head;
	}
	init();
	int i = 0;
	int len = str.length();
	while (i != len) {
		int pow = 0;
		double cff = 0;
		if (str[i] == '-') {
			i++;
			string t = "";
			while (str[i] != 'x')
			{
				t = t + str[i];
				i++;
			}
			cff = -1 * atof(t.c_str());
			cout << "cff=" << cff << endl;
		}
		if (str[i] == '+') {
			i++;
			string t = "";
			while (str[i] != 'x')
			{
				t = t + str[i]; i++;
			}
			cff = atof(t.c_str());
			cout << "cff=" << cff << endl;
		}
		if (str[i] <= '9' && str[i] >= '0') {
			string t = "";
			while (str[i] != 'x')
			{
				t = t + str[i];
				i++;
			}
			cff = atof(t.c_str());
			cout << "coef=" << cff << endl;
		}
		if (str[i] == 'x') {
			cout << "There is X" << endl;
			i++;
			string t = "";
			int k = 0;
			while (str[i] != 'y')
			{
				t = t + str[i]; i++;
			}
			k = atof(t.c_str());
			if (k >= 0 && k < 21) {
				cout << "st X is " << k << endl;
				k *= 400;
				pow += k;
			}
			else throw("The wrong power of X");
		}
		if (str[i] == 'y') {
			cout << "There is Y" << endl;
			i++;
			string t = "";
			int k;
			while (str[i] != 'z')
			{
				t = t + str[i]; i++;
			}
			k = atoi(t.c_str());
			if (k >= 0 && k < 21) {
				cout << "st Y is " << k << endl;
				k *= 20;
				pow += k;
			}
			else throw("The wrong power of Y");
		}
		if (str[i] == 'z') {
			cout << "There is Z" << endl;
			i++;
			string t = "";
			int k;
			while ((str[i] != '-') && (i != len) && (str[i] != '+'))
			{
				t = t + str[i];
				i++;
			}
			k = atoi(t.c_str());
			if (k >= 0 && k < 21) {
				cout << "st Z is " << k << endl;
				pow += k;
			}
			else ("The wrong power of Z");
		}
		Add(pow, cff);
	}
}

Polynom::Polynom(string str) {
	Head = nullptr;
	loadString(str);
}

void Polynom::Add(int power, double cf)  {
	init();
	Link prev = Head, cur = Head, tmp; //prev=указатель на пред cur=указатель на данный эл списка
	if (cf != 0){
		while ((cur->GetPointer()->GetPower() != -1)/*не бегать по кругу*/ && (cur->GetPointer()->GetPower() > power)) //найти нужное место для добавляемого монома
		{
			cur = cur->GetPointer();
		}
		cur = cur->GetPointer();
		while (prev->GetPointer() != cur)
			prev = prev->GetPointer();
		if (cur->GetPower() == power){
			if ((cur->GetCf() + cf) != 0)
				cur->SetCf(cur->GetCf() + cf);
			else	{
				prev->SetPointer(cur->GetPointer());
				cur->SetPointer(NULL);
				delete cur;
			}
		}
		else{
			tmp = new Monom(power, cf, cur);
			prev->SetPointer(tmp);
		}
	}
}

 Polynom &Polynom::operator+(Polynom op2) {
	 init();
	 Polynom res;
	 res.init();

	 Link cur = res.Head->GetPointer(); /*бегает по результату*/
	 Link point = Head->GetPointer(); //бегает по левому операнду

	 while (point->GetPower() != -1)
	 {
		 res.Add(point->GetPower(), point->GetCf());
		 point = point->GetPointer();
	 }
	 point = op2.Head->GetPointer(); // теперь бегает по правому
	 while (point->GetPower() != -1)
	 {
		 res.Add(point->GetPower(), point->GetCf());
		 point = point->GetPointer();
	 }
	 return res;
 }

 Polynom &Polynom::operator-(Polynom op2) {
	 init();
	 Polynom res;
	 res.init();

	 Link cur = res.Head->GetPointer(); /*бегает по результату*/
	 Link point = Head->GetPointer(); //бегает по левому операнду
	 while (point->GetPower() != -1)
	 {
		 res.Add(point->GetPower(), point->GetCf());
		 point = point->GetPointer();
	 }
	 point = op2.Head->GetPointer(); // теперь бегает по правому
	 while (point->GetPower() != -1)
	 {
		 res.Add(point->GetPower(), -(point->GetCf()));
		 point = point->GetPointer();
	 }
	 return res;
 }

 Polynom &Polynom::operator*(Polynom op2){
	 init();
	 Polynom res;
	 res.init();

	 Link cur1 = Head->GetPointer();
	 Link cur2 = op2.Head->GetPointer();
	 while (cur1->GetPower() != -1)
	 {
		 while (cur2->GetPower() != -1)
		 {
			 res.Add(cur1->GetPower() + cur2->GetPower(), cur1->GetCf()*cur2->GetCf());
			 cur2 = cur2->GetPointer();
		 }
		 cur2 = cur2->GetPointer();
		 cur1 = cur1->GetPointer();
	 }
	 return res;
 }

 bool Polynom::operator==(const Polynom&op2) const {
	 if (Head == nullptr)
	 {
		 if (op2.Head == nullptr)
			 return true;
		 return false;
	 }
	 bool res = true;
	 Link cur1 = Head->GetPointer();
	 Link cur2 = op2.Head->GetPointer();
	 while ((cur1->GetPower() != -1) && (cur2->GetPower() != -1)) {
		 if ((abs(cur1->GetCf() - cur2->GetCf())) || (cur1->GetPower() != cur2->GetPower()))
			 res = false;

		 if (((cur1->GetPower() == -1) && (cur2->GetPower() != -1)) || ((cur1->GetPower() != -1) && (cur2->GetPower() == -1)))
			 res = false;
		 cur1 = cur1->GetPointer();
		 cur2 = cur2->GetPointer();
	 }
	 return res;
 }

 double Polynom::calc(double x, double y, double z) {
	 init();
	 double tmp;
	 double sum = 0;
	 Link cur = Head->GetPointer();

	 while (cur->GetPower() != -1)
	 {
		 tmp = cur->GetCf() * pow(x, cur->GetPower() / 400) * pow(y, (cur->GetPower() % 400) / 20) * pow(z, cur->GetPower() % 20);
		 sum += tmp;
		 cur = cur->GetPointer();
	 }
	 return sum;
 }

 void Polynom::Print() {
	 if (Head == nullptr) {
		 return throw;
	 }
	 int x, y, z;
	 Link tmp = Head->GetPointer();
	 while (tmp->GetPower() != -1)
	 {
		 x = tmp->GetPower() / 400;
		 y = (tmp->GetPower() % 400) / 20;
		 z = tmp->GetPower() % 20;
		 if (tmp->GetPointer()->GetPower() != -1)
			 if (tmp->GetPointer()->GetCf() > 0)
				 cout << tmp->GetCf() << "*" << "x^" << x << "y^" << y << "z^" << z << "+";
			 else
				 cout << tmp->GetCf() << "*" << "x^" << x << "y^" << y << "z^" << z;
		 else
			 cout << tmp->GetCf() << "*" << "x^" << x << "y^" << y << "z^" << z;
		 tmp = tmp->GetPointer();
	 }
	 cout << endl;
	 if (Head->GetPointer() == Head) {
		 cout << 0 << endl;
	 }
 }