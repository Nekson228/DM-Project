#include "../../Rational.h"

//Написал функцию - Кузьминых Егор
//ADD_QQ_Q (Сложение дробей, короткий номер - Q5)
[[nodiscard]] Rational Rational::operator+(const Rational &other) const {

    // Находим НОК знаменателей, т.е. новый знаменатель
    Natural lcm = Natural::lcm(denominator_, other.denominator_);// Использование метода (LCM_NN_N)

    // Считаем коэфы, на которые будем домножать числители
    Integer num_1_int = Integer(lcm / denominator_);
    Integer num_2_int = Integer(lcm / other.denominator_);

    //Получаем новые значения числителей, домноженных на num_1_int и num_2_int
    Integer num1 = numerator_ * num_1_int; // Использование метода (MUL_ZZ_Z)
    Integer num2 = other.numerator_ * num_2_int;

    // Складываем числители
    Integer sum = num1 + num2; //использование метода (ADD_ZZ_Z)

    //Создаем новую дробь с новым числителем и знаменателем, возвращаем ее
    Rational result = Rational(sum, lcm);

    return result.reduce();
}