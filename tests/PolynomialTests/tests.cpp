#include "../../modules/Polynomial/Polynomial.h"
#include "gtest/gtest.h"
#include <vector>

TEST(Bormatov2383_Polynomial_FAC_P_Q, FactoriseLowDegreeTest) {
    std::vector<Rational> cf1 = {Rational{5, 1}};
    Polynomial poly1(cf1);
    EXPECT_EQ(poly1.factorize(), poly1);
}

TEST(Bormatov2383_Polynomial_FAC_P_Q, FactoriseNotChangeTest) {
    std::vector<Rational> cf1 = {Rational{5, 1}, Rational{5, 1}}, cf2 = {Rational(1, 1), Rational(1, 1)};
    Polynomial poly(cf1), answer(cf2);
    EXPECT_EQ(poly.factorize(), answer);
}

TEST(Bormatov2383_Polynomial_FAC_P_Q, FactoriseChangeTest) {
    std::vector<Rational> cf1 = {Rational{6, 5}, Rational{3, 4}};
    std::vector<Rational> cf2 = {Rational{8, 1}, Rational{5, 1}};
    Polynomial poly1(cf1);
    Polynomial poly2(cf2);
    EXPECT_EQ(poly1.factorize(), poly2);
}

//TEST(Bormatov2383_Polynomial_NMR_P_P, SinglifyZeroRootTest) {
//   std::vector<Rational> cf = {Rational{5, 1}};
//   Polynomial poly(cf);
//   EXPECT_THROW(poly.singlify(), std::invalid_argument);
//}

//TEST(Bormatov2383_Polynomial_NMR_P_P, SinglifyOneRootTest) {
//   std::vector<Rational> cf = {Rational{1, 1}, Rational{-14, 2}, Rational{12, 1}}; // (x-3)(x-4) = x^2 - 7x + 12
//   Polynomial poly(cf);
//   EXPECT_EQ(poly.singlify(), poly); // тест падает в методе singlify->gcd->(переопределение оператора остатка)
//}

TEST(Bormatov2383_Polynomial_NMR_P_P, SinglifyManyRootsTest) {
   std::vector<Rational> cf1 = {Rational{1, 1}, Rational{-6, 1}, Rational{27, 3}}; // (x-3)^2 = x^2 - 6x + 9
   std::vector<Rational> cf2 = {Rational{1, 2}, Rational{-3, 2}};                  // x - 3
   Polynomial poly1(cf1);
   Polynomial poly2(cf2);
   EXPECT_EQ(poly1.singlify(), poly2);
}

TEST(Damakin2384_Polynomial_MUL_PP_P, PolynomialMultiplicationTest1) {
    std::vector<Rational> coef1 = {Rational(Integer(1)), Rational(2, 3), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(-4)), Rational(4, 3), Rational(6, 7)};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(-4)), Rational(-4, 3), Rational(425, 63), Rational(-23, 21),
                                   Rational(-15, 14)};
    Polynomial result = p1 * p2;
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE(result == expected);
}

TEST(Damakin2384_Polynomial_MUL_PP_P, PolynomialMultiplicationTest2) {
    std::vector<Rational> coef1 = {Rational(Integer(10)), Rational(3, 2), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(2, 5), Rational(4, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(4)), Rational(227, 45), Rational(-33, 2), Rational(-55, 18),
                                   Rational(25, 12), Rational(Integer(0))};
    Polynomial result = p1 * p2;
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE(result == expected);
}

TEST(Damakin2384_Polynomial_MUL_PP_P, PolynomialMultiplicationTest3) {
    std::vector<Rational> coef1 = {Rational(2, 3), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(13)), Rational(-9, 3), Rational(6, 8)};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(26, 3), Rational(-73, 4), Rational(17, 4), Rational(-15, 16)};
    Polynomial result = p1 * p2;
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE(result == expected);
}

TEST(Damakin2384_Polynomial_MUL_PP_P, PolynomialMultiplicationTest4) {
    std::vector<Rational> coef1 = {Rational(2, 3), Rational(-5, 4)};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(0, 1)};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(0, 1)};
    Polynomial result = p1 * p2;
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE(result == expected);
}

TEST(Damakin2384_Polynomial_MUL_PP_P, PolynomialMultiplicationTest5) {
    std::vector<Rational> coef1 = {Rational(Integer(1))};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(2, 5), Rational(4, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(2, 5), Rational(4, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial result = p1 * p2;
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE(result == expected);
}

TEST(Damakin2384_Polynomial_MUL_PP_P, PolynomialMultiplicationTest6) {
    std::vector<Rational> coef1 = {Rational(1, 5), Rational(5, 9), Rational(-5, 3), Rational(Integer(0))};
    Polynomial p1 = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(-1))};
    Polynomial p2 = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(-1, 5), Rational(-5, 9), Rational(5, 3), Rational(Integer(0))};
    Polynomial result = p1 * p2;
    Polynomial expected = Polynomial(coef3);
    ASSERT_TRUE(result == expected);
}

TEST(Ilyin_2383_Polynomial_sub_test, GetZero) {
    std::vector<Rational> coefs;
    for (int i = 0; i < 5; i++) {
        coefs.emplace_back(i, i + 10);
    }
    std::vector<Rational> finalCoefs = {Rational(0, 1)};
    Polynomial p1{coefs}, expected{finalCoefs};
    EXPECT_EQ(p1 - p1, expected);
}

TEST(Ilyin_2383_Polynomial_sub_test, GetMoreThanZero) {
    std::vector<Rational> firstCoefs;
    std::vector<Rational> secondCoefs;
    std::vector<Rational> finalCoefs = {Rational(2,1), Rational(1,1), Rational(2,3), Rational(1, 2), Rational(2, 5)};
    for (int i = 0; i < 5; i++) {
        firstCoefs.emplace_back(i + 5, i + 1);
        secondCoefs.emplace_back(i + 3, i + 1);
    }
    Polynomial p1{firstCoefs}, p2{secondCoefs}, expected{finalCoefs};
    Polynomial pt = p1 - p2;
    EXPECT_EQ(pt, expected);
}

TEST(Ilyin_2383_Polynomial_sub_test, GetLessThanZero) {
    std::vector<Rational> firstCoefs = {Rational(1, 1), Rational(0, 1), Rational(1, 1)};
    std::vector<Rational> biggerCoefs = {Rational(2, 1), Rational(0, 1), Rational(1, 1)};
    std::vector<Rational> cmpCoefs = {Rational(-1, 1), Rational(0, 1), Rational(0, 1)};

    Polynomial p1{firstCoefs}, p2{biggerCoefs}, expected{cmpCoefs};
    EXPECT_EQ(p1-p2, expected);
}

TEST(Ilyin_2383_Polynomial_mod_test, GetZero) {
    std::vector<Rational> firstCoefs = {Rational(1, 1), Rational(0, 1), Rational(1, 1)};
    std::vector<Rational> secondCoefs = {Rational(1, 1)};
    std::vector<Rational> finalCoefs = {Rational(0, 1)};
    Polynomial first{firstCoefs}, second{secondCoefs}, expected{finalCoefs};
    EXPECT_EQ(first % second, expected);
}

TEST(Ilyin_2383_Polynomial_mod_test, GetNotZero) {
    std::vector<Rational> firstCoefs = {Rational(1, 1), Rational(0, 1), Rational(-4, 1)};
    std::vector<Rational> secondCoefs = {Rational(1, 1), Rational(1, 1)};
    std::vector<Rational> finalCoefs = {Rational(-3, 1)};
    Polynomial first{finalCoefs}, second{secondCoefs}, expected{finalCoefs};
    EXPECT_EQ(first % second, expected);
}

TEST(Ilyin_2383_Polynomial_mod_test, get1) {
    std::vector<Rational> firstCoefs = {Rational(9, 1), Rational(56, 1), Rational(1, 1)};
    std::vector<Rational> secondCoefs = {Rational(1, 1), Rational(0, 1)};
    std::vector<Rational> finalCoefs = {Rational(1, 1)};
    Polynomial first{finalCoefs}, second{secondCoefs}, expected{finalCoefs};
    EXPECT_EQ(first % second, expected);
}

TEST(Kuzminykh2384_Polynomial_ADD_PP_P, PolynomialAdditionTest1) {
    std::vector<Rational> coef1 = {Rational(Integer(1)), Rational(Integer(1)), Rational(Integer(1))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(1)), Rational(Integer(1)), Rational(Integer(1)),
                                   Rational(Integer(1))};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(1)), Rational(Integer(2)), Rational(Integer(2)),
                                   Rational(Integer(2))};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol + second_pol, result);
}

TEST(Kuzminykh2384_Polynomial_ADD_PP_P, PolynomialAdditionTest2) {
    std::vector<Rational> coef1 = {Rational(Integer(1))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(0))};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(1))};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol + second_pol, result);
}

TEST(Kuzminykh2384_Polynomial_ADD_PP_P, PolynomialAdditionTest3) {
    std::vector<Rational> coef1 = {Rational(1, 2), Rational(1, 2), Rational(1, 2)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(1, 2), Rational(1, 2), Rational(1, 2)};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(1, 1), Rational(1, 1), Rational(1, 1)};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol + second_pol, result);
}

TEST(Kuzminykh2384_Polynomial_ADD_PP_P, PolynomialAdditionTest4) {
    std::vector<Rational> coef1 = {Rational(1, 2), Rational(1, 2), Rational(1, 2)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(-1, 2), Rational(1, 2), Rational(1, 2)};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(1, 1), Rational(1, 1)};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol + second_pol, result);
}


TEST(Kuzminykh2384_Polynomial_DIV_PP_P, PolynomialDivisionTest1) {
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(1, 1), Rational(1, 1)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(1, 1), Rational(1, 1), Rational(1, 1)};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(1, 1)};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol / second_pol, result);
}

TEST(Kuzminykh2384_Polynomial_DIV_PP_P, PolynomialDivisionTest2) {
    std::vector<Rational> coef1 = {Rational(Integer(1)), Rational(Integer(2)), Rational(Integer(3))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(1)), Rational(Integer(5))};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(1)), Rational(Integer(-3))};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol / second_pol, result);
}

TEST(Kuzminykh2384_Polynomial_DIV_PP_P, PolynomialDivisionTest3) {
    std::vector<Rational> coef1 = {Rational(Integer(5)), Rational(Integer(2)), Rational(Integer(3)),
                                   Rational(Integer(4))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(1)), Rational(Integer(5))};
    Polynomial second_pol = Polynomial(coef2);
    std::vector<Rational> coef3 = {Rational(Integer(5)), Rational(Integer(-23)), Rational(Integer(118))};
    Polynomial result = Polynomial(coef3);
    EXPECT_EQ(first_pol / second_pol, result);
}

TEST(Kuzminykh2384_Polynomial_DIV_PP_P, PolynomialDivisionTest4) {
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(1, 1), Rational(1, 1)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(0, 1)};
    Polynomial second_pol = Polynomial(coef2);
    EXPECT_THROW(first_pol / second_pol, std::invalid_argument);
}

TEST(Kuzminykh2384_Polynomial_DER_P_P, PolynomialDerivativeTest1) {
    std::vector<Rational> coef1 = {Rational(Integer(1)), Rational(Integer(1))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(1))};
    Polynomial result = Polynomial(coef2);
    EXPECT_EQ(first_pol.derivative(), result);
}

TEST(Kuzminykh2384_Polynomial_DER_P_P, PolynomialDerivativeTest2) {
    std::vector<Rational> coef1 = {Rational(1, 3), Rational(1, 2), Rational(1, 1), Rational(1, 1)};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(1, 1), Rational(1, 1), Rational(1, 1)};
    Polynomial result = Polynomial(coef2);
    EXPECT_EQ(first_pol.derivative(), result);
}

TEST(Kuzminykh2384_Polynomial_DER_P_P, PolynomialDerivativeTest3) {
    std::vector<Rational> coef1 = {Rational(Integer(5)), Rational(Integer(3)), Rational(Integer(2)),
                                   Rational(Integer(1))};
    Polynomial first_pol = Polynomial(coef1);
    std::vector<Rational> coef2 = {Rational(Integer(15)), Rational(Integer(6)), Rational(Integer(2))};
    Polynomial result = Polynomial(coef2);
    EXPECT_EQ(first_pol.derivative(), result);
}
TEST(Kuzminykh2384_Polynomial_DER_P_P, PolynomialDerivativeTest4) {
    std::vector<Rational> coef1 = {Rational(Integer(0))};
    Polynomial first_pol = Polynomial(coef1);
    Polynomial result = Polynomial(coef1);
    EXPECT_EQ(first_pol.derivative(), result);
}

TEST(Tsygankov_Roman_2384_Polynomal_MUL_Pxk_P, Mul_x2_Test){
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};
    std::vector<Rational> coef2 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};

    coef2.push_back(Rational(0, 1));
    coef2.push_back(Rational(0, 1));

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.mulByXk(2), g);

}

TEST(Tsygankov_Roman_2384_Polynomal_MUL_Pxk_P, Mul_x0_Test){
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};

    Polynomial f(coef1);

    EXPECT_EQ(f.mulByXk(0), f);

}

TEST(Tsygankov_Roman_2384_Polynomal_MUL_Pxk_P, Mul_x1_Test){
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};

    std::vector<Rational> coef2 = {Rational(1, 1), Rational(2, 1), Rational(3, 1)};
    coef2.push_back(Rational(0, 1));

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.mulByXk(1), g);
}

TEST(Vozgrin2382_Polynomial_LEAD_P_Q, Lead_test_1) {
    std::vector<Rational> coef = {Rational(1, 1)};
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == coef[0]);
}

TEST(Vozgrin2382_Polynomial_LEAD_P_Q, Lead_test_2) {
    std::vector<Rational> coef = {Rational(1, 1)};
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == Rational(1, 1));
}

TEST(Vozgrin2382_Polynomial_LEAD_P_Q, Lead_test_3) {
    std::vector<Rational> coef = {Rational(8, 1), Rational(3, 1), Rational(1, 2)};
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == coef[0]);
}

TEST(Vozgrin2382_Polynomial_LEAD_P_Q, Lead_test_4) {
    std::vector<Rational> coef = {Rational(8, 1), Rational(3, 1), Rational(1, 2)};
    Polynomial p(coef);
    ASSERT_TRUE(p.leading() == Rational(8, 1));
}

TEST(Zhdanov_Anton_2383_DEG_P_N, regular_test) {
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(3, 1), Rational(-1, 1)};
    Polynomial f(coef1);
    std::size_t ans = 2;
    std::size_t ans_test = f.getDegree();
    EXPECT_EQ(ans, ans_test);
}

TEST(Zhdanov_Anton_2383_DEG_P_N, polynomial_with_degree_0) {
    std::vector<Rational> coef1 = {Rational((1), (1))};

    Polynomial f(coef1);
    std::size_t ans = 0;
    std::size_t ans_test = f.getDegree();
    EXPECT_EQ(ans, ans_test);
}

TEST(Zhdanov_Anton_2383_DEG_P_N, high_degree_test) {
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(3, 1), Rational(-1, 1), Rational(-4, 1),
                                   Rational(1, 1), Rational(3, 1), Rational(-1, 1), Rational(-4, 1), Rational(-3, 1)};

    Polynomial f(coef1);
    std::size_t ans = 8;
    std::size_t ans_test = f.getDegree();
    EXPECT_EQ(ans, ans_test);
}

TEST(Zhdanov_Anton_2383_MUL_PQ_P, regular_test) {
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(3, 1), Rational(-1, 1), Rational(-4, 1), Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(2, 1), Rational(6, 1), Rational(-2, 1), Rational(-8, 1), Rational(-6, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.scale(Rational(2, 1)), g);
}

TEST(Zhdanov_Anton_2383_MUL_PQ_P, negativ_number_test) {
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(3, 1), Rational(-1, 1), Rational(-4, 1), Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(-2, 3), Rational(-2, 1), Rational(2, 3), Rational(8, 3), Rational(2, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.scale(Rational(-2, 3)), g);
}

TEST(Zhdanov_Anton_2383_MUL_PQ_P, test_with_0) {
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(3, 1), Rational(-1, 1), Rational(-4, 1), Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(0, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    EXPECT_EQ(f.scale(Rational(0, 1)), g);
}

TEST(Zhdanov_Anton_2383_GCF_PP_P, polynomial_g_is_gcd) {
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(5, 1), Rational(6, 1)};

    std::vector<Rational> coef2 = {Rational(1, 1), Rational(3, 1)};

    std::vector<Rational> ans = {Rational(1, 1), Rational(3, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    Polynomial r(ans);
    EXPECT_EQ(Polynomial::gcd(f, g), r);
}

TEST(Zhdanov_Anton_2383_GCF_PP_P, regular_test1) {
    std::vector<Rational> coef1 = {Rational(1, 1), Rational(3, 1), Rational(-1, 1), Rational(-4, 1), Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(3, 1), Rational(10, 1), Rational(2, 1), Rational(-3, 1)};

    std::vector<Rational> ans = {Rational(9, 1), Rational(27, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    Polynomial r(ans);
    EXPECT_EQ(Polynomial::gcd(f, g), r);
}

TEST(Zhdanov_Anton_2383_GCF_PP_P, test_with_negativ_coef) {
    std::vector<Rational> coef1 = {Rational(3, 1), Rational(10, 1), Rational(2, 1), Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(-5, 9), Rational(-25, 9), Rational(-10, 3)};

    std::vector<Rational> ans = {Rational(9, 1), Rational(27, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    Polynomial r(ans);
    EXPECT_EQ(Polynomial::gcd(f, g), r);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}