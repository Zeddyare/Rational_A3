//
// Created by zdrol on 2025-11-11.
//

#include "rationalLib.h"

RationalNum::RationalNum() {
    _num = 0;
    _den = 1;
}

//Constructor 1: take 2 arguments to set member values of Rational object to legitimate values
RationalNum::RationalNum(int num, int denom) {

}

//Constructor 2: Initializes rational object to rational number
RationalNum::RationalNum(const RationalNum&, int num, int denom) {

}

//Constructor 3: String constructor takes a string rational or whole number and makes a rational number
RationalNum::RationalNum(const std::string& frac) {

}
RationalNum::RationalNum(int whole) {

}

// Comparisons (friends so they can access internals)
bool operator==(const RationalNum& a, const RationalNum& b) {

}
bool operator<(const RationalNum& a, const RationalNum& b) {

}
bool operator>(const RationalNum& a, const RationalNum& b){

}

//Overload: + - = += / *
RationalNum::operator+(const RationalNum& rhs) const {

}
RationalNum::operator-(const RationalNum& rhs) const {

}
RationalNum::operator*(const RationalNum& rhs) const {

}
RationalNum::operator/(const RationalNum& rhs) const {

}
RationalNum &RationalNum::operator+=(const RationalNum& rhs) {

}

//Overload: <<
//Copied over from courses
std::ostream& operator<<(std::ostream& os, const RationalNum& s) {
    s.print(os);
    return os;
}

//Driver: Demonstrate functionality of everything

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
int RationalNum::gcd(int a, int b) {

}