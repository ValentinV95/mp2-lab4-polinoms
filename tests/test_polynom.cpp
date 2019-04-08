#include <gtest.h>
#include "Polynom.h"

TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom a);
}

TEST(Polynom, exp_overflow)
{	
	Polynom a;
	ASSERT_ANY_THROW(a.insert(5,1024));
}

TEST(Polynom, can_add_monom_1)
{
	Polynom a;
	a.insert(1, 111);
	EXPECT_EQ(true, a.find(1,111));
}

TEST(Polynom, can_add_monom_2)
{
	Polynom a;
	a.insert(1, 111);
	EXPECT_EQ(false, a.find(4, 111));
}

TEST(Polynom, can_del_monom_1)
{
	Polynom a;
	a.insert(1, 111);
	a.del(1, 111);
	EXPECT_EQ(true, a.isEmpty());
}

TEST(Polynom, can_del_monom_2)
{
	Polynom a;
	a.insert(1, 111);
	a.del(4, 111);
	EXPECT_EQ(false, a.isEmpty());
}


TEST(Polynom, is_empty)
{
	Polynom a;
	EXPECT_EQ(true, a.isEmpty());
}

TEST(Polynom, is_not_empty)
{
	Polynom a;
	a.insert(4, 142);
	EXPECT_EQ(false, a.isEmpty());
}

TEST(Polynom, ins_1)
{
	Polynom a;
	a.insert(4, 111);
	a.insert(-4, 111);
	cout << a;
	EXPECT_EQ(true, a.isEmpty());
}

TEST(Polynom, ins_2)
{
	Polynom a;
	a.insert(4, 111);
	a.insert(4, 111);
	EXPECT_EQ(true, a.find(8,111));
}

TEST(Polynom, clear)
{
	Polynom a;
	a.insert(4, 111);
	a.insert(34, 234);
	a.clear();
	EXPECT_EQ(true, a.isEmpty());
}

TEST(Polynom, oper_eq)
{
	Polynom a,b;
	a.insert(4, 111);
	a.insert(54, 32);
	a = b;
	EXPECT_EQ(true, a == b );
}

TEST(Polynom, oper_plus)
{
	Polynom a, b,c,d;
	a.insert(4, 111);
	a.insert(54, 32);
	b.insert(45, 654);
	b.insert(56, 3);
	c = a + b;
	d.insert(4, 111);
	d.insert(54, 32);
	d.insert(45, 654);
	d.insert(56, 3);
	EXPECT_EQ(true, c == d);
}

TEST(Polynom, oper_minus_1)
{
	Polynom a, b,c;
	a.insert(4, 111);
	a.insert(54, 32);
	b.insert(4, 111);
	b.insert(54, 32);
	c = a - b;
	EXPECT_EQ(true, c.isEmpty());
}

TEST(Polynom, oper_minus_2)
{
	Polynom a, b, c, d;
	a.insert(4, 111);
	a.insert(54, 32);
	a.insert(5, 11);
	b.insert(54, 32);
	c = a - b;

	d.insert(4, 111);
	d.insert(5, 11);
	EXPECT_EQ(true, c == d);
}

TEST(Polynom, oper_mult_const)
{
	Polynom a, b;
	a.insert(4, 55);
	a.insert(10, 1);
	a = a * 2;
	b.insert(8, 55);
	b.insert(20, 1);
	EXPECT_EQ(true, a == b);
}

TEST(Polynom, oper_mult_poly)
{
	Polynom a, b, c, d;
	a.insert(4, 44);
	a.insert(10, 1);

	b.insert(8, 155);
	b.insert(20, 21);

	c.insert(32, 199);
	c.insert(80, 65);
	c.insert(80, 156);
	c.insert(200, 22);

	d = a * b;
	EXPECT_EQ(true, c == d);
}

TEST(Polynom, oper_mult_poly_overflow)
{
	Polynom a, b, c, d;
	a.insert(4, 555);
	a.insert(10, 1);

	b.insert(8, 755);
	b.insert(20, 21);

	ASSERT_ANY_THROW(a*b);
}