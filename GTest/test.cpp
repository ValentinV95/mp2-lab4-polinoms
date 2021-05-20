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
	EXPECT_EQ(test.getMonoms().length(), 1);
	EXPECT_EQ(test.getMonoms()[0].is_eq(Monomial(5.5, 120)), true);
	// test.getMonoms().display();
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
	EXPECT_EQ(test.getMonoms().length(), 3);
	EXPECT_EQ(test.getMonoms()[0].is_eq(Monomial(-1,220)), true);
	EXPECT_EQ(test.getMonoms()[1].is_eq(Monomial(1.5, 230)), true);
	EXPECT_EQ(test.getMonoms()[2].is_eq(Monomial(7, 240)), true);

	// test.getMonoms().display();
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
	EXPECT_EQ(test.getMonoms().length(), 2);
	EXPECT_EQ(test.getMonoms()[0].is_eq(Monomial(2, 110)), true);
	EXPECT_EQ(test.getMonoms()[1].is_eq(Monomial(-1.5, 120)), true);
	//test.getMonoms().display();
}


TEST(TestListFunc, testingAddFunction) {
	List lst = List();

	EXPECT_EQ(lst.length(), 0);

	Monomial insert1 = Monomial(1,1);
	Monomial insert2 = Monomial(1, 110);
	Monomial insert3 = Monomial(1, 101);
	Monomial insert4 = Monomial(1, 110);
	
	lst.add(insert1);

	EXPECT_EQ(lst.length(), 1);
	EXPECT_EQ(lst[0].is_eq(insert1), true);

	lst.add(insert2);

	EXPECT_EQ(lst.length(), 2);
	EXPECT_EQ(lst[0].is_eq(insert1), true);
	EXPECT_EQ(lst[1].is_eq(insert2), true);

	lst.add(insert3);//Ёлемент 3 добавл€етс€ перед элементом 2 тк степень  элемента 2 больше

	EXPECT_EQ(lst.length(), 3);
	EXPECT_EQ(lst[0].is_eq(insert1), true);
	EXPECT_EQ(lst[1].is_eq(insert3), true);
	EXPECT_EQ(lst[2].is_eq(insert2), true);


	lst.add(insert4);//Ёлемент 4 прибавл€етс€ к элементу 2 тк их степени совпали 

	EXPECT_EQ(lst.length(), 3);
	EXPECT_EQ(lst[0].is_eq(insert1), true);
	EXPECT_EQ(lst[1].is_eq(insert3), true);
	insert2.setCoeff(2);
	EXPECT_EQ(lst[2].is_eq(insert2), true);
	
	EXPECT_EQ(lst[2].getCoeff(), 2);

}

TEST(TestListFunc, testingDeleteFunction){
	List lst = List();
	//EXPECT_EQ(lst.length(), 0);

	Monomial insert1 = Monomial(1, 1);
	Monomial insert2 = Monomial(1, 10);
	Monomial insert3 = Monomial(1, 100);
	Monomial insert4 = Monomial(1, 110);
	Monomial insert5 = Monomial(1, 111);

	lst.add(insert1);
	lst.add(insert2);
	lst.add(insert3);
	lst.add(insert4);
	lst.add(insert5);

	//”далим первый,последний, центральный, затем все элементы из списка(элементы ins1-ins5 располагаютс€ в листе последовательно)
	lst.deleteMonom(insert1);

	EXPECT_EQ(lst[0].is_eq(insert2), true);
	EXPECT_EQ(lst.length(), 4);

	lst.deleteMonom(insert5);

	EXPECT_EQ(lst.length(), 3);
	EXPECT_EQ(lst[lst.length()-1].is_eq(insert4), true);

	lst.deleteMonom(insert3);

	EXPECT_EQ(lst.length(), 2);
	EXPECT_EQ(lst[0].is_eq(insert2), true);
	EXPECT_EQ(lst[lst.length()-1].is_eq(insert4), true);
}