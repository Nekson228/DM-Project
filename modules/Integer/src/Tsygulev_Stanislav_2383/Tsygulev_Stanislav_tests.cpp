#include "../../Integer.h"
#include "gtest/gtest.h"

TEST(IntegerTest, negativeZeroValueTest) {
    Integer num(0);
    EXPECT_EQ(num.negative(), Integer(0));
}

TEST(IntegerTest, negativePositiveValueTest) {
    Integer num(123);
    EXPECT_EQ(num.negative(), Integer(-123));
}

TEST(IntegerTest, negativeNegativeValueTest) {
    Integer num(-777);
    EXPECT_EQ(num.negative(), Integer(777));
}