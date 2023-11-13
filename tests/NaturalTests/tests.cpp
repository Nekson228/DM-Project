#include <gtest/gtest.h>
#include "../../modules/Natural/Natural.h"


TEST(Borisov_IP_2383_Natural_mulByDigit, zero_mult) {
    Natural natural(12345);
    digit muptiplier = 0;
    natural = natural.mulByDigit(muptiplier);
    EXPECT_TRUE(natural.isZero());
}

TEST(Borisov_IP_2383_Natural_mulByDigit, normal) {
    Natural natural(12345);
    Natural check(12345 * 3);
    digit muptiplier = 3;
    natural = natural.mulByDigit(muptiplier);
    EXPECT_TRUE(Natural::cmp(natural, check) == 0);
}

TEST(Borisov_IP_2383_Natural_mulByDigit, zero_natural) {
    Natural natural(0);
    digit muptiplier = 3;
    natural = natural.mulByDigit(muptiplier);
    EXPECT_TRUE(natural.isZero());
}

TEST(Borisov_IP_2383_Natural_subScaled, zero_other) {
    Natural natural(12345);
    Natural check(12345);
    Natural natural_other(0);
    digit k = 5;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(Natural::cmp(natural, check) == 0);
}

TEST(Borisov_IP_2383_Natural_subScaled, zero_k) {
    Natural natural(12345);
    Natural check(12345);
    Natural natural_other(12345);
    digit k = 0;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(Natural::cmp(natural, check) == 0);
}

TEST(Borisov_IP_2383_Natural_subScaled, zero_all) {
    Natural natural(0);
    Natural natural_other(0);
    digit k = 0;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(natural.isZero());
}

TEST(Borisov_IP_2383_Natural_subScaled, usual) {
    Natural natural("1234567");
    Natural check("1172842");
    Natural natural_other(12345);
    digit k = 5;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(Natural::cmp(natural, check) == 0);
}

TEST(Borisov_IP_2383_Natural_subScaled, equal) {
    Natural natural("1234567");
    Natural check(1);
    Natural natural_other("1234566");
    digit k = 1;
    natural = natural.subScaled(natural_other, k);
    EXPECT_TRUE(Natural::cmp(natural, check) == 0);
}

TEST(Borisov_IP_2383_Natural_remains, one) {
    Natural natural("1234567");
    Natural natural_other(1);
    natural = natural % natural_other;
    EXPECT_TRUE(natural.isZero());
}

TEST(Borisov_IP_2383_Natural_remains, usual) {
    Natural natural("1234567");
    Natural check(67);
    Natural natural_other(12345);
    natural = natural % natural_other;
    EXPECT_TRUE(Natural::cmp(natural, check) == 0);
}

TEST(Borisov_IP_2383_Natural_remains, smaller) {
    Natural natural("1234567");
    Natural check("1234567");
    Natural natural_other("123456789");
    natural = natural % natural_other;
    EXPECT_TRUE(Natural::cmp(natural, check) == 0);
}

TEST(Damakin2384_Natural_DIV_NN_Dk, DivFirstDigitTest1){
    Natural a = Natural(2222);
    Natural b = Natural(111);
    ASSERT_TRUE(a.divFirstDigit(b) == Natural(20));
}

TEST(Damakin2384_Natural_DIV_NN_Dk, DivFirstDigitTest2){
    Natural a = Natural(111);
    Natural b = Natural(2222);
    ASSERT_TRUE(a.divFirstDigit(b) == Natural(20));
}

TEST(Damakin2384_Natural_DIV_NN_Dk, DivFirstDigitTest3){
    Natural a = Natural(0);
    Natural b = Natural(12345);
    ASSERT_FALSE(a.divFirstDigit(b) == Natural(10000));
}

TEST(Damakin2384_Natural_DIV_NN_Dk, DivFirstDigitTest4){
    Natural a = Natural(1);
    Natural b = Natural(12345);
    ASSERT_TRUE(a.divFirstDigit(b) == Natural(10000));
}

TEST(Gurkov2384_Natural_NZER_N_B, NOT_ZERO_VALUE){
    Natural natural_1(12);
    EXPECT_EQ(natural_1.isZero(), false);
}

TEST(Gurkov2384_Natural_NZER_N_B, ZERO_VAUE){
    Natural natural_2(0);
    EXPECT_EQ(natural_2.isZero(), true);
}

TEST(Gurkov2384_Natural_COM_NN_D, FIRST_IS_BIGGER){
    Natural a(2000);
    Natural b(1000);
    digit res = 2;
    digit test = Natural::cmp(a, b);

    EXPECT_EQ(res, test);
}

TEST(Gurkov2384_Natural_COM_NN_D, FIRST_IS_SMALLER){
    Natural a(1000);
    Natural b(2000);
    digit res = 1;
    digit test = Natural::cmp(a, b);

    EXPECT_EQ(res, test);
}

TEST(Gurkov2384_Natural_COM_NN_D, FIRST_EQUALS_SECOND){
    Natural a(1000);
    Natural b(1000);
    digit res = 0;
    digit test = Natural::cmp(a, b);

    EXPECT_EQ(res, test); 
}

TEST(Ilyin_2383_Natural_mulBy10k_test, degree0) {
    Natural first(5);
    Natural second(5);
    Natural third;
    third = first.mulBy10k(0);
    EXPECT_EQ(third, second);
}

TEST(Ilyin_2383_Natural_mulBy10k_test, degree6) {
    Natural first = Natural(5), second = Natural(5000000), third = first.mulBy10k(6);
    EXPECT_EQ(third, second);
}

TEST(Ilyin_2383_Natural_mulBy10k_test, degree25) {
    Natural test_object(1);
    Natural expected_size("10000000000000000000000000");
    EXPECT_EQ(test_object.mulBy10k(25), expected_size);
}

TEST(Ilyin_2383_Natural_lcm_test, 5and6get30) {
    Natural first(5);
    Natural second(6);
    EXPECT_EQ(Natural(30), first.lcm(first, second));
}

TEST(Ilyin_2383_Natural_lcm_test, 1and1get1) {
    Natural first(1);
    Natural second(1);
    EXPECT_EQ(Natural(1), first.lcm(first, second));
}

TEST(Ilyin_2383_Natural_lcm_test, getOneOfNum) {
    Natural first("1324234234");
    Natural second(2);
    EXPECT_EQ(Natural("1324234234"), first.lcm(first, second));
}

TEST(Ivanitsky_Ilya_2383_ADD_NN_N , simple_addition){
    Natural num(1000000000);
    Natural num2(123456789);
    Natural num_answer(1123456789);
    EXPECT_TRUE(num + num2 == num_answer);
}

TEST(Ivanitsky_Ilya_2383_ADD_NN_N , hard_addition){
    Natural num(123456789);
    Natural num2(1234567890);
    Natural num_answer(1358024679);
    EXPECT_TRUE(num+num2== num_answer);
}

TEST(Ivanitsky_Ilya_2383_ADD_NN_N , addition_zero){
    Natural num(111);
    Natural num2(0);
    Natural num_answer(111);
    EXPECT_TRUE(Natural::cmp(num+num2,num_answer) == 0);
}

TEST(Ivanitsky_Ilya_2383_MUL_NN_N, simple_multyplication){
    Natural num(121);
    Natural num2(11);
    Natural num_answer(1331);
    EXPECT_TRUE(num*num2 == num_answer);
}

TEST(Ivanitsky_Ilya_2383_MUL_NN_N, hard_multyplication){
    Natural num(1331);
    Natural num2(1331);
    Natural num_answer(1771561);
    EXPECT_TRUE(num*num2 == num_answer);
}

TEST(Ivanitsky_Ilya_2383_MUL_NN_N, multyplication_zero){
    Natural num(11111111);
    Natural num2(0);
    Natural num_answer(0);
    EXPECT_TRUE(num*num2 == num_answer);
}

TEST(Ivanitsky_Ilya_2383_MUL_NN_N, multyplication_one){
    Natural num(11111111);
    Natural num2(1);
    Natural num_answer(11111111);
    EXPECT_TRUE(num*num2 == num_answer);
}


TEST(Ivanitsky_Ilya_2383_DIV_NN_N, simple_dividing){
    Natural num(1771561);
    Natural num2(1331);
    Natural num_answer(1331);
    EXPECT_TRUE(num/num2 == num_answer);
}

TEST(Ivanitsky_ILya_2383_DIV_NN_N, hard_dividing){
    Natural num(10000000000);
    Natural num2(3);
    Natural num_answer(3333333333);
    EXPECT_TRUE(num/num2 == num_answer);
}

TEST(Ivanitsky_ILya_2383_DIV_NN_N, dividing_zero){
    Natural num(10000000000);
    Natural num2(0);
    EXPECT_THROW(num / num2 , std::invalid_argument);
}

TEST(Ivanitsky_ILya_2383_DIV_NN_N, dividing_one){
    Natural num(10000000000);
    Natural num2(1);
    Natural num_answer(10000000000);
    EXPECT_TRUE(num / num2 == num_answer);
}

TEST(Sots_Katya_2384_Natural, gcdZeroTest) {
    Natural first(5);
    Natural second(0);
    EXPECT_EQ(first.cmp(first.gcd(first, second), first), 0);
}

TEST(Sots_Katya_2384_Natural, gcdPrimeTest) {
    Natural first(8);
    Natural second(5);
    EXPECT_EQ(first.cmp(first.gcd(first, second), Natural(1)), 0);
}

TEST(Sots_Katya_2384_Natural, gcdNotPrimeTest) {
    Natural first(16);
    Natural second(12);
    EXPECT_EQ(first.cmp(first.gcd(first, second), Natural(4)), 0);
}

TEST(Tsygulev_Stanislav_2383_ADD_1N_N, addOneZeroTest) {
    Natural num(0);
    EXPECT_EQ(num.addOne(), Natural(1));
}

TEST(Tsygulev_Stanislav_2383_ADD_1N_N, addOneNoTransitionTest) {
    Natural num(11);
    EXPECT_EQ(num.addOne(), Natural(12));
}

TEST(Tsygulev_Stanislav_2383_ADD_1N_N, addOneTransitionTest) {
    Natural num(99);
    EXPECT_EQ(num.addOne(), Natural(100));
}

TEST(Tsygulev_Stanislav_2383_SUB_NN_N, subLowerTest) {
    Natural num(10);
    EXPECT_THROW(num - Natural(20), std::invalid_argument);
}

TEST(Tsygulev_Stanislav_2383_SUB_NN_N, subEqualTest) {
    Natural num(77);
    EXPECT_EQ(num - Natural(77), Natural(0));
}

TEST(Tsygulev_Stanislav_2383_SUB_NN_N, subGreaterTest) {
    Natural num(2248);
    EXPECT_EQ(num - Natural(1372), Natural(876));
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
