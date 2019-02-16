#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>

class Complex
{
public:
  Complex(double r = 0.0, double i = 0.0);
  ~Complex() {}

  void reset(double r = 0.0, double i = 0.0);

  friend Complex operator~(const Complex&);
  friend Complex operator+(const Complex&, const Complex&);
  friend Complex operator-(const Complex&, const Complex&);
  friend Complex operator*(const Complex&, const Complex&);
  friend Complex operator*(const Complex&, double n);
  friend Complex operator*(double n, const Complex&);
  friend std::ostream& operator<<(std::ostream&, const Complex&);
  friend std::istream& operator>>(std::istream&, Complex&);

private:
  double real_;
  double imagine_;
};

#endif // COMPLEX_H_