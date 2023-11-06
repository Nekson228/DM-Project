#include "../../Natural.h"
#include <iostream>

// Цыгулев Станислав ADD_1N_N - Добавление 1 к натуральному числу

Natural Natural :: addOne() const {
    Natural answer(*this); // создание копии числа
    answer.digits_[0]++; // добавляем 1 к последней цифре
    for(size_t i = 0; answer.digits_[i] == 10; i++) { // проходимся по цифрам пока текущая цифра == 10
        answer.digits_[i] = 0; // заменяем текущую цифру на 0
        if(i != answer.n_) { // если нет следующей цифры то добавляем 1
            answer.digits_.push_back(1);
            answer.n_++;
        } else {  // иначе увеличиваем следующую цифру на 1
            answer.digits_[i+1]++; 
        }
    }

    return answer; // возвращаем новое число
}

// Цыгулев Станислав SUB_NN_N - Вычитание из первого большего натурального числа второго меньшего или равного
// Используемые методы - COM_NN_D
Natural Natural :: operator-(const Natural &other) const {
    if(cmp(*this, other) == 1) { // если первое число меньше второго
        throw std::invalid_argument("Первое число меньше второго");
    } else if(cmp(*this, other) == 0) { // если числа равны
        return Natural(0); // возвращаем 0
    }
    Natural answer(*this); // создание копии числа
    size_t borrow = 0; // создаем задержку для случая когда число сильно меньше
    for(size_t i = 0; i < this.n_; ++i)// проходимся по всем цифрам второго числа
    {
        int ai = i < this.n_ ? this.digits_[i] : 0; // вычисляем числа из которого будем вычислять
        int bi = i < other.n_ ? other.digits_[i] : 0; // размер 1 числа > размера 2 числа => вычитаем ноль
        
        int result = ai - bi - borrow; // текущий результат = (цифра первого - цифра второго) - задержка
        if(result < 0)// если цифра < 0 - надо забрать еденицу из следующего разряда
        {
            result += 10;
            borrow = 1; // надо проверить следующее число
        }
        else
            borrow = 0; // это число положительно из других разрядов не занимали
        answer.digits_[i] = result; // присваиваем текущей цифре нового числа вычисленный результат
    }

    while (answer.n_ > 1 && answer.digits_.back() == 0) // удаляем ведущие нули
    {
        answer.digits_.pop_back();
    }

    return answer; // возвращаем новое число
}