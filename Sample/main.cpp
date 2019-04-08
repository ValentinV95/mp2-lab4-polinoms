#include "polynom.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Правила ввода данных:" << endl << "1. Полином составлен из мономов от трех переменных." << endl << "2. Степень каждой из переменных монома - неотрицательное целое число,не превышаеющее 9." << endl  
		 << "3. Коэффициенты монома - вещественные числа" << endl;
	cout << "Введите 2 полинома:" << endl;
	Polynom a, b;
	ret_1:
	try
	{
		cout << "Первый полином:" << endl;
		cin >> a;
		cout << "Второй полином:" << endl;
		cin >> b;
	}
	catch (string err)
	{
		cout << "Вы ввели некорректную степень полинома. Повторите ввод";
		goto ret_1;
	}
	int in;
	cout << "Введенные полиномы: " << endl;
	cout << "a = " << a << endl << "b = " << b << endl;
	ret_2:
	cout << "Выберите одну из операций:" << endl;
	cout << "1. a + b" << endl;
	cout << "2. a - b" << endl;
	cout << "3. b - a" << endl;
	cout << "4. a * b" << endl;
	cin >> in;
	if (in < 1 || in > 4)
	{
		cout << "Некорректный выбор операции. Повторите ввод.";
		goto ret_2;
	}
	else
	{
		try
		{
			switch (in)
			{
			case 1:
			{
				cout << "a + b = " << a + b << endl;
				break;
			}
			case 2:
			{
				cout << "a - b = " << a - b << endl;
				break;
			}
			case 3:
			{
				cout << "b - a = " << b - a << endl;
				break;
			}
			case 4:
			{
				cout << "a * b = " << a * b << endl;
				break;
			}
			}
		}
		catch (string a)
		{
			cout << "Произошло переполнение при умножении.";
		}		
	}
}