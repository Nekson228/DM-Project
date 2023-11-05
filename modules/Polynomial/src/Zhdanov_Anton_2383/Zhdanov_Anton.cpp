#include "../../Polynomial.h"
/*
MUL_PQ_P
P - 3
Умножение полинома на рациональное число
Жданов Антон 2383
*/
[[nodiscard]] Polynomial Polynomial::scale(const Rational &scalar) const
{
    if (scalar == Rational(0,1))                       // если скаляр равен 0, то при умножении на многочлен
    {                                                  // остается многочлен степени 0, с коэффицентом Rational(0,1)
        std::vector<Rational> new_coeff{Rational(0,1)};// => создаем вектор с 1 элементом и из него создаем многочлен
        Polynomial new_coefficients_(new_coeff);
        return new_coefficients_;
    }

    std::vector <Rational> new_coeff(this->degree_+1); // создаем вектор для новых коэффицентов
    
    for (int i = 0; i < this->degree_+1; i++)
    {
        new_coeff[i] = this->coefficients_[i]*scalar; // записываем в вектор новые коэффиценты у множенные на скаляр
    }
    
    Polynomial new_coefficients_(new_coeff); // создаем многочлен с новыми коэффицентами и возвращаем его
    return new_coefficients_;
}

/*
DEG_P_N
P - 6
Возвращение степени многочлена
Жданов Антон 2383
*/
[[nodiscard]] std::size_t Polynomial::getDegree() const 
{
    return this->degree_; // возвращаем степень многочлена
}

/*
GCF_PP_P
P - 11
НОД двух многочленов
Жданов Антон 2383
*/
[[nodiscard]] Polynomial Polynomial::gcd(const Polynomial &a, const Polynomial &b)
{
    Polynomial first = a.degree_ >= b.degree_ ? a : b; // Сортируем многочлены по степени 
    Polynomial second = a.degree_ < b.degree_ ? b : a; // где first - многочлен степени больше или равной second

    Polynomial ost1{first%second}; // находим остаток от деления первого на второй
    if (ost1.coefficients_[0] == Rational(0,1)) // если остаток равен нулю, значит НОД - это second
        return second;
    Polynomial ost2{second%ost1}; // находим остаток от деления второго на ost1
    // цикл пока один из остатков не равен нулю
    while (ost1.coefficients_[0] != Rational(0,1) and ost2.coefficients_[0] != Rational(0,1))
    {
        ost1 = ost1 % ost2;
        if (ost1.coefficients_[0] == Rational(0,1)) // если остаток равен нулю, значит НОД - это ost2
            return ost2;
        ost2 = ost2 % ost1; // продолжаем делить с остатком
    }
    return ost1; // если цикл завершился и не вернул ничего => НОД - ost1
}