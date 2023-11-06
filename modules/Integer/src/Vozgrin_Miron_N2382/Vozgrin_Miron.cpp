#include "../../Integer.h"

// Мирон Возгрин 2382; Остаток от деления целого на целое (MOD_ZZ_Z)
Integer Integer::operator%(const Integer &other)const{
    Integer z1(number_);
    Integer z2(other.number_);
    return z1 - (z2 * (z1 / z2));       //Возвращаемое значение равно разности левого числа и произведения правого на разность деления 2 чисел
}
