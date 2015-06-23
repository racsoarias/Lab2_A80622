#pragma once

#include "Elemento.h"

using namespace std;

class Tesoro {

private:
	static const int ANI_MIN_CANT = 5;
	static const int ANI_MAX_CANT = 7;
	static const int COL_MIN_CANT = 2;
	static const int COL_MAX_CANT = 5;
	static const int COR_MIN_CANT = 1;
	static const int COR_MAX_CANT = 5;
	static const int MON_MIN_CANT = 5;
	static const int MON_MAX_CANT = 10;
	int tam;

public:
	Tesoro();
	int getTam();
	virtual ~Tesoro();
	void imprime(int);
	Elemento ** arreglo;
};