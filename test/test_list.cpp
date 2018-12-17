#include <gtest.h>
#include <list.h>


TEST(list, can_create_list)
{
	ASSERT_NO_THROW(List<int> L);
}

TEST(list, can_insert)
{
	List<int> L;
	ASSERT_NO_THROW(L.insert(123,12));	
}

TEST(list, correct_insert)
{
	List<int> L;
	L.insert(111, 12);
	L.insert(333, 12);

	EXPECT_EQ(L.head->power, 333);
}

TEST(list, can_delete)
{
	List<int> L;
	L.insert(333, 12);
	L.insert(111, 12);
	
	L.Delete(333);
	EXPECT_EQ(L.head->power, 111);
}

TEST(list, can_get_size)
{
	List<int> L;
	L.insert(333, 12);
	L.insert(111, 12);

	EXPECT_EQ(L.get_size(), 2);
}


TEST(list, can_clear_list)
{
	List<int> L;
	L.insert(333, 12);
	L.insert(111, 12);
	L.ClrL();

	EXPECT_EQ(L.get_size(), 0);
}

TEST(list, can_multiplication_list_by_factor)
{
	List<int> L;
	L.insert(111, 12);
	L.Mull(-1);
	EXPECT_EQ(L.head->coef, -12);
}

TEST(list, can_multiplication_list_by_null)
{
	List<int> L;
	L.insert(111, 12);
	L.Mull(0);
	EXPECT_EQ(L.get_size(), 0);
}


