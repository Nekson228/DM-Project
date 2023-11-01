#include "Rational.h"

Rational::Rational(Integer &numerator, Natural &denominator) : numerator_(numerator), denominator_(denominator) {}

Rational::Rational(std::int64_t numerator, std::size_t denominator) {
    numerator_ = Integer{numerator};
    denominator_ = Natural{denominator};
}

const Integer &Rational::getNumerator() const {
    return numerator_;
}

const Natural &Rational::getDenominator() const {
    return denominator_;
}
