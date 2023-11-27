#ifndef DM_MODULES_INTEGER_H
#define DM_MODULES_INTEGER_H

#include "../Natural/Natural.h"

class Integer : public iModel {
    Natural number_{0}; // беззнаковая часть числа
    bool sign_; // знак (минус - true, плюс - false)
public:
    explicit Integer(std::int64_t number);

    explicit Integer(const std::string &str_number);

    explicit Integer(Natural natural); // TRANS_N_Z

    [[nodiscard]] std::string str() const override;

    [[nodiscard]] Integer abs() const; // ABS_Z_N

    [[nodiscard]] digit isPositive() const; // POZ_Z_D

    [[nodiscard]] Integer negative() const; // MUL_ZM_Z

    [[nodiscard]] Natural toNatural() const; // TRANS_Z_N

    [[nodiscard]] Integer operator+(const Integer &other) const; // ADD_ZZ_Z

    [[nodiscard]] Integer operator-(const Integer &other) const; // SUB_ZZ_Z

    [[nodiscard]] Integer operator*(const Integer &other) const; // MUL_ZZ_Z

    [[nodiscard]] Integer operator/(const Integer &other) const; // DIV_ZZ_Z

    [[nodiscard]] Integer operator%(const Integer &other) const; // MOD_ZZ_Z

    [[nodiscard]] bool operator==(const Integer &other) const;

    [[nodiscard]] bool operator!=(const Integer &other) const;
};

#endif //DM_MODULES_INTEGER_H
