#include "pch.h"

#include "../lab4_polinoms/list.h"
#include"../lab4_polinoms/polinoms.h"

//тесты списка
TEST(List, can_insert_begin_with_correct_power)
{
	List a;
	a.Insert_begin(3154, 12);
	EXPECT_EQ(a.head->p, 3154);

}
TEST(List, can_insert_begin_with_correct_coef)
{
	List a;
	a.Insert_begin(3154, 12);
	EXPECT_EQ(a.head->c, 12);
}
TEST(List, can_insert_end_with_correct_power)
{
	List a;
	a.Insert_end(3154, 12);
	EXPECT_EQ(a.tail->p, 3154);
}
TEST(List, can_insert_end_with_correct_coef)
{
	List a;
	a.Insert_end(3154, 12);
	EXPECT_EQ(a.tail->c, 12);

}
TEST(List, can_delete)
{
	List a;
	a.Insert_end(3154, 12);
	a.Insert_begin(315, 37);
	a.Del(315);
	EXPECT_EQ(a.head->c, 12);
}
TEST(List, correct_eq_coef)
{
	List a;
	a.Insert_end(3154, 12);
	List b;
	b = a;
	EXPECT_EQ(a.head->c, b.head->c);
}
TEST(List, correct_eq_power)
{
	List a;
	a.Insert_end(3154, 12);
	List b;
	b = a;
	EXPECT_EQ(a.head->p, b.head->p);
}
TEST(List, correct_eq_sr)
{
	List a;
	a.Insert_end(3154, 12);
	a.Insert_begin(12, 13);
	a.Insert_begin(14, 15);
	List b;
	b = a;
	EXPECT_EQ(12, b.head->next->p);
}

//тесты полиномов
TEST(pol, can_create_pol_1)
{
	List a;
	pol b;
	EXPECT_EQ(b.a.head, b.a.tail);
}
TEST(pol, can_create_pol_2)
{
	List a;
	a.Insert_begin(123, 12);
	a.Insert_begin(124, 13);
	pol b(a);
	EXPECT_EQ(b.a.head->c, 13);
}
TEST(pol, can_create_pol_3)
{
	pol b(123, 14);
	EXPECT_EQ(b.a.head->c, 14);
}
TEST(pol, Mull_double_1)
{
	List a;
	a.Insert_begin(123, 12);
	a.Insert_begin(124, 13);
	//pol b;
	pol b(a);
	b.Mull(2);
	EXPECT_EQ(b.a.head->c, 26);
}
TEST(pol, Mull_double_2)
{
	List a;
	a.Insert_begin(123, 12);
	a.Insert_begin(124, 13);
	pol b(a);
	//pol b1(a);
	b.Mull(2);
	EXPECT_EQ(b.a.tail->c, 24);
}
TEST(pol, Mull_double_3)
{
	List a;
	a.Insert_begin(123, 12);
	a.Insert_begin(125, 15);
	a.Insert_begin(124, 13);
	pol b(a);
	//pol b1(a);
	b.Mull(2);
	EXPECT_EQ(b.a.head->next->c, 30);
}
TEST(pol, Mull_double_4)
{
	List a;
	a.Insert_begin(123, 12);
	a.Insert_begin(125, 15);
	a.Insert_begin(124, 13);
	pol b(a);
	b.Mull(-1);
	EXPECT_EQ(b.a.head->next->c, -15);
}
TEST(pol, DelZero_correct_n)
{
	List a;
	a.Insert_begin(123, 12);
	a.Insert_begin(121, 0);
	a.Insert_begin(124, 13);
	a.Insert_begin(125, 0);
	pol b(a);
	b.DelZero();
	EXPECT_EQ(2, b.a.n);
}
TEST(pol, DelZero_correct_work_0)
{
	List a;
	a.Insert_begin(125, 0);
	a.Insert_begin(125, 0);
	pol b(a);
	b.DelZero();
	EXPECT_EQ(NULL, b.a.head);
}
TEST(pol, DelZero_correct_work_1)
{
	List a;
	a.Insert_begin(123, 12);
	a.Insert_begin(121, 0);
	a.Insert_begin(124, 0);
	a.Insert_begin(125, 0);
	pol b(a);
	b.DelZero();
	EXPECT_EQ(12, b.a.tail->c);
}
TEST(pol, DelZero_correct_work_2)
{
	List a;
	a.Insert_begin(123, 12);
	a.Insert_begin(121, 0);
	a.Insert_begin(124, 13);
	a.Insert_begin(125, 0);
	pol b(a);
	b.DelZero();
	EXPECT_EQ(12, b.a.head->next->c);
}
TEST(pol, DelZero_correct_work_3)
{
	List a;
	a.Insert_begin(123, 0);
	a.Insert_begin(121, 0);
	a.Insert_begin(124, 13);
	a.Insert_begin(125, 0);
	pol b(a);
	b.DelZero();
	EXPECT_EQ(13, b.a.tail->c);
}
TEST(pol, DelZero_correct_work_4)
{
	List a;
	a.Insert_begin(123, 0);
	a.Insert_begin(121, 0);
	a.Insert_begin(124, 13);
	a.Insert_begin(125, 0);
	pol b(a);
	b.DelZero();
	EXPECT_EQ(NULL, b.a.head->next);
}
TEST(pol, DelZero_correct_work_5)
{
	List a;
	a.Insert_begin(123, 13);
	a.Insert_begin(123, 0);
	a.Insert_begin(123, 13);
	a.Insert_begin(121, 13);
	a.Insert_begin(124, 0);
	a.Insert_begin(125, 13);
	pol b(a);
	b.DelZero();
	EXPECT_EQ(4, b.a.n);
}
TEST(pol, add_1)
{
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(121, 13);
	b.Insert_begin(120, 14);
	b.Insert_begin(123, 14);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1 + b2;
	EXPECT_EQ(b3.a.tail->p, 121);
}
TEST(pol, add_2)
{
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(121, 13);
	b.Insert_begin(120, 14);
	b.Insert_begin(123, 14);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1 + b2;
	EXPECT_EQ(b3.a.head->c, 14);
}
TEST(pol, add_3)
{
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(121, 13);
	b.Insert_begin(120, 14);
	b.Insert_begin(123, 14);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1 + b2;
	EXPECT_EQ(b3.a.head->next->c, 28);
}
TEST(pol, add_4)
{
	List a;
	List b;
	a.Insert_begin(121, 0);
	b.Insert_begin(121, 0);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1 + b2;
	EXPECT_EQ(b3.a.n, 0);
}
TEST(pol, add_5)
{
	List a;
	List b;
	a.Insert_begin(121, 0);
	b.Insert_begin(121, 0);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1 + b2;
	EXPECT_EQ(NULL, b3.a.head);
}
TEST(pol, add_6)
{
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 0);
	b.Insert_begin(121, 0);
	b.Insert_begin(120, 14);
	b.Insert_begin(123, 0);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1 + b2;
	EXPECT_EQ(b3.a.head->c, 28);
}
TEST(pol, sub_1)
{
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	b.Insert_begin(121, 13);
	b.Insert_begin(120, 14);
	b.Insert_begin(123, 14);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1 - b2;
	EXPECT_EQ(b3.a.head->p, 123);
}
TEST(pol, sub_2)
{
	List a;
	List b;
	a.Insert_begin(120, 14);
	a.Insert_begin(121, 14);
	a.Insert_begin(121, 13);
	b.Insert_begin(120, 14);
	b.Insert_begin(123, 14);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1 - b2;
	EXPECT_EQ(b3.a.head->next->c, -14);
}
TEST(pol, mul_pol_1)
{
	List a;
	List b;
	a.Insert_begin(120, 4);
	a.Insert_begin(121, 2);
	b.Insert_begin(121, 3);
	b.Insert_begin(120, 5);
	b.Insert_begin(123, 6);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1.mullpol(b2);
	EXPECT_EQ(b3.a.head->p, 244);
}
TEST(pol, mul_pol_2)
{
	List a;
	List b;
	a.Insert_begin(120, 4);
	a.Insert_begin(121, 2);
	b.Insert_begin(121, 3);
	b.Insert_begin(120, 5);
	b.Insert_begin(123, 6);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1.mullpol(b2);
	EXPECT_EQ(b3.a.head->next->c, 6);
}
TEST(pol, mul_pol_3)
{
	List a;
	List b;
	a.Insert_begin(124, 4);
	a.Insert_begin(121, 2);
	b.Insert_begin(125, 3);
	b.Insert_begin(120, 5);
	b.Insert_begin(123, 6);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1.mullpol(b2);
	EXPECT_EQ(b3.a.tail->c,12);
}
TEST(pol, mul_pol_4)
{
	List a;
	List b;
	a.Insert_begin(120, 4);
	b.Insert_begin(123, 0);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1.mullpol(b2);
	EXPECT_EQ(NULL, b3.a.head);
}
TEST(pol, mul_pol_5)
{
	List a;
	List b;
	a.Insert_begin(120, 4);
	a.Insert_begin(121, 0);
	b.Insert_begin(121, 3);
	b.Insert_begin(120, 5);
	b.Insert_begin(123, 6);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1.mullpol(b2);
	EXPECT_EQ(12, b3.a.tail->c);
}
TEST(pol, mul_pol_6)
{
	List a;
	List b;
	a.Insert_begin(620, 4);
	b.Insert_begin(423, 6);
	pol b1(a);
	pol b2(b);
	pol b3;
	ASSERT_ANY_THROW(b3 = b1 * b2);
}
TEST(pol, mul_pol_7)
{
	List a, b;
	a.Insert_end(112, 2);
	a.Insert_begin(4, 3);
	a.Insert_begin(3, 2);
	b.Insert_end(412, 0);
	b.Insert_begin(4, 3);
	b.Insert_begin(3, 2);
	pol b1(a);
	pol b2(b);
	pol b3;
	b3 = b1.mullpol(b2);
	EXPECT_EQ(5, b3.a.n);
}
