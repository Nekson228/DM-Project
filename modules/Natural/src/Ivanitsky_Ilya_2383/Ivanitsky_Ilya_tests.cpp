#include <gtest/gtest.h>
#include "../../Natural.h"
#include <string>
#include <sstream>

static digit cmp(const Natural &a, const Natural &b){
    return 0;
}

TEST(NaturalAdditionTest , FirstTest){
    Natural num(1000000000);
    Natural num2(123456789);
    Natural num_answer(1123456789);
    EXPECT_TRUE(cmp(num+num2,num_answer) == 0);
}

TEST(NaturalAdditionTest , SecondTest){
    Natural num(123456789);
    Natural num2(1234567890);
    Natural num_answer(1358024679);
    EXPECT_TRUE(cmp(num+num2,num_answer) == 0);
}

TEST(NaturalAdditionTest , AdditionZeroTest){
    Natural num(999);
    Natural num2(0);
    Natural num_answer(999);
    EXPECT_TRUE(cmp(num+num2,num_answer) == 0);
}


TEST(NaturalMultyplicationTest , FirstTest){
    Natural num(121);
    Natural num2(11);
    Natural num_answer(1331);
    EXPECT_TRUE(cmp(num*num2,num_answer) == 0);
}

TEST(NaturalMultyplicationTest , SecondTest){
    Natural num(1331);
    Natural num2(1331);
    Natural num_answer(1771561);
    EXPECT_TRUE(cmp(num*num2,num_answer) == 0);
}

TEST(NaturalMultyplicationTest , MultyplicationZeroTest){
    Natural num(11111111);
    Natural num2(0);
    Natural num_answer(0);
    EXPECT_TRUE(cmp(num*num2,num_answer) == 0);
}

TEST(NaturalMultyplicationTest , MultyplicationOneTest){
    Natural num(11111111);
    Natural num2(1);
    Natural num_answer(11111111);
    EXPECT_TRUE(cmp(num*num2,num_answer) == 0);
}


TEST(NaturalDividingTest , FirstTest){
    Natural num(1771561);
    Natural num2(1331);
    Natural num_answer(1331);
    EXPECT_TRUE(cmp(num/num2,num_answer) == 0);
}

TEST(NaturalDividingTest , Secondtest){
    Natural num(10000000000);
    Natural num2(3);
    Natural num_answer(3333333333);
    EXPECT_TRUE(cmp(num/num2,num_answer) == 0);
}

TEST(NaturalDividingTest , DividingZeroTest){
    Natural num(10000000000);
    Natural num2(0);
    EXPECT_THROW(num/num2 , std::invalid_argument);
}

TEST(NaturalDividingTest , DividingOneTest){
    Natural num(10000000000);
    Natural num2(1);
    Natural num_answer(10000000000);
    EXPECT_TRUE(cmp(num/num2,num_answer) == 0);
}



int main(int argc , char **argv){
    ::testing::InitGoogleTest(&argc , argv);

    return RUN_ALL_TESTS();
}