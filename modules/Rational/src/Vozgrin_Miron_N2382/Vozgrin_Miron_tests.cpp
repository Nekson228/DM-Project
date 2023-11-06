#include"../../Rational.h"
#include"Vozgrin_Miron.cpp"
#include<gtest/gtest.h>

TEST(rationalDiv,1){
    ASSERT_TRUE(Rational(0, 1) / Rational(1, 1) == Rational(0, 1));
}

TEST(rationalDiv,2){
    ASSERT_TRUE(Rational(7, 8) / Rational(5, 6) == Rational(42, 40));
}

TEST(rationalDiv,3){
    ASSERT_TRUE(Rational(-5,10) / Rational(2, 3) == Rational(-15, 20));
}

TEST(rationalDiv,4){
    ASSERT_TRUE(Rational(5,10) / Rational(-2, 3) == Rational(-15, 20));
}

TEST(rationalDiv,5){
    ASSERT_THROW((Rational(1, 1) / Rational(0, 1)),std::invalid_argument);
}
