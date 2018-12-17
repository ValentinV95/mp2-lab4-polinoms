#include "list.h"

void main()
{
	int k = 1;
	int op = 0;

	double a;
	List<double> A;
	List<double> B;
	List<double> R;

	while (k != 0)
	{
		system("cls");
		cout << "menu function:" << endl << "1 - To enter a polynom A" << endl;
		cout << "2 - To enter a polynom B" << endl << "3 - Selected operation" << endl;
		cout << "0 - To exit" << endl;

		cout << "Polinom A: ";
		A.print();
		cout << endl;
		cout << "Polinom B: ";
		B.print();
		cout << endl;

		cout << "Polinom R: ";
		R.print();
		cout << endl;


		cin >> k;

		switch (k)
		{
		case 1:
		{
			double coef = 1;
			int power = 1;
			A.ClrL();
			system("cls");
			cout << "To inter 0 in both elements for output" << endl;
			cout << "Input example: <12 123> this is equivalent to <12*x^1*y^2*z^3>" << endl;
			cout << "the power of number is int, 0<=power<=9" << endl;

			while ((power != 0) || (coef != 0))
			{
				cout << "To enter a monom: ";
				cin >> coef >> power;

				if (coef == 0)
				{
					cout << "meaningless monom" << endl;
				}
				else
				{
					A.insert(power, coef);
				}
			}

		}
		break;
		case 2:
		{
			int power = 1;
			double coef = 1;
			B.ClrL();
			system("cls");
			cout << "To inter 0 in both elements for output" << endl;
			cout << "Input example: <12 123> this is equivalent to <12*x^1*y^2*z^3>" << endl;
			cout << "the power of number is int, 0<=power<=9" << endl;

			while ((power != 0) || (coef != 0))
			{
				cout << "To enter a monom: ";
				cin >> coef >> power;


				if (coef == 0)
				{
					cout << "meaningless monom" << endl;
				}
				else
				{
					B.insert(power, coef);
				}
			}

		}
		break;
		case 3:
		{
			cout << "to inter the nomber operation: 1 - add, 2 - subtraction, 3 - multiplication, 4 - multiplication by a constant" << endl;
			cin >> op;
			switch (op)
			{
			case 1:R = Add(A, B);
				cout << op;
				break;

			case 2:R = Sub(A, B); break;
			case 3:R = Mull(A, B); break;
			case 4:
			{
				cout << "To inter the constant" << endl;
				cin >> a;
				cout << "who? 1- A, 2- B" << endl;
				int i;
				cin >> i;
				if (i == 1)
					A.Mull(a);
				if (i == 2)
					B.Mull(a);
			} break;
			}



		}
		}
	}
}