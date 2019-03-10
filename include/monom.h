﻿#ifndef __MONOM_H
#define __MONOM_H

#define EPS 0.0000000001
#include "exception.h"

class Monom
{
    private:
        double coeff_;
        int index_;
        int sum_;
    public:
        Monom(double coeff = 0.0, int index = -1);
        Monom(const Monom& q);

        double GetCoeff();
        int GetIndex();
        int GetSum();

        void SetCoeff(double coeff);
        void SetIndex(int index);

        bool operator != (const Monom& q) const;
        bool operator == (const Monom& q) const;
        bool operator < (const Monom& q) const;
        bool operator > (const Monom& q) const;

        const Monom& operator = (const Monom& q);
        Monom& operator += (const Monom& q);
        const Monom operator + (const Monom& q) const;
        Monom operator * (double d) const;
        Monom operator * (int i) const;
        Monom& operator -= (const Monom& q);
        const Monom operator - (const Monom& q) const;
        Monom& operator *= (const Monom& q);
        const Monom operator * (const Monom& q) const;

        friend ostream& operator << (ostream& os, const Monom& m);
        friend istream& operator >> (istream& is, Monom& m);

};



Monom::Monom(double coeff, int index)
{
    if (index > 999) {
        throw Exception("incorrect index monom: max degree greater than 9");
    }
    else if (index < -1) {
        throw Exception("monom`s index cannot be less than 0");
    }
    coeff_ = coeff;
    index_ = index;
    sum_ = 0;
    while (index) {
        sum_ += index % 10;
        index /= 10;
    }
}

Monom::Monom(const Monom& q)
{
    coeff_ = q.coeff_;
    index_ = q.index_;
    sum_ = q.sum_;
}

double Monom::GetCoeff()
{
    return coeff_;
}

int Monom::GetIndex()
{
    return index_;
}

int Monom::GetSum()
{
    return sum_;
}

void Monom::SetCoeff(double coeff)
{
    coeff_ = coeff;
}

void Monom::SetIndex(int index)
{
    Monom tmp(coeff_, index);
    index_ = tmp.index_;
    sum_ = tmp.sum_;
}

bool Monom::operator == (const Monom& q) const
{
    return (((coeff_ - q.coeff_) < EPS) && (index_ == q.index_) && (sum_ == q.sum_));
}

bool Monom::operator != (const Monom& q) const
{
    return !((*this) == q);
}

bool Monom::operator < (const Monom& q) const
{
    return index_ < q.index_;
}

bool Monom::operator > (const Monom& q) const
{
    return index_ > q.index_;
}

const Monom& Monom::operator = (const Monom& q)
{
    if (this != &q) {
        coeff_ = q.coeff_;
        index_ = q.index_;
        sum_ = q.sum_;
    }
    return *this;
}

Monom& Monom::operator += (const Monom& q)
{
    if (index_ != q.index_) {
        throw Exception("cannot add monoms with different index");
    }

    coeff_ += q.coeff_;
    return *this;
}

const Monom Monom::operator + (const Monom& q) const
{
    Monom res(*this);
    res += q;
    return res;
}

Monom Monom::operator * (double d) const
{
    Monom res(*this);
    res.coeff_ *= d;
    return res;
}

Monom Monom::operator * (int i) const
{
    Monom res(*this);
    res.coeff_ *= i;
    return res;
}

Monom& Monom::operator -= (const Monom& q)
{
    (*this) += q * (-1);

    return *this;
}

const Monom Monom::operator - (const Monom& q) const
{
    Monom res(*this);
    res -= q;
    return res;
}

Monom& Monom::operator *= (const Monom& q)
{
    *this = (*this) * q;
    return *this;
}

const Monom Monom::operator * (const Monom& q) const
{
    Monom res(coeff_ * q.coeff_, (index_ + q.index_));
    
    // делаем проверку на превышение максимальной степени для ненулевых мономов
    if (res.sum_ != (sum_ + q.sum_) && (res.coeff_ > EPS)) {
        throw Exception("cannot multiply monoms: max degree greater than 9");
    }
    return res;
}

istream& operator >> (istream& is, Monom& m)
{
    string s_coeff;
    is >> s_coeff;
    string s_index;
    is >> s_index;

    size_t pos = 0;
    double coeff = stod(s_coeff, &pos);
    int index = stoi(s_index, &pos);

    Monom s(coeff, index);
    m = s;

    return is;
}

ostream& operator << (ostream& os, const Monom& m)
{
    os << "(" << m.coeff_ << "," << m.index_ << ")";
    return os;
}





#endif