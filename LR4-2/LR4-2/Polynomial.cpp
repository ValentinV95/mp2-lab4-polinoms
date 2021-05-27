#include "pch.h"
#include "Polynomial.h"

Polynomial::Polynomial(List _monoms)
    : monoms(_monoms) {}

Polynomial Polynomial::sum(Polynomial& p) {
    List lst = List();
    lst = this->monoms;
    for (int i = 0; i < p.monoms.length(); i++) {
        lst.add(p.monoms[i]);
    }
    Polynomial pol = Polynomial(lst);

    return pol;
}

Polynomial Polynomial::mult(Polynomial& p) {
    int p_size = p.monoms.length();
    Polynomial* pol = new Polynomial(List());
    Polynomial out = Polynomial(List());

    for (int i = 0; i < p_size; i++) {
        this->getMonoms().display();
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

List Polynomial::getMonoms() {
    return this->monoms;
}

Polynomial operator+(Polynomial& lp, Polynomial& rp) {
    return lp.sum(rp); // Polynomial result = 222+(lp
}

Polynomial operator*(Polynomial& lp, Polynomial& rp) {
    return lp.mult(rp);
}

Polynomial operator-(Polynomial& lp, Polynomial& rp) {
    return lp.subtr(rp);
}