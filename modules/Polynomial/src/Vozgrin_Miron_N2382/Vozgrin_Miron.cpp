// Мирон Возгрин 2382; Возвращает старший коэфицент многочлена (LED_P_Q)
#include"../../Polynomial.h"
Rational Polynomial::leading()const{
    return coefficients_[0]; //вещественное число, равное последнему числу из вектора с коэфицентами многочлена
}
