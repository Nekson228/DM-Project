#include <gtest/gtest.h>
#include "../../modules/Integer/Integer.h"

TEST(GurkovArseniy, IntegerAbsTest1) {
    Integer i1 = Integer(-1);
    Integer result = i1.abs();
    Integer expected = Integer(1);
    ASSERT_TRUE(result == expected);
}

TEST(GurkovArseniy, IntegerAbsTest2) {
    Integer i1 = Integer(0);
    ASSERT_TRUE(i1.abs() == Integer(0));
}

TEST(GurkovArseniy, IntegerAbsTest3) {
    for (int i = -100; i <= 100; ++i) {
        ASSERT_TRUE(Integer(i).abs() == Integer(std::abs(i)));
    }
}

TEST(Lavrenova_Yulia, isPositive1) {
    Integer integer_1(10);
    digit sign1 = integer_1.isPositive();
    digit sign_a_1 = 2;

    EXPECT_EQ(sign1, sign_a_1);
}

TEST(Lavrenova_Yulia, isPositive2) {
    Integer integer_2(-30000);
    digit sign_a_2 = 1;
    digit sign2 = integer_2.isPositive();

    EXPECT_EQ(sign2, sign_a_2);
}

TEST(Lavrenova_Yulia, isPositive3) {
    digit sign_a_3 = 0;
    Integer integer_3(0);
    digit sign3 = integer_3.isPositive();

    EXPECT_EQ(sign3, sign_a_3);
}

TEST(Lavrenova_Yulia, product1) {
    Integer integer_1(12);
    Integer integer_2(6);
    Integer ans1(integer_1 * integer_2);
    Integer ans1_test(72);

    EXPECT_EQ(ans1, ans1_test);
}

TEST(Lavrenova_Yulia, product2) {
    Integer integer_1(12);
    Integer integer_2(-2);
    Integer ans2(integer_1 * integer_2);
    Integer ans2_test(-24);

    EXPECT_EQ(ans2, ans2_test);
}

TEST(Lavrenova_Yulia, product3) {
    Integer integer_1(-2);
    Integer integer_2(-3);
    Integer ans3(integer_1 * integer_2);
    Integer ans3_test(6);

    EXPECT_EQ(ans3, ans3_test);
}

TEST(Lavrenova_Yulia, product4) {
    Integer integer_1(12);
    Integer integer_2(0);
    Integer ans4(integer_1 * integer_2);
    Integer ans4_test(0);

    EXPECT_EQ(ans4, ans4_test);
}

TEST(IntegerTest, toNaturalNegativeTest) {
    Integer num(-1);
    EXPECT_THROW(num.toNatural(), std::invalid_argument);
}

TEST(IntegerTest, toNaturalZeroTest) {
    Integer num(0);
    Natural value = num.toNatural();
    EXPECT_EQ(value.cmp(value, Natural(0)), 0);
}

TEST(IntegerTest, toNaturalPositiveTest) {
    Integer num(123);
    Natural value = num.toNatural();
    EXPECT_EQ(value.cmp(value, Natural(123)), 0);
}

TEST(IntegerTest, DivOperatorDivByZeroTest) {
    Integer first(2);
    Integer second(0);
    EXPECT_THROW(first = first / second, std::invalid_argument);
}

TEST(IntegerTest, DivOperatorPosPosTest) {
    Integer first(7);
    Integer second(3);
    first = first / second;
    EXPECT_EQ(first, Integer(2));
}

TEST(IntegerTest, DivOperatorPosNegTest) {
    Integer first(7);
    Integer second(-3);
    first = first / second;
    EXPECT_EQ(first, Integer(-2));
}

TEST(IntegerTest, DivOperatorNegPosTest) {
    Integer first(-7);
    Integer second(3);
    first = first / second;
    EXPECT_EQ(first, Integer(-3));
}

TEST(IntegerTest, DivOperatorNegNegTest) {
    Integer first(-7);
    Integer second(-3);
    first = first / second;
    EXPECT_EQ(first, Integer(3));
}

TEST(TsygankovRoman, operator_sub_1) {
    Integer integer_1(1000);
    Integer integer_2(500);
    Integer ans1(integer_1 - integer_2);
    Integer ans1_test(500);

    EXPECT_EQ(ans1, ans1_test);
}

TEST(TsygankovRoman, operator_sub_2) {
    Integer integer_1(1000);
    Integer integer_2(-500);
    Integer ans2(integer_1 - integer_2);
    Integer ans2_test(1500);

    EXPECT_EQ(ans2, ans2_test);
}

TEST(TsygankovRoman, operator_sub_3) {
    Integer integer_1(1000);
    Integer integer_2(0);
    Integer ans3(integer_1 - integer_2);
    Integer ans3_test(1000);

    EXPECT_EQ(ans3, ans3_test);
}

TEST(TsygankovRoman, operator_sub_4) {
    Integer integer_1(-1000);
    Integer integer_2(500);
    Integer ans4(integer_1 - integer_2);
    Integer ans4_test(-1500);

    EXPECT_EQ(ans4, ans4_test);
}

TEST(TsygankovRoman, Toperator_sub_5) {
    Integer integer_1(-1000);
    Integer integer_2(-500);
    Integer ans5(integer_1 - integer_2);
    Integer ans5_test(-500);

    EXPECT_EQ(ans5, ans5_test);
}

TEST(TsygankovRoman, operator_sub_6) {
    Integer integer_1(-1000);
    Integer integer_2(0);
    Integer ans6(integer_1 - integer_2);
    Integer ans6_test(-1000);

    EXPECT_EQ(ans6, ans6_test);
}

TEST(TsygankovRoman, operator_sub_7) {
    Integer integer_1(0);
    Integer integer_2(500);
    Integer ans7(integer_1 - integer_2);
    Integer ans7_test(-500);

    EXPECT_EQ(ans7, ans7_test);
}

TEST(TsygankovRoman, operator_sub_8) {
    Integer integer_1(0);
    Integer integer_2(-500);
    Integer ans8(integer_1 - integer_2);
    Integer ans8_test(500);

    EXPECT_EQ(ans8, ans8_test);
}

TEST(TsygankovRoman, operator_sub_9) {
    Integer integer_1(0);
    Integer integer_2(0);
    Integer ans9(integer_1 - integer_2);
    Integer ans9_test(0);

    EXPECT_EQ(ans9, ans9_test);
}

TEST(TsygankovRoman, constructor_1) {
    Natural natural_(10);
    Integer integer_(natural_);
    Integer ans10_test(10);

    EXPECT_EQ(integer_, ans10_test);
}

TEST(TsygankovRoman, constructor_2) {
    Natural natural_(100);
    Integer integer_(natural_);
    Integer ans11_test(100);

    EXPECT_EQ(integer_, ans11_test);
}


TEST(IntegerTest, negativeZeroValueTest) {
    Integer num(0);
    EXPECT_EQ(num.negative(), Integer(0));
}

TEST(IntegerTest, negativePositiveValueTest) {
    Integer num(123);
    EXPECT_EQ(num.negative(), Integer(-123));
}

TEST(IntegerTest, negativeNegativeValueTest) {
    Integer num(-777);
    EXPECT_EQ(num.negative(), Integer(777));
}


TEST(operator_add, Tests_1
) {
    Integer integer_1(2000);
    Integer integer_2(1000);
    Integer ans1(integer_1 + integer_2);
    Integer ans1_test(3000);

    EXPECT_EQ(ans1, ans1_test);
}

TEST(operator_add, Tests_2
) {
    Integer integer_1(-2000);
    Integer integer_2(1000);
    Integer ans2(integer_1 + integer_2);
    Integer ans2_test(-1000);

    EXPECT_EQ(ans2, ans2_test);
}

TEST(operator_add, Tests_3) {
    Integer integer_1(-2000);
    Integer integer_2(-1000);
    Integer ans3(integer_1 + integer_2);
    Integer ans3_test(-3000);

    EXPECT_EQ(ans3, ans3_test);
}


TEST(checkModOperator, 1) {
    ASSERT_TRUE(Integer(21) % Integer(4) == Integer(1));
}

TEST(checkModOperator, 2) {
    ASSERT_TRUE(Integer(-50) % Integer(7) == Integer(6));
}

TEST(checkModOperator, 3) {
    ASSERT_TRUE(Integer(23) % Integer(-4) == Integer(-1));
}

TEST(checkModOperator, 4) {
    ASSERT_TRUE(Integer(-32) % Integer(-30) == Integer(-2));
}

int main() {
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}