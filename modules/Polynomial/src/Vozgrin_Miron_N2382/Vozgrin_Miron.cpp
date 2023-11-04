#include"../../Polynomial.h" // LED_P_Q
Rational Polynomial::leading()const{
    return coefficients_[coefficients_.size()-1]; //вещественное число, равное последнему числу из вектора с коэфицентами многочлена
}
