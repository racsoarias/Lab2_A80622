#pragma once
#include "Elemento.h"

using namespace std;

class Anillo : public Elemento {

public:
	static const int MIN_VALOR = 100;
	static const int MAX_VALOR = 200;
	static const int MIN_PESO = 200;
	static const int MAX_PESO = 300;
	//virtual int compareTo(Elemento *);
	Anillo(string, int);
	virtual ~Anillo();
};