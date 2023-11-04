#include "../../Integer.h"
#include <gtest/gtest.h>

TEST(Tests_isPositive, Tests_1){
    Integer integer_1(10);
    digit sign1 = integer_1.isPositive();
    digit sign_a_1 = 2;

    EXPECT_EQ(sign1,sign_a_1);
}

TEST(Tests_isPositive, Tests_2){
    Integer integer_2(-30000);
    digit sign_a_2 = 1;
    digit sign2 = integer_2.isPositive();

    EXPECT_EQ(sign2,sign_a_2);
}

TEST(Tests_isPositive, Tests_3){
    digit sign_a_3 = 0;
    Integer integer_3(0);
    digit sign3 = integer_3.isPositive();

    EXPECT_EQ(sign3,sign_a_3);
}

TEST(operator_prod, test1){
    Integer integer_1(12);
    Integer integer_2(6);
    Integer ans1(integer_1*integer_2);
    Integer ans1_test(72);

    EXPECT_EQ(ans1,ans1_test);
}

TEST(operator_prod, test2){
    Integer integer_1(12);
    Integer integer_2(-2);
    Integer ans2(integer_1*integer_2);
    Integer ans2_test(-24);

    EXPECT_EQ(ans2,ans2_test);
}

TEST(operator_prod, test3){
    Integer integer_1(-2);
    Integer integer_2(-3);
    Integer ans3(integer_1*integer_2);
    Integer ans3_test(6);

    EXPECT_EQ(ans3,ans3_test);
}

TEST(operator_prod, test4){
    Integer integer_1(12);
    Integer integer_2(0);
    Integer ans4(integer_1*integer_2);
    Integer ans4_test(0);
    
    EXPECT_EQ(ans4,ans4_test);
}

int main(int argc, char** argv){
    srand(time(NULL));
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}