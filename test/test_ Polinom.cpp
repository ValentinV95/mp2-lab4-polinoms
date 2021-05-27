//#include "utmatrix.h"
#include "Polinom.h"
//#include "..\..\include\Polinom.h"
#include <gtest.h>

TEST(Polinom, can_create_copied_Polinom)
{
	Monom m(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	ASSERT_NO_THROW(Polinom p1(p));
}
TEST(Polinom, can_create_Polinom_with_default_constructor)
{
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_add_two_Polinoms)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	EXPECT_NO_THROW(p.operator+(p1));
}

TEST(Polinom, can_out_add_two_Polinoms_with_different_Monoms_with_same_value)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	Polinom p2 = p + p1;
	string str = p2.toString();
	EXPECT_EQ(str, "2.000000x^1y^2z^3 \n");
}
TEST(Polinom, can_out_add_two_Polinoms_with_different_Monoms_with_different_coef)
{
	Monom m(1, 123);
	Monom m1(2, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	Polinom p2 = p + p1;
	string str = p2.toString();
	EXPECT_EQ(str, "3.000000x^1y^2z^3 \n");
}
TEST(Polinom, can_out_add_two_Polinoms_with_different_Monoms_with_different_step)
{
	Monom m(1, 123);
	Monom m1(1, 234);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	Polinom p2 = p + p1;
	string str = p2.toString();
	EXPECT_EQ(str, "1.000000x^1y^2z^3 + 1.000000x^2y^3z^4 \n");
}

TEST(Polinom, can_add_Polinom_with_itself)
{
	Monom m(1, 123);
	Polinom p;
	p.Add(&m);
	EXPECT_NO_THROW(p.operator+(p));
}

TEST(Polinom, can_out_add_Polinom_with_itself)
{
	Monom m(1, 123);
	Polinom p;
	p.Add(&m);
	Polinom p1 = p + p;
	string str = p1.toString();
	EXPECT_EQ(str, "2.000000x^1y^2z^3 \n");
}
TEST(Polinom, can_add_Polinoms_with_same_Monom)
{
	Monom m(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m);
	EXPECT_NO_THROW(p.operator+(p1));
}

TEST(Polinom, can_out_add_Polinoms_with_same_Monom)
{
	Monom m(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m);
	Polinom p2 = p + p1;
	string str = p2.toString();
	EXPECT_EQ(str, "2.000000x^1y^2z^3 \n");
}



TEST(Polinom, can_mult_two_Polinoms)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	EXPECT_NO_THROW(p.operator*(p1));
}

TEST(Polinom, can_out_mult_two_Polinoms_with_different_Monoms_with_same_value)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	Polinom p2 = p * p1;
	string str = p2.toString();
	EXPECT_EQ(str, "1.000000x^2y^4z^6 \n");
}
TEST(Polinom, can_out_mult_two_Polinoms_with_different_Monoms_with_different_coef)
{
	Monom m(1, 123);
	Monom m1(2, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	Polinom p2 = p * p1;
	string str = p2.toString();
	EXPECT_EQ(str, "2.000000x^2y^4z^6 \n");
}
TEST(Polinom, can_out_mult_two_Polinoms_with_different_Monoms_with_different_step)
{
	Monom m(1, 123);
	Monom m1(1, 234);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	Polinom p2 = p * p1;
	string str = p2.toString();
	EXPECT_EQ(str, "1.000000x^3y^5z^7 \n");
}
TEST(Polinom, can_mult_Polinoms_with_itself)
{
	Monom m(1, 123);
	Polinom p;
	p.Add(&m);
	EXPECT_NO_THROW(p.operator*(p));
}

TEST(Polinom, can_out_mult_Polinom_with_itself)
{
	Monom m(1, 123);
	Polinom p;
	p.Add(&m);
	Polinom p1 = p * p;
	string str = p1.toString();
	EXPECT_EQ(str, "1.000000x^2y^4z^6 \n");
}
TEST(Polinom, can_mult_Polinoms_with_same_Monom)
{
	Monom m(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m);
	EXPECT_NO_THROW(p.operator*(p1));
}

TEST(Polinom, can_out_mult_Polinoms_with_same_Monom)
{
	Monom m(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m);
	Polinom p2 = p * p1;
	string str = p2.toString();
	EXPECT_EQ(str, "1.000000x^2y^4z^6 \n");
}
TEST(Polinom, can_mult_by_constant_Polinoms)
{
	Monom m(1, 123);
	Polinom p;
	p.Add(&m);
	double w = 4;
	EXPECT_NO_THROW(p.operator*(w));
}
TEST(Polinom, can_out_mult_by_constant_Polinoms)
{
	Monom m(1, 123);
	Polinom p;
	p.Add(&m);
	double w = 4;
	Polinom p2 = p * w;
	string str = p2.toString();
	EXPECT_EQ(str, "4.000000x^1y^2z^3 \n");
	
}

TEST(Polinom, can_substraction_two_Polinoms)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	EXPECT_NO_THROW(p.operator-(p1));
	
}
TEST(Polinom, can_out_substraction_two_Polinoms_with_different_Monoms_with_same_value)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	Polinom p2 = p - p1;
	string str = p2.toString();
	EXPECT_EQ(str, "0.000000x^1y^2z^3 \n");
}
TEST(Polinom, can_out_substraction_two_Polinoms_with_different_Monoms_with_different_coef)
{
	Monom m(1, 123);
	Monom m1(2, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	Polinom p2 = p1 - p;
	string str = p2.toString();
	EXPECT_EQ(str, "1.000000x^1y^2z^3 \n");
}
TEST(Polinom, can_out_substraction_two_Polinoms_with_different_Monoms_with_different_step)
{
	Monom m(1, 123);
	Monom m1(1, 234);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m1);
	Polinom p2 = p - p1;
	string str = p2.toString();
	EXPECT_EQ(str, "1.000000x^1y^2z^3 + -1.000000x^2y^3z^4 \n");
}
TEST(Polinom, can_substraction_Polinoms_with_itself)
{
	Monom m(1, 123);
	Polinom p;
	p.Add(&m);
	EXPECT_NO_THROW(p.operator-(p));
}

TEST(Polinom, can_out_substraction_Polinom_with_itself)
{
	Monom m(1, 123);
	Polinom p;
	p.Add(&m);
	Polinom p1 = p - p;
	string str = p1.toString();
	EXPECT_EQ(str, "0.000000x^1y^2z^3 \n");
}
TEST(Polinom, can_substraction_Polinoms_with_same_Monom)
{
	Monom m(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m);
	EXPECT_NO_THROW(p.operator-(p1));
}

TEST(Polinom, can_out_substraction_Polinoms_with_same_Monom)
{
	Monom m(1, 123);
	Polinom p;
	Polinom p1;
	p.Add(&m);
	p1.Add(&m);
	Polinom p2 = p - p1;
	string str = p2.toString();
	EXPECT_EQ(str, "0.000000x^1y^2z^3 \n");
}



