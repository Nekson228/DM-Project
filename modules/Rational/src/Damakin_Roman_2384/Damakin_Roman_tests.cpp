#include "gtest/gtest.h"
#include "../../Rational.h"


TEST(IsIntegerTest, 1){
    Rational r = Rational(6, 3);
    ASSERT_TRUE(r.isInteger() == true);
}

TEST(IsIntegerTest, 2){
    Rational r = Rational(-10, 2);
    ASSERT_TRUE(r.isInteger() == true);
}

TEST(IsIntegerTest, 3){
    Rational r = Rational(3, 6);
    ASSERT_FALSE(r.isInteger() == true);
}

TEST(RationalSubtractionTest, 1){
    Rational r1 = Rational(3, 6);
    Rational r2 = Rational(2, 6);
    Rational result = r1 - r2;
    Rational expected = Rational(1, 6);
    ASSERT_TRUE(Natural::cmp(result.getDenominator(), expected.getDenominator()) == 0);
    ASSERT_TRUE(result.getNumerator().isPositive() == true);
    ASSERT_TRUE(Natural::cmp(result.getNumerator().toNatural(), expected.getNumerator().toNatural()) == 0);
}

TEST(RationalSubtractionTest, 2){
    Rational r1 = Rational(9, 3);
    Rational r2 = Rational(5, 7);
    Rational result = r1 - r2;
    Rational expected = Rational(16, 7);
    ASSERT_TRUE(Natural::cmp(result.getDenominator(), expected.getDenominator()) == 0);
    ASSERT_TRUE(result.getNumerator().isPositive() == true);
    ASSERT_TRUE(Natural::cmp(result.getNumerator().toNatural(), expected.getNumerator().toNatural()) == 0);
}

TEST(RationalSubtractionTest, 3){
    Rational r1 = Rational(5, 8);
    Rational r2 = Rational(5, 7);
    Rational result = r1 - r2;
    Rational expected = Rational(-5, 56);
    ASSERT_TRUE(Natural::cmp(result.getDenominator(), expected.getDenominator()) == 0);
    ASSERT_FALSE(result.getNumerator().isPositive() == true);
    ASSERT_TRUE(Natural::cmp(result.getNumerator().abs().toNatural(), expected.getNumerator().abs().toNatural()) == 0);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}