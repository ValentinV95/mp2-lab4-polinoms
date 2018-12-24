#pragma once
#include "stdafx.h"
#include <iostream>
using namespace std;
class Monom;
typedef Monom* Link; //��������� �� �����
class Monom {
	int power; //�������
	int cf;    //����������� 
	Link pointer;   //��������� �� ����.�����
public:
	Monom(int _power = 0, int _cf = 0, Link _pointer = NULL) // ����������� �������������
	{
		power = _power;
		cf = _cf;
		pointer = _pointer;
	}
	void SetPower(int _power)//��������� �������
	{
		power = _power;
	}
	void SetCf(int _cf) //��������� ����
	{
		cf = _cf;
	}
	void SetPointer(Link _pointer) //��������� ���������
	{
		pointer = _pointer;
	}
	int GetPower(void) const //�������� ������� 
	{
		return power;
	}
	int GetCf(void) const //�������� ����
	{
		return cf;
	}
	Monom* GetPointer(void) const  // �������� ���� ����� 
	{
		return pointer;
	}
};