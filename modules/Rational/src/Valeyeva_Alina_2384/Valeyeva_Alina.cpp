#include "../../Rational.h"

// Valeyeva Alina MUL_QQ_Q - Умножение дробей(используемые методы: MUL_ZZ_Z)
Rational Rational::operator*(const Rational &other) const{ // MUL_QQ_Q
    Integer new_numerator = numerator_ * other.numerator_; // умножение числителей через MUL_ZZ_Z
    Natural new_denominator = denominator_ * other.denominator_; // умножение знаменателей

    // Создаем и возвращаем новый объект Rational
    Rational result(new_numerator, new_denominator);
    return result;
}

// Valeyeva Alina RED_Q_Q - Сокращение дроби(использумые методы: ABS_Z_N, GCF_NN_N, DIV_ZZ_Z)
Rational Rational::reduce() const{
    Natural my_numerator = numerator_.abs().toNatural(); // получили мой числитель в виде натурального неотрицательного числа
    Natural nod = Natural::gcd(my_numerator, denominator_); // получили НОД в виде натур числа

    Integer nod_integer(nod); // НОД в виде целого числа

    // Вычисляем сокращенную дробь
    Integer new_numerator = numerator_ / (nod_integer); // новый числитель (через метод DIV_ZZ_Z)
    Natural new_denominator = denominator_ / nod; // новый знаменатель (через метод DIV_NN_N)

    // Создаем и возвращаем новый объект Rational с сокращенной дробью
    Rational result(new_numerator, new_denominator);
    return result;
}