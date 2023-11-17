#ifndef DM_MODULES_RATIONAL_H
#define DM_MODULES_RATIONAL_H

#include "../Integer/Integer.h"


class Rational : public iModel {
    Integer numerator_{0}; // числитель
    Natural denominator_{1}; // знаменатель

    void checkDenominator();

public:
    Rational() = default;

    Rational(Integer numerator, Natural denominator);

    Rational(std::int64_t numerator, std::size_t denominator);

    explicit Rational(const std::string &str_number);

    explicit Rational(Integer integer); // TRANS_Z_Q

    [[nodiscard]] const Integer &getNumerator() const;

    [[nodiscard]] const Natural &getDenominator() const;

    [[nodiscard]] std::string str() const override;

    [[nodiscard]] Rational reduce() const; // RED_Q_Q

    [[nodiscard]] bool isInteger() const; // INT_Q_B

    [[nodiscard]] Integer toInteger() const; // TRANS_Q_Z

    [[nodiscard]] Rational operator+(const Rational &other) const; // ADD_QQ_Q

    [[nodiscard]] Rational operator-(const Rational &other) const; // SUB_QQ_Q

    [[nodiscard]] Rational operator*(const Rational &other) const; // MUL_QQ_Q

    [[nodiscard]] Rational operator/(const Rational &other) const; // DIV_QQ_Q

    [[nodiscard]] bool operator==(const Rational &other) const;

    [[nodiscard]] bool operator!=(const Rational &other) const;

    [[nodiscard]] std::string getSign() const;

    [[nodiscard]] Rational abs() const;

    [[nodiscard]] bool isZero() const;
};

#endif //DM_MODULES_RATIONAL_H
