//
// Created by lipmip on 05.11.2023.
//
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

TEST(mul10degree25, 3) {
    Natural test_object(1);
    Natural expected_size("10000000000000000000000000");
    EXPECT_EQ(test_object.mulBy10k(25), expected_size);
}

TEST(lcm5and6, 4) {
    Natural first(5);
    Natural second(6);
    EXPECT_EQ(Natural(30), first.lcm(first, second));
}

TEST(lcm1and1, 5) {
    Natural first(1);
    Natural second(1);
    EXPECT_EQ(Natural(1), first.lcm(first, second));
}

TEST(lcm1324234234and2, 6) {
    Natural first("1324234234");
    Natural second(2);
    EXPECT_EQ(Natural("1324234234"), first.lcm(first, second));
}

int main(int argc , char **argv){
    ::testing::InitGoogleTest(&argc , argv);
    return RUN_ALL_TESTS();
}


