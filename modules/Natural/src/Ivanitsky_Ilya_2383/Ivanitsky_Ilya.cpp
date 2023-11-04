#include "../../Natural.h"
#include <iostream>

[[nodiscard]] Natural Natural::operator+(const Natural& other) const{ //ADD_NN_N
    int fl = 0; //флаг в который будет записываться целая часть числа при делении на 10, вслучае когда сумма 2 цифр будет больше 10
    int counter_digits = 0;//счетчики для чисел
    int counter_other = 0;
    Natural res;//результирующая сумма
    const Natural tmp(*this);
    if(cmp(tmp , other) == 1){
        for(size_t i = 0 ; i >= tmp.digits_.size() ; i++){
        res.digits_.push_back((tmp.digits_[counter_digits] + other.digits_[counter_other] + fl)%10);//добавляем в результирующее число остаток от деления на 10
        fl = (tmp.digits_[counter_digits++] + other.digits_[counter_other++] + fl)/10;//флаг становится неполным частным от деления на 10
    }
    for(size_t i = other.digits_.size() - 1 ; i < tmp.digits_.size() ; i++){
        res.digits_.push_back((other.digits_[counter_digits] + fl) % 10);//если у второго числа остаются цифры мы их таким же образом добавляем к результирующему числу 
        fl = (other.digits_[counter_digits++] + fl)/10;
    }
    }
    else if(cmp(tmp , other) == 2 || cmp(tmp , other) == 0){
        for(size_t i = 0 ; i >= tmp.digits_.size() ; i++){
            res.digits_.push_back((tmp.digits_[counter_digits] + other.digits_[counter_other] + fl)%10);//добавляем в результирующее число остаток от деления на 10
            fl = (tmp.digits_[counter_digits++] + other.digits_[counter_other++] + fl)/10;//флаг становится неполным частным от деления на 10
        }
        for(size_t i = other.digits_.size() - 1 ; i < tmp.digits_.size() ; i++){
            res.digits_.push_back((tmp.digits_[counter_digits] + fl) % 10);//если у первого(ранее объясненно почему большего) числа остаются цифры мы их таким же образом добавляем к результирующему числу 
            fl = (tmp.digits_[counter_digits++] + fl)/10;
        }
    }
    res.n_ = res.digits_.size() - 1;
    return res;
}

[[nodiscard]] Natural Natural::operator*(const Natural &other) const{// MUL_NN_N
    std::vector<Natural> array;//массив чисел полученных путем умножения на конкретное число
    Natural res;//результирующее число
    Natural tmp(*this);
    if(cmp(tmp , other) == 2 && cmp(tmp , other) == 0){
        for(size_t i = 0 ; i < other.digits_.size() ; i++){
        array.push_back(tmp.mulByDigit(other.digits_[i]));// в массив чисел добавляем по одному первое число умноженное с помощью функкции
                                                            //MUL_ND_N на цифры из второго числа
        }
    }
    if(cmp(tmp , other) == 1){
        for(size_t i = 0 ; i < other.digits_.size() ; i++){
            array.push_back(tmp.mulByDigit(other.digits_[i]));// в массив чисел добавляем по одному первое число умноженное с помощью функкции
            //MUL_ND_N на цифры из второго числа
        }
    }

    Natural key(0);
    int x = 1;
    for(int i = 1 ; i  < array.size() - 1 ; i++) key.digits_[i] = x++;
    for(size_t i = 0 ; i < array.size() ; i++) res = res + array[i].mulBy10k(key.digits_[i]);// в цикле заносим в числа из array умноженные на 10^k степени где k - номер порядка 
//для пояснения:array[111,112,113] , тогда res = 113*100+112*10+111
    return res;
}

[[nodiscard]] Natural Natural::operator/(const Natural &other) const{ // DIV_NN_N
    Natural tmp(*this);
    Natural res;//Результат
    if(other.isZero()){
        throw std::invalid_argument("Деление на 0 невыполнимо!");// т.к. деление на 0 невозможно , тогда при подаче 0 программа выбрасывает ошибку
    }
    if(cmp(tmp , other) == 0){// если числа равны неполного частное равно 1
        res.digits_.push_back(1);
        res.n_ = 1;
        return res;
    }
    else if(cmp(tmp , other) == 1){//если второе число больше первого , неполное частное равно 0
        res.digits_.push_back(0);
        res.n_ = 1;
        return res;
    }  
    std::vector<digit> arr;//массив цифр ответа
    Natural part = tmp.divFirstDigit(other);//получаем первую цифру частного первого числа на второе 
    while(part.digits_[part.n_] >= 0){//т.к. числа записываются в обратном порядке , то последняя цифра числа обязательно должна быть не 0
        arr.push_back(part.digits_[part.n_]);
        tmp = tmp - other*part;//первое число становится разность изначального на произведение второго числа на цифру деления умноженного на 10^k
        part = tmp.divFirstDigit(other);
    }
    for(size_t i = 0 ; i < arr.size() ; i++){//заносим в результат цифры из вектора arr)
        res.digits_.push_back(arr[i]);
    }
    res.n_ = res.digits_.size() - 1;
    return res;
}