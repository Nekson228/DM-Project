#ifndef DM_RATIONAL_H
#define DM_RATIONAL_H

#include "../Integer/Integer.h"


class Rational {
    Integer numerator_{0}; // числитель
    Natural denominator_{1}; // знаменатель
public:
    Rational(Integer &numerator, Natural &denominator);

    Rational(std::int64_t numerator, std::size_t denominator);

    std::string str(); // TODO

    Rational &reduce(); // RED_Q_Q

    bool isInteger(); // INT_Q_B

    Rational &fromInteger(const Integer &integer); // TRANS_Z_Q

    Integer &toInteger(); // TRANS_Q_Z

    Rational &operator+(const Rational &other); // ADD_QQ_Q

    Rational &operator-(const Rational &other); // SUB_QQ_Q

    Rational &operator*(const Rational &other); // MUL_QQ_Q

    Rational &operator/(const Rational &other); // DIV_QQ_Q
};


#endif //DM_RATIONAL_H
