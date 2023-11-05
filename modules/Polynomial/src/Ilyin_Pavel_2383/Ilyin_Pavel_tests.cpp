//
// Created by lipmip on 05.11.2023.
//

#include "gtest/gtest.h"
#include "../../Polynomial.h"

TEST(subToGetZero, 1) {
    std::vector<Rational> coefs;
    for (int i = 0; i < 5; i++) {
        coefs.push_back(Rational(i, i+10));
    }
    std::vector<Rational> finalCoefs = {Rational(0, 1)};
    EXPECT_EQ(Polynomial(coefs)-Polynomial(coefs), Polynomial(finalCoefs));
}

TEST(subToGetNotZero, 2) {
    std::vector<Rational>firstCoefs;
    std::vector<Rational>secondCoefs;
    std::vector<Rational>finalCoefs;
    for (int i = 0; i < 5; i++) {
        firstCoefs.push_back(Rational(i+5, i+1));
        secondCoefs.push_back(Rational(i+3, i+1));
        finalCoefs.push_back(Rational(2, i+1));
    }
    EXPECT_EQ(Polynomial(firstCoefs) - Polynomial(secondCoefs) , Polynomial(finalCoefs));
}

TEST(subZero, 3) {
    std::vector<Rational>firstCoefs = {Rational(1,1), Rational(0,1), Rational(1,1)};
    std::vector<Rational>zero = {Rational(0,1)};
    EXPECT_EQ(Polynomial(firstCoefs) - Polynomial(zero), Polynomial(firstCoefs));
}

TEST(modToGetZero, 4){
    std::vector<Rational> firstCoefs = {Rational(1,1), Rational(0,1), Rational(1,1)};
    std::vector<Rational> secondCoefs = {Rational(1,1)};
    std::vector<Rational> finalCoefs = {Rational(0,1)};
    EXPECT_EQ(Polynomial(firstCoefs)%Polynomial(secondCoefs), Polynomial(finalCoefs));
}

TEST(modToGetNotZero, 5){
    std::vector<Rational> firstCoefs = {Rational(1,1), Rational(0,1), Rational(-1,1)};
    std::vector<Rational> secondCoefs = {Rational(1,1), Rational(1,1)};
    std::vector<Rational> finalCoefs = {Rational(1,1), Rational(-1,1)};
    EXPECT_EQ(Polynomial(firstCoefs)%Polynomial(secondCoefs), Polynomial(finalCoefs));
}

TEST(modToSmtElse, 6) {
    std::vector<Rational> firstCoefs = {Rational(9,1), Rational(56,1), Rational(1,1)};
    std::vector<Rational> secondCoefs = {Rational(1,1), Rational(0,1)};
    std::vector<Rational> finalCoefs = {Rational(1,1)};
    EXPECT_EQ(Polynomial(firstCoefs)%Polynomial(secondCoefs), Polynomial(finalCoefs));
}
