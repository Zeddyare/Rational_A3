#include "rationalLib.h"
#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <random>
using namespace std;

int main() {

    cout << "Rational Assignment 3" << endl;
    cout << "===============================================" << endl;

    bool running = true;
    string select;
    while (running) {
        cout << "\nSelect Operation: \n\n"
        << "1. Default Constructor\n"
        << "2. Whole Number Constructor (1 Argument)\n"
        << "3. Rational Constructor (2 Arguments)\n"
        << "4. String Constructor\n"
        << "5. Comparison Demo\n"
        << "6. Arithmetic Demo\n"
        << "7. Exit\n"
        << "Choice: ";

        if (!getline(cin, select)) break;
        try {
            int choice = stoi(select);
            switch (choice) {
                case (1): {
                    cout << "\n";
                    auto first = RationalNum();
                    cout << first;
                    break;
                }
                case (2): {
                    string entry;
                    cout << "Enter integer: ";
                    getline(cin, entry);
                    const int num = stoi(entry);
                    auto second = RationalNum(num);
                    cout << second;
                    break;
                }
                case (3): {
                    string n, d;
                    int num, den;
                    cout << "Enter Numerator: ";
                    getline(cin, n);
                    cout << "\nEnter Denominator: ";
                    getline(cin, d);
                    num = stoi(n);
                    den = stoi(d);
                    auto third = RationalNum(num, den);
                    cout << third;
                    break;
                }
                case (4): {
                    string frac;
                    cout << "Enter Fraction (i.e. #/#): ";
                    getline(cin, frac);
                    auto fourth = RationalNum(frac);
                    cout << fourth;
                    break;
                }
                case (5): {
                    int a, b, c, d;
                    a = (rand() % 10) + 1;
                    b = (rand() % 10) + 1;
                    c = (rand() % 10) + 1;
                    d = (rand() % 10) + 1;
                    cout << "Generating Fractions..." << endl;
                    auto ranOne = RationalNum(a, b);
                    auto ranTwo = RationalNum(c, d);
                    cout << ranOne;
                    cout << ranTwo;

                    cout << "\nDisplay + " << endl;
                    cout << ranOne + ranTwo;

                    cout << "\nDisplay - " << endl;
                    cout << ranOne - ranTwo;

                    cout << "\nDisplay * " << endl;
                    cout << ranOne * ranTwo;

                    cout << "\nDisplay / " << endl;
                    cout << ranOne / ranTwo;

                    cout << "\nDisplay += " << endl;
                    ranOne += ranTwo;
                    cout << ranOne;
                    break;
                }
                case (6): {
                    bool truFal;
                    string value;
                    int a, b, c, d;
                    a = (rand() % 10) + 1;
                    b = (rand() % 10) + 1;
                    c = (rand() % 10) + 1;
                    d = (rand() % 10) + 1;
                    cout << "Generating Fractions..." << endl;
                    auto ranOne = RationalNum(a, b);
                    auto ranTwo = RationalNum(c, d);
                    cout << ranOne;
                    cout << ranTwo;

                    cout << "\nCompare ==" << endl;
                    truFal = ranOne == ranTwo;
                    if (truFal) {
                        value = "True";
                    } else {
                        value = "False";
                    }
                    cout << value << endl;

                    cout << "\nCompare >" << endl;
                    truFal = ranOne > ranTwo;
                    if (truFal) {
                        value = "True";
                    } else {
                        value = "False";
                    }
                    cout << value << endl;

                    cout << "\nCompare <" << endl;
                    truFal = ranOne < ranTwo;
                    if (truFal) {
                        value = "True";
                    } else {
                        value = "False";
                    }
                    cout << value << endl;
                    break;
                }
                case (7): {
                    running = false;

                    break;
                }
                default: {
                    cout << "Invalid choice." << endl;
                    break;
                }
            }
        }
        catch (...) {
            cout << "Invalid entry, please try again." << endl;
            continue;
        }

    }
    return 0;
}