// тесты 


#include "arithmetic.h"
#include <gtest.h>



TEST(Polynom, can_make_polynom)
{
	ASSERT_NO_THROW(Polynom A);
}

TEST(Polynom, can_make_polynom_like_another_one)
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	Polynom B(A);
	EXPECT_EQ(A, B);
}

TEST(Polynom, cant_insert_a_monom_with_wrong_degree)
{
	Polynom A;
	EXPECT_ANY_THROW(A.Insert(5, 2000));
}


TEST(Polynom, can_insert_monom_in_the_end)
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	A.Insert(4, 444);
	for (int i = 0; i < 4; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom B(pol, 4);
	EXPECT_EQ(A, B);
}

TEST(Polynom, can_insert_monom_in_the_begin) 
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 2;
		pol[i].deg = 100 * (i + 2) + 10 * (i + 2) + i + 2;
	}
	Polynom A(pol, 3);
	A.Insert(1, 111);
	for (int i = 0; i < 4; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom B(pol, 4);
	EXPECT_EQ(A, B);
}

TEST(Polynom, can_insert_existing_monom) 
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	A.Insert(3, 333);
	for (int i = 0; i < 2; i++)
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	pol[2].coef = 6;
	pol[2].deg = 333;
	Polynom B(pol, 3);
	EXPECT_EQ(A, B);
}



TEST(Polynom, cant_insert_monom_with_zero_coef)
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	Polynom B(A);
	A.Insert(0, 444);
	EXPECT_EQ(A, B);
}

TEST(Polynom, can_delete_monom_in_the_end)
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	A.Delete(333);
	for (int i = 0; i < 2; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom B(pol, 2);
	EXPECT_EQ(A, B);
}

TEST(Polynom, can_delete_monom_in_the_begin) 
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	A.Delete(111);
	for (int i = 0; i < 2; i++) 
	{
		pol[i].coef = i + 2;
		pol[i].deg = 100 * (i + 2) + 10 * (i + 2) + i + 2;
	}
	Polynom B(pol, 2);
	EXPECT_EQ(A, B);
}

TEST(Polynom, can_check_emptiness) 
{
	Polynom A;
	EXPECT_EQ(A.IsEmpty(), true);
}

TEST(Polynom, can_assign_polynoms) 
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	Polynom B(A);
	Polynom C;
	C = A;
	EXPECT_EQ(C, B);
}

TEST(Polynom, can_add_polynoms_with_different_sizes) 
{

	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	for (int i = 0; i < 4; i++) {
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom B(pol, 4);
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = 2 * (i + 1);
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	pol[3].coef = 4;
	pol[3].deg = 444;
	Polynom C(pol, 4);
	EXPECT_EQ(A + B, C);
}

TEST(Polynom, can_add_polynoms_with_equal_sizes) 
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 2;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom B(pol, 3);
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = 2 * i + 3;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom C(pol, 3);
	EXPECT_EQ(A + B, C);
}

TEST(Polynom, can_subtract_polynoms_with_equal_sizes) 
{
	struct Monom* pol;
	pol = new Monom[5];
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 1;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom A(pol, 3);
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = i + 2;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom B(pol, 3);
	for (int i = 0; i < 3; i++) 
	{
		pol[i].coef = -1.0;
		pol[i].deg = 100 * (i + 1) + 10 * (i + 1) + i + 1;
	}
	Polynom C(pol, 3);
	Polynom D;
	D = A - B;
	EXPECT_EQ(A - B, C);
}

TEST(Polynom, cant_multiply_polynoms_with_too_big_degs) 
{
	Polynom A;
	A.Insert(7, 777);
	Polynom B;
	B.Insert(8, 888);
	EXPECT_ANY_THROW(A*B);
}
