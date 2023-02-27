#pragma once
#include "IntN.h"
class Factory {
public:
	Factory() = default;
	virtual IntN* Create(int n,int* array) = 0;
	virtual ~Factory() {};
};
