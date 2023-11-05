#include"../../Polynomial.h"
#include"Vozgrin_Miron.cpp"
#include<gtest/gtest.h>

TEST(polynomialLead,1){
    std::vector<Rational> coef;
    coef.push_back(Rational(1,1));
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == coef[0]);
}

TEST(polynomialLead,2){
    std::vector<Rational> coef;
    coef.push_back(Rational(1,1));
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == Rational(1,1));
}

TEST(polynomialLead,3){
    std::vector<Rational> coef;
    coef.push_back(Rational(1,1));
    coef.push_back(Rational(3,1));
    coef.push_back(Rational(8,1));
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == coef[0]);
}

TEST(polynomialLead,3){
    std::vector<Rational> coef;
    coef.push_back(Rational(1,1));
    coef.push_back(Rational(3,1));
    coef.push_back(Rational(8,1));
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == Rational(8,1));
}
