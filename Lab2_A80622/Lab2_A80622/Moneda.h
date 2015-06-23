#pragma once
#include "Elemento.h"

using namespace std;

class Moneda : public Elemento {

public:
	static const int MIN_VALOR = 1;
	static const int MAX_VALOR = 100;
	static const int MIN_PESO = 100;
	static const int MAX_PESO = 200;
	//virtual int compareTo(Elemento *);
	Moneda(string, int);
	virtual ~Moneda();
};
