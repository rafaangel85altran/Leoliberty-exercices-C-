/*
** Name: complex.h
** Author: Leo Liberti
** Purpose: header file for a complex numbers class
** Source: GNU C++
** History: 061019 work started
*/

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
#include <string>

namespace std {

class Complex {
	public:
		Complex();
		virtual ~Complex();
		Complex(double re, double im);

		double getReal(void);
		double getImaginary(void);
		void setReal(double re);
		void setImaginary(double im);
		void fromString(const std::string& complexString);

		Complex operator+(Complex& theComplex);
		Complex operator-(Complex& theComplex);
		Complex operator*(Complex& theComplex);
		Complex operator/(Complex& theComplex);

	private:
		double real;
		double imag;
	};

std::ostream& operator<<(std::ostream& out, Complex& theComplex);

} /* namespace std */

#endif /* COMPLEX_H_ */
