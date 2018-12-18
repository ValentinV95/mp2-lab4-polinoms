#include "polinom.h"
#include <gtest.h>
#include <iostream>

TEST(Polinom, create_polinom) {
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, plus_polinom) {
	Polinom a;
	a.ins(1, 225);
	a.ins(3, 112);
	a.ins(2, 111);
	Polinom b;
	b.ins(1, 227);
	b.ins(1, 225);
	b.ins(1, 111);
	Polinom c = a + b;
	Polinom d;
	d.ins_at_end(1, 227);
	d.ins_at_end(2, 225);
	d.ins_at_end(3, 112);
	d.ins_at_end(3, 111);
	Polinom ans = c - d;
	EXPECT_EQ((ans.pol->next == nullptr), true);
}

TEST(Polinom, plus_polinom1) {
	Polinom a;
	a.ins(1, 222);
	Polinom b;
	b.ins(2, 222);
	Polinom c = a + b;
	Polinom d;
	d.ins_at_end(3, 222);
	Polinom ans = d - c;
	EXPECT_EQ((ans.pol->next == nullptr), true);
}

TEST(Polinom, mul_const) {
	Polinom a;
	a.ins(1, 225);
	a.ins(3, 112);
	a.ins(2, 111);
	Polinom b = a * 2;
	Polinom d;
	d.ins_at_end(2, 225);
	d.ins_at_end(6, 112);
	d.ins_at_end(3, 111);
	Polinom ans = d - b;
	EXPECT_EQ((ans.pol->next == nullptr), true);
}


TEST(Polinom, mul_const1) {
	Polinom a;
	a.ins(1, 225);
	a.ins(3, 112);
	a.ins(2, 111);
	Polinom b = a * 100;
	Polinom d;
	d.ins_at_end(100, 225);
	d.ins_at_end(300, 112);
	d.ins_at_end(200, 111);
	Polinom ans = d - b;
	EXPECT_EQ((ans.pol->next == nullptr), true);
}


TEST(Polinom, mul_const2) {
	Polinom a;
	a.ins(2, 225);
	a.ins(4, 112);
	a.ins(2, 111);
	Polinom b = a * 0.5;
	Polinom d;
	d.ins_at_end(1, 225);
	d.ins_at_end(2, 112);
	d.ins_at_end(1, 111);
	Polinom ans = d - b;
	EXPECT_EQ((ans.pol->next == nullptr), true);
}


TEST(Polinom, mul) {
	Polinom a;
	a.ins(1, 225);
	a.ins(3, 112);
	a.ins(2, 111);
	Polinom b;
	b.ins(1, 227);
	b.ins(1, 225);
	b.ins(1, 111);
	EXPECT_ANY_THROW(Polinom c = a*b);
}


TEST(Polinom, mul1) {
	Polinom a;
	a.ins(1, 225);
	a.ins(3, 112);
	a.ins(2, 111);
	Polinom b;
	b.ins(1, 225);
	b.ins(1, 225);
	b.ins(1, 111);
	EXPECT_ANY_THROW(Polinom c = a*b);
}


TEST(Polinom, mul2) {
	Polinom a;
	a.ins(1, 500);
	Polinom b;
	b.ins(1, 500);
	EXPECT_ANY_THROW(Polinom c = a*b);
}

TEST(Polinom, mul3) {
	Polinom a;
	a.ins(1, 500);
	Polinom b;
	b.ins(1, 400);
	Polinom c = a*b;
	Polinom d;
	d.ins_at_end(1, 900);
	Polinom ans = d - c;
	EXPECT_EQ((ans.pol->next == nullptr), true);
}


TEST(Polinom, mul4) {
	Polinom a;
	a.ins(1, 223);
	a.ins(3, 112);
	a.ins(2, 111);
	Polinom b;
	b.ins(1, 223);
	b.ins(1, 222);
	b.ins(1, 111);
	Polinom c = a*b;
	Polinom d;
	d.ins_at_end(1, 446);
	d.ins_at_end(1, 445);
	d.ins_at_end(3, 335);
	d.ins_at_end(6, 334);
	d.ins_at_end(2, 333);
	d.ins_at_end(3, 223);
	d.ins_at_end(2, 222);
	Polinom ans = d - c;
	EXPECT_EQ((ans.pol->next == nullptr), true);
}

