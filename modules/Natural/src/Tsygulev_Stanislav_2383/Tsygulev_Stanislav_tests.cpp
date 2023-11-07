#include "../../Natural.h"
#include "gtest/gtest.h"

TEST(NaturalTest, addOneZeroTest) {
    Natural num(0);
    EXPECT_EQ(num.addOne(), Natural(1));
}

TEST(NaturalTest, addOneNoTransitionTest) {
    Natural num(11);
    EXPECT_EQ(num.addOne(), Natural(12));
}

TEST(NaturalTest, addOneTransitionTest) {
    Natural num(99);
    EXPECT_EQ(num.addOne(), Natural(100));
}

TEST(NaturalTest, subLowerTest) {
    Natural num(10);
    EXPECT_THROW(num - Natural(20), std::invalid_argument);
}

TEST(NaturalTest, subEqualTest) {
    Natural num(77);
    EXPECT_EQ(num - Natural(77), Natural(0));
}

TEST(NaturalTest, subGreaterTest) {
    Natural num(2248);
    EXPECT_EQ(num - Natural(1372), Natural(876));
}