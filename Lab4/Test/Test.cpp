#include "gtest.h"

#include "Polinom.h"
#include "Polinom.cpp"

TEST(Polinom, can_create_monom)
{
	Monom m;

	ASSERT_NO_THROW(m.init(3, 98));
}

TEST(Polinom, can_create_monom_with_incorrect_deg)
{
	Monom m;

	ASSERT_ANY_THROW(m.init(3, -98));
}

TEST(Polinom, add_monom_with_equal_deg)
{
	Monom m, l, g;
	m.init(3, 125);
	l.init(5, 125);

	g.init(8, 125);

	EXPECT_EQ(m + l, g);
}

TEST(Polinom, can_not_add_monom_with_not_equal_deg)
{
	Monom m, l;
	m.init(3, 125);
	l.init(5, 365);

	ASSERT_ANY_THROW(m + l);
}

TEST(Polinom, correct_mult_monom)
{
	Monom m, l, g;
	m.init(3, 100);
	l.init(5, 205);

	g.init(15, 305);

	EXPECT_EQ(m * l, g);
}

TEST(Polinom, can_create_polinom)
{
	Polinom a;
	Monom m;
	m.init(1, 625);

	ASSERT_NO_THROW(a.init(m));
}

TEST(Polinom, can_not_create_polinom_with_incorrect_deg)
{
	Polinom a;
	Monom m;
	m.coeff = 1;
	m.deg = 1300;

	ASSERT_ANY_THROW(a.init(m));
}
TEST(Polinom, add_polinom)
{
	Polinom a, b, c;
	Monom m;

	m.init(1, 200);	a.init(m);
	m.init(2, 56);	a.init(m);

	m.init(5, 56);	b.init(m);

	m.init(1, 200);	c.init(m);
	m.init(7, 56);	c.init(m);

	EXPECT_EQ(a + b, c);
}

TEST(Polinom, sub_polinom)
{
	Polinom a, b, c;
	Monom m;

	m.init(1, 200);	a.init(m);
	m.init(2, 56);	a.init(m);

	m.init(5, 56);	b.init(m);


	m.init(1, 200);	c.init(m);
	m.init(-3, 56);	c.init(m);

	EXPECT_EQ(a - b, c);
}

TEST(Polinom, mult_polinom_on_const)
{
	Polinom a, b;
	Monom m;
	double q = 0.5;
	m.init(8, 300);	a.init(m);
	m.init(2, 254); a.init(m);

	m.init(4, 300);	b.init(m);
	m.init(1, 254); b.init(m);

	EXPECT_EQ(a*q, b);
}

TEST(Polinom, mult_polinom_on_polinom)
{
	Polinom a, b, c;
	Monom m;

	m.init(8, 40);	a.init(m);
	m.init(2, 110); a.init(m);

	m.init(4, 10);	b.init(m);
	m.init(1, 40); b.init(m);

	m.init(32, 50);	c.init(m);
	m.init(8, 80); c.init(m);
	m.init(8, 120);	c.init(m);
	m.init(2, 150); c.init(m);

	EXPECT_EQ(a*b, c);
}