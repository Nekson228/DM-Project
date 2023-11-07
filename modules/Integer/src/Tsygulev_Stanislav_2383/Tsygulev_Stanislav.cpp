#include "../../Integer.h"

// Цыгулев Станислав MUL_ZM_Z - Умножение целого на (-1)

Integer Integer :: negative() const {
    Integer answer(*this); // копируем число
    answer.sign_ = !answer.sign_; // меняем знак числа
    return answer; // возвращаем новое число
}