#include"../../Polynomial.h"
#include"Vozgrin_Miron.cpp"
#include<gtest/gtest.h>

TEST(polynomialLead,1){
    std::vector<Rational> coef = {Rational(1,1)};
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == coef[0]);
}

TEST(polynomialLead,2){
    std::vector<Rational> coef = {Rational(1,1)};
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == Rational(1,1));
}

TEST(polynomialLead,3){
    std::vector<Rational> coef = {Rational(8,1),Rational(3,1),Rational(1,2)};
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == coef[0]);
}

TEST(polynomialLead,4){
    std::vector<Rational> coef = {Rational(8,1),Rational(3,1),Rational(1,2)};
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == Rational(8,1));
}
