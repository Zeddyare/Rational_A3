//
// Created by zdrol on 2025-11-11.
//

#include "rationalLib.h"
#include <iostream>
#include <string>

RationalNum::RationalNum(): _num(0), _den(1) {
    std::cout << "Default Constructor" << std::endl;
}

//Constructor 1: take 2 arguments to set member values of Rational object to legitimate values
RationalNum::RationalNum(int num, int denom): _num(num), _den(denom) {
    std::cout << "Rational Constructor (Two Arg)" << std::endl;
    normalize();
}
//Constructor 2: Rational object (whole number) to rational number
RationalNum::RationalNum(int whole): _num(whole), _den(1) {
    std::cout << "Rational Object Constructor (One Arg)" << std::endl;
    normalize();
}

//Constructor 3: String constructor takes a string rational or whole number and makes a rational number
RationalNum::RationalNum(const std::string& frac) {
    std::cout << "String Constructor (Parsed Rational)" << std::endl;

    //TODO: Create function to build rational from string
}

// Comparisons (friends so they can access internals)
bool operator==(const RationalNum& a, const RationalNum& b) {
    std::cout << "operator== used\n";
    return a._num * b._den == b._num * a._den;
}
bool operator<(const RationalNum& a, const RationalNum& b) {
    std::cout << "operator< used\n";
    int x, y;
    x = a._num * b._den;
    y = b._num * a._den;
    return x < y;
}
bool operator>(const RationalNum& a, const RationalNum& b){
    std::cout << "operator> used\n";
    return b < a; //Reuses < logic
}

//Overload: + - = += / *
RationalNum RationalNum::operator+(const RationalNum& rhs) const {
    std::cout << "operator+ used\n";
    int n = _num * rhs._den + rhs._num * _den;
    int d = _den * rhs._den;
    return RationalNum(n, d);
}
RationalNum RationalNum::operator-(const RationalNum& rhs) const {
    std::cout << "operator- used\n";
    int n = _num * rhs._den - rhs._num * _den;
    int d = _den * rhs._den;
    return RationalNum(n, d);
}
RationalNum RationalNum::operator*(const RationalNum& rhs) const {
    std::cout << "operator* used\n";
    int n = _num * rhs._num;
    int d = _den * rhs._den;
    return RationalNum(n, d);
}
RationalNum RationalNum::operator/(const RationalNum& rhs) const {
    std::cout << "operator/ used\n";
    if (rhs._num == 0) throw std::invalid_argument("Division by 0");
    int n = _num * rhs._den;
    int d = _den * rhs._num;
    return RationalNum(n, d);
}
RationalNum& RationalNum::operator+=(const RationalNum& rhs) {
    std::cout << "operator+= used\n";
    *this = *this + rhs; //Uses operator+
    return *this;
}

//Overload: <<
//Copied over from courses
void RationalNum::print(std::ostream& os) const {
    os << "Fraction: \n";
    os << _num << "/" << _den << "\n";
}
std::ostream& operator<<(std::ostream& os, const RationalNum& s) {
    s.print(os);
    return os;
}

//Accessors (if necessary)
int RationalNum::numerator() const {
    return _num;
}
int RationalNum::denominator() const {
    return _den;
}

//Normalization: Output of math operations should be normalized (1/2 instead of 2/4)
void RationalNum::normalize() {
    if (_den == 0) throw std::invalid_argument("Denominator must be a whole number");
    if (_den < 0) {
        _num = -_num; _den = -_den;
    }
    int g = gcd(_num, _den);
    _num /= g; _den /= g;
}

//AI Help received
int RationalNum::gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a == 0 ? 1 : a;
}

//Driver: Demonstrate functionality of everything