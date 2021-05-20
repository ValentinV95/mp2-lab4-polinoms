#pragma once
#include <iostream>




class Monomial {
private:
	double coeff;
	int grade;

public:

	bool is_eq(Monomial m) {
		if ((grade == m.getGrade()) && (coeff == m.getCoeff())) {
			return true;
		}
		return false;
	}

	int getGradeX();//div 100
	int getGradeY();//div 10 %10  123->12->2
	int getGradeZ();//%10


	double getCoeff() const;

	int getGrade();

	void setGrade(int _grade);

	void setCoeff(double _coeff);

	int countPower();

	Monomial();

	Monomial(double _coeff, int _grade);

	void displaySingleMonom();
};
