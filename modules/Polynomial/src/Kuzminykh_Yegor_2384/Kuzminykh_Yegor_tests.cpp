#include <gtest/gtest.h>
#include "../../Polynomial.h"

TEST(PolynomialAdditionTest,1){
    std::vector<Rational> coef1 = {Rational(Integer(1)), Rational(Integer(1)), Rational(Integer(1))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(1)), Rational(Integer(1)), Rational(Integer(1)),Rational(Integer(1))};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(1)), Rational(Integer(2)), Rational(Integer(2)),Rational(Integer(2))};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol+second_pol, result);
}

TEST(PolynomialAdditionTest,2){
    std::vector<Rational> coef1 = {Rational(Integer(1))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(0))};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(1))};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol+second_pol, result);
}
TEST(PolynomialAdditionTest,3){
    std::vector<Rational> coef1 = {Rational(1,2), Rational(1,2),Rational(1,2)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(1,2), Rational(1,2),Rational(1,2)};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(1,1), Rational(1,1),Rational(1,1)};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol+second_pol, result);
}
TEST(PolynomialAdditionTest,4){
    std::vector<Rational> coef1 = {Rational(1,2), Rational(1,2),Rational(1,2)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(-1,2), Rational(1,2),Rational(1,2)};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(1,1),Rational(1,1)};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol+second_pol, result);
}


TEST(PolynomialDivisionTest,1){
    std::vector<Rational> coef1 = {Rational(1,1), Rational(1,1),Rational(1,1)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(1,1), Rational(1,1),Rational(1,1)};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(1,1)};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol/second_pol, result);
}
TEST(PolynomialDivisionTest,2){
    std::vector<Rational> coef1 = {Rational(Integer(1)), Rational(Integer(2)), Rational(Integer(3))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(1)), Rational(Integer(5))};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(1)), Rational(Integer(-3))};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol/second_pol, result);
}
TEST(PolynomialDivisionTest,3){
    std::vector<Rational> coef1 = {Rational(Integer(5)), Rational(Integer(2)), Rational(Integer(3)), Rational(Integer(4))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(1)), Rational(Integer(5))};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(5)), Rational(Integer(-23)), Rational(Integer(118))};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol/second_pol, result);
}
TEST(PolynomialDivisionTest,4){
    std::vector<Rational> coef1 = {Rational(1,1), Rational(1,1),Rational(1,1)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(0,1)};
    Polynomial second_pol = Polynomial(coef2);
    try {
        Polynomial res = first_pol/second_pol;
    }catch (std::invalid_argument &e){
        EXPECT_EQ(e.what(), (std::string)"Деление на ноль невозможно");
    }
}

TEST(PolynomialDerivativeTest,1){
    std::vector<Rational> coef1 = {Rational(Integer(1)), Rational(Integer(1))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(1))};
    Polynomial result = Polynomial(coef2);
    EXPECT_EQ(first_pol.derivative(), result);
}

TEST(PolynomialDerivativeTest,2){
    std::vector<Rational> coef1 = {Rational(1,3), Rational(1,2), Rational(1,1), Rational(1,1)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(1,1), Rational(1,1), Rational(1,1)};
    Polynomial result = Polynomial(coef2);
    EXPECT_EQ(first_pol.derivative(), result);
}
TEST(PolynomialDerivativeTest,3){
    std::vector<Rational> coef1 = {Rational(Integer(5)), Rational(Integer(3)), Rational(Integer(2)), Rational(Integer(1))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(15)), Rational(Integer(6)), Rational(Integer(2))};
    Polynomial result = Polynomial(coef2);
    EXPECT_EQ(first_pol.derivative(), result);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
