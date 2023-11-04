#include <gtest/gtest.h>
#include "../../Polynomial.h"


TEST(PolynomialMultiplicationTest, 1){
    std::vector<Rational> coef1 = {Rational(Integer(1)), Rational(2, 3), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(-4)), Rational(4, 3), Rational(6, 7)};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(-4)), Rational(-4, 3), Rational(425, 63), Rational(-23, 21), Rational(-15, 14)};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1*p2) == expected);
}

TEST(PolynomialMultiplicationTest, 2){
    std::vector<Rational> coef1 = {Rational(Integer(10)), Rational(3, 2), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(2, 5), Rational(4, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(4)), Rational(227, 45), Rational(-33, 2), Rational(-55, 18), Rational(25, 12), Rational(Integer(0))};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1*p2) == expected);
}

TEST(PolynomialMultiplicationTest, 3){
    std::vector<Rational> coef1 = {Rational(2, 3), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(13)), Rational(-9, 3), Rational(6, 8)};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(26, 3), Rational(-73, 4), Rational(17, 4), Rational(-15, 16)};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1*p2) == expected);
}

TEST(PolynomialMultiplicationTest, 4){
    std::vector<Rational> coef1 = {Rational(2, 3), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(0, 1)};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(0, 1)};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1*p2) == expected);
}

TEST(PolynomialMultiplicationTest, 5){
    std::vector<Rational> coef1 = {Rational(Integer(1))};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(2, 5), Rational(4, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(2, 5), Rational(4, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1*p2) == expected);
}

TEST(PolynomialMultiplicationTest, 6){
    std::vector<Rational> coef1 = {Rational(1, 5), Rational(5, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(-1))};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(-1, 5), Rational(-5, 9), Rational(5, 3), Rational(Integer(0))};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1*p2) == expected);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}