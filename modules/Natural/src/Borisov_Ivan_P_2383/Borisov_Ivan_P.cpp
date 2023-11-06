//Борисов Иван Павлович 2383, N-6, MUL_ND_N, умножение натурального числа на цифру

Natural Natural:: mulByDigit(const digit multiplier) const
{
    if(multiplier == 0){ //если множитель равень нул, то натуральное число равно нулю
        Natural number(0);
        return number;
    }
    Natural number(*this); //создаем копию от данного объекта
    int discharge = 0; //разряды. используется, если результат умножения затрагивает и следующий разряд 
    int add; //число, которое получается в результате умножения цифры разряда числа на цифру
    for (size_t i = 0; i<=number.n_; i++)
    {
        add = number.digits_[i]*multiplier+ discharge; //добавляется discharge- часть результата прошлого умножения, относящаяся к новому разряду
        number.digits_[i] = (add)%10;
        discharge = add/10; 
    }
    if (discharge!=0) number.digits_.push_back(discharge); //если в результате умножения число стало на разряд больше

    return number;
}

//Борисов Иван Павлович 2383, N-9, SUB_NDN_N, вычитание натурального числа, умноженного на цифру

Natural Natural:: subScaled(const Natural &other, digit k) const
{
    Natural number (*this); //создаём копии объектов
    Natural other_num(other);

    other_num = other_num.mulByDigit(k); //умножаем вычитаемое на цифру

    number = number - other_num; //производим вычетание


    return number;
}

//Борисов Иван Павлович 2383, N-12, MOD_NN_N, Остаток от деления первого натурального числа на второе натуральное (делитель отличен от нуля)
Natural Natural:: operator%(const Natural &other) const
{
    Natural number(*this); 

    if(cmp(number, other) == 1) return number; //если делимое меньше делителя возвращаем делимое

    Natural quotient = number/other; //целочисленно делим число на второе, остаток деления на которое мы ищем

    Natural res = number.subScaled(other, quotient); //вычилсляем остаток от деления

    return res;
}