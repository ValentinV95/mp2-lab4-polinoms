#pragma warning(disable:4267)
#include "pch.h"
#include "Polynomial.h"


Polynomial::Polynomial(List _monoms){
    List* l = new List();
    *l = _monoms;
    this->monoms = *l;
}

Polynomial Polynomial::sum(const Polynomial p) {
    /*Polynomial pol = Polynomial(p.getMonoms());
    //List *lst = new List();
    //pol->monoms = (this->getMonoms());
    //lst.display();
    Polynomial out = Polynomial(List());
    for (int i = 0; i < this->monoms.length(); i++) {
        pol.monoms.add(this->monoms[i]);
    }
    //Polynomial *pol = new Polynomial(lst);
    out.monoms = pol.monoms;
    return out;*/
    List l = List();
    for (size_t i = 0; i < this->monoms.length(); i++)
    {
        l.add(monoms[i]);
    }
    Polynomial pol = Polynomial(l);
    //List l = this->getMonoms();
    for (int i = 0; i < p.getMonoms().length(); i++ ) {
        pol.monoms.add(p.getMonoms()[i]);
    }
    //pol.getMonoms().display();
    return pol.getMonoms();
}

Polynomial Polynomial::mult(Polynomial& p) {
    int p_size = p.getMonoms().length();
    Polynomial* pol = new Polynomial(List());
    Polynomial out = Polynomial(List());

    for (int i = 0; i < p_size; i++) {
        //this->getMonoms().display();
        pol->monoms = this->mult(p.monoms[i]);
        for (int j = 0; j < pol->monoms.length(); j++) {
            out.monoms.add(pol->monoms[j]);
        }
    }
    return out;
}

List Polynomial::mult(Monomial m) {
    int gx;
    int gy;
    int gz;
    List lst = List();
    for (int i = 0; i < monoms.length(); i++) {

        gx = monoms[i].getGradeX() + m.getGradeX();
        gy = monoms[i].getGradeY() + m.getGradeY();
        gz = monoms[i].getGradeZ() + m.getGradeZ();

        if ((gx > 9) || (gy > 9) || (gz > 9)) {
            return List();      // coeff out of range
        }
        lst.add(Monomial(monoms[i].getCoeff() * m.getCoeff(), gx * 100 + gy * 10 + gz));

    }
    return lst;
}

Polynomial Polynomial::subtr(Polynomial p) {
    Monomial mon(-1, 0);
    p.setMonoms(p.mult(mon));
    return this->sum(p);
}

void Polynomial::setMonoms(List _monoms) {
    this->monoms = _monoms;
}

List Polynomial::getMonoms() const{
    return this->monoms;
}

Polynomial operator+(Polynomial& lp, Polynomial& rp) {
    //p.setMonoms(lp.getMonoms());
    return lp.sum(rp); // Polynomial result = 222+(lp
}

Polynomial operator*(Polynomial& lp, Polynomial& rp) {
    return lp.mult(rp);
}

Polynomial operator-(Polynomial& lp, Polynomial& rp) {
    return lp.subtr(rp);
}