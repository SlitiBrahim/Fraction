#ifndef FRACTION_FRACTION_H
#define FRACTION_FRACTION_H

#include <iostream>

class Fraction {

    public:
    /*
     * Constructors
     */
        Fraction(int a, int b);
        Fraction(int a);
        Fraction();

    /*
     * Methods
     */
        Fraction& operator+=(Fraction const &b);
        Fraction& operator*=(Fraction const &b);
        Fraction& operator=(Fraction const &a);
    void display(std::ostream &flux, Fraction const& fraction) const;
        bool isEqual(Fraction const &b) const;
        bool isLower(Fraction const &b) const ;

private:
        int numerator;
        int denominator;

        bool isSameDenominator(Fraction const &b) const;
        // highest common factor of two integers
        int hcf(int a, int b);
        void reduce();
};

bool operator==(Fraction const &a, Fraction const &b);
bool operator!=(Fraction const &a, Fraction const &b);
bool operator<(Fraction const &a, Fraction const &b);
bool operator>(Fraction const &a, Fraction const &b);
bool operator<=(Fraction const &a, Fraction const &b);
bool operator>=(Fraction const &a, Fraction const &b);

Fraction operator+(Fraction const &a, Fraction const &b);
Fraction operator*(Fraction const &a, Fraction const &b);

std::ostream& operator<<(std::ostream &flux, Fraction const& fraction);

#endif //FRACTION_FRACTION_H
