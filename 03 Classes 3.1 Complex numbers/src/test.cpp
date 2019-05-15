/*
** Name: test.cxx
** Author: Leo Liberti
** Purpose: testing the complex numbers class
** Source: GNU C++
** History: 061019 work started
*/

#include <iostream>
#include <string>
#include "complex.h"

int main(int argc, char** argv) {
using namespace std;
/*
if (argc < 4) {
	cerr << "need an operation on command line" << endl;
	cerr << " e.g. ./test 4.3+3i - 2+3.1i" << endl;
	cerr << " (no spaces within each complex number, use spaces to\n";
	cerr << " separate the operands and the operator - use arithmetic\n";
	cerr << " operators only)" << endl;
	return 1;
	}*/

string complexString1;
string complexString2;
char operation;

cout << "Enter first complex number" << endl;
cin >> complexString1;

cout << "Enter second complex number" << endl;
cin >> complexString2;

cout << "Enter operation" << endl;
cin >> operation;

Complex complex1;
complex1.fromString(complexString1);
Complex complex2;
complex2.fromString(complexString2);
Complex complex3;

	if (operation == '+') {
		complex3 = complex1 + complex2;
	} else if (operation == '-') {
		complex3 = complex1 - complex2;
	} else if (operation == '*' || operation == '.') {
		operation = '*';
		complex3 = complex1 * complex2;
	} else if (operation == '/') {
		complex3 = complex1 / complex2;}
	cout << "(" << complex1 << ") " << operation << " (" << complex2 << ") = " << complex3 << endl;

return 0;
}
