#include"Polinom.h"

void main()
{
	Polinom A, B;
	Polinom C, D, E;
	int w = 1;
	cout << "Demonstration of performing arithmetic operations of addition, subtraction and multiplication for polynomials." << endl;
	while (w)
	{
		cout << endl << "Entering the polynomial A:  ";
		A.Input(); cout << "A="; A.Print();  cout << endl << endl;
		cout << "Entering the polynomial B:  ";
		B.Input(); cout << "B="; B.Print();  cout << endl << endl;
		C = A + B;
		D = A - B;
		E = A * B;
		cout << "Addition:  "; cout << "A+B="; C.Print();  cout << endl;
		cout << "Subtraction:  "; cout << "A-B="; D.Print();  cout << endl;
		cout << "Multiplication:  ";

		if (E.Highest_Degree() < 999)
		{
			cout << "A*B="; E.Print();  cout << endl << endl;
		}
		else
			cout << "The degree of a polynomial is outside the scope of this implementation." << endl;

		cout << "If you want to continue the program, press 1," << endl;
		cout << "if you want to exit the program, press 0:";
		cin >> w;
	}

	system("pause");
}
