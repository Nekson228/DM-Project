#include"../../Rational.h"  // DIV_QQ_Q
Rational Rational::operator/(const Rational &other)const{
    Integer subNumeratorRight(other.denominator_);                      //вспомогательное целое число равное модулю числитея правой дроби

    Integer newNominator = numerator_ * subNumeratorRight;                  //новый числитель. Произведение левого числителя и правого знаменателя
    Natural newDenominator = denominator_ * other.numerator_.toNatural();   //новыйз наминатель. Произведение левого наминателя и правого числителя
                                                                            //так как все числа были лишены знака, предстоит провести проверку входных данных и присвоить нужный знак возвращаемому значению
    if ((numerator_.isPositive() and other.numerator_.isPositive()) or (not numerator_.isPositive() and not other.numerator_.isPositive())){
        Rational rat(newNominator, newDenominator);
        return rat;
    }
    else{
        newNominator.negative();
        Rational rat(newNominator, newDenominator);
        return rat;
    }
}
