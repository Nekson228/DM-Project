#include "../../Rational.h"

//Лавренова Юлия гр.2384 TRANS_Z_Q - Преобразование целого в дробное
Rational::Rational(const Integer &integer):numerator_(integer), denominator_(1){} 
//присваиваем числу абсолютную часть числа, а знаменателю 1