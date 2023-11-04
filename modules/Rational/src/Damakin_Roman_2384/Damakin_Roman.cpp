#include "../../Rational.h"


/*
Дамакин Роман гр2384
Функция Q-2: Проверка на целое, если рациональное число является целым, то «да», иначе «нет»
*/
bool Rational::isInteger() const{ // INT_Q_B
    Natural denominator = this->reduce().getDenominator(); // Получаем знаменатель сокращенной дроби
    Natural oneNum = Natural(1); // Создаем "натуральную" единицу
    return Natural::cmp(denominator, oneNum) == 0; // Сравниваем знаменатель сокращенной дроби с единицей, если равно, возвращаем true
}


/*
Дамакин Роман гр2384
Функция Q-6: Вычитание дробей
*/
[[nodiscard]] Rational Rational::operator-(const Rational &other) const{ // SUB_QQ_Q
    // Скоращаем дроби
    Rational minuend = this->reduce(); // Уменьшаемое
    Rational subtrahend = other.reduce(); // Вычитаемое
    Rational* difference; // Разность
    // Проверяем равенство знаменателей уменьшлаемого и вычитаемого
    bool isDenominatorsEqual = (Natural::cmp(minuend.getDenominator(), subtrahend.getDenominator()) == 0);
    if (isDenominatorsEqual){ // Если знаменатели равны
        Natural newDenominator = minuend.getDenominator(); // Фиксируем знаменатель
        *difference = Rational(minuend.getNumerator() - subtrahend.getNumerator(), newDenominator); // Записыываем результат
    } else {
        Natural minuendDenominator = minuend.getDenominator(); // Получаем знаменатель уменьшаемого
        Natural subtrahendDenominator = subtrahend.getDenominator(); // Получаем знаменатель вычитаемого
        Natural newDenominator = Natural::lcm(minuendDenominator, subtrahendDenominator); // Ищем НОК - фиксируем как получившийся знаменатель
        Integer minuendNumerator = Integer(newDenominator/minuendDenominator) * minuend.getNumerator(); // Считаем новый числитель уменьшаемого
        Integer subtrahendNumerator = Integer(newDenominator/subtrahendDenominator) * subtrahend.getNumerator(); // Считаем новый числитель вычитаемого
        *difference = Rational(minuendNumerator - subtrahendNumerator, newDenominator); // Записыываем результат
    }
    *difference = difference->reduce(); // Сокращаем полученный результат
    return *difference;
}
