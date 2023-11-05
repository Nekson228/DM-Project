#include "../../Integer.h"
using digit = uint8_t;

// Valeyeva Alina ADD_ZZ_Z - Сложение целых чисел(используемые мметоды: POZ_Z_D, ABS_Z_N, COM_NN_D, ADD_NN_N, SUB_NN_N, MUL_ZM_Z)
Integer Integer::operator+(const Integer &other) const {
    int flag_MUL_ZM_Z = 0; // для определения знака. Если флаг = 1, то умножаем на (-1) через метод MUL_ZM_Z
    Natural number_other = other.abs().number_; // получаю абсолютную часть второго числа (ABS_Z_Z)
    Natural result; // число-резутат, натуральное

    digit my_cmp = Natural::cmp(number_, number_other); // сравниваню два натуральных числа (COM_NN_D)

    // если числа положительные или равны 0 (POZ_Z_D)
    if ((other.isPositive() == 2 ||other.isPositive() == 0) && (this->isPositive() == 2 || this->isPositive() == 0)){
        result = (number_ + other.number_); //  складываю два натуральных числа без модуля, т.к. положительные
    }

        // если оба числа отрицательные
    else if (other.isPositive() == 1 && this->isPositive() == 1){
        result = (number_ + number_other); // складываю два натуральных числа(ADD_NN_N)
        flag_MUL_ZM_Z = 1; // нужно поменять знак у моего возвращаемого целого числа на минус
    }

        // Если одно число положительное, а другое отрицательное
    else{
        if (my_cmp == 2 || my_cmp == 0){ // если первое > второго или они равны
            result = (number_ - number_other); // (SUB_NN_N)
        }
        else{ // если первое < второго (my_cmp == 1)
            result = (number_other - number_); // вычитаем из второго первое (SUB_NN_N)
            flag_MUL_ZM_Z = 1; // но впоследствии меняем знак у ответа
        }
    }

    // создаем и возвращаем объект класса Integer
    Integer result_integer(result);
    if (flag_MUL_ZM_Z == 1){
        result_integer = result_integer.negative(); // меняем знак на минус, домножая на (-1)
    }
    return result_integer;
}