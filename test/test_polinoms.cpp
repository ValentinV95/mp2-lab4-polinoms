#include <gtest.h>
#include <list.h>


TEST(Polinoms, is_equel_polinoms)
{
	List<int> L1;
	List<int> L2;

	L1.insert(111, 12);
	L1.insert(333, 12);

	L2.insert(111, 12);
	L2.insert(333, 12);

	EXPECT_EQ(IsEquel(L1,L2), 1);
}


TEST(Polinoms, can_add_polinoms)
{

	List<int> L1;
	List<int> L2;
	List<int> L3;

	L1.insert(111, 12);
	L1.insert(333, 12);

	L2.insert(111, 12);
	L2.insert(421, 12);

	L3.insert(333, 12);
	L3.insert(111, 24);
	L3.insert(421, 12);

	EXPECT_EQ(IsEquel(Add(L1,L2), L3), 1);
}

TEST(Polinoms, can_delete_zero)
{

	List<int> L1;
	List<int> L2;
	List<int> L3;

	L1.insert(111, 12);
	L1.insert(333, 12);

	L2.insert(111, -12);
	L2.insert(421, 12);

	L3.insert(333, 12);
	L3.insert(421, 12);

	EXPECT_EQ(IsEquel(Add(L1, L2), L3), 1);
}

TEST(Polinoms, can_subtraction_polinoms)
{
	List<int> L1;
	List<int> L2;
	List<int> L3;

	L1.insert(111, 12);
	L1.insert(333, 12);

	L2.insert(111, 12);
	

	L3.insert(333, 12);

	EXPECT_EQ(IsEquel(Sub(L1, L2), L3), 1);
}

TEST(Polinoms, cant_mull_large_polinoms)
{
	List<int> L1;
	List<int> L2;
	

	L1.insert(888, 12);
	
	L2.insert(444, 12);
	
	ASSERT_ANY_THROW(Mull(L1,L2));
}

TEST(Polinoms, correct_mull_polinoms)
{
	List<int> L1;
	List<int> L3;

	L1.insert(111, 2);
	L1.insert(222, 2);

	L3.insert(444, 4);
	L3.insert(333, 8);
	L3.insert(222, 4);


	EXPECT_EQ(IsEquel(Mull(L1, L1), L3), 1);
}


