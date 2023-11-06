#include "../../Rational.h"
#include "gtest/gtest.h"

TEST(RationalTest, ToIntegerThrowTest) {
    Rational num(1,2);
    EXPECT_THROW(num.toInteger(), std::invalid_argument);
}

TEST(RationalTest, ToIntegerNegativeTest) {
    Rational num(-2,1);
    EXPECT_EQ(num.toInteger(), Integer(-2));
}

TEST(RationalTest, ToIntegerPositiveReduceTest) {
    Rational num(6,2);
    EXPECT_EQ(num.toInteger(), Integer(3));
}

