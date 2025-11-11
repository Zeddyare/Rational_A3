//
// Created by zdrol on 2025-11-11.
//

#ifndef RATIONAL_RATIONALLIB_H
#define RATIONAL_RATIONALLIB_H

#include <string>
#include <iostream>

class RationalNum {

public:

    //Default Constructor
    RationalNum();

    //Constructor 1: take 2 arguments to set member values of Rational object to legitimate values
    RationalNum(int num, int denom);

    //Constructor 2: Initializes rational object to rational number
    RationalNum(const RationalNum&, int num, int denom);

    //Constructor 3: String constructor takes a string rational or whole number and makes a rational number
    explicit RationalNum(const std::string& frac);
    explicit RationalNum(int whole);

    // Comparisons (friends so they can access internals)
    friend bool operator==(const RationalNum& a, const RationalNum& b);
    friend bool operator<(const RationalNum& a, const RationalNum& b);
    friend bool operator>(const RationalNum& a, const RationalNum& b);

    //Overload: + - = += / *
    RationalNum operator+(const RationalNum& rhs) const;
    RationalNum operator-(const RationalNum& rhs) const;
    RationalNum operator*(const RationalNum& rhs) const;
    RationalNum operator/(const RationalNum& rhs) const;
    RationalNum& operator+=(const RationalNum& rhs);

    //Overload: <<
    //Copied over from courses
    friend std::ostream& operator<<(std::ostream& os, const RationalNum& s);

    //Driver: Demonstrate functionality of everything

    //Accessors (if necessary)
    int numerator() const;
    int denominator() const;



private:
    int _num;
    int _den;

    //Normalization: Output of math operations should be normalized (1/2 instead of 2/4)
    static int gcd(int a, int b);
    void normalize();
};




#endif //RATIONAL_RATIONALLIB_H