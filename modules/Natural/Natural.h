#ifndef DM_MODULES_NATURAL_H
#define DM_MODULES_NATURAL_H

#include "../Interfaces/Model.h"

#include <cstdint>
#include <vector>
#include <string>

using digit = uint8_t;

class Natural : public iModel {
    std::vector<digit> digits_ = {}; // цифры в обратном порядке
    std::size_t n_ = -1; // номер старшей позциии (начиная с 0)

public:
    Natural() = default;

    explicit Natural(std::size_t number);

    explicit Natural(const std::string &str_number);

    [[nodiscard]] std::string str() const override;

    [[nodiscard]] static digit cmp(const Natural &a, const Natural &b); // COM_NN_D

    [[nodiscard]] static Natural gcd(const Natural &a, const Natural &b); // GCF_NN_N

    [[nodiscard]] static Natural lcm(const Natural &a, const Natural &b); // LCM_NN_N

    [[nodiscard]] bool isZero() const; // NZER_N_B

    [[nodiscard]] Natural addOne() const; // ADD_1N_N

    [[nodiscard]] Natural mulByDigit(digit multiplier) const; // MUL_ND_N

    [[nodiscard]] Natural mulBy10K(std::size_t k) const; // MUL_Nk_N

    [[nodiscard]] Natural subScaled(const Natural &other, digit k) const; // SUB_NDN_N

    [[nodiscard]] Natural divFirstDigit(const Natural &other) const; // DIV_NN_Dk

    [[nodiscard]] Natural operator+(const Natural &other) const; // ADD_NN_N

    [[nodiscard]] Natural operator-(const Natural &other) const; // SUB_NN_N

    [[nodiscard]] Natural operator*(const Natural &other) const; // MUL_NN_N

    [[nodiscard]] Natural operator/(const Natural &other) const; // DIV_NN_N

    [[nodiscard]] Natural operator%(const Natural &other) const; // MOD_NN_N

    [[nodiscard]] bool operator==(const Natural &other) const;

    [[nodiscard]] bool operator!=(const Natural &other) const;
};

#endif //DM_MODULES_NATURAL_H
