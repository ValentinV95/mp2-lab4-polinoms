#include "polinom.h"
#include "iomanip"
using namespace std;

void InputAll(bool frst, bool scnd, bool cons, Polinom& p1, Polinom& p2, double& constant);
Polinom InputPolinom();

int main()
{
	cout << "Program name: Testing polinoms" << endl;

	Polinom p1;
	Polinom p2;
	double constant;
	bool exit = false;
	bool prnt = true;

	InputAll(true, true, true, p1, p2, constant);

	cout << "First: ";
	p1.Print();
	cout << "Second: ";
	p2.Print();
	cout << "Const: " << constant << endl;

	while (!exit)
	{
		if (prnt) 
		{
			cout << endl << "Select one of the menu items" << endl;
			cout << "1) Addition" << endl;
			cout << "2) Subtraction" << endl;
			cout << "3) Multiplication by a constatnt" << endl;
			cout << "4) Multiplication by the second polinom" << endl;
			cout << "5) Change input data" << endl;
			cout << "6) Exit" << endl;
			prnt = false;
		}

		cout << endl << "Your selection: ";
		int slct1;
		cin >> slct1;
		
		Polinom res;
		switch (slct1)
		{
		case 1:
			res = p1 + p2;
			cout << "Result: ";
			res.Print();

			break;
		case 2:
			res = p1 - p2;
			cout << "Result: ";
			res.Print();

			break;
		case 3:
			res = p1 * constant;
			cout << "Result: ";
			res.Print();

			break;
		case 4:

			try 
			{	
				res = p1*p2;
				cout << "Result: ";
		     	res.Print();
			}

			catch (char* str)
			{
				cout << str << endl;
				cout << "Try to change first or second polinoms" << endl;
			}

			break;
		case 5:

			cout << endl << "Select the item you want to change" << endl;
			cout << "1) First polinom"<< endl;
			cout << "2) Second polinom" << endl;
			cout << "3) Constanst" << endl;

			cout << endl << "Your selection: ";
			int slct2;
			cin >> slct2;

			switch (slct2)
			{
			case 1:
				InputAll(true, false, false, p1, p2, constant);
				cout << endl << "First: ";
				p1.Print();

				break;
			case 2:
				InputAll(false, true, false, p1, p2, constant);
				cout << endl << "Second: ";
				p2.Print();

				break;
			case 3:
				InputAll(false, false, true, p1, p2, constant);
				cout << "Const: ";
				cout << constant << endl;

				break;
			}

			prnt = true;

			break;
		case 6:
			exit = true;

			break;
		}
	}
}

Polinom InputPolinom()
{
	Polinom res;
	double coef;
	int deg;
	int number;
	bool crct1 = false;

	while (!crct1)
	{
		cout << "Input number of monoms ";
		cin >> number;

		if (number <= 0)
			cout << endl << "Incorrect input, try again" << endl;
		else 
			crct1 = true;
	}

	for (int i = 0; i<number; i++)
	{
		cout << endl << "Monom" << i + 1 << ":" << endl;
		cout << "Coefficient = ";
		cin >> coef;
		cout << "Degree = ";
		cin >> deg;

		Monom mon(coef, deg);
		res.Insert(mon);
	}

	res.ToStandartView();
	return(res);
}

void InputAll(bool frst, bool scnd, bool cons, Polinom& p1, Polinom& p2, double& constant)
{
	if (frst)
	{
		cout << endl << "Input first polinom:" << endl;
		p1 = InputPolinom();
	}

	if (scnd)
	{
		cout << endl << "Input second polinom:" << endl;
		p2 = InputPolinom();
	}

	if (cons)
	{
		cout << endl << "Input constant: ";
		cin >> constant;
		cout << endl;
	}
}
