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
    Integer first(*this);  // копируем первое число
    Integer second(other); // копируем второе число
    if(second == Integer(0)) {
        throw std::invalid_argument("Деление на 0 невозможно");
    }

    Integer answer(0);  // частное
    answer.sign_ = false;

    if(first.isPositive() == 2 && second.isPositive() == 2) { // a > 0, b > 0
        while(first.isPositive() != 1) {  // пока a >= 0
            answer = answer + Integer(1); // ans += 1
            first = first - second;       // a -= b
        }
        answer = answer - Integer(1); 
    } else if(first.isPositive() == 2 && second.isPositive() == 1) { // a > 0, b < 0
        while(first.isPositive() != 1) {  // пока a >= 0
            answer = answer + Integer(1); // ans += 1
            first = first + second;       // a += b
        }
        answer = answer - Integer(1);
        answer.sign_ = true;              // ответ - отрицательное число
    } else if(first.isPositive() == 1 && second.isPositive() == 1) { // a < 0, b > 0
        while(first.isPositive() == 1) {  // пока a < 0
            answer = answer + Integer(1); // ans += 1
            first = first + second;       // a += b
        }
        answer.sign_ = true;              // ответ - отрицательное число
    } else { // a < 0, b < 0
        while(first.isPositive() == 1) {  // пока a < 0
            answer = answer + Integer(1); // ans += 1
            first = first - second;       // a -= b
        }
    }

    return answer; // возвращаем полученный результат
}

