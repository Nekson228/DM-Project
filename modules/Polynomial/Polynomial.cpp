#include "Polynomial.h"

#include <sstream>
#include <map>
#include <algorithm>

#include "../utils/utils.h"

Polynomial::Polynomial(const std::vector<Rational> &coefficients) : coefficients_(coefficients) {
    degree_ = coefficients_.size() - 1;
    removeLeadingZeros();
}

std::string Polynomial::str() const {
    std::ostringstream resStream; // Output stream for the result string
    for (size_t i = 0; i <= degree_; i++) { // Iterate over the coefficients
        const Rational &currCoefficient = coefficients_[i]; // Get the current coefficient
        if (currCoefficient.isZero()) { // If the coefficient is zero
            if (i == 0 && degree_ == 0) // If the degree is zero
                resStream << "0"; // Write zero
            continue; // Skip the coefficient
        }

        if (i == 0) // If the coefficient is the first one
            resStream << (currCoefficient.getSign() == "-" ? "-" : "");
        else // If the coefficient is not the first one
            resStream << (currCoefficient.getSign() == "-" ? " - " : " + ");

        bool coefficientIgnored = currCoefficient.abs() == Rational{1, 1} && i != degree_;

        if (!coefficientIgnored)
            // If the coefficient is not 1, or it is the last one
            resStream << currCoefficient.abs().str(); // Write the absolute value of the coefficient
        if (i < degree_) { // If the coefficient is not the last one
            if (!coefficientIgnored) // If the coefficient is not 1
                resStream << "*"; // Write *
            resStream << "x"; // Write x
            if (i < degree_ - 1) // If the coefficient is not the penultimate one
                resStream << "^" << degree_ - i; // Write the exponent
        }
    }
    return resStream.str();
}

std::vector<std::string> tokenizePolynomial(const std::string &polynomial) {
    size_t start = 0, end = 0; // Start and end positions of the current monomial token
    std::vector<std::string> tokens; // Vector of monomial tokens
    while (end != std::string::npos) {
        // Find the next monomial token
        end = polynomial.find_first_of("+-", start + 1);
        // Add the token to the vector
        tokens.push_back(polynomial.substr(start, end - start));
        // Update the start position
        start = end;
    }
    return tokens;
}

std::tuple<std::string, size_t, char> parseMonomialToken(const std::string &token) {
    size_t x_pos = token.find('x'),
            caret_pos = token.find('^'),
            star_pos = token.find('*'),
            sign_pos = token.find_first_of("+-"); // Positions of the x, ^, * and sign symbols in the token
    if (sign_pos != std::string::npos && utils::trim(token.substr(sign_pos + 1)).empty())
        throw std::invalid_argument("Operand data is invalid");
    std::string coefficient_str; // String representation of the coefficient
    size_t exponent; // Exponent of the monomial
    char sign; // Sign of the monomial
    if (x_pos == std::string::npos) // If the monomial doesn't contain x
        exponent = 0; // The exponent is 0
    else { // If the monomial contains x
        if (caret_pos == std::string::npos) { // If the monomial doesn't contain ^
            exponent = 1; // The exponent is 1
        } else { // If the monomial contains ^
            exponent = std::stoull(token.substr(caret_pos + 1)); // Parse the exponent
        }
    }

    size_t coeff_start = (sign_pos == std::string::npos) ? 0 : sign_pos + 1,  // Start position of the coefficient
    coeff_end = (star_pos == std::string::npos) ? x_pos : star_pos; // End position of the coefficient
    coefficient_str = utils::trim(token.substr(coeff_start, coeff_end - coeff_start)); // Parse the coefficient
    if (coefficient_str.empty())
        coefficient_str = "1"; // If the coefficient is empty, it is 1
    // Handle the sign
    sign = (token[0] == '-') ? '-' : '+';

    return std::make_tuple(coefficient_str, exponent, sign);
}

std::map<size_t, std::string> getDegreeToCoefficientsMap(const std::string &polynomial) {
    if (utils::trim(polynomial).empty())
        throw std::invalid_argument("Operand data is invalid");
    utils::checkForRedundantSymbols(polynomial, " +-1234567890x*/^");
    // Tokenize the polynomial string into monomial tokens
    std::vector<std::string> tokens = tokenizePolynomial(polynomial);

    std::map<size_t, std::string> res;

    for (const auto &token: tokens) {
        // Parse coefficient and exponent from the token
        auto [coefficient_str, exponent, sign] = parseMonomialToken(token);
        // Add the coefficient to the map
        res[exponent] = sign + coefficient_str;
    }
    return res;
}

Polynomial::Polynomial(const std::string &polynomial) : degree_(0) {
    std::map<size_t, std::string> degree_to_coefficient = getDegreeToCoefficientsMap(
            polynomial); // Map of degrees to coefficients
    for (const auto &iter: degree_to_coefficient) { // Iterate over the map
        auto [degree, coefficient_str] = iter;  // Get the degree and coefficient from the map
        coefficients_.insert(coefficients_.end(), degree - degree_, Rational(0, 1)); // Add zeros to the vector
        Rational coefficient{coefficient_str}; // Parse the coefficient
        coefficients_.push_back(coefficient); // Add the coefficient to the vector
        degree_ = degree + 1; // Update the degree
    }
    std::reverse(coefficients_.begin(), coefficients_.end()); // Reverse the vector
    removeLeadingZeros(); // Remove leading zeros
}


// Bormatov_Yaroslav FAC_P_Q - Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
// Используемые методы - ABS_Z_N TRANS_Z_N LCM_NN_N GCF_NN_N TRANS_N_Z DIV_ZZ_Z
Polynomial Polynomial::factorize() const {
    Polynomial result = Polynomial(*this); // создание многочлена возвращаемого методом

    if (degree_ < 1) return result; // если многочлен степени < 1 -> нельзя ничего вынести

    // создаем два натуральных числа - НОД и НОК знаменателей и числителей коэф-ов многочлена соответственно
    Natural lcm_{1}, gcd_{1};

    // вычисление НОД <a_0, a_1>
    gcd_ = Natural::gcd(coefficients_[0].getNumerator().toNatural(), coefficients_[1].getNumerator().toNatural());
    // вычисление НОК <a_0, a_1>
    lcm_ = Natural::lcm(coefficients_[0].getDenominator(), coefficients_[1].getDenominator());

    for (size_t i = 2; i <= degree_; i++) {
        gcd_ = Natural::gcd(gcd_, coefficients_[i].getNumerator().toNatural()); // вычисление НОД от <gcd, a_i>
        lcm_ = Natural::lcm(lcm_, coefficients_[i].getDenominator());           // вычисление НОК от <lcm, a_i>
    }

    Integer gcd_int(gcd_); // gcd -> int
    Rational ratio(gcd_int, lcm_); // ratio = gcd / lcm

    for (size_t i = 0; i <= degree_; i++) {
        result.coefficients_[i] = coefficients_[i] / ratio; // делим каждый коэффициент на ratio
    }

    if (result.coefficients_[0].getSign() == "-") { // если коэффициент при старшей степени отрицательный
        result = result.scale(Rational{-1, 1});
    }

    return result.reduceAllCoefficients(); // возвращаем новый многочлен
}

// Bormatov_Yaroslav NMR_P_P - Преобразование многочлена — кратные корни в простые
// Используемые методы - GCF_PP_P DER_P_P DIV_PP_P
Polynomial Polynomial::singlify() const {
    Polynomial der_ = derivative();  // вычисление производной многочлена
    Polynomial gcd_ = gcd(*this, der_); // вычисление НОД <P(x), P'(x)>
    Polynomial result = *this / gcd_; // вычисление P(x) / gcd(<P(x), P'(x))
    return result.reduceAllCoefficients().factorize(); // возвращаем новый многочлен
}

/*
Дамакин Роман гр2384
Функция P-8: Умножение многочленов
*/
[[nodiscard]] Polynomial Polynomial::operator*(const Polynomial &other) const { // MUL_PP_P
    size_t k = other.degree_; // Степень многочлена
    // Создаем переменную для записи результата и записываем туда результат умножения первого многочлена на свободный коэффициент второго многочлена
    Polynomial result = this->scale(other.coefficients_[k]);
    while (k > 0) { // Цикл по степеням многочлена
        k--; // Уменьшаем степень
        // Прибавляем к результату результат умножения первого многочлена на очередной составляющий одночлен второго многочлена
        result = result + this->scale(other.coefficients_[k]).mulByXk(other.degree_ - k);
    }
    return result.reduceAllCoefficients();
}


// P-2
// Вычитание многочленов
// SUB_PP_P
// Ильин Павел 2383
[[nodiscard]] Polynomial Polynomial::operator-(const Polynomial &other) const {
    // копируем коэфы для изменяемого числа
    std::vector<Rational> new_coefs = coefficients_;
    // приводим к одной длине с вычитаемым числом, если то больше
    while (new_coefs.size() < other.degree_ + 1) {
        new_coefs.insert(new_coefs.begin(), Rational(0, 1));
    }
    // проводим вычитание коэфов в соответствии с их принадлежностью к степени
    size_t indexShift = new_coefs.size() - other.degree_ - 1;
    for (size_t i = other.degree_ + 1; i > 0; i--) {
        new_coefs[indexShift + i - 1] = new_coefs[indexShift + i - 1] - other.coefficients_[i - 1];
    }
    // удаляем крайние слева коэфы, если он равны нулю, в случае многочлена равного нулю, вектор будет в виде [0/1]
    while (new_coefs.size() > 1 && new_coefs[0] == Rational(0, 1)) {
        new_coefs.erase(new_coefs.begin());
    }
    // возвращаем измененный многочлен
    return Polynomial(new_coefs).reduceAllCoefficients();
}


// P-10
// Остаток от деления многочлена на многочлен при делении с остатком
// MOD_PP_P
// Ильин Павел 2383
[[nodiscard]] Polynomial Polynomial::operator%(const Polynomial &other) const {
    // копируем коэфы для изменения
    std::vector<Rational> coefsForDivisor = coefficients_;
    // создаем на их основе делимое число
    Polynomial firstDivisor(coefsForDivisor);
    //если делимое меньше делителя
    if (firstDivisor.degree_ < other.degree_)
        return firstDivisor.reduceAllCoefficients();
    // вычисляем остаток и тут же возвращаем
    return (firstDivisor - (firstDivisor / other) * other).reduceAllCoefficients();
}

//Написал функцию - Кузьминых Егор
//ADD_PP_P (операция сложения многочленов, короткий номер - P1)
[[nodiscard]] Polynomial Polynomial::operator+(const Polynomial &other) const {

    // в maxDegree храню итоговую (макс) степень сложения двух многочленов,
    std::size_t maxDegree = std::max(degree_, other.degree_);
    //Создал вектор, в котором буду хранить коэффы от результата сложения, заполнил его коэфами с первого многочлена
    std::vector<Rational> resultCoefficients = coefficients_;

    // Складываем коэффициенты многочленов
    //В первом цикле мы просто добавляем в массив с коэффами коэффы при первом многочлене
    while (resultCoefficients.size() < other.coefficients_.size()) {
        resultCoefficients.insert(resultCoefficients.begin(), Rational(0, 1));
    }

    //складываем коэффы из второго многочлена с новыми
    for (std::size_t i = 0; i <= other.degree_; i++) {
        // Использование метода (ADD_QQ_Q)
        resultCoefficients[maxDegree - other.degree_ + i] =
                resultCoefficients[maxDegree - other.degree_ + i] + other.coefficients_[i];
    }

    // Создаем новый многочлен с полученными коэффами и возвращаем его
    return Polynomial(resultCoefficients).reduceAllCoefficients();
}

//Написал функцию - Кузьминых Егор
//DIV_PP_P (операция получения частного от деления многочлена на многочлен при делении с остатком, которткий номер - P9)
[[nodiscard]] Polynomial Polynomial::operator/(const Polynomial &other) const {
    //Создал вектор c одним нулевым коэффициентом, будет использоваться, если частное от деления ноль и в дальнейших операциях
    std::vector<Rational> resultCoefficients(1, Rational(0, 1));
    Polynomial quotient = Polynomial(resultCoefficients); // Частное от деления
    Polynomial remainder(*this); // Остаток от деления
    if (other.coefficients_[0].getNumerator() == Integer(0)) {
        throw std::invalid_argument("Деление на ноль невозможно");
    }
    if (degree_ < other.degree_) {
        // Если степень делителя больше степени делимого, возвращаем ноль (частное на данный момент)
        return quotient.reduceAllCoefficients();
    }

    //Цикл действует, пока степень остатка от деления будет больше, чем степень делителя
    while (remainder.degree_ >= other.degree_ && !remainder.coefficients_[0].isZero()) {

        std::size_t k = remainder.getDegree() -
                        other.getDegree();//вычислили степень на данном шагу, использование метода (DEG_P_N)
        Rational factor = remainder.leading() /
                          other.leading();//вычислили коэфф при старшей степени, Использование метода (DIV_QQ_Q)
        std::vector<Rational> coef(1, Rational(1, 1));
        Polynomial polynomial = Polynomial(coef);
        Polynomial term = polynomial.mulByXk(k).scale(factor);//домножили на x^k, использование метода (MUL_Pxk_P)
        quotient = quotient + term;// увеличили частное, использование метода (ADD_PP_P)

        remainder = remainder - term * other;//Вычислили остаток
    }
    return quotient.reduceAllCoefficients();
}

//Написал функцию - Кузьминых Егор
//DER_P_P (Производная многочлена, короткий номер - P12)
Polynomial Polynomial::derivative() const {
    //Создали вектор для хранения коэффициентов
    std::vector<Rational> derivativeCoefficients(degree_, Rational(0, 1));
    if (degree_ == 0) {
        std::vector<Rational> const_coeff(1, Rational(0, 1));
        Polynomial zero = Polynomial(const_coeff);
        return zero;
    }

    for (std::size_t i = 0; i <= degree_ - 1; i++) {// умножаю коэффициент на степень
        derivativeCoefficients[i] = coefficients_[i] * Rational(degree_ - i, 1);
    }
    Polynomial result = Polynomial(derivativeCoefficients);//создаю новый многочлен и возвращаю его
    return result.reduceAllCoefficients();
}

//Цыганков Роман гр 2384 MUL_Pxk_P - умножение мн-на на x^k
Polynomial Polynomial::mulByXk(std::size_t k) const {
    std::size_t degree = this->degree_ + k; // степень нового мн-на
    std::vector<Rational> new_coeff(degree + 1); // создаем новыый вектор с коэффицентами
    for (size_t i = 0; i < this->degree_ + 1; i++) {
        new_coeff[i] = coefficients_[i]; // присваиваем коэффиценты
    }

    for (size_t i = this->degree_ + 1; i < degree; i++) {
        new_coeff[i] = Rational(0, 1); // оставшееся заполняем нулями
    }

    return Polynomial(new_coeff).reduceAllCoefficients(); // создаем мн-н с новыми коэффицентами и возвращаем его
}

// Мирон Возгрин 2382; Возвращает старший коэфицент многочлена (LED_P_Q)
Rational Polynomial::leading() const {
    return coefficients_[0]; //вещественное число, равное первому числу из вектора с коэфицентами многочлена
}

/*
MUL_PQ_P
P - 3
Умножение полинома на рациональное число
Жданов Антон 2383
*/
[[nodiscard]] Polynomial Polynomial::scale(const Rational &scalar) const {
    if (scalar.isZero())                       // если скаляр равен 0, то при умножении на многочлен
    {                                                  // остается многочлен степени 0, с коэффицентом Rational(0,1)
        std::vector<Rational> new_coeff{Rational(0, 1)};// => создаем вектор с 1 элементом и из него создаем многочлен
        return Polynomial{new_coeff};
    }

    std::vector<Rational> new_coeff(this->degree_ + 1); // создаем вектор для новых коэффицентов

    for (int i = 0; i < this->degree_ + 1; i++) {
        new_coeff[i] = this->coefficients_[i] * scalar; // записываем в вектор новые коэффиценты у множенные на скаляр
    }
    return Polynomial{new_coeff}.reduceAllCoefficients(); // создаем многочлен с новыми коэффицентами и возвращаем его
}

/*
DEG_P_N
P - 6
Возвращение степени многочлена
Жданов Антон 2383
*/
[[nodiscard]] std::size_t Polynomial::getDegree() const {
    return this->degree_; // возвращаем степень многочлена
}

/*
GCF_PP_P
P - 11
НОД двух многочленов
Жданов Антон 2383
*/
[[nodiscard]] Polynomial Polynomial::gcd(const Polynomial &a, const Polynomial &b) {
    Polynomial first = a.degree_ >= b.degree_ ? a : b; // Сортируем многочлены по степени
    Polynomial second = a.degree_ < b.degree_ ? a : b; // где first - многочлен степени больше или равной second

    Polynomial ost1{first % second}; // находим остаток от деления первого на второй
    if (ost1.coefficients_[0].isZero()) // если остаток равен нулю, значит НОД - это second
        return second.reduceAllCoefficients();
    Polynomial ost2{second % ost1}; // находим остаток от деления второго на ost1
    // цикл пока один из остатков не равен нулю
    while (!ost1.coefficients_[0].isZero() and !ost2.coefficients_[0].isZero()) {
        ost1 = ost1 % ost2;
        if (ost1.coefficients_[0].isZero()) // если остаток равен нулю, значит НОД - это ost2
            return ost2.reduceAllCoefficients();
        ost2 = ost2 % ost1; // продолжаем делить с остатком
    }
    return ost1.reduceAllCoefficients(); // если цикл завершился и не вернул ничего => НОД - ost1
}

Polynomial Polynomial::reduceAllCoefficients() const {
    Polynomial copy{*this};
    std::transform(copy.coefficients_.begin(), copy.coefficients_.end(), copy.coefficients_.begin(),
                   [](const Rational &rational) { return rational.reduce(); });
    return copy;
}

void Polynomial::removeLeadingZeros() {
    size_t leading_zeros_n = 0;
    for (const auto &coefficient: coefficients_) {
        if (coefficients_.size() - leading_zeros_n == 1 || !coefficient.isZero())
            break;
        leading_zeros_n++;
    }
    coefficients_.erase(coefficients_.begin(), coefficients_.begin() + leading_zeros_n);
    degree_ = coefficients_.size() - 1;
}

bool Polynomial::operator==(const Polynomial &other) const {
    return coefficients_ == other.coefficients_ && degree_ == other.degree_;
}

bool Polynomial::operator!=(const Polynomial &other) const {
    return !(*this == other);
}
