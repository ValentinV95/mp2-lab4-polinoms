#include <gtest.h>
#include "Polynom.h"

TEST(polynom, can_create_polinom) {
    ASSERT_NO_THROW(polynom p);
}
TEST(polynom, can_insert_new_monom) {
    polynom p;
    p.insert(2, 210);
    EXPECT_EQ(true, p.find(2.0, 210));
}
TEST(polynom, can_not_insert_incorrect_monom_1) {
    polynom p;
    ASSERT_ANY_THROW(p.insert(2, 2100));
}
TEST(polynom, can_not_insert_incorrect_monom_2) {
    polynom p;
    ASSERT_ANY_THROW(p.insert(2, -1));
}
TEST(polynom, can_delete_monom) {
    polynom p;
    p.insert(2, 210);
    EXPECT_EQ(true, p.find(2.0, 210));
    p.insert(4, 211);
    EXPECT_EQ(true, p.find(4.0, 211));
    p.insert(42, 100);
    EXPECT_EQ(true, p.find(42.0, 100));
    p.del(4, 211);
    EXPECT_EQ(false, p.find(4.0, 211));
}
TEST(polynom, polynomial_is_sorted) {
    polynom p;
    p.insert(1, 210);
    p.insert(2, 220);
    p.insert(0, 211);
    p.insert(5, 900);
    p.insert(4, 458);
    p.insert(3, 333);
	int a[] = { 900, 458, 333, 220, 210 };
    monom* temp = p.get_head();
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(a[i], temp->next->deg);
        temp = temp->next;
    }
}
TEST(polynom, can_lead_to_caconic_view_1) {
    polynom p;

    p.insert(3, 210);
    p.insert(3, 210);
    p.insert(9, 210);

    p.insert(5, 42);
    p.insert(4, 42);
    p.insert(3, 42);

    p.insert(25, 999);
    p.insert(16, 999);
    p.insert(9, 999);

    int a[] = { 999, 210, 42 };
    int b[] = { 50, 15, 12 };
    monom* temp = p.get_head();

    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(a[i], temp->next->deg);
        EXPECT_EQ(b[i], temp->next->k);
        temp = temp->next;
    }
}
TEST(polynom, can_lead_to_caconic_view_2) {
    polynom p;
    
    p.insert(3, 210);
    p.insert(5, 42);
    p.insert(16, 999);
    p.insert(3, 42);
    p.insert(9, 210);
    p.insert(25, 999);
    p.insert(4, 42);
    p.insert(9, 999);
    p.insert(3, 210);

    int a[] = { 999, 210, 42 };
    int b[] = { 50, 15, 12 };
    monom* temp = p.get_head();
    
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(a[i], temp->next->deg);
        EXPECT_EQ(b[i], temp->next->k);
        temp = temp->next;
    }
}
TEST(polynom, can_lead_to_caconic_view_3) {
    polynom p;
    
    p.insert(3, 210);
    p.insert(5, 42);
    p.insert(-16, 999);
    p.insert(3, 42);
    p.insert(9, 210);
    p.insert(25, 999);
    p.insert(4, 42);
    p.insert(-9, 999);
    p.insert(3, 210);

    int a[] = { 210, 42 };
    int b[] = { 15, 12 };
    monom* temp = p.get_head();
    
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(a[i], temp->next->deg);
        EXPECT_EQ(b[i], temp->next->k);
        temp = temp->next;
    }
}
TEST(polynom, can_compare_polynomials_1) {
    polynom p, m;

    p.insert(3, 210);
    p.insert(3, 210);
    p.insert(9, 210);

    p.insert(5, 42);
    p.insert(4, 42);
    p.insert(3, 42);

    m.insert(3, 210);
    m.insert(3, 210);
    m.insert(9, 210);

    m.insert(5, 42);
    m.insert(4, 42);
    m.insert(3, 42);

    EXPECT_EQ(true, p == m);
}

TEST(polynom, can_compare_polynomials_2) {
    polynom p, m;

    p.insert(3, 210);
    p.insert(3, 210);
    p.insert(9, 210);

    p.insert(5, 42);
    p.insert(4, 42);
    p.insert(3, 42);

    m.insert(3, 210);
    m.insert(3, 210);
    m.insert(9, 210);

    m.insert(5, 42);
    m.insert(4, 42);
    m.insert(3, 42);
    m.insert(3, 41);

    EXPECT_EQ(false, p == m);
}
TEST(polynom, can_copy_polynomials) {
    polynom p;
    
    p.insert(3, 210);
    p.insert(5, 42);
    p.insert(16, 999);
    p.insert(3, 42);
    p.insert(9, 210);
    p.insert(25, 999);
    p.insert(4, 42);
    p.insert(9, 999);
    p.insert(3, 210);

    polynom m(p);

    EXPECT_EQ(p, m);
}
TEST(polynom, can_assign_polynomials) {
    polynom p, m;
    
    p.insert(3, 210);
    p.insert(5, 42);
    p.insert(16, 999);
    p.insert(3, 42);
    p.insert(9, 210);
    p.insert(25, 999);
    p.insert(4, 42);
    p.insert(9, 999);
    p.insert(3, 210);

    m = p;

    EXPECT_EQ(p, m);
}
TEST(polynom, can_mult_to_double_1) {
    polynom p;
    
    p.insert(3, 210);
    p.insert(5, 42);
    p.insert(16, 999);
    p.insert(3, 42);
    p.insert(9, 210);
    p.insert(25, 999);
    p.insert(4, 42);
    p.insert(9, 999);
    p.insert(3, 210);

    p = p * (-2);

    int a[] = { 999, 210, 42 };
    int b[] = { -100, -30, -24 };
    monom* temp = p.get_head();
    
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(a[i], temp->next->deg);
        EXPECT_EQ(b[i], temp->next->k);
        temp = temp->next;
    }
}

TEST(polynom, can_mult_to_double_2) {
    polynom p;
    
    p.insert(3, 210);
    p.insert(5, 42);
    p.insert(16, 999);
    p.insert(3, 42);
    p.insert(9, 210);
    p.insert(25, 999);
    p.insert(4, 42);
    p.insert(9, 999);
    p.insert(3, 210);

    p = p * 0.0;

    monom* temp = p.get_head();
    EXPECT_EQ(NULL, temp->next);
}

TEST(polynom, can_add_polynomials_1) {
    polynom p, m, ans;
    
    p.insert(4, 210);
    p.insert(3, 1);
    p.insert(2, 0);
    p.insert(1, 10);

    m.insert(2, 210);
    m.insert(2, 1);
    m.insert(2, 0);
    m.insert(2, 10);

    ans = m + p;

    monom* temp = ans.get_head();

    int a[] = { 210, 10, 1, 0 };
    int b[] = { 6, 3, 5, 4};
    
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(a[i], temp->next->deg);
        EXPECT_EQ(b[i], temp->next->k);
        temp = temp->next;
    }
}
TEST(polynom, can_add_polynomials_2) {
    polynom p, m, ans;
    
    p.insert(4, 220);
    p.insert(3, 2);
    p.insert(2, 3);
    p.insert(1, 11);

    m.insert(2, 210);
    m.insert(2, 1);
    m.insert(2, 0);
    m.insert(2, 10);

    ans = m + p;

    monom* temp = ans.get_head();

    int a[] = { 220, 210, 11, 10, 3, 2, 1, 0 };
    int b[] = { 4, 2, 1, 2, 2, 3, 2, 2 };
    
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(a[i], temp->next->deg);
        EXPECT_EQ(b[i], temp->next->k);
        temp = temp->next;
    }
}

TEST(polynom, can_add_polynomials_3) {
    polynom p, m, ans;
    
    p.insert(4, 210);
    p.insert(3, 1);
    p.insert(2, 0);
    p.insert(1, 10);

    m.insert(-4, 210);
    m.insert(-3, 1);
    m.insert(2, 0);
    m.insert(-1, 10);

    ans = m + p;

    monom* temp = ans.get_head();

    int a[] = { 0 };
    int b[] = { 4 };
    
    for (int i = 0; i < 1; i++) {
        EXPECT_EQ(a[i], temp->next->deg);
        EXPECT_EQ(b[i], temp->next->k);
        temp = temp->next;
    }
}
TEST(polynom, can_mult_polynomials_1) {
    polynom p, m, ans, res;
    
    p.insert(4, 222);
    p.insert(-1, 0);

    m.insert(4, 222);
    m.insert(1, 0);

    res.insert(16, 444);
    res.insert(-1, 0);

    ans = m * p;

    EXPECT_EQ(res, ans);
}

TEST(polynom, can_mult_polynomials_2) {
    polynom p, ans, res;
    
    p.insert(4, 222);
    p.insert(-2, 123);

    res.insert(16, 444);
    res.insert(-16, 345);
    res.insert(4, 246);

    ans = p * p;

    EXPECT_EQ(res, ans);
}
TEST(polynom, can_not_mult_incorrect_polynomials) {
    polynom p;
    
    p.insert(4, 500);
    p.insert(-2, 123);

    ASSERT_ANY_THROW(p * p);
}