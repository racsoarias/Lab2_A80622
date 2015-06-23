#include "stdafx.h"
#include "Corona.h"

Corona::Corona(string id, int i) :Elemento(id, i) {
	setValor((rand() % (MAX_VALOR - MIN_VALOR) + MIN_VALOR));
	setGramos((rand() % (MAX_PESO - MIN_PESO) + MIN_PESO));
}

Corona::~Corona() {
}
/*
int Corona::compareTo(Elemento * otro) {
	int cmp = 0;
	Corona * eInt = static_cast<Corona *>(otro);
	if (eInt != 0) {
		cmp = this->getValor() < eInt->getValor() ? -1 : this->getValor() == eInt->getValor() ? 0 : 1;
	}
	return cmp;
}
*/