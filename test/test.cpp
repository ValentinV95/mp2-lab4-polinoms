#include <gtest.h>
#include "pol.h"
TEST(pol, can_monom)
{
	ASSERT_NO_THROW(monom  a);
}
TEST(pol, can_polinom)
{
	ASSERT_NO_THROW(pol A);
}
TEST(pol, can_insert)
{
	monom a(1, 100);
	pol A;
	ASSERT_NO_THROW( A.insert(a) );
}
TEST(pol, EQ_polinoms)
{
	monom a(1, 100);
	pol A, B;
	A.insert(a);
	B.insert(a);
	EXPECT_EQ ( B, A );
}
TEST(pol, EQ_EQpolinoms)
{
	monom a(1, 100);
	pol A, B;
	A.insert(a);
	B = A;
	EXPECT_EQ(B , A);
}
TEST(pol, NE_polinoms_same_size)
{
	monom a(1, 100), b(-1, 100);
	pol A, B;

	A.insert(a);

	B.insert(b);

	EXPECT_NE(B, A);
}
TEST(pol, NE_polinoms_diff_size)
{
	monom a(1, 100), b(-1, 100);
	pol A, B;
	A.insert(a);

	B.insert(a);
	B.insert(b);

	EXPECT_NE(B, A);
}
TEST(pol, can_mult_polinom_const)
{
	monom a(1, 100);
	pol A;
	A.insert(a);
	ASSERT_NO_THROW(A * 9);
}
TEST(pol, mult_polinom_const)
{
	monom a(1, 100), b(9, 100);
	pol A, B;
	A.insert(a);

	B.insert(b);
	
	EXPECT_EQ(B, A*9);
}
TEST(pol, mult_polinoms)
{
	monom a(1, 100), b(-1, 100), c(-1, 200);
	pol A, B, C;
	A.insert(a);

	C.insert(c);

	B.insert(b);
	EXPECT_EQ(C, A*B);
}
TEST(pol, add_polinoms)
{
	monom a(1, 100), b(1, 10);
	pol A, B, C;
	A.insert(a);

	B.insert(a);
	B.insert(b);

	C.insert(a);
	C.insert(a);
	C.insert(b);

	EXPECT_EQ(C, A+B);
}
TEST(pol, insert_same_monoms)
{
	monom a(1, 100), b(2, 100);
	pol A, B;

	A.insert(a);
	A.insert(a);

	B.insert(b);

	EXPECT_EQ(A, B);
}
TEST(pol, add_same_monoms)
{
	monom a(1, 100), b(2, 100);
	pol A, B, C;

	A.insert(a);

	B.insert(a);

	C.insert(b);

	EXPECT_EQ(C, B+A);
}
TEST(pol, add_opposite_monoms)
{
	monom a(1, 100), a1(1, 10), b(-1, 100);
	pol A, B, C;

	A.insert(a);
	A.insert(a1);

	B.insert(b);

	C.insert(a1);

	EXPECT_EQ(C, B + A);
}
TEST(pol, insert_monom_with_wrong_power)
{
	pol A;
	monom a(1, 1000);
	ASSERT_ANY_THROW(A.insert(a));
}
TEST(pol, insert_monom_with_wrong_nepower)
{
	pol A;
	monom a(1, -1);
	ASSERT_ANY_THROW( A.insert(a));
}
TEST(pol, insert_monom_with_wrong_coeff)
{
	pol A;
	monom a(0, 100);
	ASSERT_ANY_THROW(A.insert(a));
}
TEST(pol, mult_polinoms_with_large_power)
{
	pol A, B;
	monom a(1, 199), b(1, 30);

	A.insert(a);
	B.insert(b);

	ASSERT_ANY_THROW( A*B);
}
TEST(pol, compose1_polinoms)
{
	monom a(1, 100), b(10, 100);
	pol A, B, C;

	A.insert(a);

	B.insert(a);

	C.insert(b);

	EXPECT_EQ(C, B*9 + A);
}
TEST(pol, add_3polinoms)
{
	monom a(3, 100), b(1, 1), c(2, 10);
	pol A, B, C, D;

	A.insert(a);

	B.insert(b);

	C.insert(c);

	D.insert(a);
	D.insert(b);
	D.insert(c);
	
	EXPECT_EQ(D, A+C+B);
}
TEST(pol, mult_3polinoms)
{
	monom a(3, 100), b(1, 1), c(2, 10), d(6, 111);
	pol A, B, C, D;

	A.insert(a);

	B.insert(b);

	C.insert(c);

	D.insert(d);	

	EXPECT_EQ(D, A * C * B);
}
TEST(pol, compose_3polinoms)
{
	monom a(3, 100), b(1, 1);
	pol A, B, C;

	A.insert(a);

	B.insert(b);	
	
	C = B*(-1);

	EXPECT_EQ(A, A + C + B);
}
