#include "pch.h"
#include "Monomial.h"


Monomial::Monomial() {}

Monomial::Monomial(double _coeff, int _grade) : grade(_grade), coeff(_coeff) {}


double Monomial::getCoeff() const {
    return this->coeff;
}

void Monomial::setCoeff(double _coeff) {
    this->coeff = _coeff;
}

int Monomial::getGradeX() {
    return this->grade / 100;
}

int Monomial::getGradeY() {
    return this->grade / 10 % 10;
}

int Monomial::getGradeZ() {
    return this->grade % 10;
}

int Monomial::countPower() {
    return this->getGradeX() + this->getGradeY() + this->getGradeZ();
}

int Monomial::getGrade() {
    return this->grade;
}

void Monomial::displaySingleMonom() {
    std::cout << "(" << this->getCoeff() << ", " << this->countPower() << ", " << this->getGrade() << ")" << std::endl;
}

void Monomial::setGrade(int _grade) {
    this->grade = _grade;
}