//#include "utmatrix.h"

#include "Monom.h"

#include <gtest.h>

TEST(Monom, can_create_Monom_with_default_constructor)
{
	ASSERT_NO_THROW(Monom m);
}

TEST(Monom, cant_create_Monom_zero_coefficient)
{
  ASSERT_ANY_THROW(Monom m(0, 1));
}

TEST(Monom, can_create_Monom_with_not_negative_step)
{
	ASSERT_NO_THROW(Monom m(1,123));
}
TEST(Monom, cant_create_Monom_negative_step)
{
	ASSERT_ANY_THROW(Monom m(1,-123));
}
TEST(Monom, cant_create_Monom_with_too_large_step)
{
	ASSERT_ANY_THROW(Monom m(1,1000));
}

TEST(Monom, can_create_copied_Monom)
{
  Monom m(1, 123);

  ASSERT_NO_THROW(Monom m1(m));
}

TEST(Monom, copied_Monom_is_equal_to_source_one)
{
	Monom m(1, 123);
	Monom m1(m);
	EXPECT_EQ(m.GetStep(),m1.GetStep());
	EXPECT_EQ(m.GetCoef(), m1.GetCoef());
}

TEST(Monom, can_get_coef)
{
  Monom m(1, 123);

  EXPECT_EQ(1, m.GetCoef());
}
TEST(Monom, can_get_step)
{
	Monom m(1,123);

	EXPECT_EQ(123, m.GetStep());
}
TEST(Monom, cant_set_zero_coef)
{
	Monom m(1, 123);
	EXPECT_ANY_THROW( m.SetCoef(0.0));
}

TEST(Monom, can_add_two_Monoms)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	EXPECT_NO_THROW(m.Plus(&m1));
}
TEST(Monom, can_add_Monoms_with_itself)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	m.Plus(&m1);
	EXPECT_EQ(m.GetStep(), m1.GetStep());
	EXPECT_EQ(m.GetCoef(),2);
}
TEST(Monom, can_mult_two_Monoms)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	EXPECT_NO_THROW(m.Mult(m1));
}

TEST(Monom, can_mult_Monoms_with_itself)
{
	Monom m(1, 123);
	Monom m1(1, 123);
	Monom m2=m.Mult(m1);

	EXPECT_EQ(m2.GetStep(), 246);
	EXPECT_EQ(m2.GetCoef(), 1);
}


