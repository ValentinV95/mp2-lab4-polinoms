#include "pol.h"

pol::pol() {
	monom *tmp = new monom;
	head = tmp;
	head->a = 0;
	head->s = 0;
	size = 0;

}
void pol::insert(monom m) {
	if(m.a!=0 && m.s<1000 && m.s>=0){

		if (size == 0) {
			monom *nw = new monom;
			head->next = nw;
			nw->next = NULL;
			nw->a = m.a;
			nw->s = m.s;
			size++;
		}
		else {
			monom *tmp = head, *tmp2 = head;
			int i = 0;

			monom *nw = new monom;

			while ((tmp->next != NULL) && ((tmp->next)->s > m.s)) {
				tmp = tmp->next;
				i++;
			}

			for (int j = 0; j < i; j++) {
				tmp2 = tmp2->next;
			}

			if (tmp->next == NULL) {

				tmp->next = nw;
				nw->next = NULL;
				size++;
				nw->a = m.a;
				nw->s = m.s;
			}

			else if (tmp->next->s == m.s) {
				tmp->next->a = m.a + tmp->next->a;
				if (tmp->next->a == 0) {
					tmp2->next = tmp->next;
					size--;
					delete nw;
				}
			}
			else {

				nw->next = tmp->next;
				tmp2->next = nw;
				size++;
				nw->a = m.a;
				nw->s = m.s;
			}
		}
	}
	else { 
		cout << "неверно введен моном" << endl;
		throw ("wrong monom");
	}
}
void pol::show() {
	monom *tmp = head->next;
	int i = 0;

	while (i < size) {
		if (i > 0) { cout << "+ "; }
		cout <<"("<< tmp->a ;
		cout << "x^"<<tmp->s/100 <<"y^" << (tmp->s%100)/10 << "z^"<< tmp->s % 10<< ") ";
		tmp = tmp->next;
		i++;
	}
	cout <<endl;
}

pol& pol::operator= (pol sec) {
	head->next = NULL;
	size = 0;

	monom *tmp2 = sec.head;

	while (tmp2->next) {

		insert(*(tmp2->next));
		tmp2 = tmp2->next;

	}
	return *this;
}
pol& pol::operator+ (pol sec) {
	pol *np = new pol;
	monom *tmp = head, *tmp2 = sec.head;
	while ((tmp->next != NULL) && (tmp2->next != NULL)) {

		if (((tmp->next)->s) >= ((tmp2->next)->s)) {

			np->insert(*(tmp->next));
			tmp = tmp->next;
		}
		else {

			np->insert(*(tmp2->next));
			tmp2 = tmp2->next;
		}
	}
	while (tmp->next != NULL)
	{
		np->insert(*(tmp->next));
		tmp = tmp->next;
	}
	while (tmp2->next != NULL)
	{
		np->insert(*(tmp2->next));
		tmp2 = tmp2->next;
	}
	return *np;

}
pol& pol::operator- (pol sec) {
	return (sec*(-1) + *this);
}

pol& pol::operator* (pol sec) {
	setlocale(LC_ALL, "Russian");
	pol *np = new pol;
	monom *tmp = head, *tmp2;
	for (int i = 0; i < size; i++) {
		tmp2 = sec.head;
		for (int j = 0; j < sec.size; j++) {
			if (((tmp->next->s) / 100 + (tmp2->next->s) / 100)<10 && ((tmp->next->s) % 100 + (tmp2->next->s) % 100)<100 && ((tmp->next->s) % 10 + (tmp2->next->s) % 10)<10) {
				monom *nw = new monom;
				nw->s = (tmp->next->s) + (tmp2->next->s);
				nw->a = (tmp->next->a)*(tmp2->next->a);
				nw->next;
				tmp2 = tmp2->next;
				np->insert(*nw);
			}
			else {
				cout << "превышена степень" << endl;
				throw ("limit power is exceeded");
			}
		}
		tmp = tmp->next;
	}
	return *np;
}
pol& pol::operator* (double con) {
	int i = 0;
	monom *tmp = head;
	pol *np=new pol;
	while (i < size) {
		monom *nw = new monom;
		nw->a=con*(tmp->next->a);
		nw->s = (tmp->next->s);
		nw->next = NULL;
		np->insert(*nw);
		tmp = tmp->next;
		i++;
	}
	return *np;
}

bool pol::operator== (const pol &sec) const {
	if(size != sec.size){ return false; }
	else {
		bool f = true;
		monom *tmp = head, *tmp2 = sec.head;
		while (tmp->next) {
			if ((tmp->next->a != tmp2->next->a) || (tmp->next->s != tmp2->next->s)) { f = false; }
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		return f;
	}
	
}
bool pol::operator!= (const pol &sec) const {	
	return!(*this==sec);
}