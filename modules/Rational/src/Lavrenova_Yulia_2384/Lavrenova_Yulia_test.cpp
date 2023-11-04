#include "../../Rational.h"
#include "gtest/gtest.h"

TEST(Construction_test, test1){
    Integer integer_(234);
    Rational rational_(integer_);
    Rational test("234/1");
    EXPECT_EQ(rational_, test);
}

TEST(Construction_test, test2){
    Integer integer_(347564);
    Rational rational_(integer_);
    Rational test("347564/1");
    EXPECT_EQ(rational_, test);
}

TEST(Construction_test, test3){
    Integer integer_(-172);
    Rational rational_(integer_);
    Rational test("-172/1");
    EXPECT_EQ(rational_, test);
}

int main(int argc, char** argv){
    srand(time(NULL));
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
