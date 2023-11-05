#include "../../Polynomial.h"
#include "gtest/gtest.h"
#include <vector>

TEST(PolynomialTest, FactoriseLowDegreeTest) {
    std::vector<Rational> cf1 = {Rational{5,1}};
    std::vector<Rational> cf2 = {};
    Polynomial poly1(cf1);
    Polynomial poly2(cf2);
    EXPECT_EQ(poly1.factorize(), poly1);
    EXPECT_EQ(poly2.factorize(), poly2);
}

TEST(PolynomialTest, FactoriseNotChangeTest) {
    std::vector<Rational> cf = {Rational{5,1}, Rational{5, 1}};
    Polynomial poly(cf);
    EXPECT_EQ(poly.factorize(), poly);
}

TEST(PolynomialTest, FactoriseChangeTest) {
    std::vector<Rational> cf1 = {Rational{6,5}, Rational{3,4}};
    std::vector<Rational> cf2 = {Rational{8,1}, Rational{5,1}};
    Polynomial poly1(cf1);
    Polynomial poly2(cf2);
    EXPECT_EQ(poly1.factorize(), poly2);
}

TEST(PolynomialTest, SinglifyZeroRootTest) {
    std::vector<Rational> cf = {Rational{5,1}};
    Polynomial poly(cf);
    EXPECT_EQ(poly.singlify(), poly);
}

TEST(PolynomialTest, SinglifyOneRootTest) {
    std::vector<Rational> cf = {Rational{1,1}, Rational{-14,2}, Rational{12,1}}; // (x-3)(x-4) = x^2 - 7x + 12
    Polynomial poly(cf);
    EXPECT_EQ(poly.singlify(), poly);
}

TEST(PolynomialTest, SinglifyManyRootsTest) {
    std::vector<Rational> cf1 = {Rational{1,1}, Rational{-6,1}, Rational{27,3}}; // (x-3)^2 = x^2 - 6x + 9
    std::vector<Rational> cf2 = {Rational{1,1}, Rational{-3,1}};                 // x - 3
    Polynomial poly1(cf1);
    Polynomial poly2(cf2);
    EXPECT_EQ(poly1.singlify(), poly2);
}