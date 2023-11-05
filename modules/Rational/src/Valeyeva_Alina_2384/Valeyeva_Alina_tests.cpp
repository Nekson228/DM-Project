#include "gtest/gtest.h"
#include "../../Rational.h"

TEST(Multiplication_test, test1){
    Integer integer_1(8);
    Natural natural_1(15);
    Rational rational_1(integer_1, natural_1);

    Integer integer_2(7);
    Natural natural_2(30);
    Rational rational_2(integer_2, natural_2);

    Rational rational_ = rational_1 * rational_2;
    Rational test("56/450");

    EXPECT_EQ(rational_, test);
}

TEST(Multiplication_test, test2){
    Integer integer_1(-8);
    Natural natural_1(15);
    Rational rational_1(integer_1, natural_1);

    Integer integer_2(7);
    Natural natural_2(30);
    Rational rational_2(integer_2, natural_2);

    Rational rational_ = rational_1 * rational_2;
    Rational test("-56/450");

    EXPECT_EQ(rational_, test);
}

TEST(Multiplication_test, test3){
    Integer integer_1(-8);
    Natural natural_1(15);
    Rational rational_1(integer_1, natural_1);

    Integer integer_2(-7);
    Natural natural_2(30);
    Rational rational_2(integer_2, natural_2);

    Rational rational_ = rational_1 * rational_2;
    Rational test("56/450");

    EXPECT_EQ(rational_, test);
}


TEST(Reduce_test, test1){
    Integer integer_1(150);
    Natural natural_1(300);
    Rational rational_(integer_1, natural_1);
    Rational my_answer = rational_.reduce();
    Rational test("1/2");

    EXPECT_EQ(my_answer, test);
}

TEST(Reduce_test, test2){
    Integer integer_1(150);
    Natural natural_1(-300);
    Rational rational_(integer_1, natural_1);
    Rational my_answer = rational_.reduce();
    Rational test("-1/2");

    EXPECT_EQ(my_answer, test);
}

TEST(Reduce_test, test3){
    Integer integer_1(2000);
    Natural natural_1(2000);
    Rational rational_(integer_1, natural_1);
    Rational my_answer = rational_.reduce();
    Rational test("1");

    EXPECT_EQ(my_answer, test);
}

int main(int argc, char** argv){
    srand(time(NULL));
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}