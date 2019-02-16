#include <gtest.h>
#include "tlist.h"

TEST(TList, can_create_list)
{
    ASSERT_NO_THROW(TList<int> s);
}

TEST(TList, can_copied_list)
{
    TList<int> s;
    s.Insert(3);
    TList<int> copy(s);

    EXPECT_EQ((s.GetFirst()->GetDatValue()), (copy.GetFirst()->GetDatValue()));
}

TEST(TList, can_insert_link_in__list)
{
    TList<int> s;
    const int expVal = 9;

    s.Insert(expVal);

    EXPECT_EQ(expVal, (s.GetFirst())->GetDatValue());
}

TEST(TList, check_list_always_sorted_after_insert)
{
    TList<int> s;
    const bool expVal = true;
    
    s.Insert(3);
    s.Insert(19);
    s.Insert(-4);
    s.Insert(0);

    EXPECT_EQ(expVal, s.IsSort());
}

TEST(TList, can_delete_first_link)
{
    const int expVal = 4;
    TList<int> s;

    s.Insert(4);
    s.Insert(5);

    s.Delete(s.GetFirst());

    EXPECT_EQ(expVal, s.GetFirst()->GetDatValue());
}

TEST(TList, can_delete_last_link)
{
    const int expVal = -2;
    TList<int> s;
    
    s.Insert(expVal);
    s.Insert(-3);
    s.Insert(5);

    s.Delete(s.GetLast());

    EXPECT_EQ(expVal, s.GetLast()->GetDatValue());
}

TEST(TList, can_delete_link)
{
    const int expVal = -2;
    TList<int> s;

    s.Insert(expVal);
    s.Insert(-2);
    s.Insert(9);

    s.Delete(s.GetFirst()->GetNextLink());

    EXPECT_EQ(expVal, (s.GetFirst()->GetNextLink())->GetDatValue());
}

TEST(TList, check_length_of_list_after_merge)
{
    TList<int> s1, s2;
    const int l1 = 3, l2 = 4, expVal = 7;
    
    s1.Insert(3); s1.Insert(9); s1.Insert(-2);
    s2.Insert(0); s2.Insert(-1); s2.Insert(1); s2.Insert(6);

    s1.Merge(s2);

    EXPECT_EQ(expVal, s1.GetLength());
}

TEST(TList, check_list_is_sorted_after_merge)
{  
    TList<int> s1, s2;
    const bool expVal = true;

    s1.Insert(3); s1.Insert(9); s1.Insert(-2);
    s2.Insert(0); s2.Insert(-1); s2.Insert(1); s2.Insert(6);

    s1.Merge(s2);

    EXPECT_EQ(expVal, s1.IsSort());
}