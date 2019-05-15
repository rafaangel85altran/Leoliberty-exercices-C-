/*
 * Complex.cpp
 *
 *  Created on: 15 may. 2019
 *      Author: jrangel
 */

#include <sstream>
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
	int iPos;

	if (opPos != complexString.npos) {
		realstring = complexString.substr(0, opPos);	//Real string starts from pos = 0 to opPos
		stringBufReal.str(realstring);					//Setting a new buffer
		stringBufReal >> real;							//Trasfer this value to the private member real of the object
		imagstring = complexString.substr(opPos + 1);	//Imag string starts from opPos + 1 to the end
		stringBufImag.str(imagstring);					//Setting a new buffer
		stringBufImag >> imag;							//Trasfer this value to the private member imag of the object

		if (imag == 0)	imag = 1;						//don´t undetstand this sentence, if imag = 0 the number is 100% real
	}

	else {

	}

		imagstring = complexString.substr();
	}

}

/*


void fromString(const std::string& complexString);

Complex operator+(Complex& theComplex);
Complex operator-(Complex& theComplex);
Complex operator*(Complex& theComplex);
Complex operator/(Complex& theComplex);
*/

} /* namespace std */
