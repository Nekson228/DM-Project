#include "../../Integer.h"
using digit = uint8_t;

// Цыганков Роман гр. 2384 SUB_ZZ_Z- Вычитание целых чисел
Integer Integer::operator-(const Integer &other) const{
    int flag = 0; // знак (0 - плюс, 1 - минус)
    Natural number_other = other.abs().number_; //абсолютная часть 2ого числа
    Natural result; // результат

    digit my_cmp = Natural::cmp(number_, number_other); // сравнение
    
    if(this->isPositive() == 2 && other.isPositive() == 2){ // если оба числа положительные
        if(my_cmp == 2 || my_cmp == 0){ // если первое болльше, или они равны
            result = number_ - number_other;
        }
        else if(my_cmp == 1){ // если второе больше
            result = number_other - number_;
            flag = 1;
        }
    }

    else if(this->isPositive() == 2 && (other.isPositive() == 1 || other.isPositive() == 0)){ // если первое положительное, а второе отрицаетльное или 0
        result = number_ + number_other;
    }

    else if(this->isPositive() == 1 && other.isPositive() == 2){ // если первое отрицательное, а второе положительное
        result = number_ + number_other;
        flag = 1;
    }

    else if(this->isPositive() == 1 && (other.isPositive() == 1 || other.isPositive() == 0)){ // если первое отрицательное, а второе отрицательное или 0
        if(my_cmp == 2){ // если первое больше
            result = number_ - number_other;
            flag = 1;
        }
        else if(my_cmp == 1 || my_cmp == 0){// если перове меньше, или числа равны
            result = number_other - number_;
        }
    }

    else if(this->isPositive() == 0 && other.isPositive() == 2){ // если первое 0, а второе положительное
        result = number_other;
        flag = 1;
    }

    else{ // если первое 0, а второе отрицательное или 0
        result = number_other;
    }

    Integer result_integer(result); // создаем объект класса
    if(flag == 1){ 
        result_integer = result_integer.negative(); // указываем минус
    }
    return result_integer; // возвращаем значение
}
// Цыганков Роман гр 2384 TRANS_N_Z - Преобразование натурального в целое
Integer::Integer(const Natural &natural):number_(natural), sign_(false){}
// присваиваем числу абсолютную часть, а знаку false (+)