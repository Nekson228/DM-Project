#include <gtest/gtest.h>
#include "../../Natural.h"

TEST(IsZero___Test, test1){
    Natural natural_1(12);
    EXPECT_EQ(natural_1.isZero(), false);
}

TEST(IsZero___Test, test2){
    Natural natural_2(0);
    EXPECT_EQ(natural_1.isZero(), true);
}

TEST(IsZero___Test, test3){
    Natural natural_3;
    EXPECT_EQ(natural_1.isZero(), true);
}

TEST(Compare_test, test1){
    Natural a(2000);
    Natural b(1000);
    digit res = 2;
    digit test = Natural::cmp(a, b);

    EXPECT_EQ(res, test);
}

TEST(Compare_test, test1){
    Natural a(1000);
    Natural b(2000);
    digit res = 1;
    digit test = Natural::cmp(a, b);

    EXPECT_EQ(res, test);
}

TEST(Compare_test, test1){
    Natural a(1000);
    Natural b(1000);
    digit res = 0;
    digit test = Natural::cmp(a, b);

    EXPECT_EQ(res, test);
}