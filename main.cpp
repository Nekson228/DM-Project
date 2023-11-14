#include <iostream>
#include "modules/Natural/Natural.h"
#include "modules/Integer/Integer.h"
#include "modules/Rational/Rational.h"
#include "modules/Polynomial/Polynomial.h"

int main() {
    Polynomial pol1{"1"}, pol2{"x"}, div = pol1 / pol2;
//    Polynomial mul = div * pol2;
    std::cout << div.mulByXk(1).str();
}