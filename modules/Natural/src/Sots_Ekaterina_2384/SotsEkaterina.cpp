#include "../../Natural.h"

// Katya Sots - GCF_NN_N - НОД натуральных чисел
// Используемые методы - MOD_NN_N COM_NN_D NZER_N_B

static Natural gcd(const Natural &a, const Natural &b) { // стандартный алгоритм Евклида для нахождения НОД
    Natural first(a);
    Natural second(b);
    while(!first.isZero() && !second.isZero()) { // while a != 0 && b != 0
        if(first.cmp(first, second) == 2) { // if first > second
            first = first % second;       
        } else {
            second = second % first;       
        }
    }
    return first + second; 
}
