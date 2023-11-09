#include "../../modules/Polynomial/Polynomial.h"
#include "gtest/gtest.h"
#include <vector>

TEST(PolynomialTest, FactoriseLowDegreeTest) {
    std::vector<Rational> cf1 = {Rational{5, 1}};
    std::vector<Rational> cf2 = {};
    Polynomial poly1(cf1);
    Polynomial poly2(cf2);
    EXPECT_EQ(poly1.factorize(), poly1);
    EXPECT_EQ(poly2.factorize(), poly2);
}

TEST(PolynomialTest, FactoriseNotChangeTest) {
    std::vector<Rational> cf = {Rational{5, 1}, Rational{5, 1}};
    Polynomial poly(cf);
    EXPECT_EQ(poly.factorize(), poly);
}

TEST(PolynomialTest, FactoriseChangeTest) {
    std::vector<Rational> cf1 = {Rational{6, 5}, Rational{3, 4}};
    std::vector<Rational> cf2 = {Rational{8, 1}, Rational{5, 1}};
    Polynomial poly1(cf1);
    Polynomial poly2(cf2);
    EXPECT_EQ(poly1.factorize(), poly2);
}

TEST(PolynomialTest, SinglifyZeroRootTest) {
    std::vector<Rational> cf = {Rational{5, 1}};
    Polynomial poly(cf);
    EXPECT_EQ(poly.singlify(), poly);
}

TEST(PolynomialTest, SinglifyOneRootTest) {
    std::vector<Rational> cf = {Rational{1, 1}, Rational{-14, 2}, Rational{12, 1}}; // (x-3)(x-4) = x^2 - 7x + 12
    Polynomial poly(cf);
    EXPECT_EQ(poly.singlify(), poly);
}

TEST(PolynomialTest, SinglifyManyRootsTest) {
    std::vector<Rational> cf1 = {Rational{1, 1}, Rational{-6, 1}, Rational{27, 3}}; // (x-3)^2 = x^2 - 6x + 9
    std::vector<Rational> cf2 = {Rational{1, 1}, Rational{-3, 1}};                 // x - 3
    Polynomial poly1(cf1);
    Polynomial poly2(cf2);
    EXPECT_EQ(poly1.singlify(), poly2);
}

TEST(PolynomialMultiplicationTest, 1) {
    std::vector<Rational> coef1 = {Rational(Integer(1)), Rational(2, 3), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(-4)), Rational(4, 3), Rational(6, 7)};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(-4)), Rational(-4, 3), Rational(425, 63), Rational(-23, 21),
                                   Rational(-15, 14)};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1 * p2) == expected);
}

TEST(PolynomialMultiplicationTest, 2) {
    std::vector<Rational> coef1 = {Rational(Integer(10)), Rational(3, 2), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(2, 5), Rational(4, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(4)), Rational(227, 45), Rational(-33, 2), Rational(-55, 18),
                                   Rational(25, 12), Rational(Integer(0))};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1 * p2) == expected);
}

TEST(PolynomialMultiplicationTest, 3) {
    std::vector<Rational> coef1 = {Rational(2, 3), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(13)), Rational(-9, 3), Rational(6, 8)};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(26, 3), Rational(-73, 4), Rational(17, 4), Rational(-15, 16)};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1 * p2) == expected);
}

TEST(PolynomialMultiplicationTest, 4) {
    std::vector<Rational> coef1 = {Rational(2, 3), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(0, 1)};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(0, 1)};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1 * p2) == expected);
}

TEST(PolynomialMultiplicationTest, 5) {
    std::vector<Rational> coef1 = {Rational(Integer(1))};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(2, 5), Rational(4, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(2, 5), Rational(4, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1 * p2) == expected);
}

TEST(PolynomialMultiplicationTest, 6)

{
    std::vector<Rational> coef1 = {Rational(1, 5), Rational(5, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(-1))};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(-1, 5), Rational(-5, 9), Rational(5, 3), Rational(Integer(0))};
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE((p1 * p2) == expected);
}

TEST(Ilyin_2383_Polynomial_sub_test, GetZero) {
    std::vector<Rational> coefs;
    for (int i = 0; i < 5; i++) {
        coefs.push_back(Rational(i, i + 10));
    }
    std::vector<Rational> finalCoefs = {Rational(0, 1)};
    EXPECT_EQ(Polynomial(coefs)-Polynomial(coefs), Polynomial(finalCoefs));
}

TEST(Ilyin_2383_Polynomial_sub_test, GetNotZero) {
    std::vector<Rational> firstCoefs;
    std::vector<Rational> secondCoefs;
    std::vector<Rational> finalCoefs;
    for (int i = 0; i < 5; i++) {
        firstCoefs.push_back(Rational(i + 5, i + 1));
        secondCoefs.push_back(Rational(i + 3, i + 1));
        finalCoefs.push_back(Rational(2, i + 1));
    }
    EXPECT_EQ(Polynomial(firstCoefs) -Polynomial(secondCoefs), Polynomial(finalCoefs));
}

TEST(Ilyin_2383_Polynomial_sub_test, subZero) {
    std::vector<Rational> firstCoefs = {Rational(1, 1), Rational(0, 1), Rational(1, 1)};
    std::vector<Rational> zero = {Rational(0, 1)};
    EXPECT_EQ(Polynomial(firstCoefs) -Polynomial(zero), Polynomial(firstCoefs));
}

TEST(Ilyin_2383_Polynomial_mod_test, GetZero) {
    std::vector<Rational> firstCoefs = {Rational(1, 1), Rational(0, 1), Rational(1, 1)};
    std::vector<Rational> secondCoefs = {Rational(1, 1)};
    std::vector<Rational> finalCoefs = {Rational(0, 1)};
    EXPECT_EQ(Polynomial(firstCoefs)%Polynomial(secondCoefs), Polynomial(finalCoefs));
}

TEST(Ilyin_2383_Polynomial_mod_test, GetNotZero) {
    std::vector<Rational> firstCoefs = {Rational(1, 1), Rational(0, 1), Rational(-1, 1)};
    std::vector<Rational> secondCoefs = {Rational(1, 1), Rational(1, 1)};
    std::vector<Rational> finalCoefs = {Rational(1, 1), Rational(-1, 1)};
    EXPECT_EQ(Polynomial(firstCoefs)%Polynomial(secondCoefs), Polynomial(finalCoefs));
}

TEST(Ilyin_2383_Polynomial_mod_test, get1) {
    std::vector<Rational> firstCoefs = {Rational(9, 1), Rational(56, 1), Rational(1, 1)};
    std::vector<Rational> secondCoefs = {Rational(1, 1), Rational(0, 1)};
    std::vector<Rational> finalCoefs = {Rational(1, 1)};
    EXPECT_EQ(Polynomial(firstCoefs)%Polynomial(secondCoefs), Polynomial(finalCoefs));
}

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

TEST(mulByXk, mul_test1){
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};
    std::vector<Rational> coef2 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};

    coef2.push_back(Rational(0, 1));
    coef2.push_back(Rational(0, 1));

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.mulByXk(2), g);

}

TEST(mulByXk, mul_test2){
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};

    Polynomial f(coef1);

    EXPECT_EQ(f.mulByXk(0), f);

}

TEST(mulByXk, mul_test3){
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};

    std::vector<Rational> coef2 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};
    coef2.push_back(Rational(0, 1));

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.mulByXk(1), g);
}

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

TEST(getDegree, regular_test){
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(3, 1), Rational(-1, 1)};
    Polynomial f(coef1);
    std::size_t ans = 2;
    std::size_t ans_test = f.getDegree();
    EXPECT_EQ(ans,ans_test);
}

TEST(getDegree, polynomial_with_degree_0){
    std::vector<Rational> coef1 = {Rational((1), (1))};

    Polynomial f(coef1);
    std::size_t ans = 0;
    std::size_t ans_test = f.getDegree();
    EXPECT_EQ(ans,ans_test);
}

TEST(getDegree, high_degree_test){
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(3, 1),Rational(-1, 1),Rational(-4, 1),
                                   Rational(1, 1),Rational(3, 1),Rational(-1, 1),Rational(-4, 1),Rational(-3, 1)};

    Polynomial f(coef1);
    std::size_t ans = 9;
    std::size_t ans_test = f.getDegree();
    EXPECT_EQ(ans,ans_test);
}

TEST(scale, regular_test){
    std::vector<Rational> coef1 = {Rational(1, 1),Rational(3, 1),Rational(-1, 1),Rational(-4, 1),Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(2, 1),Rational(6, 1),Rational(-2, 1),Rational(-8, 1),Rational(-6, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.scale(Rational(2,1)), g);
}

TEST(scale, negativ_number_test){
    std::vector<Rational> coef1 = {Rational(1, 1),Rational(3, 1),Rational(-1, 1),Rational(-4, 1),Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(-2,3),Rational(-2, 1),Rational(2, 3),Rational(8, 3),Rational(2, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.scale(Rational(-2,3)), g);
}

TEST(scale, test_with_0){
    std::vector<Rational> coef1 = {Rational(1, 1),Rational(3, 1),Rational(-1, 1),Rational(-4, 1),Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(0,1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.scale(Rational(0,1)), g);
}

TEST(gcd, polynomial_g_is_gcd){
    std::vector<Rational> coef1 = {Rational(1, 1),Rational(5, 1),Rational(6, 1)};

    std::vector<Rational> coef2 = {Rational(1, 1),Rational(3, 1)};

    std::vector<Rational> ans = {Rational(1, 1),Rational(3, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    Polynomial r(ans);
    EXPECT_EQ(Polynomial::gcd(f,g), r);
}

TEST(gcd, regular_test1){
    std::vector<Rational> coef1 = {Rational(1, 1),Rational(3, 1),Rational(-1, 1),Rational(-4, 1),Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(3, 1),Rational(10, 1),Rational(2, 1),Rational(-3, 1)};

    std::vector<Rational> ans = {Rational(1, 1),Rational(3, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    Polynomial r(ans);
    EXPECT_EQ(Polynomial::gcd(f,g), r);
}

TEST(gcd, regular_test2){
    std::vector<Rational> coef1 = {Rational(3, 1),Rational(10, 1),Rational(2, 1),Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(-5, 9),Rational(-25, 9),Rational(-10, 3)};

    std::vector<Rational> ans = {Rational(1, 1), Rational(3, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    Polynomial r(ans);
    EXPECT_EQ(Polynomial::gcd(f,g), r);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}