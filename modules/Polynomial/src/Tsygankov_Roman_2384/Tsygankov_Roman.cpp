#include "../../Polynomial.h"


Polynomial Polynomial::mulByXk(std::size_t k) const {
    std::size_t degree = this->degree_ + k+ 1; // степень нового мн-на
    std::vector <Rational> new_coeff(degree); // создаем новыый вектор с коэффицентами
    for(int i=0; i < this->degree_ + 1; i++){
        new_coeff[i] = coefficients_[i]; // присваиваем коэффиценты
    }

    for(int i=this->degree_+1; i<degree; i++){
        new_coeff[i] = Rational(0, 1); // оставшееся заполняем нулями
    }

    Polynomial new_coefficients_(new_coeff); // создаем мн-н с новыми коэффицентами и возвращаем его
    new_coefficients_.degree_ = degree - 1;

    return new_coefficients_;
}