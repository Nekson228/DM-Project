#include "../../modules/Rational/Rational.h"
#include "gtest/gtest.h"

TEST(RationalTest, ToIntegerThrowTest) {
    Rational num(1,2);
    EXPECT_THROW(num.toInteger(), std::invalid_argument);
}

TEST(RationalTest, ToIntegerNegativeTest) {
    Rational num(-2,1);
    EXPECT_EQ(num.toInteger(), Integer(-2));
}

TEST(RationalTest, ToIntegerPositiveReduceTest) {
    Rational num(6,2);
    EXPECT_EQ(num.toInteger(), Integer(3));
}

TEST(Damakin2384_Rational_INT_Q_B, IsIntegerTest1){
    Rational r = Rational(6, 3);
    ASSERT_TRUE(r.isInteger() == true);
}

TEST(Damakin2384_Rational_INT_Q_B, IsIntegerTest2){
    Rational r = Rational(-10, 2);
    ASSERT_TRUE(r.isInteger() == true);
}

TEST(Damakin2384_Rational_INT_Q_B, IsIntegerTest3){
    Rational r = Rational(3, 6);
    ASSERT_FALSE(r.isInteger() == true);
}

TEST(Damakin2384_Rational_SUB_QQ_Q, RationalSubtractionTest1){
    Rational r1 = Rational(3, 6);
    Rational r2 = Rational(2, 6);
    Rational result = r1 - r2;
    Rational expected = Rational(1, 6);
    ASSERT_TRUE(result == expected);
}

TEST(Damakin2384_Rational_SUB_QQ_Q, RationalSubtractionTest2){
    Rational r1 = Rational(9, 3);
    Rational r2 = Rational(5, 7);
    Rational result = r1 - r2;
    Rational expected = Rational(16, 7);
    ASSERT_TRUE(result == expected);
}

TEST(Damakin2384_Rational_SUB_QQ_Q, RationalSubtractionTest3){
    Rational r1 = Rational(5, 8);
    Rational r2 = Rational(5, 7);
    Rational result = r1 - r2;
    Rational expected = Rational(-5, 56);
    ASSERT_TRUE(result == expected);
}

TEST(Damakin2384_Rational_SUB_QQ_Q, RationalSubtractionTest4){
    Rational r1 = Rational(5, 8);
    Rational r2 = Rational(5, 8);
    Rational result = r1 - r2;
    Rational expected = Rational(Integer(0));
    ASSERT_TRUE(result == expected);
}

TEST(Kuzminykh2384_Rational_ADD_QQ_Q, RationalAdditionTest1) {
    Rational first_number = Rational(1, 4);
    Rational second_number = Rational(1, 4);
    Rational answer = Rational(2, 4);
    EXPECT_EQ(first_number + second_number, answer);
}

TEST(Kuzminykh2384_Rational_ADD_QQ_Q, RationalAdditionTest2) {
    Rational first_number = Rational(1, 2);
    Rational second_number = Rational(1, 2);
    Rational answer = Rational(2, 2);
    EXPECT_EQ(first_number + second_number, answer);

}

TEST(Kuzminykh2384_Rational_ADD_QQ_Q, RationalAdditionTest3) {
    Rational first_number = Rational(3, 5);
    Rational second_number = Rational(1, 3);
    Rational answer = Rational(14, 15);
    EXPECT_EQ(first_number + second_number, answer);
}

TEST(Kuzminykh2384_Rational_ADD_QQ_Q, RationalAdditionTest4) {
    Rational first_number = Rational(2, 3);
    Rational second_number = Rational(5, 7);
    Rational answer = Rational(29, 21);
    EXPECT_EQ(first_number + second_number, answer);
}

TEST(Kuzminykh2384_Rational_ADD_QQ_Q, RationalAdditionTest5) {
    Rational first_number = Rational(2, 3);
    Rational second_number = Rational(0, 1);
    Rational answer = Rational(2, 3);
    EXPECT_EQ(first_number + second_number, answer);
}

TEST(Kuzminykh2384_Rational_ADD_QQ_Q, RationalAdditionTest6) {
    Rational first_number = Rational(3, 5);
    Rational second_number = Rational(-2, 5);
    Rational answer = Rational(1, 5);
    EXPECT_EQ(first_number + second_number, answer);
}

TEST(Lavrenova2384_Rational_TRANS_Z_Q, RationalTransformationTest1){
    Integer integer_(234);
    Rational rational_(integer_);
    Rational test("234/1");
    EXPECT_EQ(rational_, test);
}

TEST(Lavrenova2384_Rational_TRANS_Z_Q, RationalTransformationTest2){
    Integer integer_(347564);
    Rational rational_(integer_);
    Rational test("347564/1");
    EXPECT_EQ(rational_, test);
}

TEST(Lavrenova2384_Rational_TRANS_Z_Q, RationalTransformationTest3){
    Integer integer_(-172);
    Rational rational_(integer_);
    Rational test("-172/1");
    EXPECT_EQ(rational_, test);
}

TEST(Valeyeva2384_Rational_MUL_QQ_Q, Multiplication_test1){
    Integer integer_1(8 );
    Natural natural_1(15);
    Rational rational_1(integer_1, natural_1);

    Integer integer_2(7);
    Natural natural_2(30);
    Rational rational_2(integer_2, natural_2);

    Rational rational_ = rational_1 * rational_2;
    Rational test("56/450");

    EXPECT_EQ(rational_, test);
}

TEST(Valeyeva2384_Rational_MUL_QQ_Q, Multiplication_test2){
    Integer integer_1(-8);
    Natural natural_1(15);
    Rational rational_1(integer_1, natural_1);

    Integer integer_2(7);
    Natural natural_2(30);
    Rational rational_2(integer_2, natural_2);

    Rational rational_ = rational_1 * rational_2;
    Rational test("-56/450");

    EXPECT_EQ(rational_, test);
}

TEST(Valeyeva2384_Rational_MUL_QQ_Q, Multiplication_test3){
    Integer integer_1(-8);
    Natural natural_1(15);
    Rational rational_1(integer_1, natural_1);

    Integer integer_2(-7);
    Natural natural_2(30);
    Rational rational_2(integer_2, natural_2);

    Rational rational_ = rational_1 * rational_2;
    Rational test("56/450");

    EXPECT_EQ(rational_, test);
}


TEST(Valeyeva2384_Rational_RED_Q_Q, Reduce_test1){
    Integer integer_1(150);
    Natural natural_1(300);
    Rational rational_(integer_1, natural_1);
    Rational my_answer = rational_.reduce();
    Rational test("1/2");

    EXPECT_EQ(my_answer, test);
}

TEST(Valeyeva2384_Rational_RED_Q_Q, Reduce_test2){
    Integer integer_1(-150);
    Natural natural_1(300);
    Rational rational_(integer_1, natural_1);
    Rational my_answer = rational_.reduce();
    Rational test("-1/2");

    EXPECT_EQ(my_answer, test);
}

TEST(Valeyeva2384_Rational_RED_Q_Q, Reduce_test3){
    Integer integer_1(2000);
    Natural natural_1(2000);
    Rational rational_(integer_1, natural_1);
    Rational my_answer = rational_.reduce();
    Rational test("1");

    EXPECT_EQ(my_answer, test);
}

TEST(Vozgrin2382_Rational_DIV_QQ_Q, DIV_test_zero){
    ASSERT_TRUE(Rational(0, 1) / Rational(1, 1) == Rational(0, 1));
}

TEST(Vozgrin2382_Rational_DIV_QQ_Q, DIV_test_PP){
    ASSERT_TRUE(Rational(7, 8) / Rational(5, 6) == Rational(42, 40));
}

TEST(Vozgrin2382_Rational_DIV_QQ_Q, DIV_test_NP){
    ASSERT_TRUE(Rational(-5,10) / Rational(2, 3) == Rational(-15, 20));
}

TEST(Vozgrin2382_Rational_DIV_QQ_Q, DIV_test_PN){
    ASSERT_TRUE(Rational(5,10) / Rational(-2, 3) == Rational(-15, 20));
}

TEST(Vozgrin2382_Rational_DIV_QQ_Q, DIV_test_NN){
    ASSERT_THROW((Rational(1, 1) / Rational(0, 1)),std::invalid_argument);
}


int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
