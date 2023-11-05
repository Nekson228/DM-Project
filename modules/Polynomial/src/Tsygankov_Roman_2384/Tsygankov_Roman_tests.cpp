#include "gtest/gtest.h"
#include "../../Polynomial.h"

TEST(mulByXk, mul_test){
    std::vector<Rational> coef1;
    coef1.push_back(Rational(1, 1));
    coef1.push_back(Rational(2, 1));
    coef1.push_back(Rational(3, 1));

    std::vector<Rational> coef2;
    coef2.push_back(Rational(1, 1));
    coef2.push_back(Rational(2, 1));
    coef2.push_back(Rational(3, 1));
    coef2.push_back(Rational(0, 1));
    coef2.push_back(Rational(0, 1));

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.mulByXk(2), g);

}