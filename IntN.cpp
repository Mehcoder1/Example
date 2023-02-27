#include "IntN.h"
IntN::IntN(int sz, int* x) {
	this->sz = sz;
	this->x = new int[this->sz];
	if (this->x == NULL) {
		std::cout << "Can not allocate memory";
		exit(1);
	}
	for (int i = 0; i < this->sz; i++) {
		this->x[i] = x[i];
		if (this->x[i] >= 10 || this->x[i] <= -10) {
			std::cout << "Number is out of decimal system";
			exit(1);
		}
	}
}
IntN::IntN(const IntN& b) {
	sz = b.sz;
	x = new int[sz];
	if (x == NULL) {
		std::cout << "Can not allocate memory";
		exit(1);
	}
	for (int i = 0; i < sz; i++) {
		x[i] = b.x[i];
	}

}
int IntN::  Size() const { return sz; }
int* IntN:: X() const { return x; }
IntN& IntN::operator=(const IntN& b) {
	if (sz != b.sz && x != NULL) {
		throw std::runtime_error("Error! Opeartor= Sizes of classes are not equal!\n");
		exit(1);
	}
	delete[] x;
	sz = b.sz;
	x = new int[sz];
	if (x == NULL) {
		std::cout << "Can not allocate memory";
		exit(1);
	}
	for (int i = 0; i < sz; i++) {
		x[i] = b.x[i];
	}
	//	std::copy(b.x,b.x+sz,x);
	return *this;
}

IntN:: ~IntN() {
	
        if (x!= NULL) {
		delete[] x;
		x = NULL;
        }
}

