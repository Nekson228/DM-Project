#include "../../Polynomial.h"
#include <stdexcept>

//Написал функцию - Кузьминых Егор
//ADD_PP_P (операция сложения многочленов, короткий номер - P1)
[[nodiscard]] Polynomial Polynomial::operator+(const Polynomial &other) const {

    // в maxDegree храню итоговую (макс) степень сложения двух многочленов,
    std::size_t maxDegree = std::max(degree_, other.degree_);
    //Создал вектор, в котором буду хранить коэффы от результата сложения, заполнил его коэфами с первого многочлена
    std::vector<Rational> resultCoefficients = coefficients_;

    // Складываем коэффициенты многочленов
    //В первом цикле мы просто добавляем в массив с коэффами коэффы при первом многочлене
    while (resultCoefficients.size() < other.coefficients_.size()) {
        resultCoefficients.insert(resultCoefficients.begin(), Rational(0, 1));
    }

    //складываем коэффы из второго многочлена с новыми
    for (std::size_t i = 0; i < other.degree_; i++) {
        resultCoefficients[maxDegree - other.degree_ + i] = resultCoefficients[maxDegree - other.degree_ + i] +
                                                            other.coefficients_[i];// Использование метода (ADD_QQ_Q)
    }

    // Создаем новый многочлен с полученными коэффами и возвращаем его
    Polynomial result = Polynomial(resultCoefficients);
    return result;
}


//Написал функцию - Кузьминых Егор
//DIV_PP_P (операция получения частного от деления многочлена на многочлен при делении с остатком, которткий номер - P9)
[[nodiscard]] Polynomial Polynomial::operator/(const Polynomial &other) const {
    //Создал вектор c одним нулевым коэффициентом, будет использоваться, если частное от деления ноль и в дальнейших операциях
    std::vector<Rational> resultCoefficients(1, Rational(0, 1));
    Polynomial quotient = Polynomial(resultCoefficients); // Частное от деления
    Polynomial remainder(*this); // Остаток от деления
    if (other.coefficients_[0].getNumerator() == Integer(0)) {
        throw std::invalid_argument("Деление на ноль невозможно");
    }
    if (degree_ < other.degree_) {
        // Если степень делителя больше степени делимого, возвращаем ноль (частное на данный момент)
        return quotient;
    }

    //Цикл действует, пока степень остатка от деления будет больше, чем степень делителя
    while (remainder.degree_ >= other.degree_) {
        std::size_t k = remainder.getDegree() -
                        other.getDegree();//вычислили степень на данном шагу, использование метода (DEG_P_N)
        Rational factor = remainder.leading() /
                          other.leading();//вычислили коэфф при старшей степени, Использование метода (DIV_QQ_Q)
        std::vector<Rational> coef(1, Rational(1, 1));
        Polynomial polynomial = Polynomial(coef);
        Polynomial term = polynomial.mulByXk(k).scale(factor);//домножили на x^k, использование метода (MUL_Pxk_P)
        quotient = quotient + term;// увеличили частное, использование метода (ADD_PP_P)

        remainder = remainder - term * other;//Вычислили остаток
    }

    return quotient;
}

//Написал функцию - Кузьминых Егор
//DER_P_P (Производная многочлена, короткий номер - P12)
Polynomial Polynomial::derivative() const {
    //Создали вектор для хранения коэфициентов
    std::vector<Rational> derivativeCoefficients(degree_, Rational(0, 1));

    for (std::size_t i = 0; i <= degree_ - 1; i++) {//домножаю коэффициент на степень
        derivativeCoefficients[i] = coefficients_[i] * Rational((degree_ - i), 1);

    }
    Polynomial result = Polynomial(derivativeCoefficients);//создаю новый многочлен и возвращаю его

    return result;
}