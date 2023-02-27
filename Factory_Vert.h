#pragma once
#include "IntN.h"
#include "Factory.h"
#include "IntN_Vert.h"
class Factory_Vert:public Factory  {
public:
	Factory_Vert() = default;
	virtual IntN* Create(int n,int* array) {
		return new IntN_Vert(n,array);
	}
	~Factory_Vert() = default;
};
