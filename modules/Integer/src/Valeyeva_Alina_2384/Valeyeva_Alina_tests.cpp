#include "gtest/gtest.h"
#include "../../Integer.h"

TEST(operator_add, Tests_1){
    Integer integer_1(2000);
    Integer integer_2(1000);
    Integer ans1(integer_1 + integer_2);
    Integer ans1_test(3000);

    EXPECT_EQ(ans1,ans1_test);
}

TEST(operator_add, Tests_2){
    Integer integer_1(-2000);
    Integer integer_2(1000);
    Integer ans2(integer_1 + integer_2);
    Integer ans2_test(-1000);

    EXPECT_EQ(ans2,ans2_test);
}

TEST(operator_add, Tests_3){
    Integer integer_1(-2000);
    Integer integer_2(-1000);
    Integer ans3(integer_1 + integer_2);
    Integer ans3_test(-3000);

    EXPECT_EQ(ans3,ans3_test);
}
int main(int argc, char** argv){
    srand(time(NULL));
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}