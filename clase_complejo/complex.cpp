#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;


void Complex::Re(const double &r)
{
  re = r;
}

void Complex::Im(const double &i)
{
  im = i;
}

double Complex::Re()
{
  return re;
}

double Complex::Im()
{
  return im;
}


Complex::Complex(double r, double i)
{
    re = r;
    im = i;
}


    double Complex::angle() const
    {
    return atan2(im, re);
    }
    double Complex::magnitude() const
    {
    return sqrt(re*re + im*im);
    }
    Complex Complex::conjugate() const
    {
    return Complex(re, -im);
    }

    Complex Complex::operator+( const Complex &a ){
        Complex c;
        c.re = re+a.re;
        c.im = im+a.im;
        return c;
    }
    Complex Complex::operator-( const Complex &a )
    {
        Complex c;
        c.re = re-a.re;
        c.im = im-a.im;
        return c;
    }
    Complex Complex::operator*( const Complex &a ){
        Complex c;
        c.re = a.re*re - a.im*im;
        c.im = a.re*im + a.im*re;
        return c;
    }
    bool Complex::operator==(const Complex &a ){
        bool res;
        res = (magnitude() == a.magnitude()) && (angle() == a.angle());
        return res;
    } 
    bool Complex::operator<( const Complex &a ){
        bool res;
        res = magnitude() < a.magnitude();
        return res;
    }
    bool Complex::operator>( const Complex &a ){
        bool res;
        res = magnitude()> a.magnitude();
        return res;
    }

    ostream& operator<<(std::ostream& out, Complex a){
        out << a.re << "," << a.im;
    }
