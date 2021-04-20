#include "List.h"

#include "Monom.h"

int main()
{
	Polinom<float> A, B, C, D, E;
	bool decision = 1;

	while (decision)
	{
		cout << endl << "Set polynom A:  ";
		A.Input(); 
		cout << endl << "A= " << A << endl << endl;

		cout << "Set polynom B:  ";
		B.Input(); 
		cout << endl << "B=" << B << endl << endl;

		//C = A;
		//cout << "equally: C = A then C = " << C << endl << endl;

		
		C = A + B;
		cout << "Add: A + B: " << C << endl << endl;

		D = A - B;
		cout << "Minus: A - B: " << D << endl << endl;

		E = A * B;
		cout << "Multi: ";
		if (E.Get_max_index() < 999)
		{
		cout << "A * B = " << E << endl << endl;
		}
		else
		{			
			cout << "E.max_index() > 999" << endl;
		}

		cout << "To do tit again tap 1," << endl;
		cout << "To exit the program, tap 0:";
		cin >> decision;
		cout << "u`ve tapped: " << decision << endl << endl;
	}
}