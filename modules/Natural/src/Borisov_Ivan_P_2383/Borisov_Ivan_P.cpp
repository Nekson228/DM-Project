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

    for (size_t i = 0; i<=other_num.n_; i++){ //вычитание будет производиться до последнего разряда второго числа
        if(number.digits_[i] < other_num.digits_[i]) //если цифра разряда первого числа меньше второго
        {   
            number.digits_[i]+=10; //добавляем десяток "занимаемый" из старшего разряда
            size_t j = i+1;
            if(number.digits_[j] == 0){
                while (number.digits_[j]==0) //пока цифры старших разрядов равны нулю, записываем 9, так как мы занимаем из следующего, и предыдущему даём из данного
                {
                    number.digits_[j] = 9;
                    j++;
                }
                number.digits_[j] -= 1; //разряд из которого "заняли" предыдущие
            }
            else number.digits_[j] -= 1; //если цифра следующего разряда не равна ноль, то мы просто занимаем у него
        }
        number.digits_[i] -= other_num.digits_[i]; //производим вычетание
    }
    for(int i = number.n_; number.digits_[i]==0; i--){   //если у числа стало меньше разрядов убираем их
        number.digits_.pop_back(); 
    }

    return number;
}

//Борисов Иван Павлович 2383, N-12, MOD_NN_N, Остаток от деления первого натурального числа на второе натуральное (делитель отличен от нуля)
Natural Natural:: operator%(const Natural &other) const
{
    Natural number(*this); 

    if(cmp(number, other) == 1) return number; //если делитель меньше делимого возвращаем делитель

    Natural quotient = number/other; //целочисленно делим число на второе, остаток деления на которое мы ищем

    Natural op = quotient*other; //находим произведение частного и делителя

    Natural res = number.subScaled(op, 1); //вычилсляем остаток от деления

    return res;
}