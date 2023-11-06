#include "../../Integer.h"
#include "gtest/gtest.h"

TEST(IntegerTest, toNaturalNegativeTest) {
    Integer num(-1);
    try {
        num.toNatural();
    } catch (std::invalid_argument const& err) {
        EXPECT_EQ(err.what(), std::string("Число отрицательное"));
    }
}

TEST(IntegerTest, toNaturalZeroTest) {
    Integer num(0);
    Natural value = num.toNatural();
    EXPECT_EQ(value.cmp(value, Natural(0)), 0);
}

TEST(IntegerTest, toNaturalPositiveTest) {
    Integer num(123);
    Natural value = num.toNatural();
    EXPECT_EQ(value.cmp(value, Natural(123)), 0);
}

TEST(IntegerTest, DivOperatorDivByZeroTest) {
    Integer first(2);
    Integer second(0);
    EXPECT_THROW(first = first / second, std::invalid_argument);
}

TEST(IntegerTest, DivOperatorPosPosTest) {
    Integer first(7);
    Integer second(3);
    first = first / second;
    EXPECT_EQ(first, Integer(2));
}

TEST(IntegerTest, DivOperatorPosNegTest) {
    Integer first(7);
    Integer second(-3);
    first = first / second;
    EXPECT_EQ(first, Integer(-2));
}

TEST(IntegerTest, DivOperatorNegPosTest) {
    Integer first(-7);
    Integer second(3);
    first = first / second;
    EXPECT_EQ(first, Integer(-3));
}

TEST(IntegerTest, DivOperatorNegNegTest) {
    Integer first(-7);
    Integer second(-3);
    first = first / second;
    EXPECT_EQ(first, Integer(3));
}

