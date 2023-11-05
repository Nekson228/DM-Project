//
// Created by lipmip on 05.11.2023.
//

#include "gtest/gtest.h"
#include "../../Polynomial.h"

TEST(subToGetZero, 1) {
    std::vector<Rational> coefs;
    for (int i = 0; i < 5; i++) {
        coefs.push_back(Rational(Integer(i), Natural(i + 10)));
    }
    std::vector<Rational> finalCoefs = {Rational(Integer(0), Natural(1))};
    EXPECT_EQ(Polynomial(coefs)-Polynomial(coefs), Polynomial(finalCoefs));
}

TEST(subToGetNotZero, 2) {
    std::vector<Rational>firstCoefs;
    std::vector<Rational>secondCoefs;
    std::vector<Rational>finalCoefs;
    for (int i = 0; i < 5; i++) {
        firstCoefs.push_back(Rational(Integer(i+5), Natural(i+1)));
        secondCoefs.push_back(Rational(Integer(i+3), Natural(i+1)));
        finalCoefs.push_back(Rational(Integer(2), Natural(i+1)));
    }
    EXPECT_EQ(Polynomial(firstCoefs) - Polynomial(secondCoefs) , Polynomial(finalCoefs));
}

TEST(modToGetZero, 3){
    std::vector<Rational> firstCoefs = {Rational(Integer(1), Natural(1)), Rational(Integer(0)), Rational(Integer(1))};
    std::vector<Rational> secondCoefs = {Rational(Integer(1))};
    std::vector<Rational> finalCoefs = {Rational(Integer(0), Natural(1))};
    EXPECT_EQ(Polynomial(firstCoefs)%Polynomial(secondCoefs), Polynomial(finalCoefs));
}

TEST(modToGetNotZero, 4){
    std::vector<Rational> firstCoefs = {Rational(Integer(1), Natural(1)), Rational(Integer(0)), Rational(Integer(-1))};
    std::vector<Rational> secondCoefs = {Rational(Integer(1)), Rational(Integer(1))};
    std::vector<Rational> finalCoefs = {Rational(Integer(1), Natural(1)), Rational(Integer(-1))};
    EXPECT_EQ(Polynomial(firstCoefs)%Polynomial(secondCoefs), Polynomial(finalCoefs));
}