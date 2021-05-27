#include "pch.h"
#include "../LR4-2/Monomial.h"
#include "../LR4-2/Monomial.cpp"
#include "../LR4-2/Polynomial.h"
#include "../LR4-2/Polynomial.cpp"
#include "../LR4-2/List.h"
#include "../LR4-2/List.cpp"

TEST(TestMathOperators, TestingPlus) {
    Monomial m1 = Monomial(1, 110);
    Monomial m2 = Monomial(2, 120);
    Monomial m3 = Monomial(-1, 110);
    Monomial m4 = Monomial(3.5, 120);

    List l1 = List();
    List l2 = List();

    l1.add(m1);
    l1.add(m2);
    l2.add(m3);
    l2.add(m4);

    Polynomial p1 = Polynomial(l1);
    Polynomial p2 = Polynomial(l2);

    Polynomial test = p1 + p2;

    test.getMonoms().display();
}

TEST(TestMathOperators, TestMultiple) {
    Monomial m1 = Monomial(1, 110);
    Monomial m2 = Monomial(2, 120);
    Monomial m3 = Monomial(-1, 110);
    Monomial m4 = Monomial(3.5, 120);

    List l1 = List();
    List l2 = List();

    l1.add(m1);
    l1.add(m2);
    l2.add(m3);
    l2.add(m4);

    Polynomial p1 = Polynomial(l1);
    Polynomial p2 = Polynomial(l2);

    Polynomial test = p1 * p2;

    test.getMonoms().display();
}

TEST(TestMathOperators, TestingMinus) {
    Monomial m1 = Monomial(1, 110);
    Monomial m2 = Monomial(2, 120);
    Monomial m3 = Monomial(-1, 110);
    Monomial m4 = Monomial(3.5, 120);

    List l1 = List();
    List l2 = List();

    l1.add(m1);
    l1.add(m2);
    l2.add(m3);
    l2.add(m4);

    Polynomial p1 = Polynomial(l1);
    Polynomial p2 = Polynomial(l2);

    Polynomial test = p1 - p2;

    test.getMonoms().display();
}