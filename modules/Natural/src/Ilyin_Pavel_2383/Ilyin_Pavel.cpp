//
// Created by lipmip on 05.11.2023.
//
#include "../../Natural.h"
#include <algorithm>

// MUL_Nk_N N-7 умножение на 10^k Ильин Павел 2383
[[nodiscard]] Natural Natural::mulBy10k(const std::size_t k) const {
    //копируем изменяемый объект
    Natural new_num;
    new_num.digits_ = digits_;

    //вносим изменения
    for (size_t i = 0; i < k; i++) {
        new_num.digits_.insert(new_num.digits_.begin(), 0);
    }

    //обновляем поле старшего разряда числа
    new_num.n_ = new_num.digits_.size() - 1;

    //возвращаем результатик
    return new_num;
}

//LCM_NN_N N-14 НОК натуральных чисел Ильин Павел 2383
[[nodiscard]] Natural Natural::lcm(const Natural &a, const Natural &b) {
    // формула НОК(а, b): a * b / НОД(a, b). Вычисляем и сразу возвращаем
    return a * b / gcd(a, b);
}

