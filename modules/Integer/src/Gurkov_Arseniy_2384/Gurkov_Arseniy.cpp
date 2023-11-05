#include "../../Integer.h"

Integer Integer::abs() const
{
    Integer abs_int(number_);    //создание объекта типа Integer с использованием текущего значения, без учета знака
    return abs_int;
}

