#include "stdafx.h"
#include "Anillo.h"

Anillo::Anillo(string id, int i) :Elemento(id, i) {
	setValor((rand() % (MAX_VALOR - MIN_VALOR) + MIN_VALOR));
	setGramos((rand() % (MAX_PESO - MIN_PESO) + MIN_PESO));
}

Anillo::~Anillo() {
}
/*
int Anillo::compareTo(Elemento * otro) {
	int cmp = 0;
	Anillo * eInt = static_cast<Anillo *>(otro);
	if (eInt != 0) {
		cmp = this->getValor() < eInt->getValor() ? -1 : this->getValor() == eInt->getValor() ? 0 : 1;
	}
	return cmp;
}
*/