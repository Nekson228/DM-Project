#include "../../Rational.h"
#include "gtest/gtest.h"

TEST(RationalTest, ToIntegerThrowTest) {
    Rational num(1,2);
    try {
        num.toInteger();
    } catch (std::invalid_argument const& err) {
        EXPECT_EQ(err.what(), std::string("Преобразование в \"Integer\" невозможно"));
    }
}

TEST(RationalTest, ToIntegerNegativeTest) {
    Rational num(-2,1);
    EXPECT_EQ(num.toInteger(), Integer(-2));
}

TEST(RationalTest, ToIntegerPositiveReduceTest) {
    Rational num(6,2);
    EXPECT_EQ(num.toInteger(), Integer(3));
}

