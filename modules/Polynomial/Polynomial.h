#ifndef DM_POLYNOMIAL_H
#define DM_POLYNOMIAL_H

#include "../Rational/Rational.h"


class Polynomial {
    std::vector<Rational> coefficients_; // массив дробных коэффициентов
    std::size_t degree_; // степень многочлена
public:
    explicit Polynomial(std::vector<Rational> &coefficients);

    explicit Polynomial(std::string polynomial); // TODO

    static Polynomial &gcd(const Polynomial &a, const Polynomial &b); //GCF_PP_P

    std::string str(); // TODO

    void scale(const Rational &scalar); // MUL_PQ_P

    void mulByXk(std::size_t k); // MUL_Pxk_P

    Rational &leading(); // LED_P_Q

    std::size_t getDegree(); // DEG_P_N

    Polynomial &factorize(); // FAC_P_Q

    Polynomial &derivative(); // DER_P_P

    Polynomial &singlify(); // NMR_P_P

    Polynomial &operator+(const Polynomial &other); // ADD_PP_P

    Polynomial &operator-(const Polynomial &other); // SUB_PP_P

    Polynomial &operator*(const Polynomial &other); // MUL_PP_P

    Polynomial &operator/(const Polynomial &other); // DIV_PP_P

    Polynomial &operator%(const Polynomial &other); // MOD_PP_P
};


#endif //DM_POLYNOMIAL_H
