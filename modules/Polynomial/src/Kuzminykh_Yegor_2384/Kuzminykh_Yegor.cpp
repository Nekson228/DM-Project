#include "../../Polynomial.h"


//Написал функцию - Кузьминых Егор
//ADD_PP_P (операция сложения многочленов, короткий номер - P1)
[[nodiscard]] Polynomial Polynomial::operator+(const Polynomial &other) const {

    // в maxDegree храню итоговую (макс) степень сложения двух многочленов,
    std::size_t maxDegree = std::max(degree_, other.degree_);
    //Создал вектор, в котором буду хранить коэффы от результата сложения, заполнил его нулями
    std::vector<Rational> resultCoefficients(maxDegree + 1, Rational(0, 1));

    // Складываем коэффициенты многочленов
    //В первом цикле мы просто добавляем в массив с коэффами коэффы при первом многочлене
    for (std::size_t i = 0; i <= degree_; i++) {
        resultCoefficients[i] = coefficients_[i];
    }
    //Во втором цикле мы складываем коэффы второго многочлена с коэффами в resultCoefficients
    for (std::size_t i = 0; i <= other.degree_; i++) {
        resultCoefficients[i] = resultCoefficients[i] + other.coefficients_[i];// Использование метода (ADD_QQ_Q)
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

        Polynomial term = other.mulByXk(k).scale(factor);//домножили на x^k, использование метода (MUL_Pxk_P)
        quotient = quotient + term;// увеличили частное, использование метода (ADD_PP_P)

        remainder = remainder - term;//Поменяли остаток, сделали меньше
    }

    return quotient;
}

//Написал функцию - Кузьминых Егор
//DER_P_P (Производная многочлена, короткий номер - P12)
Polynomial Polynomial::derivative() const {
    //Создали вектор для хранения коэфициентов
    std::vector<Rational> derivativeCoefficients(degree_, Rational(0, 1));

    for (std::size_t i = 1; i <= degree_; i++) {//домножаю коэффициент на степень
        derivativeCoefficients[i - 1] = coefficients_[i] * Rational(i, 1);
    }
    Polynomial result = Polynomial(derivativeCoefficients);//создаю новый многочлен и возвращаю его

    return result;
}