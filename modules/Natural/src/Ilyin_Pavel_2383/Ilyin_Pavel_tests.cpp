#include <gtest/gtest.h>
#include "../../Natural.h"

TEST(mul10degree0check, 1) {
    Natural first(5);
    Natural second(5);
    Natural third;
    third = first.mulBy10k(0);
    EXPECT_EQ(third, second);
}

TEST(mul10degree6check, 2) {
    Natural first = Natural(5), second = Natural(5000000), third = first.mulBy10k(6);
    EXPECT_EQ(third, second);
}

TEST(gcd5i6, 3) {
    Natural first(5);
    Natural second(6);
    EXPECT_EQ(Natural(30), first.gcd(first, second));
}

int main(int argc , char **argv){
    ::testing::InitGoogleTest(&argc , argv);
    return RUN_ALL_TESTS();
}
