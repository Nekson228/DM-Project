#include <gtest/gtest.h>
#include "../../Integer.h"
 
 
TEST(IntegerAbsTest, 1){
    Integer i1 = Integer(-1);
    Integer result = i1.abs();
    Integer expected = Integer(1);
    ASSERT_TRUE(result == expected);
}
 
 
int main(int argc, char** argv) {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

TEST(IntegerAbsTest, 2){
    Integer i1 = Integer(0);
    ASSERT_TRUE(i1.abs() == Integer(0));
}

TEST(IntegerAbsTest, 3){
    for (int i=-100; i<=100; ++i) {
        ASSERT_TRUE(Integer(i).abs() == Integer(std::abs(i)));
    }
}