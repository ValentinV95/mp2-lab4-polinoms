#include <iostream>
#include "polinom.h"

int main()
{
	std::cout << "Enter the polynom\n";
	Polinom a;
	std::cin >> a;
	std::cout << "Enter the operation with polynom\n";
	std::cout << "1) + polynom\n";
	std::cout << "2) * polynom\n";
	std::cout << "3) - polynom\n";
	std::cout << "4) * const\n";
	int x;
	std::cin >> x;
	if (x == 1) {
		std::cout << "Enter the polynom\n";
		Polinom b;
		std::cin >> b;
		std::cout << a + b;
	} 
	else if (x == 2) {
		std::cout << "Enter the polynom\n";
		Polinom b;
		std::cin >> b;
		std::cout << a * b;
	}
	else if (x == 3) {
		std::cout << "Enter the polynom\n";
		Polinom b;
		std::cin >> b;
		std::cout << a - b;
	}
	else if (x == 4) {
		std::cout << "Enter the const\n";
		double cons;
		std::cin >> cons;
		std::cout << a*cons;
	}
	else {
		throw("Incorect input");
	}
	return 0;
}