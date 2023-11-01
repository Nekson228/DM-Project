#ifndef DM_RATIONAL_H
#define DM_RATIONAL_H

#include "../Integer/Integer.h"


class Rational {
    Integer numerator_{0}; // числитель
    Natural denominator_{1}; // знаменатель
public:
    Rational(Integer &numerator, Natural &denominator);

    Rational(std::int64_t numerator, std::size_t denominator);

    Rational(const Integer &integer); // TRANS_Z_Q

    [[nodiscard]] const Integer &getNumerator() const;

    [[nodiscard]] const Natural &getDenominator() const;

    std::string str() const; // TODO

    Rational &reduce() const; // RED_Q_Q

    bool isInteger() const; // INT_Q_B

    Integer &toInteger() const; // TRANS_Q_Z

    Rational &operator+(const Rational &other) const; // ADD_QQ_Q

    Rational &operator-(const Rational &other) const; // SUB_QQ_Q

    Rational &operator*(const Rational &other) const; // MUL_QQ_Q

    Rational &operator/(const Rational &other) const; // DIV_QQ_Q
};


#endif //DM_RATIONAL_H
