#include "../../Integer.h"

//Лавренова Юлия гр.2384 POZ_Z_D - Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)
[[nodiscard]] digit Integer::isPositive() const{ 
    digit sign; //перемнная знака
    if (sign_ == true) sign = 1; //если знак числа true, число отрицательное - возвращаем 1
    else if (sign_ == false) sign = 2; //если знак числа false, число положительное - возвращаем 2
    else sign = 0; //иначе ноль
    return sign; //возвращаем знак
}

//Лавренова Юлия гр.2384 MULL_ZZ_Z - Умножение целых чисел 
[[nodiscard]] Integer Integer::operator*(const Integer &other) const{ 
    digit sign_this = this->isPositive(); //знак текущего числа
    digit sign_other = other.isPositive(); //знак другого числа
    Integer n_this = this->abs(); //абсолютная часть текущего числа
    Integer n_other = other.abs(); //абсолютная часть другого числа

    Integer new_num(n_other*n_this); //абсолютная часть произведения чисел
    if ((sign_other == 1 && sign_this == 1) || (sign_other == 2 && sign_this == 2) || (sign_other == 0 || sign_this == 0)) 
        return new_num; //если знаки оба положительные, оба отрицательные или оба ноль
    else{
        new_num.negative(); //иначе присваиваем отрицательный знак
        return new_num;
    }
}