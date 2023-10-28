#include "Natural.h"

Natural::Natural(std::size_t number) {
    if (number == 0)
        digits_.push_back(0);
    while (number > 0) {
        digits_.push_back(number % 10);
        number /= 10;
    }
    n_ = digits_.size() - 1;
}
