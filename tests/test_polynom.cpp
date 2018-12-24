#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include "Polynom.h"
#include <gtest.h>
#include <string>
using namespace std;



TEST(Polynom, can_create_polynom)
{
	ASSERT_NO_THROW(Polynom A);
}
//TEST(Polynom, can_create_polynom_as_another_one)
//{
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//	Polynom B(A);
//	EXPECT_EQ(A, B);
//}
//TEST(Polynom, cannot_insert_a_monom_with_a_wrong_degree)
//{
//	Polynom A;
//	EXPECT_ANY_THROW(A.Insert(5, 1000));
//}
//
//
//TEST(Polynom, can_insert_a_monom_in_the_end) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//	A.Insert(4, 444);
//
//	for (int i = 0; i < 4; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom B(pol, 4);
//	EXPECT_EQ(A, B);
//
//}
//TEST(Polynom, can_insert_a_monom_in_the_begining) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 2;
//		pol[i].d = 100 * (i + 2) + 10 * (i + 2) + i + 2;
//	}
//	Polynom A(pol, 3);
//	A.Insert(1, 111);
//
//	for (int i = 0; i < 4; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom B(pol, 4);
//	EXPECT_EQ(A, B);
//
//}
//TEST(Polynom, can_insert_an_existing_monom) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//	A.Insert(3, 333);
//
//	for (int i = 0; i < 2; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	pol[2].c = 6;
//	pol[2].d = 333;
//	Polynom B(pol, 3);
//	EXPECT_EQ(A, B);
//
//}
//TEST(Polynom, cannot_insert_a_monom_with_zero_coefficient) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//	Polynom B(A);
//	A.Insert(0, 444);
//	EXPECT_EQ(A, B);
//}
//
//TEST(Polynom, can_delete_a_monom_in_the_end) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//	A.Delete(333);
//
//	for (int i = 0; i < 2; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom B(pol, 2);
//	EXPECT_EQ(A, B);
//
//}
//TEST(Polynom, can_delete_a_monom_in_the_begining) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//	A.Delete(111);
//
//	for (int i = 0; i < 2; i++) {
//		pol[i].c = i + 2;
//		pol[i].d = 100 * (i + 2) + 10 * (i + 2) + i + 2;
//	}
//	Polynom B(pol, 2);
//	EXPECT_EQ(A, B);
//
//}
//
//TEST(Polynom, can_check_emptiness) {
//	Polynom A;
//	EXPECT_EQ(A.IsEmpty(), true);
//}
//
//TEST(Polynom, can_assign_polynomials) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//	Polynom B(A);
//	Polynom C;
//	C = A;
//	EXPECT_EQ(C, B);
//}
//
//TEST(Polynom, can_add_polynomials_with_different_sizes) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//
//	for (int i = 0; i < 4; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom B(pol, 4);
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = 2 * (i + 1);
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	pol[4].c = 4;
//	pol[4].d = 444;
//	Polynom C(pol, 4);
//	Polynom D;
//	D = A + B;
//	EXPECT_EQ(A + B, C);
//}
//
//TEST(Polynom, can_add_polynomials_with_equal_sizes) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 2;
//		pol[i].d = 100 * (i + 2) + 10 * (i + 2) + i + 2;
//	}
//	Polynom B(pol, 3);
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = 2 * (i + 3);
//		pol[i].d = 100 * (i + 3) + 10 * (i + 3) + i + 3;
//	}
//	Polynom C(pol, 3);
//	EXPECT_EQ(A + B, C);
//}
//
//
//TEST(Polynom, can_subtract_polynomials_with_equal_sizes) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 2;
//		pol[i].d = 100 * (i + 2) + 10 * (i + 2) + i + 2;
//	}
//	Polynom B(pol, 3);
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = -1;
//		pol[i].d = 100 * (i + 3) + 10 * (i + 3) + i + 3;
//	}
//	Polynom C(pol, 3);
//	EXPECT_EQ(A - B, C);
//}
//TEST(Polynom, can_subtract_polynomials_with_different_sizes) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//
//	for (int i = 0; i < 4; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom B(pol, 4);
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = -1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	pol[4].c = -5;
//	pol[4].d = 444;
//	Polynom C(pol, 4);
//	EXPECT_EQ(A + B, C);
//}
//
//TEST(Polynom, can_multiply_polynomials_with_different_sizes) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 3; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 3);
//
//	for (int i = 0; i < 2; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom B(pol, 2);
//	Polynom C;
//	C.Insert(1, 222);
//	C.Insert(2, 333);
//	C.Insert(2, 333);
//	C.Insert(4, 444);
//	C.Insert(3, 444);
//	C.Insert(6, 555);
//	EXPECT_EQ(A*B, C);
//}
//
//TEST(Polynom, can_multiply_polynomials_with_equal_sizes) {
//	struct m* pol;
//	pol = (struct m*)malloc(5 * (sizeof(int) + sizeof(double)));
//	for (int i = 0; i < 2; i++) {
//		pol[i].c = i + 1;
//		pol[i].d = 100 * (i + 1) + 10 * (i + 1) + i + 1;
//	}
//	Polynom A(pol, 2);
//
//	for (int i = 0; i < 2; i++) {
//		pol[i].c = i + 2;
//		pol[i].d = 100 * (i + 2) + 10 * (i + 2) + i + 2;
//	}
//	Polynom B(pol, 2);
//	Polynom C;
//	C.Insert(1, 222);
//	C.Insert(2, 333);
//	C.Insert(2, 333);
//	C.Insert(4, 444);
//	EXPECT_EQ(A*B, C);
//}
//
//TEST(Polynom, cannot_multiply_polynomials_with_too_big_sum_sizes) {
//	Polynom A;
//	A.Insert(7, 777);
//	Polynom B;
//	B.Insert(8, 888);
//	EXPECT_ANY_THROW(A*B);
//}