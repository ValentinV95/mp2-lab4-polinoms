#include "List.h"
#include "gtest.h"
TEST(Poly, can_polinom)
{
	ASSERT_NO_THROW(Poly A);
}
TEST(Poly, can_insert_ordinary_mon)
{
	Poly A;
	ASSERT_NO_THROW(A.Insert(5,777));
}
TEST(Poly, can_insert_wrong_mon1)
{
	Poly A;
	ASSERT_ANY_THROW(A.Insert(5, 1001));

}
TEST(Poly, can_insert_wrong_mon2)
{
	Poly A;
	ASSERT_ANY_THROW(A.Insert(9999999999999, 111));

}
TEST(Poly, can_del_empty_list)
{
	Poly A;
	ASSERT_ANY_THROW(A.Del(333));

}
TEST(Poly, can_del)
{
	double*cf;
	cf = new double[4];
	int*pw;
	pw = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf[i] = (i + 1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 4);

	ASSERT_NO_THROW(A.Del(444));
}
TEST(Poly, can_del_wrong_pow)
{
	double*cf;
	cf = new double[4];
	int*pw;
	pw = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf[i] = (i + 1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 4);
	Poly B = A;
	A.Del(888);
	EXPECT_EQ(A, B);

}
TEST(Poly, can_check_regular)
{
	Poly A;
	A.Insert(4,444);
	A.Insert(5,555);
	Poly B;
	B.Insert(5,555);
	B.Insert(4,444);
	EXPECT_EQ(A,B);
}
TEST(Poly, can_copy1)
{
	double*cf;
	cf= new double[4];
	int*pw;
	pw = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf[i] = (i+1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf,pw,4);
	Poly B(A);

	EXPECT_EQ(A, B);

}
TEST(Poly, can_copy2)
{
	double*cf;
	cf = new double[4];
	int*pw;
	pw = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf[i] = (i + 1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 4);
	Poly B = A;

	EXPECT_EQ(A, B);

}

TEST(Poly, can_insert_in_beg)
{
	double*cf;
	cf = new double[3];
	int*pw = new int[3];
	for (int i = 0; i < 3; i++)
	{
		cf[i] = (i + 2) * 10;
		pw[i] = (i + 2) * 100 + (i + 2) * 10 + i + 2;
	}
	double*cf1;
	cf1 = new double[4];
	int*pw1;
	pw1 = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf1[i] = (i + 1) * 10;
		pw1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 3);
	Poly S(cf1, pw1, 4);
	A.Insert(10, 111);
	EXPECT_EQ(A, S);

}
TEST(Poly, can_del_begin)
{
	double*cf;
	cf = new double[3];
	int*pw = new int[3];
	for (int i = 0; i < 3; i++)
	{
		cf[i] = (i + 2) * 10;
		pw[i] = (i + 2) * 100 + (i + 2) * 10 + i + 2;
	}
	double*cf1;
	cf1 = new double[4];
	int*pw1;
	pw1 = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf1[i] = (i + 1) * 10;
		pw1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly S(cf, pw, 3);
	Poly A(cf1, pw1, 4);
	A.Del(111);
	EXPECT_EQ(A, S);

}
TEST(Poly, can_insert_in_end)
{
	double*cf;
	cf = new double[3];
	int*pw = new int[3];
	for (int i = 0; i < 3; i++)
	{
		cf[i] = (i + 1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	double*cf1;
	cf1 = new double[4];
	int*pw1;
	pw1 = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf1[i] = (i + 1) * 10;
		pw1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 3);
	Poly S(cf1, pw1, 4);
	A.Insert(40, 444);
	EXPECT_EQ(A, S);

}
TEST(Poly, can_plus_eq_poly)
{
	double*cf;
	cf = new double[4];
	int*pw;
	pw = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf[i] = (i + 1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 4);
	double*cf1;
	cf1 = new double[4];
	int*pw1;
	pw1 = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf1[i] = (i + 1) * 20;
		pw1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly B(cf1, pw1, 4);
	Poly C = A + A;


	EXPECT_EQ(C, B);

}
TEST(Poly, can_plus_not_eq)
{
	double*cf;
	cf = new double[3];
	int*pw;
	pw = new int[3];
	for (int i = 0; i < 3; i++)
	{
		cf[i] = (i + 1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 3);
	Poly K;
	K.Insert(40, 444);
	double*cf1;
	cf1 = new double[4];
	int*pw1;
	pw1 = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf1[i] = (i + 1) * 10;
		pw1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly B(cf1, pw1, 4);
	Poly C = A + K;


	EXPECT_EQ(C, B);

}
TEST(Poly, can_mult_const)
{
	double*cf;
	cf = new double[4];
	int*pw;
	pw = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf[i] = (i + 1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 4);
	double*cf1;
	cf1 = new double[4];
	int*pw1;
	pw1 = new int[4];
	for (int i = 0; i < 4; i++)
	{
		cf1[i] = (i + 1) * 30;
		pw1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly B(cf1, pw1, 4);
	A = A*3;
	EXPECT_EQ(A, B);

}

TEST(Poly, can_mult_two_eq_poly)
{
	double*cf;
	cf = new double[2];
	int*pw;
	pw = new int[2];
	for (int i = 0; i < 2; i++)
	{
		cf[i] = (i + 1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 2);
	Poly B;
	B.Insert(100, 222);
	B.Insert(400, 333);
	B.Insert(400, 444);
	Poly C = A*A;


	EXPECT_EQ(C, B);

}
TEST(Poly, can_mult_two_noteq)
{
	double*cf;
	cf = new double[2];
	int*pw;
	pw = new int[2];
	for (int i = 0; i < 2; i++)
	{
		cf[i] = (i + 1) * 10;
		pw[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(cf, pw, 2);
	Poly C;
	C.Insert(2, 111);
	Poly B;
	B.Insert(20, 222);
	B.Insert(40, 333);
	Poly D = A*C;


	EXPECT_EQ(D, B);

}