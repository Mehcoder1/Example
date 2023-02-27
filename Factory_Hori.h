#pragma once
#include "IntN.h"
#include "Factory.h"
#include "IntN_Hori.h"
class Factory_Hori:public Factory {
public:
	Factory_Hori() = default;
	IntN* Create(int n,int* array) {
		return new IntN_Hori(n,array);
	}
	 ~Factory_Hori() = default;
};
