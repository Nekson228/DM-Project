#include "Polynomial.h"

Polynomial::Polynomial(std::vector<Rational> &coefficients) :
        coefficients_(coefficients), degree_(coefficients.size() - 1) {}
