#include "test.h"

TEST(test_divide_two_integers, divideTwoIntegers001)
{
    int dividend = 10;
    int divisor = 3;
    int expect = 3;
    ASSERT_EQ(expect, divide(dividend, divisor));
}

TEST(test_divide_two_integers, divideTwoIntegers002)
{
    int dividend = 7;
    int divisor = -3;
    int expect = -2;
    ASSERT_EQ(expect, divide(dividend, divisor));
}

TEST(test_divide_two_integers, divideTwoIntegers003)
{
    int dividend = 0;
    int divisor = -3;
    int expect = 0;
    ASSERT_EQ(expect, divide(dividend, divisor));
}

TEST(test_divide_two_integers, divideTwoIntegers004)
{
    int dividend = -2147483648;
    int divisor = -1;
    int expect = 2147483647;
    ASSERT_EQ(expect, divide(dividend, divisor));
}

TEST(test_divide_two_integers, divideTwoIntegers005)
{
    int dividend = -2147483648;
    int divisor = 1;
    int expect = -2147483648;
    ASSERT_EQ(expect, divide(dividend, divisor));
}

TEST(test_divide_two_integers, divideTwoIntegers006)
{
    int dividend = -2147483648;
    int divisor = -2147483648;
    int expect = 1;
    ASSERT_EQ(expect, divide(dividend, divisor));
}
