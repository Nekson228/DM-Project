#include "Rational.h"

#include <stdexcept>
#include <utility>

Rational::Rational(Integer numerator, Natural denominator) :
        numerator_(std::move(numerator)), denominator_(std::move(denominator)) {
//    checkDenominator();
}

Rational::Rational(std::int64_t numerator, std::size_t denominator) :
        Rational(Integer(numerator), Natural(denominator)) {
}

Rational::Rational(const std::string &str_number) {
    std::size_t slash_sign = str_number.find('/');
    if (slash_sign == 0)
        throw std::invalid_argument("No numerator specified.");
    else if (slash_sign == str_number.size() - 1)
        throw std::invalid_argument("No denominator specified.");
    if (slash_sign != std::string::npos)
        denominator_ = Natural{str_number.substr(slash_sign + 1)};
    numerator_ = Integer(str_number.substr(0, slash_sign));
//    checkDenominator();
}

std::string Rational::str() const {
    return numerator_.str() + "/" + denominator_.str();
}

const Integer &Rational::getNumerator() const {
    return numerator_;
}

const Natural &Rational::getDenominator() const {
    return denominator_;
}

//void Rational::checkDenominator() {
//    if (denominator_.isZero())
//        throw std::invalid_argument("Denominator should be non zero");
//}
