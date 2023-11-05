#include "gtest/gtest.h"
#include "../../Polynomial.h"

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

TEST(gcd, regular_test){
    std::vector<Rational> coef1 = {Rational(1, 1),Rational(3, 1),Rational(-1, 1),Rational(-4, 1),Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(3, 1),Rational(10, 1),Rational(2, 1),Rational(-3, 1)};

    std::vector<Rational> ans = {Rational(1, 1),Rational(3, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    Polynomial r(ans);
    EXPECT_EQ(Polynomial::gcd(f,g), r);
}

TEST(gcd, regular_test){
    std::vector<Rational> coef1 = {Rational(3, 1),Rational(10, 1),Rational(2, 1),Rational(-3, 1)};

    std::vector<Rational> coef2 = {Rational(-5, 9),Rational(-25, 9),Rational(-10, 3)};

    std::vector<Rational> ans = {Rational(1, 1), Rational(3, 1)};

    Polynomial f(coef1);
    Polynomial g(coef2);
    Polynomial r(ans);
    EXPECT_EQ(Polynomial::gcd(f,g), r);
}

int main(){
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}