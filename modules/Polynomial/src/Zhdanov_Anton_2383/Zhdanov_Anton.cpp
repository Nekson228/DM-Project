#include "../../Polynomial.h"

[[nodiscard]] Polynomial Polynomial::scale(const Rational &scalar) const // MUL_PQ_P
{
    std::vector <Rational> new_coeff(this->degree_+1); // создаем вектор для новых коэффицентов
    
    for (int i = 0; i < this->degree_+1; i++)
    {
        new_coeff[i] = this->coefficients_[i]*scalar; // записываем в вектор новые коэффиценты у множенные на скаляр
    }
    
    std::size_t degree = this->degree_;
    std::size_t i = 0;
    while (i < degree) // удаляем нулевые коэффиценты
    {
        if (new_coeff[i] == Rational(0,1))
        {
            new_coeff.erase(new_coeff.begin()+i); // если коэф равен нулю => удаляем его
            degree -= 1;                          // итератор при этом не меняем
            continue;                             // степень многочлена уменьшаем
        }                                         // тк итератор идет до степени многочлена
        i += 1;                                   // свободный член будет оставаться 
    }                                             // и в случае при умножении на 0 будет равен 0

    Polynomial new_coefficients_(new_coeff); // создаем многочлен с новыми коэффицентами и возвращаем его
    new_coefficients_.degree_ = degree;
    return new_coefficients_;
}


[[nodiscard]] std::size_t Polynomial::getDegree() const // DEG_P_N
{
    return this->degree_; // возвращаем степень многочлена
}

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