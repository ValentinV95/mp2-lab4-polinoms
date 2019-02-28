#include <iostream>
#include "../Polinom/polinom.h"

using namespace std;

int main()
{
	cout << "Rules:" << endl;
	cout << "1. Polinom sum(a(u) * x^i * y^j * z^k)" << endl;
	cout << "2. a(u) - real number" << endl;
	cout << "3. deg(xyz) - integer number, 0 <= deg(xyz) < 1000" << endl;

	cout << endl;
	bool w = true;
	Polinom pol1, pol2;
	while (w)
	{
		cout << "Input two polinoms" << endl;
		w = false;
		try
		{
			cout << "First:" << endl;
			cin >> pol1;
			cout << "Second" << endl;
			cin >> pol2;
		}
		catch (string)
		{
			cout << "Incorrect degree" << endl;
			w = true;
		}
		if (w == false)
		{
			break;
		}
	}
	cout << "Pol_1: " << pol1 << endl;
	cout << "Pol_2: " << pol2 << endl;
	int ch;
	w = true;
	while (w)
	{
		w = false;
		cout << "Choice operation" << endl;
		cout << "1 - (pol_1+pol_2), 2 - (pol_1*pol_2), 3 - (pol_1-pol_2), 4 - (pol_2-pol_1)" << endl;
		cin >> ch;
		if (ch < 1 || ch > 4)
		{
			cout << "Choice num 1 - 4" << endl;
			w = true;
		}
	}
	try
	{
		if (ch == 1)
		{
			cout << pol1 + pol2 << endl;
		}
		if (ch == 2)
		{
			cout << pol1 * pol2 << endl;
		}
		if (ch == 3)
		{
			cout << pol1 - pol2 << endl;
		}
		if (ch == 4)
		{
			cout << pol2 - pol1 << endl;
		}
	}
	catch (string)
	{
		cout << "degree > 9" << endl;
	}
	return 0;
}