#include "../../Integer.h"

//Гурков Арсений 2384, Z1, ABS_Z_Z, Абсолютная величина числа
Integer Integer::abs() const
{
    Integer abs_int(number_);    //создание объекта типа Integer с использованием текущего значения, без учета знака
    return abs_int;
}

