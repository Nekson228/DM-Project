#include <iostream>
#include "modules/Natural/Natural.h"
#include "modules/Integer/Integer.h"
#include "modules/Rational/Rational.h"
#include "modules/Polynomial/Polynomial.h"

int main() {
    Natural nat1{"100"}, nat2{"1"};
    Natural res = nat1.divFirstDigit(nat2);
    std::cout << res.str();
}