//
// Created by lipmip on 05.11.2023.
//
#include "../../Polynomial.h"


// P-2
// Вычитание многочленов
// SUB_PP_P
// Ильин Павел 2383
[[nodiscard]] Polynomial Polynomial::operator-(const Polynomial &other) const {
    // копируем коэфы для изменяемого числа
    std::vector<Rational> new_coefs = coefficients_;
    // приводим к одной длине с вычитаемым числом, если то больше
    while (new_coefs.size() < other.degree_+1) {
        new_coefs.insert(new_coefs.begin(), Rational(0, 1));
    }
    // проводим вычитание коэфов в соответствии с их принадлежностью к степени
    size_t indexShift = new_coefs.size() - other.degree_-1;
    for (size_t i = other.degree_+1; i > 0; i--) {
        new_coefs[indexShift + i-1] = new_coefs[indexShift + i-1] - other.coefficients_[i-1];
    }
    // удаляем крайние слева коэфы, если он равны нулю, в случае многочлена равного нулю, вектор будет в виде [0/1]
    while (new_coefs.size() > 1 && new_coefs[0] == Rational (0, 1)) {
        new_coefs.erase(new_coefs.begin());
    }
    // возвращаем измененный многочлен
    return Polynomial(new_coefs);
}


// P-10
// Остаток от деления многочлена на многочлен при делении с остатком
// MOD_PP_P
// Ильин Павел 2383
[[nodiscard]] Polynomial Polynomial::operator%(const Polynomial &other) const {
    // копируем коэфы для изменения
    std::vector<Rational> coefsForDivisor = coefficients_;
    // создаем на их основе делимое число
    Polynomial firstDivisor(coefsForDivisor);
    // вычисляем остаток и тут же возвращаем
    return firstDivisor - (firstDivisor/other)*other;
}
