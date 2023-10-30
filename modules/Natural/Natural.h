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

    std::string str() const; // TODO

    static digit cmp(const Natural &a, const Natural &b); // COM_NN_D

    static Natural &gcd(const Natural &a, const Natural &b); // GCF_NN_N

    static Natural &lcm(const Natural &a, const Natural &b); // LCM_NN_N

    bool &isZero() const; // NZER_N_B

    Natural &addOne() const; // ADD_1N_N

    Natural &mulByDigit(const digit multiplier) const; // MUL_ND_N

    Natural &mulBy10k(const std::size_t k) const; // MUL_Nk_N

    Natural &subScaled(const Natural &other, digit k) const; // SUB_NDN_N

    Natural &divFirstDigit(const Natural &other) const; // DIV_NN_Dk

    Natural &operator+(const Natural &other) const; // ADD_NN_N

    Natural &operator-(const Natural &other) const; // SUB_NN_N

    Natural &operator*(const Natural &other) const; // MUL_NN_N

    Natural &operator/(const Natural &other) const; // DIV_NN_N

    Natural &operator%(const Natural &other) const; // MOD_NN_N
};


#endif //DM_NATURAL_H
