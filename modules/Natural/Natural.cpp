#include "Natural.h"

#include <stdexcept>
#include <algorithm>

Natural::Natural(std::size_t number) {
    if (number == 0)
        digits_.push_back(0);
    while (number > 0) {
        digits_.push_back(number % 10);
        number /= 10;
    }
    n_ = digits_.size() - 1;
}

Natural::Natural(const std::string &str_number) {
    for (digit digit: str_number) {
        if (!isdigit(digit)) {
            std::string exception = "Operand data is invalid. Unknowm character ";
            exception += static_cast<char>(digit);
            throw std::invalid_argument(exception);
        }
        digits_.push_back(digit - '0');
    }
    std::reverse(digits_.begin(), digits_.end());
    n_ = digits_.size() - 1;
}

std::string Natural::str() const {
    std::vector<digit> digits_copy = digits_;
    std::reverse(digits_copy.begin(), digits_copy.end());
    std::transform(digits_copy.begin(), digits_copy.end(), digits_copy.begin(),
                   [](digit digit) { return digit + '0'; });
    std::string res(digits_copy.begin(), digits_copy.end());
    return res;
}
