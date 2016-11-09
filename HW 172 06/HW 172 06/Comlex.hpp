//
//  Comlex.hpp
//  HW 172 06
//
//  Created by Eric Klicker on 11/7/16.
//  Copyright © 2016 Eric Klicker. All rights reserved.
//

#ifndef Comlex_hpp
#define Comlex_hpp
#include <string>
#include <stdio.h>
using namespace std;

class Complex
{
private:
    double a;
    double b;
    
public:
    Complex();
    Complex(double);
    Complex(double, double);
    
    double getA() const;
    double getB() const;
    void setA(double);
    void setB(double);
    
    Complex add(Complex&);
    Complex subtract(Complex&);
    Complex multiply(Complex&);
    Complex divide(Complex&);
    double abs();
    string toString();
    
    Complex& operator+=(Complex&);
    Complex& operator-=(Complex&);
    Complex& operator*=(Complex&);
    Complex& operator/=(Complex&);
    int operator[](int);
    Complex operator+();
    Complex operator-();
    Complex& operator++();
    Complex& operator--();
    Complex operator++(int);
    Complex operator--(int);
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(ostream&, const Complex&);
};

Complex operator+(Complex&, Complex&);
Complex operator-(Complex&, Complex&);
Complex operator*(Complex&, Complex&);
Complex operator/(Complex&, Complex&);


#endif /* Comlex_hpp */
