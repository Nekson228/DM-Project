#include "Integer.h"

#include <utility>
#include <stdexcept>

Integer::Integer(std::int64_t number) : sign_(number < 0), number_(Natural(std::abs(number))) {}

Integer::Integer(const std::string &str_number) : sign_(false) {
    size_t sign_pos = str_number.find_first_of("-+");
    if (sign_pos != std::string::npos)
        sign_ = str_number[sign_pos] == '-';
    number_ = Natural{str_number.substr(sign_pos + 1)};
}

std::string Integer::str() const {
    return (sign_ ? "-" : "") + number_.str();
}

//Лавренова Юлия гр.2384 POZ_Z_D - Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)
[[nodiscard]] digit Integer::isPositive() const {
    if (number_.isZero()) //если число равно 0, возвращаем 0
        return 0;
    return sign_ ? 1 : 2; //если число отрицательное, возвращаем 1, иначе 2
}

//Гурков Арсений 2384, Z1, ABS_Z_Z, Абсолютная величина числа
Integer Integer::abs() const {
    //создание объекта типа Integer с использованием текущего значения, без учета знака
    return Integer{number_};
}

// Цыганков Роман гр 2384 TRANS_N_Z - Преобразование натурального в целое
Integer::Integer(Natural natural) : number_(std::move(natural)), sign_(false) {}
// присваиваем числу абсолютную часть, а знаку false (+)

//Лавренова Юлия гр.2384 MULL_ZZ_Z - Умножение целых чисел
[[nodiscard]] Integer Integer::operator*(const Integer &other) const {
    digit sign_this = this->isPositive(); //знак текущего числа
    digit sign_other = other.isPositive(); //знак другого числа
    Natural n_this = this->toNatural(); //абсолютная часть текущего числа
    Natural n_other = other.toNatural(); //абсолютная часть другого числа

    Integer new_num(n_other * n_this); //абсолютная часть произведения чисел
    if ((sign_other == 1 && sign_this == 1) || (sign_other == 2 && sign_this == 2) ||
        (sign_other == 0 || sign_this == 0))
        return new_num; //если знаки оба положительные, оба отрицательные или оба ноль
    else
        return new_num.negative(); //иначе присваиваем отрицательный знак
}


// Katya Sots TRANS_Z_N - Преобразование целого неотрицательного в натуральное

Natural Integer::toNatural() const {
    return Natural{number_}; // возвращаем натуральное число
}

// Katya Sots DIV_ZZ_Z - Частное от деления целого на целое (делитель отличен от нуля)
// Используемые методы - ABS_Z_N POZ_Z_D DIV_NN_N ADD_1N_N
Integer Integer::operator/(const Integer &other) const {
    if(other == Integer{0}) { // если второе число - 0
        throw std::invalid_argument("Деление на 0 невозможно"); 
    }

    if(this->number_.isZero() == true) { // если первое число 0 - результат 0
        return Integer{0}; 
    }

    // вычисляем модуль результата используя деление нацело для натуральных чисел
    Integer result = Integer(this->number_ / other.number_); 

    if(this->sign_ == true) { // если делитель - отрицательный, то добавляем к ответу единицу
        result = result + Integer{1};
    }

    // меняем знак у результата в зависимости от знаков делимого и делителя (sign a XOR sign b)
    result.sign_ = this->sign_ ^ other.sign_;

    return result; // возвращаем полученный результат
}



// Цыганков Роман гр. 2384 SUB_ZZ_Z- Вычитание целых чисел
Integer Integer::operator-(const Integer &other) const {
    int flag = 0; // знак (0 - плюс, 1 - минус)
    Natural number_other = other.abs().number_; //абсолютная часть 2ого числа
    Natural result; // результат

    digit my_cmp = Natural::cmp(number_, number_other); // сравнение

    if (this->isPositive() == 2 && other.isPositive() == 2) { // если оба числа положительные
        if (my_cmp == 2 || my_cmp == 0) { // если первое больше, или они равны
            result = number_ - number_other;
        } else if (my_cmp == 1) { // если второе больше
            result = number_other - number_;
            flag = 1;
        }
    } else if (this->isPositive() == 2 && (other.isPositive() == 1 || other.isPositive() == 0)) {
        // если первое положительное, а второе отрицательное или 0
        result = number_ + number_other;
    } else if (this->isPositive() == 1 &&
               other.isPositive() == 2) { // если первое отрицательное, а второе положительное
        result = number_ + number_other;
        flag = 1;
    } else if (this->isPositive() == 1 && (other.isPositive() == 1 || other.isPositive() ==
                                                                      0)) { // если первое отрицательное, а второе отрицательное или 0
        if (my_cmp == 2) { // если первое больше
            result = number_ - number_other;
            flag = 1;
        } else if (my_cmp == 1 || my_cmp == 0) {// если первое меньше, или числа равны
            result = number_other - number_;
        }
    } else if (this->isPositive() == 0 && other.isPositive() == 2) { // если первое 0, а второе положительное
        result = number_other;
        flag = 1;
    } else { // если первое 0, а второе отрицательное или 0
        result = number_other;
    }

    Integer result_integer(result); // создаем объект класса
    if (flag == 1) {
        result_integer = result_integer.negative(); // указываем минус
    }
    return result_integer; // возвращаем значение
}

// Цыгулев Станислав MUL_ZM_Z - Умножение целого на (-1)
Integer Integer::negative() const {
    if (this->isPositive() == 0)
        return *this;
    Integer answer(*this); // копируем число
    answer.sign_ = !answer.sign_; // меняем знак числа
    return answer; // возвращаем новое число
}

// Valeyeva Alina ADD_ZZ_Z - Сложение целых чисел(используемые методы: POZ_Z_D, ABS_Z_N, COM_NN_D, ADD_NN_N, SUB_NN_N, MUL_ZM_Z)
Integer Integer::operator+(const Integer &other) const {
    if (this->isPositive() == 0)
        return other;
    if (other.isPositive() == 0)
        return *this;

    Natural number_other = other.abs().number_; // получаю абсолютную часть второго числа (ABS_Z_Z)
    digit my_cmp = Natural::cmp(number_, number_other); // сравниваю два натуральных числа (COM_NN_D)

    // если числа положительные или равны 0 (POZ_Z_D)
    if (other.isPositive() == 2 && this->isPositive() == 2) {
        return Integer(number_ + other.number_);//  Складываю два натуральных числа без модуля, т.к. положительные
    }
        // если оба числа отрицательные
    else if (other.isPositive() == 1 && this->isPositive() == 1) {
        return Integer(number_ + other.number_).negative();// меняем знак на минус, домножая на (-1) MUL_ZM_Z
    }
        // Если одно число положительное, а другое отрицательное
    else {
        switch (my_cmp) {
            case 0:  // если равны
                return Integer(number_ - number_other); // (SUB_NN_N)
            case 1:// если первое < второго
                if (this->isPositive() == 2) { // первое +
                   return Integer(number_other - number_).negative(); // вычитаю из второго первое(SUB_NN_N)
                } else if (this->isPositive() == 1) { // если при этом первое - отрицательное (второе полож)
                    return Integer(number_other - number_); // вычитаю из второго первое(SUB_NN_N)
                }
            case 2: // если первое > второго
                if (this->isPositive() == 2) { // если при этом первое - положительное (второе отр)
                    return Integer(number_ - number_other); // вычитаю из первого второе(SUB_NN_N)
                } else if (this->isPositive() == 1) { // если при этом первое - отрицательное (второе полож)
                    return Integer(number_ - number_other).negative(); // вычитаю из первого второе(SUB_NN_N) и нужно поменять знак у моего возвращаемого целого числа на минус
                }
        }
    }
    return Integer(0);
}

// Мирон Возгрин 2382; Остаток от деления целого на целое (MOD_ZZ_Z)
Integer Integer::operator%(const Integer &other) const {
    //проверка на деление на 0
    if (other == Integer(0)) throw std::invalid_argument("Деление на 0 невозможно!");
    // Возвращаемое значение равно разности левого числа и произведения правого на разность деления 2 чисел
    return *this - (other * (*this / other));
}

bool Integer::operator==(const Integer &other) const {
    return number_ == other.number_ && sign_ == other.sign_;
}

bool Integer::operator!=(const Integer &other) const {
    return !(*this == other);
}
