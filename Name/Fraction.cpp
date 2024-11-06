#include "Fraction.h"

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) throw invalid_argument("Denominator cannot be zero");
    simplify();
}

void Fraction::simplify() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

string Fraction::toString() const {
    return to_string(numerator) + "/" + to_string(denominator);
}

Fraction Fraction::sum(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Fraction Fraction::minus(int value) const {
    return Fraction(numerator - value * denominator, denominator);
}

Fraction Fraction::multiply(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::divide(const Fraction& other) const {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

void Fraction::print() const {
    cout << toString() << endl;
}
