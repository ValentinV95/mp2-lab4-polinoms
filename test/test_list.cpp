#include <gtest.h>
#include <list.h>

TEST(List,can_insert_element_front)
{
	List <int> test1;
	List <int> test2;
	int k;
	k =  1;
	test1.insert_front(k);
	test2.insert_front(k);
	k = 2;
	test1.insert_front(k);
	test2.insert_front(k);
	EXPECT_EQ(test1,test2);
}

TEST(List,can_insert_element_at_end)
{
	List <int> test1;
	List <int> test2;
	test1.insert_front(2);
	test2.insert_at_end(1);
	test1.insert_front(1);
	test2.insert_at_end(2);
	EXPECT_EQ(test1,test2);
}

TEST(List,can_insert_element_after_element)
{
	List <int> test1;
	List <int> test2;
	test1.insert_front(1);
	test1.insert_front(2);
	test1.insert_front(3);
	test2.insert_front(1);
	test2.insert_front(3);
	Node<int> *a = test2.head;
	test2.insert_after(a,2);
	EXPECT_EQ(test1,test2);
}

TEST(List,can_delete_element)
{
	List <int> test1;
	List <int> test2;
	test1.insert_front(1);
	test1.insert_front(3);
	test2.insert_front(1);
	test2.insert_front(2);
	test2.insert_front(3);
	test2.del(2);
	EXPECT_EQ(test1,test2);
}

