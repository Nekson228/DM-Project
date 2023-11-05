#include <gtest/gtest.h>
#include "../../Rational.h"

TEST(RationalAddictionTest, 1) {
    Rational first_number = Rational(1, 4);
    Rational second_number = Rational(1, 4);
    Rational answer = Rational(1, 2);
    EXPECT_EQ(first_number + second_number, answer);
}

TEST(RationalAddictionnTest, 2) {
    Rational first_number = Rational(1, 2);
    Rational second_number = Rational(1, 2);
    Rational answer = Rational(1, 1);
    EXPECT_EQ(first_number + second_number, answer);

}

TEST(RationalAddictionTest, 3) {
    Rational first_number = Rational(3, 5);
    Rational second_number = Rational(1, 3);
    Rational answer = Rational(14, 15);
    EXPECT_EQ(first_number + second_number, answer);
}

TEST(RationalAddictionTest, 4) {
    Rational first_number = Rational(2, 3);
    Rational second_number = Rational(5, 7);
    Rational answer = Rational(29, 21);
    EXPECT_EQ(first_number + second_number, answer);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}