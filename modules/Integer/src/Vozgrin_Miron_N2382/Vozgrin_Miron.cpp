#include"../../Integer.h" //MOD_ZZ_Z

Integer &count(const Integer &z1,const Integer &z2){
    Integer sub(z1 / z2);       // функция для вычисления остатка 2 положительных целых чисел
    sub = sub * z2;
    sub = z1 - sub;
    return sub;
}

Integer Integer::operator%(const Integer &other)const{
    Integer z1(this->number_);
    Integer z2(other.number_);

    if ((z1.isPositive() and z2.isPositive()) or (not z1.isPositive() and not z2.isPositive())){  // при условии, что у 2 чисел одинаковый знак выполняется функция поиска остатка
        return count(z1, z2);
    }
    else if (not z1.isPositive()){     // в зависимости от того, какое из 2 чисел имеет - выполняется функция.
        z1.negative();                 // при возврате значения учитывается знак
        return count(z1, z2);
    }
    else{ 
        z2.negative();
        return count(z1, z2);
    }
}
