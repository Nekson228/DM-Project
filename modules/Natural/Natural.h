#ifndef DM_NATURAL_H
#define DM_NATURAL_H

#include <cstdint>
#include <vector>
#include <string>

using digit = uint8_t;

class Natural {
    std::vector<digit> digits_; // цифры в обратном порядке (154 == [4 5 1])
    std::size_t n_; // номер старшей позциии

public:
    explicit Natural(std::size_t number);

    explicit Natural(const std::string &str_number);

    [[nodiscard]] std::string str() const;

    [[nodiscard]] static digit cmp(const Natural &a, const Natural &b); // COM_NN_D

    [[nodiscard]] static Natural gcd(const Natural &a, const Natural &b); // GCF_NN_N

    [[nodiscard]] static Natural lcm(const Natural &a, const Natural &b); // LCM_NN_N

    [[nodiscard]] bool isZero() const; // NZER_N_B

    [[nodiscard]] Natural addOne() const; // ADD_1N_N

    [[nodiscard]] Natural mulByDigit(digit multiplier) const; // MUL_ND_N

    [[nodiscard]] Natural mulBy10k(const std::size_t k) const; // MUL_Nk_N

    [[nodiscard]] Natural subScaled(const Natural &other, digit k) const; // SUB_NDN_N

    [[nodiscard]] Natural divFirstDigit(const Natural &other) const; // DIV_NN_Dk

    [[nodiscard]] Natural operator+(const Natural &other) const; // ADD_NN_N

    [[nodiscard]] Natural operator-(const Natural &other) const; // SUB_NN_N

    [[nodiscard]] Natural operator*(const Natural &other) const; // MUL_NN_N

    [[nodiscard]] Natural operator/(const Natural &other) const; // DIV_NN_N

    [[nodiscard]] Natural operator%(const Natural &other) const; // MOD_NN_N

    [[nodiscard]] bool operator==(const Natural &other) const = default;

    [[nodiscard]] bool operator!=(const Natural &other) const = default;
};

#endif //DM_NATURAL_H
