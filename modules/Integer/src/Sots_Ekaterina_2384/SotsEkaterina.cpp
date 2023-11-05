#include "../../Integer.h"
#include <iostream>

// Katya Sots TRANS_Z_N - Преобразование целого неотрицательного в натуральное

Natural Integer :: toNatural() const {
    if(sign_ == true) { // проверка на то, является ли число отрицательным
        throw std::invalid_argument("Число отрицательное");
    }

    return Natural(number_); // возвращаем натуральное число
}

// Katya Sots DIV_ZZ_Z - Частное от деления целого на целое (делитель отличен от нуля)
// Используемые методы - ABS_Z_N POZ_Z_D DIV_NN_N ADD_1N_N

Integer Integer :: operator/ (const Integer &other) const {
    bool flag = sign_ ^ other.sign_; // итоговый знак нового числа (используется XOR)
    Integer first(*this);  // копируем первое число
    Integer second(other); // копируем второе число
    if(second == Integer(0)) {
        throw std::invalid_argument("Деление на 0 невозможно");
    }
    u_int32_t answer = 0;  // частное
    while(first.isPositive() == 2) { // цикл пока делимое > 0
        answer++; // увеличиваем частное на 1
        first = first - second; // вычитаем из делимого делитель
    }
    return Integer(answer - 1);
}