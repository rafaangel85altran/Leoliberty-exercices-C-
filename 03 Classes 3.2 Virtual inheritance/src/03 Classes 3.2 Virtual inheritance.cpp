//============================================================================
// Name        : 2.cpp
// Author      : jrangel
// Version     :
// Copyright   : Module 3. 3.2 Virtual inheritance
// Description : Hello World in C++, Ansi-style
//============================================================================

// this program does not compile!
#include<iostream>

class VirtualBase {
	public:
		virtual ~VirtualBase() { }
		virtual void setValue(int i) = 0;
		virtual int getValue(void) = 0;
	};

class Derived : public virtual VirtualBase {
	public:
		~Derived() { }
		void setValue(int i) {
			theValue = i;
			}
		int getValue(void) {
			return theValue;
			}
		void printValue(void) {
			std::cout << "Derived::printValue(): value is " << theValue << std::endl;
			}
	private:
		int theValue;
	};

void printTheValue1(VirtualBase* v) {
	std::cout << "printTheValue1(): value is " << v->getValue() << std::endl;
	}

void printTheValue2(VirtualBase* v) {
	Derived* d = dynamic_cast<Derived*>(v);
	d->printValue();
	}

int main(int argc, char** argv) {
	int ret = 0;
	Derived d;
	VirtualBase* v = &d;
	v->setValue(1);
	printTheValue1(v);
	printTheValue2(v);
	return ret;
	}
