//
// Ильин Павел 2383
//
#include "../../Natural.h"
#include <algorithm>

// MUL_Nk_N N-7 умножение на 10^k
[[nodiscard]] Natural Natural::mulBy10k(const std::size_t k) const {
    // изменяемое число
    std::vector<int> new_digits;
    for (int i:digits_){
        new_digits.push_back(i);
    }

    // процесс изменения числа
    for (int i = 0; i < k; i++) {
        new_digits.insert(new_digits.begin(), 0);
    }
    std::reverse(new_digits.begin(), new_digits.end());

    // перевод в вид строки
    std::string num_string;
    for (int i: new_digits) {
        num_string += std::to_string(i);
    }

    //возвращаем результатик
    return Natural(num_string);
}

//LCM_NN_N N-14 НОК натуральных чисел
[[nodiscard]] Natural Natural::lcm(const Natural &a, const Natural &b) {
    // формула НОК(а, b): a * b / НОД(a, b). Вычисляем и сразу возвращаем
    return a * b / a.gcd(a, b);
}

