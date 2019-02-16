#include <iostream>
#include "7_Complex.h"

Complex::Complex(double r, double i)
{
	real_ = r;
	imagine_ = i;
}

void Complex::reset(double r, double i)
{
	real_ = r;
	imagine_ = i;
}

Complex operator~(const Complex& complex)
{
	Complex result(complex.real_, complex.imagine_ * (-1));
	return result;
}

Complex operator+(const Complex& first, const Complex& second)
{
	Complex result(first.real_ + second.real_,
		             first.imagine_ + second.imagine_);
	return result;
}

Complex operator-(const Complex& first, const Complex& second)
{
	Complex result(first.real_ - second.real_,
		             first.imagine_ - second.imagine_);
	return result;
}

Complex operator*(const Complex& first, const Complex& second)
{
	Complex result(first.real_ * second.real_ -
	               first.imagine_ * second.imagine_,
	               first.real_ * second.imagine_ +
	               first.imagine_ * second.real_);
	return result;
}

Complex operator*(const Complex& complex, double n)
{
	Complex result(complex.real_ * n, complex.imagine_ * n);
	return result;
}

Complex operator*(double n, const Complex& complex)
{
	return complex * n;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	os << "(" << double(complex.real_) << "," 
	   << double(complex.imagine_) << "i)\n";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& complex)
{
	std::cout << "real: ";
	is >> complex.real_;
	std::cout << "imaginary: ";
	is >> complex.imagine_;
	return is;
}