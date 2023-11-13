#include <iostream>
#include "modules/Natural/Natural.h"
#include "modules/Integer/Integer.h"
#include "modules/Rational/Rational.h"
#include "modules/Polynomial/Polynomial.h"

int main() {
    Polynomial pol1{"x^100 - 0x^2 + x + 1"}, pol2{"x - 5x^2"}, pol3("0");
    std::cout << (pol1 * pol2).str();
}