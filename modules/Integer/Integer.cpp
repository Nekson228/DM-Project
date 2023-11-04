#include "Integer.h"

Integer::Integer(std::int64_t number) : sign_(number < 0), number_(Natural(std::abs(number))) {}

Integer::Integer(const std::string &str_number): sign_(str_number[0] == '-') {
    std::string abs_data = str_number;
    if (str_number[0] == '-' || str_number[1] == '+')
        abs_data = abs_data.substr(1);
    number_ = Natural{abs_data};
}

std::string Integer::str() const {
    return (sign_ ? "-" : "") + number_.str();
}
