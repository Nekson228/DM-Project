#include "gtest/gtest.h"
#include "../../Natural.h"


TEST(DivFirstDigitTest, 1){
    Natural a = Natural(2222);
    Natural b = Natural(111);
    ASSERT_TRUE(Natural::cmp(a.divFirstDigit(b), Natural(20)) == 0);
}

TEST(DivFirstDigitTest, 2){
    Natural a = Natural(111);
    Natural b = Natural(2222);
    ASSERT_TRUE(Natural::cmp(a.divFirstDigit(b), Natural(20)) == 0);
}

TEST(DivFirstDigitTest, 3){
    Natural a = Natural(0);
    Natural b = Natural(12345);
    ASSERT_FALSE(Natural::cmp(a.divFirstDigit(b), Natural(10000)) != 0);
}

TEST(DivFirstDigitTest, 4){
    Natural a = Natural(1);
    Natural b = Natural(12345);
    ASSERT_TRUE(Natural::cmp(a.divFirstDigit(b), Natural(10000)) == 0);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
