#include <iostream>
#include "modules/Natural/Natural.h"
#include "modules/Integer/Integer.h"
#include "modules/Rational/Rational.h"
#include "modules/Polynomial/Polynomial.h"

int main() {
    Polynomial pol1{"1/2*x"}, pol2{"x-2"};
    std::cout << (pol1 + pol1).str();
}