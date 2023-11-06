#include "../../Natural.h"
#include "gtest/gtest.h"

TEST(NaturalTest, gcdZeroTest) {
    Natural first(5);
    Natural second(0);
    EXPECT_EQ(first.cmp(first.gcd(first, second), first), 0);
}

TEST(NaturalTest, gcdPrimeTest) {
    Natural first(8);
    Natural second(5);
    EXPECT_EQ(first.cmp(first.gcd(first, second), Natural(1)), 0);
}

TEST(NaturalTest, gcdNotPrimeTest) {
    Natural first(16);
    Natural second(12);
    EXPECT_EQ(first.cmp(first.gcd(first, second), Natural(4)), 0);
}