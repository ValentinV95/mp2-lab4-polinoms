#include "polynom.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� ����� ������:" << endl << "1. ������� ��������� �� ������� �� ���� ����������." << endl << "2. ������� ������ �� ���������� ������ - ��������������� ����� �����,�� ������������ 9." << endl  
		 << "3. ������������ ������ - ������������ �����" << endl;
	cout << "������� 2 ��������:" << endl;
	Polynom a, b;
	ret_1:
	try
	{
		cout << "������ �������:" << endl;
		cin >> a;
		cout << "������ �������:" << endl;
		cin >> b;
	}
	catch (string err)
	{
		cout << "�� ����� ������������ ������� ��������. ��������� ����";
		goto ret_1;
	}
	int in;
	cout << "��������� ��������: " << endl;
	cout << "a = " << a << endl << "b = " << b << endl;
	ret_2:
	cout << "�������� ���� �� ��������:" << endl;
	cout << "1. a + b" << endl;
	cout << "2. a - b" << endl;
	cout << "3. b - a" << endl;
	cout << "4. a * b" << endl;
	cin >> in;
	if (in < 1 || in > 4)
	{
		cout << "������������ ����� ��������. ��������� ����.";
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
			cout << "��������� ������������ ��� ���������.";
		}		
	}
}