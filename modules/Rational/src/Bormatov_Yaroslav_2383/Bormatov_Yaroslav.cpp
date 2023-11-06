#include "../../Rational.h"
#include <iostream>

// Bormatov Yaroslav TRANS_Q_Z - Преобразование сокращенного дробного в целое (если знаменатель равен 1)

Integer Rational::toInteger() const {
    Rational tmp = reduce(); // Сокращение дроби
    if(tmp.denominator_.cmp(tmp.denominator_, Natural{1}) == 0) { // проверка на то, является ли знаменатель равным 1
        return tmp.numerator_;
    } else {
        throw std::invalid_argument("Преобразование в \"Integer\" невозможно");
    }
}