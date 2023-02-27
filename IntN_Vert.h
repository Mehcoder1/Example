#pragma once
#include "IntN.h"
#include <fstream>
class IntN_Vert : public IntN {
public:
	char filename0[20] = {0};
	int output();
	IntN_Vert() = default;
	IntN_Vert(int sz, int* x);
	IntN_Vert(const IntN& b);
	void Get_file_Vert();
	IntN& operator=(const IntN& b);
	~IntN_Vert() = default;
};
