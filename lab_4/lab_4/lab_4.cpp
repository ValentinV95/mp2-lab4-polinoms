// lab_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "polinom.h"

int main()
{
	int k, p;
	double c;
	List a, b;
	std::cout << "Entering 1-st polynomial" << std::endl;
	std::cout << "Enter number of monomials" << std::endl;
	std::cin >> k;
	std::cout << std::endl;
	for (int i = 0; i < k; i++)
	{
		std::cout << "Enter power of monom" << " " << i + 1 << std::endl;
		std::cin >> p;
		std::cout << std::endl;
		while (p > 999)
		{
			std::cout << "Incorrect power, try again" << std::endl;
			std::cin >> p;
			std::cout << std::endl;
		}
		std::cout << "Enter coefficient of monom" << " " << i + 1 << std::endl;
		std::cin >> c; std::cout << std::endl;
		a.Insert_end(p, c);
	}
	std::cout << "Entering 2-nd polynomial" << std::endl;
	std::cout << "Enter number of monomials" << std::endl;
	std::cin >> k; std::cout << std::endl;
	for (int i = 0; i < k; i++)
	{
		std::cout << "Enter power of monom" << " " << i + 1 << std::endl;
		std::cin >> p;
		std::cout << std::endl;
		while (p > 999)
		{
			std::cout << "Incorrect power, try again" << std::endl;
			std::cin >> p;
			std::cout << std::endl;
		}
		std::cout << "Enter coefficient of monom" << " " << i + 1 << std::endl;
		std::cin >> c;
		std::cout << std::endl;
		b.Insert_end(p, c);
	}
	std::cout << "Entering of polynomials is complited";

	std::cout << std::endl;
	std::cout << "Choose operation" << std::endl;
	std::cout << "1.Add polynomials" << std::endl;
	std::cout << "2.Subtract polynomials" << std::endl;
	std::cout << "3.Multiply polynomials" << std::endl;
	std::cout << "4.Multiply 1-st polynomial on const" << std::endl;
	pol b1(a);
	pol b2(b);
	pol b3;
	std::cin >> k;
	std::cout << std::endl;
	switch (k)
	{
	case 1:
	{
		std::cout << "(";
		for (int i = 0; i < b1.a.n; i++)
		{
			b1.a.Print(i);
			if (i != b1.a.n - 1)
				std::cout << "  +  ";
		}
		std::cout << ")";
		std::cout << "  +  ";
		std::cout << "(";
		for (int i = 0; i < b2.a.n; i++)
		{
			b2.a.Print(i);
			if (i != b2.a.n - 1)
				std::cout << "  +  ";
		}
		std::cout << ")";
		std::cout << "  =  ";
		b3 = b1 + b2;
		for (int i = 0; i < b3.a.n; i++)
		{
			b3.a.Print(i);
			if (i != b3.a.n - 1)
				std::cout << "  +  ";
		}
		break;
	}
	case 2:
	{
		std::cout << "(";
		for (int i = 0; i < b1.a.n; i++)
		{
			b1.a.Print(i);
			if (i != b1.a.n - 1)
				std::cout << "  +  ";
		}
		std::cout << ")";
		std::cout << "  -  ";
		std::cout << "(";
		for (int i = 0; i < b2.a.n; i++)
		{
			b2.a.Print(i);
			if (i != b2.a.n - 1)
				std::cout << "  +  ";
		}
		std::cout << ")";
		std::cout << "  =  ";
		b3 = b1 - b2;
		for (int i = 0; i < b3.a.n; i++)
		{
			b3.a.Print(i);
			if (i != b3.a.n - 1)
				std::cout << "  +  ";
		}
		break;
	}
	case 3:
	{
		std::cout << "(";
		for (int i = 0; i < b1.a.n; i++)
		{
			b1.a.Print(i);
			if (i != b1.a.n - 1)
				std::cout << "  +  ";
		}
		std::cout << ")";
		std::cout << "  *  ";
		std::cout << "(";
		for (int i = 0; i < b2.a.n; i++)
		{
			b2.a.Print(i);
			if (i != b2.a.n - 1)
				std::cout << "  +  ";
		}
		std::cout << ")";
		std::cout << "  =  ";
		b3 = b1 * b2;
		for (int i = 0; i < b3.a.n; i++)
		{
			b3.a.Print(i);
			if (i != b3.a.n - 1)
				std::cout << "  +  ";
		}
		break;
	}
	case 4:
	{
		std::cout << "Enter constant" << std::endl;
		std::cin >> c;
		std::cout << std::endl;
		std::cout << "(";
		for (int i = 0; i < b1.a.n; i++)
		{
			b1.a.Print(i);
			if (i != b1.a.n - 1)
				std::cout << "  +  ";
		}
		std::cout << ")";
		std::cout << "  *  " << c << "  =  ";
		b3 = b1.Mull(c);
		for (int i = 0; i < b3.a.n; i++)
		{
			b3.a.Print(i);
			if (i != b3.a.n - 1)
				std::cout << "  +  ";
		}
		break;
	}
	default:
		break;
	}
	std::cin >> k;


	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
