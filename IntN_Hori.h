#pragma once
#include "IntN.h"
class IntN_Hori : public IntN {
public:
	char filename0[20] = {0};
	int output(); 
	IntN_Hori() = default;
	friend IntN_Hori operator+(IntN& b, IntN& f);
	friend IntN_Hori operator-(IntN& b, IntN& f);
	IntN_Hori(int sz, int* x); 
	IntN_Hori(const IntN& b);
	IntN& operator=(const IntN& b);
	void Get_file_Hori();
	~IntN_Hori() = default;
};
IntN_Hori operator+(IntN& b, IntN& f);
IntN_Hori operator-(IntN& b, IntN& f);
