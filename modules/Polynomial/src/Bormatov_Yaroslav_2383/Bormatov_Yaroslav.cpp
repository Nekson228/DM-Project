#include "../../Polynomial.h"
#include <iostream>

// Bormatov_Yaroslav FAC_P_Q - Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
// Используемые методы - ABS_Z_N TRANS_Z_N LCM_NN_N GCF_NN_N TRANS_N_Z DIV_ZZ_Z

Polynomial Polynomial::factorize() const {
    Polynomial result = Polynomial(*this); // создание многочлена возвращаемого методом

    if(degree_ <= 1) return result; // если многочлен степени <= 1 -> нельзя ничего вынести

    Natural lcm_{1}, gcd_{1}; // создаем два натуральных числа - НОД и НОК знаменателей и числителей коэф-ов многочлена соответственно
    gcd_ = gcd_.gcd(coefficients_[0].getNumerator().toNatural(), coefficients_[1].getNumerator().toNatural()); // вычисление НОД <a_0, a_1>
    lcm_ = lcm_.lcm(coefficients_[0].getDenominator(), coefficients_[1].getDenominator());                     // вычисление НОК <a_0, a_1>

    for(size_t i = 2; i < degree_; i++) {
        gcd_ = gcd_.gcd(gcd_, coefficients_[i].getNumerator().toNatural()); // вычисление НОД от <gcd, a_i>
        lcm_ = lcm_.lcm(lcm_, coefficients_[i].getDenominator());           // вычисление НОК от <lcm, a_i>
    }

    Integer gcd_int(gcd_); // gcd -> int
    Rational ratio(gcd_int, lcm_); // ratio = gcd / lcm

    for(size_t i = 0; i < degree_; i++) {
        result.coefficients_[i] = coefficients_[i] / ratio; // делим каждый коэффициент на ratio
    }

    return result; // возвращаем новый многочлен

}

// Bormatov_Yaroslav NMR_P_P - Преобразование многочлена — кратные корни в простые
// Используемые методы - GCF_PP_P DER_P_P DIV_PP_P

Polynomial Polynomial :: singlify() const {
    Polynomial der_ = derivative();  // вычисление производной многочлена
    Polynomial gcd_ = gcd(*this, der_); // вычисление НОД <P(x), P'(x)>
    Polynomial result = *this / gcd_; // вычисление P(x) / gcd(<P(x), P'(x))
    
    return result; // возвращаем новый многочлен
}