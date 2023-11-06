#include "gtest/gtest.h"
#include "../../Integer.h"

TEST(operator_sub, Tests_1){
    Integer integer_1(1000);
    Integer integer_2(500);
    Integer ans1(integer_1 - integer_2);
    Integer ans1_test(500);

    EXPECT_EQ(ans1,ans1_test);
}

TEST(operator_sub, Tests_2){
    Integer integer_1(1000);
    Integer integer_2(-500);
    Integer ans2(integer_1 - integer_2);
    Integer ans2_test(1500);

    EXPECT_EQ(ans2,ans2_test);
}

TEST(operator_sub, Tests_3){
    Integer integer_1(1000);
    Integer integer_2(0);
    Integer ans3(integer_1 - integer_2);
    Integer ans3_test(1000);

    EXPECT_EQ(ans3,ans3_test);
}

TEST(operator_sub, Tests_4){
    Integer integer_1(-1000);
    Integer integer_2(500);
    Integer ans4(integer_1 - integer_2);
    Integer ans4_test(-1500);

    EXPECT_EQ(ans4,ans4_test);
}

TEST(operator_sub, Tests_5){
    Integer integer_1(-1000);
    Integer integer_2(-500);
    Integer ans5(integer_1 - integer_2);
    Integer ans5_test(-500);

    EXPECT_EQ(ans5,ans5_test);
}

TEST(operator_sub, Tests_6){
    Integer integer_1(-1000);
    Integer integer_2(0);
    Integer ans6(integer_1 - integer_2);
    Integer ans6_test(-1000);

    EXPECT_EQ(ans6,ans6_test);
}

TEST(operator_sub, Tests_7){
    Integer integer_1(0);
    Integer integer_2(500);
    Integer ans7(integer_1 - integer_2);
    Integer ans7_test(-500);

    EXPECT_EQ(ans7,ans7_test);
}

TEST(operator_sub, Tests_8){
    Integer integer_1(0);
    Integer integer_2(-500);
    Integer ans8(integer_1 - integer_2);
    Integer ans8_test(500);

    EXPECT_EQ(ans8,ans8_test);
}

TEST(operator_sub, Tests_9){
    Integer integer_1(0);
    Integer integer_2(0);
    Integer ans9(integer_1 - integer_2);
    Integer ans9_test(0);

    EXPECT_EQ(ans9,ans9_test);
}

TEST(Constuction_test, Tests_10){
    Natural natural_(10);
    Integer integer_(natural_);
    Integer ans10_test(10);

    EXPECT_EQ(integer_,ans10_test);
}

TEST(Constuction_test, Tests_11){
    Natural natural_(100);
    Integer integer_(natural_);
    Integer ans11_test(100);

    EXPECT_EQ(integer_,ans11_test);
}

int main(int argc, char** argv ){
    srand(time(NULL));
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
