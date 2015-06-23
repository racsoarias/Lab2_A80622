#include "stdafx.h"
#include "Collar.h"

Collar::Collar(string id, int i) :Elemento(id, i) {
	setValor((rand() % (MAX_VALOR - MIN_VALOR) + MIN_VALOR));
	setGramos((rand() % (MAX_PESO - MIN_PESO) + MIN_PESO));
}

Collar::~Collar() {
}
/*
int Collar::compareTo(Elemento * otro) {
	int cmp = 0;
	Collar * eInt = static_cast<Collar *>(otro);
	if (eInt != 0) {
		cmp = this->getValor() < eInt->getValor() ? -1 : this->getValor() == eInt->getValor() ? 0 : 1;
	}
	return cmp;
}
*/