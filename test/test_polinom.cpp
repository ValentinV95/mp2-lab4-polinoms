#include <gtest.h>
#include "polinom.h"

TEST(Monom, can_create_monom)
{
    ASSERT_NO_THROW(Monom q(9.0, 123));
}

TEST(Monom, cant_create_monom_with_degree_greater_than_nine)
{
    ASSERT_ANY_THROW(Monom q(1.0, 1001));
}

TEST(Monom, cant_create_monom_with_negative_index)
{
    ASSERT_ANY_THROW(Monom q(1.0, -3));
}

TEST(Monom, can_add_monoms_with_equal_index)
{
    const int index = 389;
    const double c1 = 9.0, c2 = 54.0, c3 = c1 + c2;
    Monom a(c1, index), b(c2, index), expVal(c3, index);

    EXPECT_EQ(expVal, a + b);
}

TEST(Monom, cant_add_monoms_with_different_index)
{
    Monom a(1.0, 198), b(1.0, 823);

    ASSERT_ANY_THROW(a + b);
}

TEST(Monom, can_multiply_scalar_by_monom)
{
    const int index = 111;
    const double coeff = 9.0, d = 3.9;
    Monom a(coeff, index), expVal(coeff * d, index);

    EXPECT_EQ(expVal, a*d);
}

TEST(Monom, can_multiply_monoms)
{
    int index1 = 123, index2 = 456, index3 = index1 + index2;
    double coeff1 = 9.0, coeff2 = 123.02, coeff3 = coeff1 * coeff2;
    Monom a(coeff1, index1), b(coeff2, index2), expVal(coeff3, index3);

    EXPECT_EQ(expVal, a * b);
}

TEST(Monom, throw_when_result_of_mupltiply_has_incorrect_degree)
{
    int index1 = 109, index2 = 203;
    Monom a(5.0, index1), b(3.0, index2);

    ASSERT_ANY_THROW(a * b);
}

TEST(Polinom, can_create_polinom)
{
    const int km = 3;
    Monom* monoms = new Monom[3];
    Monom m1(9.0, 333), m2(1.0, 777), m3(8.9, 123);
    monoms[0] = m1; monoms[1] = m2; monoms[2] = m3;
    ASSERT_NO_THROW(Polinom q(monoms, km));
}

TEST(Polinom, can_reduce_a_polinom_to_standart_view)
{
    Monom expMon(5.3, 123);
    Monom a1(4.3, 123), a2(1.0, 123);

    Monom* monoms = new Monom[2];
    Monom* expMonoms = new Monom(expMon);

    monoms[0] = a1; monoms[1] = a2;
    Polinom a(monoms, 2), expPolinom(expMonoms, 1);

    a.Reduce();

    EXPECT_EQ(expPolinom, a);
}

TEST(Polinom, polinom_does_not_contain_zero_monom_after_reduce)
{
    Monom a1(1.0, 123), a2(0.0, 987), a3(2.0, 0);

    Monom* monoms = new Monom[3];
    Monom* expMonoms = new Monom[2];

    monoms[0] = a1; monoms[1] = a2; monoms[2] = a3;
    expMonoms[0] = a1; expMonoms[1] = a3;
    Polinom a(monoms, 3), expPolinom(expMonoms, 2);

    a.Reduce();

    EXPECT_EQ(expPolinom, a);
}

TEST(Polinom, polinom_is_reduced_after_insert)
{
    Polinom a, expPolinom;
    Monom a1(1.0, 123), a2(2.0, 123), expMonom(3.0, 123);

    a.Insert(a1); a.Insert(a2); 
    expPolinom.Insert(expMonom);

    EXPECT_EQ(expPolinom, a);
}

TEST(Polinom, polinom_does_not_contain_zero_monom_after_insert)
{
    Polinom a, expPolinom;
    Monom a1(1.0, 123), a2(0.0, 345), a3(0.0, 456);
    
    a.Insert(a1); a.Insert(a2); a.Insert(a3);
    expPolinom.Insert(a1);

    EXPECT_EQ(expPolinom, a);
}

TEST(Polinom, can_assign_polinoms_of_different_length)
{
    Monom a1(1.0, 123), a2(2.0, 321);
    Monom b1(3.0, 234), b2(4.0, 456), b3(5.0, 653);
    Polinom a, b;
    
    a.Insert(a1); a.Insert(a2);
    b.Insert(b1); b.Insert(b2); b.Insert(b3);

    a = b;

    EXPECT_EQ(b, a);
}

TEST(Polinom, can_assign_polinoms_change_polinom_length)
{
    Monom a1(1.0, 101), a2(2.0, 301);
    Monom b1(2.0, 300);

    Polinom a, b;
    a.Insert(a1); a.Insert(a2); b.Insert(b1);

    a = b;

    EXPECT_EQ(b.GetLength(), a.GetLength());
}

TEST(Polinom, can_add_polinoms)
{
    Monom a1(1.0, 123), a2(2.0, 456);
    Monom b1(3.0, 789), b2(4.0, 102), b3(8.4, 354);
    Polinom a, b, expPolinom;

    a.Insert(a1); a.Insert(a2);
    b.Insert(b1); b.Insert(b2); b.Insert(b3);

    expPolinom.Insert(a1); expPolinom.Insert(a2);
    expPolinom.Insert(b1); expPolinom.Insert(b2);
    expPolinom.Insert(b3);

    EXPECT_EQ(expPolinom, a + b);
}

TEST(Polinom, result_of_addition_polinoms_is_reduced)
{
    Monom a1(1.0, 123), a2(2.0, 102);
    Monom b1(8.9, 123), b2(4.0, 102), b3(8.4, 354);
    Monom c1(9.9, 123), c2(6.0, 102);
    
    Polinom a, b, expPolinom;

    a.Insert(a1); a.Insert(a2);
    b.Insert(b1); b.Insert(b2); b.Insert(b3);
    expPolinom.Insert(c1); expPolinom.Insert(c2);
    expPolinom.Insert(b3);

    EXPECT_EQ(expPolinom, a + b);
}

TEST(Polinom, result_of_addition_polinoms_does_not_contain_zero_monoms)
{
    Monom a1(1.0, 123), a2(2.0, 102);
    Monom b1(-1.0, 123), b2(4.0, 000), b3(9.9, 159);
    
    Polinom a, b, expPolinom;

    a.Insert(a1); a.Insert(a2);
    b.Insert(b1); b.Insert(b2); b.Insert(b3);
    expPolinom.Insert(a2); expPolinom.Insert(b2); expPolinom.Insert(b3);

    EXPECT_EQ(expPolinom, a + b);
}

TEST(Polinom, can_multiply_scalar_by_polinom)
{
    const double scalar = 10.0;
    Monom a1(3.0, 123), a2(-1.0, 523);
    Monom e1(30.0, 123), e2(-10.0, 523);

    Polinom a, expPolinom;

    a.Insert(a1); a.Insert(a2);
    expPolinom.Insert(e1); expPolinom.Insert(e2);

    EXPECT_EQ(expPolinom, a*scalar);
}

TEST(Polinom, can_subtract_polinoms)
{
    Monom a1(9.9, 123), a2(4.0, 432);
    Monom b1(9.0, 123), b2(2.0, 432);
    Monom e1(0.9, 123), e2(2.0, 432);
    
    Polinom a, b, expPolinom;

    a.Insert(a1); a.Insert(a2);
    b.Insert(b1); b.Insert(b2);
    expPolinom.Insert(e1); expPolinom.Insert(e2);

    EXPECT_EQ(expPolinom, (a - b));
}

TEST(Polinom, can_multiply_monom_by_polinom)
{
    Monom m(10, 111);
    Monom a1(3.5, 123), a2(-1.5, 456);
    Monom e1(35.0, 234), e2(-15.0, 567);

    Polinom a, expPolinom;
    a.Insert(a1); a.Insert(a2);
    expPolinom.Insert(e1); expPolinom.Insert(e2);
    
    EXPECT_EQ(expPolinom, a*m);
}

TEST(Polinom, throw_when_result_of_multiply_monom_by_polinom_have_incorrect_index)
{
    Monom m(1.0, 456);
    Monom a1(3.0, 345), a2(9.0, 111);

    Polinom a;
    a.Insert(a1); a.Insert(a2);

    ASSERT_ANY_THROW(a*m);
}

TEST(Polinom, can_multiply_polinoms)
{
    Polinom a;
    Monom a1(1.5, 789), a2(2.5, 123), a3(3.5, 123);
    a.Insert(a1); a.Insert(a2); a.Insert(a3);

    Polinom b;
    Monom b1(2.0, 210), b2(0.0, 111);
    b.Insert(b1); b.Insert(b2); 

    Polinom expPolinom;
    Monom e1(3.0, 999), e2(12.0, 333);
    expPolinom.Insert(e1); expPolinom.Insert(e2);

    EXPECT_EQ(expPolinom, a * b);
}

TEST(Polinom, result_of_multiply_polinoms_is_reduced)
{
    Polinom a;
    Monom a1(1.5, 123), a2(2.5, 342), a3(3.5, 300);
    a.Insert(a1); a.Insert(a2); a.Insert(a3);

    Polinom b;
    Monom b1(2.0, 451), b2(2.2, 232);
    b.Insert(b1); b.Insert(b2);

    Polinom expPolinom;
    Monom e1(5.0, 793), e2(7.0, 751), e3(8.5, 574);
    Monom e4(7.7, 532), e5(3.3, 355);
    expPolinom.Insert(e1); expPolinom.Insert(e2); expPolinom.Insert(e3);
    expPolinom.Insert(e4); expPolinom.Insert(e5);
    
    EXPECT_EQ(expPolinom, a * b);
}

TEST(Polinom, throw_when_result_of_multiply_polinoms_have_incorrect_index)
{
    Polinom a;
    Monom a1(1.5, 123), a2(2.5, 352), a3(9.0, 102);

    Polinom b;
    Monom b1(2.0, 451), b2(2.2, 232);
    b.Insert(b1); b.Insert(b2);
    
    ASSERT_ANY_THROW(a * b);
}