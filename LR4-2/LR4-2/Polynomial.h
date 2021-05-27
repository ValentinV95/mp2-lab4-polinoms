#pragma once
#include "List.h"


class Polynomial {
private:
    List monoms;
    List mult(Monomial m);
public:
    Polynomial(List _monoms);
    List getMonoms();
    Polynomial sum(Polynomial& p);
    Polynomial mult(Polynomial& p);
    Polynomial subtr(Polynomial p);

    void setMonoms(List _monoms);

};


Polynomial operator  +(Polynomial& lp, Polynomial& rp);

Polynomial operator *(Polynomial& lp, Polynomial& rp);

Polynomial operator -(Polynomial& lp, Polynomial& rp);

