#include "../../Polynomial.h"


/*
Дамакин Роман гр2384
Функция P-8: Умножение многочленов
*/
Polynomial& Polynomial::operator*(const Polynomial &other) const{ // MUL_PP_P
    int k = other.degree_; // Степень многочлена
    // Создаем переменную для записи результата и записываем туда результат умножения первого многочлена на свободный коэффициент второго многочлена
    Polynomial result = Polynomial(this->scale(other.coefficients_[k]));
    while (k > 0){ // Цикл по степеням многочлена
        k--; // Уменьшаем степень
        // Прибавляем к результату результат умножения первого многочлена на очередной составляющий одночлен второго многочлена
        result = result + this->scale(other.coefficients_[k]).mulByXk(other.degree_ - k);
    }
    return result;
}
