#include"../../Integer.h"
#include"Vozgrin_Miron.cpp"
#include<gtest/gtest.h>

TEST(checkModOperator,1){
    ASSERT_TRUE(Integer(21) % Integer(4) == Integer(1));
}

TEST(checkModOperator,2){
    ASSERT_TRUE(Integer(-50) % Integer(7) == Integer(6));
}

TEST(checkModOperator,3){
    ASSERT_TRUE(Integer(23) % Integer(-4) == Integer(-1));
}

TEST(checkModOperator,4){
    ASSERT_TRUE(Integer(-32) % Integer(-30) == Integer(-2));
}
