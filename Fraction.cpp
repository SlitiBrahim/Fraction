#include <iostream>
#include "Fraction.h"

using namespace std;

Fraction::Fraction(int a, int b) : numerator(a), denominator(b) {}
Fraction::Fraction(int a) : numerator(a), denominator(1) {}
Fraction::Fraction() : numerator(0), denominator(0) {}

bool Fraction::isSameDenominator(Fraction const &b) const {
    return this->denominator == b.denominator;
}
int Fraction::hcf(int a, int b) {
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}
void Fraction::reduce() {
    int number = hcf(this->numerator, this->denominator);

    this->numerator /= number;
    this->denominator /= number;
}
bool Fraction::isEqual(Fraction const &b) const {
    return this->numerator == b.numerator && this->denominator == b.denominator;
}
bool Fraction::isLower(Fraction const &b) const {
    return this->numerator * b.denominator < this->denominator * b.numerator;
}

Fraction& Fraction::operator+=(Fraction const &b) {

    if (this->isSameDenominator(b)) {
        this->numerator += b.numerator;
    }
    else {
        this->numerator = this->numerator * b.denominator + this->denominator * b.numerator;
        this->denominator *= b.denominator;
    }

    reduce();

    return *this;
}
Fraction& Fraction::operator*=(Fraction const &b) {

    this->numerator *= b.numerator;
    this->denominator *= b.denominator;

    reduce();

    return *this;
}
Fraction& Fraction::operator=(Fraction const &a) {

    this->numerator = a.numerator;
    this->denominator = a.denominator;

    reduce();

    return *this;
}

Fraction operator+(Fraction const &a, Fraction const &b) {

    Fraction result(a);

    result += b;

    return result;
}
Fraction operator*(Fraction const &a, Fraction const &b) {

    Fraction result(a);

    result *= b;

    return result;
}

bool operator==(Fraction const &a, Fraction const &b) {
    return a.isEqual(b);
}
bool operator!=(Fraction const &a, Fraction const &b) {
    return !(a == b);
}
bool operator<(Fraction const &a, Fraction const &b) {
    return a.isLower(b);
}
bool operator>(Fraction const &a, Fraction const &b) {
    return !(a.isLower(b));
}
bool operator<=(Fraction const &a, Fraction const &b) {
    return !(b.isLower(a));
}
bool operator>=(Fraction const &a, Fraction const &b) {
    return !(a.isLower(b));
}

void Fraction::display(ostream &flux, Fraction const& fraction) const {

    // greater number length between numerator and denominator
    unsigned int num((unsigned int) to_string((to_string(numerator).size() > to_string(denominator).size() ? numerator : denominator)).size());

    // display fraction well: add empty spaces depending on length difference of numerator and denominator
    if (numerator != denominator) {
        flux << string((num - to_string(numerator).size()) / 2, ' ') << numerator << endl << string(num, '-') << endl << string((num - to_string(denominator).size()) / 2, ' ') << denominator;
    }
    else {
        flux << numerator << endl;
    }
}
ostream& operator<<(ostream &flux, Fraction const& fraction) {

    fraction.display(flux, fraction);

    return flux;
}
