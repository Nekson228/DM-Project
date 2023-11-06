#include "../../Natural.h"

//Гурков Арсений 2384, N-2, Проверка на ноль: если число не равно нулю, то «да» иначе «нет», NZER_N_B
bool Natural::isZero() const {
  return digits_[digits_.size() - 1] == 0;
  // это проверка того, что последний элемент массива - это 0 (проверяем последний  элемент, т.к 
  // числа хранятся в массиве в обратном порядке)
  
}


// Гурков Арсений 2384, N-1, COM_NN_D, Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе
digit Natural::cmp(const Natural& a, const Natural& b) {
  
  // если размер массива, в котором хранится число A < размера массива, в котором хранится число B,
  // то А < B гарантированно => выводим 1
  if (a.digits_.size() < b.digits_.size()) {
    return 1;
  }
  // если длина массива A > длины массива B => аналогично А > B => выводим 2
  else if (a.digits_.size() > b.digits_.size()) {
    return 2;
  }

  // если длина массива A = длине массива B, то нужно уже проверять по разрядам чисел
  // делаем это в цикле for начиная со старшего разряда, т.е с конца массива,
  // и идем до до начала массива, сравнивая цифры в каждом разряде
  for (int64_t i = static_cast<int64_t>(a.digits_.size() - 1); i >= 0; --i) {
    // если какая-то цифра из разряда A оказалась < цифры из того же разряда B, то А < B => возвращаем 1
    if (a.digits_[i] < b.digits_[i]) {
      return 1;
    } 
    // если цифры в разряде равны, то продолжаем проверку на следующем разряде
    else if (a.digits_[i] == b.digits_[i]) {
      continue; // переходим на новую итерацию 
    }
    // иначе, остался лишь случай: цифра из разряда A оказалась > цифры из того же разряда =>
    // A > B => возвращаем 2
    return 2;
  }

  // сюда попадем только если A = B => возвращаем 0
  return 0;
}