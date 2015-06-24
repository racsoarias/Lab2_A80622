#pragma once

#include "Tesoro.h"
#include "Elemento.h"

using namespace std;

class Pirata {
public:
	static const int MIN_CAPACIDAD = 1000;
	static const int MAX_CAPACIDAD = 2000;

	int capSaco;
	Pirata();
	virtual ~Pirata();
	void robe(Tesoro);
	void robeNoRe(Tesoro);
private:
	void robeRe(Elemento **, int, int, int, int, string);
	void printToFile(string, string);
	void mejorRobo(int, int, string);
	void sort(Elemento **, int);
	void imprimeVector(Elemento**, int);
	int peso, valor;
	string elementos;

};
