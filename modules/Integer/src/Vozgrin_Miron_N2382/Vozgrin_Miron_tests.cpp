#include"../../Integer.h"
#include"Vozgrin_Miron.cpp"
#include<gtest/gtest.h>

TEST(checkModOperator,1){
    ASSERT_TRUE(Integer(50) % Integer(-7) == Integer(6));
}

TEST(checkModOperator,2){
    ASSERT_TRUE(Integer(20) % Integer(4) == Integer(0));
}

TEST(checkModOperator,3){
    ASSERT_TRUE(Integer(32) % Integer(30) == Integer(2));
}
