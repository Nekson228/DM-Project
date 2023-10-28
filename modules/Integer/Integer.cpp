#include "Integer.h"

Integer::Integer(std::int64_t number): sign_(number < 0), number_(Natural(std::abs(number))) {}
