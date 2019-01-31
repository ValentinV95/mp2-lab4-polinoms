#include "gtest.h"
#include "Polynoms.h"
#include<string>


TEST(Polynom, create_polynom)
{
	ASSERT_NO_THROW(Polynom A);
}

TEST(Polynom, add_polimons_with_different_exponents_and_equal_sizes)
{
	string t1 = "1x1y1z1+2x1y2z2";
	string t2 = "1x1y1z1+2x1y2z2";
	string t3 = "2x1y1z1+4x1y2z2";
	Polynom A(t1);
	Polynom B(t2);
	Polynom C(t3);
	Polynom D(A + B);
	EXPECT_EQ(D, C);
}

TEST(Polynom, add_polimons_with_different_exponents_and_different_sizes)
{
	string t1 = "1x1y1z1+2x1y2z2";
	string t2 = "2x2y2z2";
	string t3 = "1x1y1z1+2x1y2z2+2x2y2z2"; ;
	Polynom A(t1);
	Polynom B(t2);
	Polynom C(t3);
	Polynom D(A + B);
	EXPECT_EQ(D, C);
}

TEST(Polynom, add_polimons_with_equal_exponents_and_opposite_coefficients)
{
	string t1 = "1x1y1z1+2x2y2z2";
	string t2 = "-1x1y1z1-2x2y2z2";
	Polynom A(t1);
	Polynom B(t2);
	Polynom D(A + B);
	EXPECT_EQ(D.GetCf(), 0);
}

TEST(Polynom, sub_polimons_with_different_exponents_and_equal_sizes)
{
	string t1 = "1x1y1z1+2x1y2z2";
	string t2 = "1x1y1z1+3x1y2z2";
	string t3 = "-1x1y2z2";
	Polynom A(t1);
	Polynom B(t2);
	Polynom C(t3);
	Polynom D(A - B);
	EXPECT_EQ(D, C);
}

TEST(Polynom, sub_polimons_with_different_exponents_and_different_sizes)
{
	string t1 = "1x1y1z1+2x1y2z2+3x1y2z3";
	string t2 = "1x1y1z1+3x1y2z2";
	string t3 = "1x1y1z1-1x1y2z2+3x1y2z3";
	Polynom A(t1);
	Polynom B(t2);
	Polynom C(t3);
	Polynom D(A - B);
	EXPECT_EQ(D, C);
}


TEST(Polynom, sub_polimons_with_equal_exponents_and_equal_coefficients)
{
	string t1 = "1x1y1z1+2x1y2z2";
	string t2 = "1x1y1z1+2x1y2z2";
	string t3 = "x1y1z1";
	Polynom A(t1);
	Polynom B(t2);
	Polynom C(t3);
	Polynom D(A - B);
	EXPECT_EQ(D, C);
}

TEST(Polynom, multiply_polynom_by_polynom)
{
	string t1 = "1x1y1z1+2x1y2z2";
	string t2 = "2x1y1z1+3x1y1z2";
	string t3 = "6x2y3z4+4x2y3z3+3x2y2z3+2x2y2z2";
	Polynom A(t1);
	Polynom B(t2);
	Polynom C(t3);
	Polynom D(A*B);
	EXPECT_EQ(D, C);
}
