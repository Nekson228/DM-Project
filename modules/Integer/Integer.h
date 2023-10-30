#ifndef DM_INTEGER_H
#define DM_INTEGER_H

#include "../Natural/Natural.h"

class Integer {
    Natural number_; // беззнаковая часть числа
    bool sign_; // знак (минус - true, плюс - false)
public:
    explicit Integer(std::int64_t number);

    explicit Integer(const Natural &natural); // TRANS_N_Z

    std::string str() const; // TODO

    Natural &abs() const; // ABS_Z_N

    digit isPositive() const; // POZ_Z_D

    Integer &negative() const; // MUL_ZM_Z

    Natural &toNatural() const; // TRANS_Z_N

    Integer &operator+(const Integer &other) const; // ADD_ZZ_Z

    Integer &operator-(const Integer &other) const; // SUB_ZZ_Z

    Integer &operator*(const Integer &other) const; // MUL_ZZ_Z

    Integer &operator/(const Integer &other) const; // DIV_ZZ_Z

    Integer &operator%(const Integer &other) const; // MOD_ZZ_Z
};

#endif //DM_INTEGER_H
