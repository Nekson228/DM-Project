#include <gtest/gtest.h>
#include "../Natural/Natural.h"
#include <random>


TEST(mulByDigit, zero_mult)
{
    Natural natural(12345);
    digit muptiplier = 0;
    natural = natural.mulByDigit(muptiplier);
    EXPECT_TRUE(natural.isZero());
}

TEST(mulByDigit, normal)
{
    Natural natural(12345);
    Natural check(12345*3);
    digit muptiplier = 3;
    natural = natural.mulByDigit(muptiplier);
    EXPECT_TRUE(Natural::cmp(natural, check)==0);
}

TEST(mulByDigit, zero_natural)
{
    Natural natural(0);
    digit muptiplier = 3;
    natural.mulByDigit(muptiplier);
    EXPECT_TRUE(natural.isZero());
}

TEST(subScaled, zero_other)
{
    Natural natural(12345);
    Natural check(12345);
    Natural natural_other(0);
    digit k = 5;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(Natural::cmp(natural, check)==0);
}

TEST(subScaled, zero_k)
{
    Natural natural(12345);
    Natural check(12345);
    Natural natural_other(12345);
    digit k = 0;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(Natural::cmp(natural, check)==0);
}

TEST(subScaled, zero_all)
{
    Natural natural(0);
    Natural natural_other(0);
    digit k = 0;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(natural.isZero());
}

TEST(subScaled, usual)
{
    Natural natural("1234567");
    Natural check("1172842");
    Natural natural_other(12345);
    digit k = 5;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(Natural::cmp(natural, check)==0);
}

TEST(subScaled, equal)
{
    Natural natural("1234567");
    Natural check(1);
    Natural natural_other("1234566");
    digit k = 1;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(Natural::cmp(natural, check)==0);
}

TEST(remains, one)
{
    Natural natural("1234567");
    Natural natural_other(1);
    natural = natural%natural_other;
    EXPECT_TRUE(natural.isZero());
}

TEST(remains, usual)
{
    Natural natural("1234567");
    Natural check(67);
    Natural natural_other(12345);
    natural = natural%natural_other;
    EXPECT_TRUE(Natural::cmp(natural, check)==0);
}

TEST(remains, smaller)
{
    Natural natural("1234567");
    Natural check("1234567");
    Natural natural_other("123456789");
    natural = natural%natural_other;
    EXPECT_TRUE(Natural::cmp(natural, check)==0);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}