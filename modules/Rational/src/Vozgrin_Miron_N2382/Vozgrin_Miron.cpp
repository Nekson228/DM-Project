#include"../../Rational.h"

// Мирон Возгрин 2382; оператор деления для дробей (DIV_QQ_Q)
Rational Rational::operator/(const Rational &other)const{

    if(numerator_.isPositive()==0) std::invalid_argument("Деление на ноль невозможно"); // проверка делимой дроби на равенство 0

    Integer subNumeratorRight(other.denominator_);                          //вспомогательное целое число равное модулю числитея правой дроби

    Integer newNominator = numerator_ * subNumeratorRight;                  //новый числитель. Произведение левого числителя и правого знаменателя
    Natural newDenominator = denominator_ * other.numerator_.toNatural();   //новыйз знаминатель. Произведение левого знаминателя и правого числителя
                                                                            //так как все числа были лишены знака, предстоит провести проверку входных данных и присвоить нужный знак возвращаемому значению
    if ((numerator_.isPositive()==1 and other.numerator_.isPositive()==1) or (numerator_.isPositive()==-1 and other.numerator_.isPositive()==-1)){
        Rational rat(newNominator, newDenominator);
        return rat;
    }
    else{
        newNominator.negative();
        Rational rat(newNominator, newDenominator);
        return rat;
    }
}
