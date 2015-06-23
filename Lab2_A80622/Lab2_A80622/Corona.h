#pragma once
#include "Elemento.h"

using namespace std;

class Corona : public Elemento {

public:
	static const int MIN_VALOR = 1000;
	static const int MAX_VALOR = 10000;
	static const int MIN_PESO = 500;
	static const int MAX_PESO = 2000;
	//virtual int compareTo(Elemento *);
	Corona(string, int);
	virtual ~Corona();
};

