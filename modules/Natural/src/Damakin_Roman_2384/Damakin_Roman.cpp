#include "../../Natural.h"

/*
Дамакин Роман гр2384
Функция N-10: Вычисление первой цифры деления большего натурального на меньшее, домноженной на 10^k,где k - номер позиции этой цифры (номер считается с нуля)
*/
Natural& Natural::divFirstDigit(const Natural &other) const{ // DIV_NN_Dk
    if ((Natural::cmp(*this, Natural(0)) == 0) || (Natural::cmp(other, Natural(0)) == 0)){ // Проверка, что числа не нули
        Natural nullNum = Natural(0); // Возвращаем 0 если какое то из чисел ноль
        return nullNum;
    }
    bool cmpFlag = Natural::cmp(*this, other); // Сравниваем два числа
    // Записываем большее в larger, меньшее в smaller
    Natural* larger;
    Natural* smaller;
    if (cmpFlag >= 0){
        *larger = Natural(*this);
        *smaller = Natural(other);
    } else {
        *larger = Natural(other);
        *smaller = Natural(*this);
    }
    // Создаем счетчик номера позиции первой цифры
    int k = 1;
    // Пока меньшее число, домноженное на 10^k, меньше большего, увеличиваем k
    while (Natural::cmp(*larger, smaller->mulBy10k(k)) >= 0){ 
        k++;
    }
    k--; // Посчитали k, при котором меньшее, домноженное на 10^k, стало больше большего и вычли единицу
    *smaller = smaller->mulBy10k(k); // Домножили меньшее на 10^k
    Natural firstDigit = Natural(0); // Создали перемемнную для подсчета старшего разряда частного и положили туда 0
    // Запускаем цикл и вычитаем из большего меньшее до тех пор, пока большее не станет меньше меньшего
    while (Natural::cmp(*larger, *smaller) >= 0){
        *larger = *larger - *smaller;
        firstDigit = firstDigit.addOne(); // Увеличиваем исходное значение на 1
    }
    // Возвращаем в качестве результата первую цифру (старший разряд частного), домноженную на 10^k, где k - номер позиции этой цифры (разряд)
    return firstDigit.mulBy10k(k);
}
