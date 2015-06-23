#include "stdafx.h"
#include "Tesoro.h"
#include "Elemento.h"
#include "Anillo.h"
#include "Collar.h"
#include "Corona.h"
#include "Moneda.h"

Tesoro::Tesoro() {

	int aniQ = rand() % (ANI_MAX_CANT - ANI_MIN_CANT) + ANI_MIN_CANT;
	int colQ = rand() % (COL_MAX_CANT - COL_MIN_CANT) + COL_MIN_CANT;
	int corQ = rand() % (COR_MAX_CANT - COR_MIN_CANT) + COR_MIN_CANT;
	int monQ = rand() % (MON_MAX_CANT - MON_MIN_CANT) + MON_MIN_CANT;
	tam = aniQ + colQ + corQ + monQ;

	arreglo = new Elemento*[tam];

	/*
	cout << "Cantidad de anillos: " << aniQ << ", cantidad de collares: " << colQ
		<< "\nCantidad de coronas: " << corQ << ", cantidad de monedas: " << monQ << endl;
	*/

	int i, total = aniQ;

	for (i = 0; i < total; i++){
		arreglo[i] = new Anillo("ANI", i);
	}
	total += colQ;

	for (i = aniQ; i < total; i++){
		arreglo[i] = new Collar("COL", i);
	}
	total += corQ;

	for (i = aniQ + colQ; i < total; i++){
		arreglo[i] = new Corona("COR", i);
	}
	total += monQ;

	for (i = aniQ + colQ + corQ; i < total; i++){
		arreglo[i] = new Moneda("MON", i);
	}
	imprime(total);
}

Tesoro::~Tesoro() {
	//delete []arreglo;
}

int Tesoro::getTam(){
	return this->tam;
}
void Tesoro::imprime(int total){
	string str = "";
	for (int i = 0; i < total; i++){
		stringstream valorStr, pesoStr;
		valorStr << arreglo[i]->getValor();
		pesoStr << arreglo[i]->getGramos();
		str += arreglo[i]->getID() + "->\tvalor: " + valorStr.str() + "\tgramos: " + pesoStr.str() + "\n";
	}

	ofstream out("tesoro.txt");
	out << str;
	out.close();
}
