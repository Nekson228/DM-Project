#include <iostream>
#include "modules/Natural/Natural.h"
#include "modules/Integer/Integer.h"
#include "modules/Rational/Rational.h"
#include "modules/Polynomial/Polynomial.h"

int main() {
    Rational n1{123, 3}, n2{123, 2}, n3{5, 2};
    std::vector<Rational> v1 = {n1, n2}, v2 = {n1, n3, n2};
    Polynomial p1{v1}, p2{v2};
    std::cout << (p1 != p2);
}