/*
 * Complex.cpp
 *
 *  Created on: 15 may. 2019
 *      Author: jrangel
 */

#include <sstream>
#include "math.h"
#include "Complex.h"

namespace std {

const char charPlusOp = '+';
const char charMinusOp = '-';
const char charIValue = 'i';

Complex::Complex() {
	real = 0.0;
	imag = 0.0;
}

Complex::Complex(double re, double im) {
	real = re;
	imag = im;
}

Complex::~Complex() {
	real = 0.0;
	imag = 0.0;
}

double Complex::getReal(){return real;}

double Complex::getImaginary(){return imag;}

void Complex::setReal(double re) { real = re;}

void Complex::setImaginary(double im) {imag = im;}

void Complex::fromString(const std::string& complexString) {
	string realstring;
	string imagstring;
	stringstream stringBufReal;		// Stream class to operate on strings. Objects of this class use a string buffer that contains a sequence of characters.
	stringstream stringBufImag;					//accessed directly as a string object, using member str.
	int opPos = complexString.find(charPlusOp);	//string library member function that returns the position of the char introduced
	//int iPos;											Never used, candidate to be removed

	if (opPos != (int) complexString.npos) {			//Add a cast so the comparison is made between ints
		// deal with cases re + im i
		realstring = complexString.substr(0, opPos);	//Real string starts from pos = 0 to opPos
		stringBufReal.str(realstring);					//Setting a new buffer
		stringBufReal >> real;							//Trasfer this value to the private member real of the object
		imagstring = complexString.substr(opPos + 1);	//Imag string starts from opPos + 1 to the end
		stringBufImag.str(imagstring);					//Setting a new buffer
		stringBufImag >> imag;							//Trasfer this value to the private member imag of the object
		//case re + i
		if (imag == 0)	imag = 1;						//don´t understand this sentence, if imag = 0 the number is 100% real
	}
	else {
		opPos = complexString.find(charMinusOp);
		if (opPos != (int) complexString.npos && opPos > 0) {
			// deal with cases re - im i
			realstring = complexString.substr(0, opPos);
			stringBufReal.str(realstring);
			stringBufReal >> real;
			imagstring = complexString.substr(opPos + 1);
			stringBufImag.str(imagstring);
			stringBufImag >> imag;
			if (imag == 0) imag = 1;
		} else {
			opPos = complexString.find(charIValue);
			if (opPos != (int) complexString.npos) {
				// deal with case im i
				imagstring = complexString.substr(0, opPos);
				stringBufImag.str(imagstring);
				stringBufImag >> imag;
			} else {
				// deal with case re
				stringBufReal.str(realstring);
				stringBufReal >> real;
			}
		}
	}

}

Complex Complex::operator+ (Complex& theComplex) {		//Add the actual value in real + the getReal() in the parameter, same for Imaginary
	return Complex(real + theComplex.getReal(), imag + theComplex.getImaginary());}

Complex Complex::operator- (Complex& theComplex) {		//Subs the actual value in real + the getReal() in the parameter, same for Imaginary
	return Complex(real - theComplex.getReal(), imag - theComplex.getImaginary());}

Complex Complex::operator* (Complex& theComplex) {		//Mult (a + bi)*(c + di) = (ac - bd) + (ad - bc)i
	double re = real * theComplex.getReal() - imag * theComplex.getImaginary();
	double im = real * theComplex.getImaginary() + imag * theComplex.getReal();
	return Complex (re,im);}

Complex Complex::operator/ (Complex& theComplex) {		//Div (a + bi)*(c + di) = ((ac+db)/(c^2+d^2))+((bc-ad)/(c^2+d^2))i
	double re;
	double im;
	double c = theComplex.getReal();
	double d = theComplex.getImaginary();
	double denom = c*c + d*d;

	if (denom == 0) {									//prevent the result to coplase wether the denom is 0
		re = 1e100;
		im = 1e100;
	}

	re = (real * c + imag * d)/denom;
	im = (imag * c - imag * d)/denom;
	return Complex (re, im);}

std::ostream& operator<<(std::ostream& out, Complex& theComplex) {
	using namespace std;
	double re = theComplex.getReal();
	double im = theComplex.getImaginary();

	if (im > 0 && re != 0) {
		if (im != 1)
			out << re << " + " << im << "i";
		else
			out << re << " + i";
	} else if (im < 0 && re != 0) {
			if (im != -1)
				out << re << " - " << fabs(im) << "i";
			else
				out << re << " - i";
		} else if (re == 0) {
			out << im << "i";}
		else if (im == 0) {
			out << re;}
	return out;
}

} /* namespace std */
