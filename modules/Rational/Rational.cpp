#include "Rational.h"
#include "../utils/utils.h"

#include <stdexcept>
#include <utility>

Rational::Rational(Integer numerator, Natural denominator) :
        numerator_(std::move(numerator)), denominator_(std::move(denominator)) {
    checkDenominator();
}

Rational::Rational(std::int64_t numerator, std::size_t denominator) :
        Rational(Integer(numerator), Natural(denominator)) {
}

Rational::Rational(const std::string &str_number) {
    std::string trimmed_str_number = utils::trim(str_number);
    std::size_t slash_sign = trimmed_str_number.find('/');
    if (slash_sign == 0)
        throw std::invalid_argument("No numerator specified.");
    else if (slash_sign == trimmed_str_number.size() - 1)
        throw std::invalid_argument("No denominator specified.");
    if (slash_sign != std::string::npos)
        denominator_ = Natural{trimmed_str_number.substr(slash_sign + 1)};
    numerator_ = Integer(trimmed_str_number.substr(0, slash_sign));
    checkDenominator();
}

std::string Rational::str() const {
    if (denominator_ == Natural{1})
        return numerator_.str();
    return numerator_.str() + "/" + denominator_.str();
}

const Integer &Rational::getNumerator() const {
    return numerator_;
}

const Natural &Rational::getDenominator() const {
    return denominator_;
}

std::string Rational::getSign() const {
    if (numerator_.isPositive() == 2)
        return "+";
    else if (numerator_.isPositive() == 1)
        return "-";
    return "";
}

Rational Rational::abs() const {
    Rational res = *this;
    res.numerator_ = res.numerator_.abs();
    return res;
}

bool Rational::isZero() const {
    return numerator_.isPositive() == 0;
}

void Rational::checkDenominator() {
    if (denominator_.isZero())
        throw std::invalid_argument("Denominator should be non zero");
}

// Bormatov Yaroslav TRANS_Q_Z - Преобразование сокращенного дробного в целое (если знаменатель равен 1)
Integer Rational::toInteger() const {
    Rational tmp = reduce(); // Сокращение дроби
    if (Natural::cmp(tmp.denominator_, Natural{1}) == 0) { // проверка на то, является ли знаменатель равным 1
        return tmp.numerator_;
    } else {
        throw std::invalid_argument("Преобразование в \"Integer\" невозможно");
    }
}

/*
Дамакин Роман гр2384
Функция Q-2: Проверка на целое, если рациональное число является целым, то «да», иначе «нет»
*/
bool Rational::isInteger() const { // INT_Q_B
    Natural denominator = this->reduce().getDenominator(); // Получаем знаменатель сокращенной дроби
    Natural oneNum = Natural(1); // Создаем "натуральную" единицу
    // Сравниваем знаменатель сокращенной дроби с единицей, если равно, возвращаем true
    return Natural::cmp(denominator, oneNum) == 0;
}


/*
Дамакин Роман гр2384
Функция Q-6: Вычитание дробей
*/
[[nodiscard]] Rational Rational::operator-(const Rational &other) const { // SUB_QQ_Q
    // Скоращаем дроби
    Rational minuend = *this; // Уменьшаемое
    Rational subtrahend = other; // Вычитаемое
    Rational difference; // Разность
    // Проверяем равенство знаменателей уменьшлаемого и вычитаемого
    bool isDenominatorsEqual = (Natural::cmp(minuend.getDenominator(), subtrahend.getDenominator()) == 0);
    if (isDenominatorsEqual) { // Если знаменатели равны
        const Natural &newDenominator = minuend.getDenominator(); // Фиксируем знаменатель
        difference = Rational(minuend.getNumerator() - subtrahend.getNumerator(),
                               newDenominator); // Записыываем результат
    } else {
        Natural newDenominator = Natural::lcm(minuend.getDenominator(),
                                              subtrahend.getDenominator()); // Ищем НОК - фиксируем как получившийся знаменатель
        Integer minuendNumerator = Integer(newDenominator / minuend.getDenominator()) *
                                   minuend.getNumerator(); // Считаем новый числитель уменьшаемого
        Integer subtrahendNumerator = Integer(newDenominator / subtrahend.getDenominator()) *
                                      subtrahend.getNumerator(); // Считаем новый числитель вычитаемого
        difference = Rational(minuendNumerator - subtrahendNumerator, newDenominator); // Записыываем результат
    }
    return difference.reduce();
}

//Написал функцию - Кузьминых Егор
//ADD_QQ_Q (Сложение дробей, короткий номер - Q5)
[[nodiscard]] Rational Rational::operator+(const Rational &other) const {
    // Находим НОК знаменателей, т.е. новый знаменатель
    Natural lcm = Natural::lcm(denominator_, other.denominator_);// Использование метода (LCM_NN_N)

    // Считаем коэфы, на которые будем домножать числители
    Integer num_1_int = Integer(lcm / denominator_);
    Integer num_2_int = Integer(lcm / other.denominator_);

    //Получаем новые значения числителей, домноженных на num_1_int и num_2_int
    Integer num1 = numerator_ * num_1_int; // Использование метода (MUL_ZZ_Z)
    Integer num2 = other.numerator_ * num_2_int;

    // Складываем числители
    Integer sum = num1 + num2; //использование метода (ADD_ZZ_Z)
    //Создаем новую дробь с новым числителем и знаменателем, возвращаем ее
    return Rational{sum, lcm}.reduce();
}

//Лавренова Юлия гр.2384 TRANS_Z_Q - Преобразование целого в дробное
Rational::Rational(Integer integer) : numerator_(std::move(integer)), denominator_(1) {}
//присваиваем числу абсолютную часть числа, а знаменателю 1

// Valeyeva Alina MUL_QQ_Q - Умножение дробей(используемые методы: MUL_ZZ_Z)
Rational Rational::operator*(const Rational &other) const { // MUL_QQ_Q
    Integer new_numerator = numerator_ * other.numerator_; // умножение числителей через MUL_ZZ_Z
    Natural new_denominator = denominator_ * other.denominator_; // умножение знаменателей

    // Создаем и возвращаем новый объект Rational
    Rational result(new_numerator, new_denominator);
    return result.reduce();
}

// Valeyeva Alina RED_Q_Q - Сокращение дроби(используемые методы: ABS_Z_N, GCF_NN_N, DIV_ZZ_Z )
Rational Rational::reduce() const {
    Natural my_numerator = numerator_.abs().toNatural(); // получили мой числитель в виде натурального неотрицательного числа
    Natural nod = Natural::gcd(my_numerator, denominator_); // получили НОД в виде натур числа

    Integer nod_integer(nod); // НОД в виде целого числа

    // Вычисляем сокращенную дробь
    Integer new_numerator = numerator_ / (nod_integer); // новый числитель (через метод DIV_ZZ_Z)
    Natural new_denominator = denominator_ / nod; // новый знаменатель (через метод DIV_NN_N)

    // Создаем и возвращаем новый объект Rational с сокращенной дробью
    return Rational{new_numerator, new_denominator};
}

// Мирон Возгрин 2382; оператор деления для дробей (DIV_QQ_Q)
Rational Rational::operator/(const Rational &other) const {
    if (other.numerator_.isPositive() == 0) // проверка на равенство делителя нулю
        throw std::invalid_argument("Деление на ноль невозможно");
    //вспомогательное целое число равное модулю числителя правой дроби
    Integer subNumeratorRight(other.denominator_);
    //Новый числитель. Произведение правого знаменателя и левого числителя
    Integer newNominator = numerator_ * subNumeratorRight;
    //Новый знаменатель. Произведение левого знаменателя и правого числителя
    Natural newDenominator = denominator_ * other.numerator_.toNatural();
    //так как все числа были лишены знака,
    //предстоит провести проверку входных данных и присвоить нужный знак возвращаемому значению
    if (other.numerator_.isPositive() == 1)
        return Rational{newNominator.negative(), newDenominator}.reduce();
    return Rational{newNominator, newDenominator}.reduce();
}

bool Rational::operator==(const Rational &other) const {
    return numerator_ == other.numerator_ && denominator_ == other.denominator_;
}

bool Rational::operator!=(const Rational &other) const {
    return !(*this == other);
}
