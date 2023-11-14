#include <iostream>
#include "modules/Natural/Natural.h"
#include "modules/Integer/Integer.h"
#include "modules/Rational/Rational.h"
#include "modules/Polynomial/Polynomial.h"

int main() {
    Polynomial poly("x^6 - 15 x^5 + 63 x^4 + 39 x^3 - 660 x^2 + 300 x + 2000");
    Polynomial ans("x^3 - 7 x^2 + 2 x + 40");
    std::cout << poly.singlify().factorize().reduceAllCoefficients().str();
    // "6*x^5 - 75*x^4 + 252*x^3 + 117*x^2 - 1320*x + 300"
    // "-41/4*x^4 + 249/2*x^3 - 1565/4*x^2 - 300*x + 2125"

}