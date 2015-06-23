#pragma once
#include "Elemento.h"

using namespace std;

class Collar : public Elemento {

public:
	static const int MIN_VALOR = 2000;
	static const int MAX_VALOR = 4000;
	static const int MIN_PESO = 500;
	static const int MAX_PESO = 1000;
	//virtual int compareTo(Elemento *);
	Collar(string, int);
	virtual ~Collar();
};

