#include "stdafx.h"
#include "Moneda.h"

Moneda::Moneda(string id, int i) :Elemento(id, i) {
	setValor((rand() % (MAX_VALOR - MIN_VALOR) + MIN_VALOR));
	setGramos((rand() % (MAX_PESO - MIN_PESO) + MIN_PESO));
}

Moneda::~Moneda() {
}
/*
int Moneda::compareTo(Elemento * otro) {
	int cmp = 0;
	Moneda * eInt = static_cast<Moneda *>(otro);
	if (eInt != 0) {
		cmp = this->getValor() < eInt->getValor() ? -1 : this->getValor() == eInt->getValor() ? 0 : 1;
	}
	return cmp;
}
*/