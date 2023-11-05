#include <gtest/gtest.h>
#include "../../Rational.h"
TEST(RationalMultiplicationTest,1){
    Rational first_number = Rational(1,4);
    Rational second_number = Rational(2,1);
    Rational answer = Rational(1,2);
    EXPECT_EQ(first_number*second_number, answer);
}
TEST(RationalMultiplicationTest, 2){
    Rational first_number = Rational(5,2);
    Rational second_number = Rational(2,5);
    Rational answer = Rational(1,1);
    EXPECT_EQ(first_number*second_number, answer);

}
TEST(RationalMultiplicationTest,3){
    Rational first_number = Rational(2,3);
    Rational second_number = Rational(3,4);
    Rational answer = Rational(1,2);
    EXPECT_EQ(first_number*second_number,answer);
}

TEST(RationalMultiplicationTest,4){
    Rational first_number = Rational(2,3);
    Rational second_number = Rational(5,7);
    Rational answer = Rational(10,21);
    EXPECT_EQ(first_number*second_number,answer);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}