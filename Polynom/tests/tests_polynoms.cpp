#include "gtest.h"
#include "Polynoms.h"

TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom a;);
}

TEST(Polynom, can_add_monom)
{
	Polynom a;
	a.insert(1, 101);
	EXPECT_EQ(true, a.find(1, 101));
}

TEST(Polynom, can_del_monom)
{
	Polynom a;
	a.insert(1, 101);
	Monom b(1, 101);
	a.del(b);
	EXPECT_EQ(false, a.find(1, 101));
}

TEST(Polynom, can_clear_polynom)
{
	Polynom a;
	a.insert(1, 101);
	a.clear();
	EXPECT_EQ(0, a.getSize());
}

TEST(Polynom, can_find_in_polynom)
{
	Polynom a;
	a.insert(1, 100);
	EXPECT_EQ(true, a.find(1, 100));
	EXPECT_EQ(false, a.find(1, 101));
}

TEST(Polynom, can_sum_polynoms)
{
	Polynom a, b, c;
	a.insert(1, 100);
	a.insert(2, 105);
	b.insert(3, 100);
	b.insert(75, 105);
	// (x + 2xz^5) + ( 3x + 75xz^5) = 4x + 77xz^5
	c = a + b;
	EXPECT_EQ(true, c.find(4, 100));
	EXPECT_EQ(true, c.find(77, 105));
}

TEST(Polynom, can_del_monom_with_coef_0_after_sum)
{
	Polynom a;
	a.insert(5.432, 101);
	EXPECT_EQ(1, a.getSize());
	a.insert(-5.432, 101);
	EXPECT_EQ(0, a.getSize());
}

TEST(Polynom, can_sub_polynoms)
{
	Polynom a, b, c;
	a.insert(1, 100);
	a.insert(2, 105);
	b.insert(3, 100);
	b.insert(75, 105);
	// (x + 2xz^5) - ( 3x + 75xz^5) = -2x -73xz^5
	c = a - b;
	EXPECT_EQ(true, c.find(-2, 100));
	EXPECT_EQ(true, c.find(-73, 105));
}

TEST(Polynom, can_mult_slacar_by_polynom)
{
	Polynom a;
	a.insert(1, 101);
	a = a * 5;
	EXPECT_EQ(true, a.find(5, 101));
	a = a * 2;
	EXPECT_EQ(true, a.find(10, 101));
}

TEST(Polynom, can_mult_polynoms)
{
	Polynom a, b, c;
	a.insert(1, 100);
	a.insert(2, 104);
	b.insert(3, 100);
	b.insert(75, 105);
	// (x + 2xz^4) * ( 3x + 75xz^5) = 3x^2 + 75x^2 z^5 + 6x^2 z^4 + 150x^2 z^9
	c = a * b;
	EXPECT_EQ(true, c.find(3, 200));
	EXPECT_EQ(true, c.find(150, 209));
	EXPECT_EQ(true, c.find(75, 205));
	EXPECT_EQ(true, c.find(6, 204));
}

TEST(Polynom, can_not_mult_polynoms_exp_greater_than_9)
{
	Polynom a, b, c;
	a.insert(1, 100);
	a.insert(2, 105);
	b.insert(3, 100);
	b.insert(75, 105);
	// (x + 2xz^5) * ( 3x + 75xz^5) = 3x^2 + 75x^2 z^5 + 6x^2 z^4 + 150x^2 z^10
	EXPECT_ANY_THROW(c = a * b);
}

TEST(Monom, can_create_monom)
{
	ASSERT_NO_THROW(Monom a;);
}

TEST(Monom, can_not_create_monom_with_negative_exp)
{
	ASSERT_ANY_THROW(Monom a(1, -101););
}