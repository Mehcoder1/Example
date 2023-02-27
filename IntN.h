#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <map>
#include <fstream>
#include <string>
#include <stdlib.h>
class IntN {
protected:
	int* x = nullptr;
	int sz = 0;
public:
	IntN() = default;
	IntN(int sz, int* x);
	IntN(const IntN& b);
	virtual int output() = 0;
	int  Size() const;
	int* X() const;
	IntN& operator=(const IntN& b);
		virtual ~IntN();
};
