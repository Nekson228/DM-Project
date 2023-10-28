#ifndef DM_INTEGER_H
#define DM_INTEGER_H

#include "../Natural/Natural.h"

class Integer {
    Natural number_; // беззнаковая часть числа
    bool sign_; // знак (минус - true, плюс - false)
public:
    explicit Integer(std::int64_t number);

    std::string str(); // TODO

    Natural &abs(); // ABS_Z_N

    digit isPositive(); // POZ_Z_D

    Integer &negative(); // MUL_ZM_Z

    Integer &fromNatural(const Natural &natural); // TRANS_N_Z

    Natural &toNatural(); // TRANS_Z_N

    Integer &operator+(const Integer &other); // ADD_ZZ_Z

    Integer &operator-(const Integer &other); // SUB_ZZ_Z

    Integer &operator*(const Integer &other); // MUL_ZZ_Z

    Integer &operator/(const Integer &other); // DIV_ZZ_Z

    Integer &operator%(const Integer &other); // MOD_ZZ_Z
};

#endif //DM_INTEGER_H
