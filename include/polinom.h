#ifndef __POLINOM_H
#define __POLINOM_H

#include <iostream>

using namespace std;

#include "tlist.h"
#include "monom.h"

class Polinom : public TList<Monom>
{
    public:
        Polinom(Monom* monoms = nullptr, int km = 0);  // monoms - массив мономов
                                             // km - количество мономов в полиноме

        void CombineLikeTerms();     // привести подобные и убрать нулевые
        void Insert(const Monom& q);   // вставить на нужное место и привести подобные

        bool operator == (const Polinom& q) const;

        const Polinom& operator = (const Polinom& q);
        const Polinom operator + (const Polinom& q) const;
        const Polinom operator - (const Polinom& q) const;
        Polinom& operator += (const Polinom& q); //
        Polinom& operator *= (const Polinom& q); //
        Polinom operator * (double d) const; //
        Polinom operator * (const Monom& m) const; //
        Polinom operator * (const Polinom& q) const;

        friend istream& operator >> (istream& in, Polinom& p);
        friend ostream& operator << (ostream& os, const Polinom& p);

};


Polinom::Polinom(Monom* monoms, int km) : TList<Monom>()
{
    TLink<Monom>* curr = pHead;
    for (int i = 0; i < km; i++) {
        if (monoms[i].GetCoeff() > EPS) {
            TList<Monom>::Insert(monoms[i]);
        }
    }
}

void Polinom::CombineLikeTerms()
{
    TLink<Monom>* prev = pHead->pNext;
    TLink<Monom>* curr = prev->pNext;

    while (curr != pHead) {

        if (abs(prev->data.GetCoeff()) < EPS) {
            //cout << "q" << endl;
            Delete(prev);
            prev = prev->pNext;
            curr = curr->pNext;
        }
        else if ((prev->data).GetIndex() == (curr->data).GetIndex()) {
            prev->data += curr->data;
            prev->pNext = curr->pNext;
            curr = prev->pNext;
        }
        else {
            prev = prev->pNext;
            curr = curr->pNext;
        }

    }

    // проверяем на равенство нулю последний моном
    if (abs(prev->data.GetCoeff()) < EPS) {
        Delete(prev);
    }
}

void Polinom::Insert(const Monom& q)
{
    (*this).TList<Monom>::Insert(q);
    (*this).CombineLikeTerms();
}

bool Polinom::operator == (const Polinom& q) const
{
    if (GetLength() != q.GetLength()) {
        return false;
    }

    TLink<Monom>* curr1 = pHead->pNext;
    TLink<Monom>* curr2 = (q.pHead)->pNext;

    while (curr1 != pHead) {
        if (curr1->data != curr2->data) {
            return false;
        }
        curr1 = curr1->pNext;
        curr2 = curr2->pNext;
    }

    return true;
}

const Polinom& Polinom::operator = (const Polinom& q)
{
    if (this != &q) {
        TLink<Monom>* pCurr = pHead;        // указатель, которым идём по полиному this
        TLink<Monom>* walk = q.GetFirst();  // укзатель, которым идём по полиному q
        while (walk != q.GetHead()) {
            TLink<Monom>* tlink = new TLink<Monom>(walk->data);
            pCurr->pNext = tlink;
            pCurr = tlink;
            walk = walk->pNext;
        }
        pCurr->pNext = pHead;
    }
    return *this;
}

const Polinom Polinom::operator + (const Polinom& q) const
{
    Polinom res = (*this);
    res.Merge(q);
    res.CombineLikeTerms();
   // res.Reduce();
    return res;
}

Polinom& Polinom::operator += (const Polinom& q)
{
    (*this) = (*this) + q;
    return (*this);
}

Polinom Polinom::operator * (double d) const
{
    Polinom res(*this);
    TLink<Monom>* curr = res.pHead->pNext;
    while (curr != res.pHead) {
        curr->data = curr->data*d;
        curr = curr->pNext;
    }
    res.CombineLikeTerms();
    return res;
}

const Polinom Polinom::operator - (const Polinom& q) const
{
    Polinom res;
    res = (*this) + ((q)*(-1.0));
    return res;
}

Polinom Polinom::operator * (const Monom& m) const
{
    Polinom res(*this);
    TLink<Monom>* curr = (res.pHead)->pNext;
    while (curr != res.pHead) {
        curr->data = (curr->data) * m;
        curr = curr->pNext;
    }
    res.CombineLikeTerms();
    return res;
}

Polinom& Polinom::operator *= (const Polinom& q)
{
    Polinom temp;
    TLink<Monom>* curr2 = (q.pHead)->pNext;
    while (curr2 != q.pHead) {
        temp += (*this) * curr2->data;
        curr2 = curr2->pNext;
    }
    (*this) = temp;
    CombineLikeTerms();
    return *this;
}

Polinom Polinom::operator * (const Polinom& q) const
{
    Polinom res(*this);
    res *= q;
    res.CombineLikeTerms();
    return res;
}

istream& operator >> (istream& is, Polinom& p)
{
    int km;
    is >> km;
    for (int i = 0; i < km; i++) {
        Monom m;
        is >> m;
        p.Insert(m);
    }
    p.CombineLikeTerms();
    return is;
}

ostream& operator << (ostream& os, const Polinom& p)
{
    if (p.IsEmpty()) {
        os << "0";
        return os;
    }
    int length = p.GetLength();
    TLink<Monom>* curr = p.GetFirst();
    for (int i = 0; i < length; i++) {
        os << curr->GetDatValue() << endl;
        curr = curr->GetNextLink();
    }
    return os;
}



#endif
