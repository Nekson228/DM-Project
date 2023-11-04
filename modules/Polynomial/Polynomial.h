#ifndef DM_POLYNOMIAL_H
#define DM_POLYNOMIAL_H

#include "../Rational/Rational.h"


class Polynomial {
    std::vector<Rational> coefficients_; // массив дробных коэффициентов
    std::size_t degree_; // степень многочлена
public:
    explicit Polynomial(std::vector<Rational> &coefficients);

    explicit Polynomial(std::string polynomial); // TODO

    [[nodiscard]] static Polynomial gcd(const Polynomial &a, const Polynomial &b); //GCF_PP_P

    [[nodiscard]] std::string str() const; // TODO

    [[nodiscard]] Polynomial scale(const Rational &scalar) const; // MUL_PQ_P

    [[nodiscard]] Polynomial mulByXk(std::size_t k) const; // MUL_Pxk_P

    [[nodiscard]] Rational leading() const; // LED_P_Q

    [[nodiscard]] std::size_t getDegree() const; // DEG_P_N

    [[nodiscard]] Polynomial factorize() const; // FAC_P_Q

    [[nodiscard]] Polynomial derivative() const; // DER_P_P

    [[nodiscard]] Polynomial singlify() const; // NMR_P_P

    [[nodiscard]] Polynomial operator+(const Polynomial &other) const; // ADD_PP_P

    [[nodiscard]] Polynomial operator-(const Polynomial &other) const; // SUB_PP_P

    [[nodiscard]] Polynomial operator*(const Polynomial &other) const; // MUL_PP_P

    [[nodiscard]] Polynomial operator/(const Polynomial &other) const; // DIV_PP_P

    [[nodiscard]] Polynomial operator%(const Polynomial &other) const; // MOD_PP_P

    [[nodiscard]] bool operator==(const Polynomial &other) const = default;

    [[nodiscard]] bool operator!=(const Polynomial &other) const = default;
};


#endif //DM_POLYNOMIAL_H
