//
//  Comlex.cpp
//  HW 172 06
//
//  Created by Eric Klicker on 11/7/16.
//  Copyright © 2016 Eric Klicker. All rights reserved.
//

#include "Comlex.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>


Complex::Complex()
{
    a = 0;
    b = 0;
}
Complex::Complex(double A)
{
    a = A;
}
Complex::Complex(double A, double B)
{
    a = A;
    b = B;
}
double Complex::getA() const
{
    return a;
}
double Complex::getB() const
{
    return b;
}
void Complex::setA(double newA)
{
    a = newA;
}
void Complex::setB(double newB)
{
    b = newB;
}
Complex Complex::add(Complex& c)
{
    double newA = getA() + c.getA();
    double newB = getB() + c.getB();
    Complex cSum(newA, newB);
    return cSum;
}
Complex Complex::subtract(Complex& c)
{
    double newA = getA() - c.getB();
    double newB = getB() - c.getB();
    Complex cSub(newA, newB);
    return cSub;
}
Complex Complex::multiply(Complex& c)
{
    double newA = (getA() * c.getA()) - (getB() * c.getB());
    double newB = (getB() * c.getA()) + (getA() * c.getB());
    Complex cSub(newA, newB);
    return cSub;
}
Complex Complex::divide(Complex& c)
{
    double newA = ((getA() * c.getA()) + (getB() * c.getB())) / ((c.getA() * c.getA()) + (c.getB() * c.getB()));
    double newB = (getB() * c.getA()) - (getA() * c.getB()) / ((c.getA() * c.getA()) + (c.getB() * c.getB()));
    Complex cDiv(newA, newB);
    return cDiv;
}
double Complex::abs()
{
    double ABS = pow(pow( getA(), 2) + pow(getB() , 2), 1/2);
    return ABS;
}
string Complex::toString()
{
    string newC = " + i";
    string newA = to_string(getA());
    string newB = to_string(getB());
    newC.insert(0, newA);
    newC.insert(newC.size()-1, newB);
    
    return newC;
}
Complex& Complex::operator+=(Complex& c)
{
    *this=add(c);
    return *this;
}
Complex& Complex::operator-=(Complex& c)
{
    *this = subtract(c);
    return *this;
}
Complex& Complex::operator*=(Complex& c)
{
    *this = multiply(c);
    return *this;
}
Complex& Complex::operator/=(Complex& c)
{
    *this = divide(c);
    return *this;
}
int Complex::operator[](int index)
{
    if(index == 0)
        return getA();
    if(index == 1)
        return getB();
    else
        return -1;
}
Complex Complex::operator+()
{
    double newA = -getA();
    double newB = -getB();
    Complex newC(newA, newB);
    return newC;
}
Complex Complex::operator-()
{
    return Complex(-getA(), -getB());
}
Complex& Complex::operator++()
{
    int newA = getA() + 1;
    int newB = getB() + 1;
    Complex c(newA, newB);
    return c;
}
Complex& Complex::operator--()
{
    double newA = getA()-1;
    double newB = getB()-1;
    Complex newC(newA,newB);
    return newC;
}
Complex Complex::operator++(int temp)
{
    double newA = getA()+1;
    double newB = getB()+1;
    Complex newC(newA,newB);
    return newC;
}
Complex Complex::operator--(int temp)
{
    double newA = getA()-1;
    double newB = getB()-1;
    Complex newC(newA,newB);
    return newC;
}
ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.getA() << " + " << c.getB() << "i";
    return out;
}
istream& operator>>(istream& in, Complex& c)
{
    double newA, newB;
    in >> newA;
    in >> newB;
    c.setA(newA);
    c.setB(newB);
    return in;
}
