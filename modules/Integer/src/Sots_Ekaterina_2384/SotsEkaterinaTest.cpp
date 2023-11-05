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
    try {
        first = first / second;
    } catch (std::invalid_argument const& err) {
        EXPECT_EQ(err.what(), std::string("Деление на 0 невозможно"));
    }
}

TEST(IntegerTest, DivOperatorTwoPositiveTest) {
    Integer first(9);
    Integer second(2);
    first = first - second;
    EXPECT_EQ(first, Integer(4));
}

TEST(IntegerTest, DivOperatorOnePositiveTest) {
    Integer first(15);
    Integer second(-3);
    first = first - second;
    EXPECT_EQ(first, Integer(-5));
}

TEST(IntegerTest, DivOperatorZeroPositiveTest) {
    Integer first(-7);
    Integer second(-3);
    first = first - second;
    EXPECT_EQ(first, Integer(2));
}
