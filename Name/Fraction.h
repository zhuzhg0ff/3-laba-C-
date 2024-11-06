#ifndef FRACTION_H
#define FRACTION_H
#include <string>
#include <iostream>
#include <numeric>
#include <stdexcept>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    void simplify();

public:
    Fraction(int num, int den);
    string toString() const;
    Fraction sum(const Fraction& other) const;
    Fraction minus(int value) const;
    Fraction multiply(const Fraction& other) const;
    Fraction divide(const Fraction& other) const;
    void print() const;
};

#endif // FRACTION_H
