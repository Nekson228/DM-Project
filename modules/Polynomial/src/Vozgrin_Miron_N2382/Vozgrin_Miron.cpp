#include"../../Polynomial.h"

// Мирон Возгрин 2382; Возвращает старший коэфицент многочлена (LED_P_Q)
Rational Polynomial::leading()const{
    return coefficients_[0]; //вещественное число, равное первому числу из вектора с коэфицентами многочлена
}
