#include "stdafx.h"
#include "Pirata.h"

Pirata::Pirata() {
	this->capSaco = rand() % (MAX_CAPACIDAD - MIN_CAPACIDAD) + MIN_CAPACIDAD;
	peso = 0;
	valor = 0;
	elementos = "";
}

Pirata::~Pirata() {
}

void Pirata::robe(Tesoro treasure){
	robeRe(treasure.arreglo, treasure.getTam(), 0, 0, 0, "");
	stringstream capSacoStr, pesoStr, valorStr;
	capSacoStr << this->capSaco;
	pesoStr << this->peso;
	valorStr << this->valor;
	printToFile("Capacidad del pirata: " + capSacoStr.str() + ", capacidad utilizada: " + pesoStr.str() + "\n" +
		"Ganancia obtenida: " + valorStr.str() + ", por el robo de: \n" + elementos + "\n\n", "robado-recursivo.txt");
}

void Pirata::robeRe(Elemento ** arreglo, int tamArreglo, int pesoAcum, int pos, int valorAcum, string tesoro){
	if (pesoAcum < capSaco){
		if (pos < tamArreglo){//No lo tomo
			tesoro += "";
			robeRe(arreglo, tamArreglo, pesoAcum, (pos + 1), valorAcum, tesoro);
		}
		if (pos < tamArreglo){//Lo tomo
			tesoro += arreglo[pos]->getID() + "\n";
			robeRe(arreglo, tamArreglo, (pesoAcum + arreglo[pos]->getGramos()), (pos + 1),
				(valorAcum + arreglo[pos]->getValor()), tesoro);
		}
		if (pos == tamArreglo && valorAcum > 0){//Posible solucion		
			stringstream valorStr, pesoStr;
			valorStr << valorAcum;
			pesoStr << pesoAcum;
			mejorRobo(pesoAcum, valorAcum, tesoro);
			/*
			tesoro = "Peso del motín: " + pesoStr.str() + "\nValor del motín : " + valorStr.str() +
			"\nCompuesto por : \n" + tesoro + "\n\n";
			printToFile(tesoro, "robado-recursivo.txt");
			*/
		}
	}
	else{
		//printToFile("\nNo escogidos, compuesto por: \n" + tesoro + "\n\n", "sobro.txt");
	}
}


void Pirata::robeNoRe(Tesoro treasure){
	this->valor = 0;
	this->peso = 0;
	this->elementos = "";
	int pesoSol = 0, valorSol = 0, tam = treasure.getTam(), i = 0, auxCapSaco = 0, capSaco = this->capSaco;
	string elementos = "";
	Elemento * aux = NULL;
	Elemento ** arreglo = treasure.arreglo;

	sort(arreglo, tam);

	for (i; i < tam; i++){
		if (arreglo[i]->getGramos() <= capSaco){
			pesoSol += arreglo[i]->getGramos();
			valorSol += arreglo[i]->getValor();
			elementos += arreglo[i]->getID() + "\n";
			capSaco = capSaco - arreglo[i]->getGramos();
			auxCapSaco = capSaco;
			break;
		}
	}
	for (int j = i + 1; j < tam; j++){
		if (arreglo[j]->getGramos() <= capSaco){
			if (aux == NULL){
				aux = arreglo[j];
				auxCapSaco = capSaco - aux->getGramos();
			}
			else{
				if (auxCapSaco >= arreglo[j]->getGramos()){//Si cabe en el saco, lo meto
					pesoSol += aux->getGramos();
					valorSol += aux->getValor();
					elementos += aux->getID() + "\n";
					capSaco = capSaco - aux->getGramos();
					auxCapSaco = capSaco;
					aux = arreglo[j];
					auxCapSaco = capSaco - aux->getGramos();
				}
				else{//Si es mejor, reemplazo
					if (arreglo[j]->getValor() > aux->getValor()){
						aux = arreglo[j];
						auxCapSaco = capSaco - aux->getGramos();
					}
				}
			}
		}
	}
	pesoSol += aux->getGramos();
	valorSol += aux->getValor();
	elementos += aux->getID() + "\n";
	mejorRobo(pesoSol, valorSol, elementos);
	stringstream capSacoStr, pesoStr, valorStr;
	capSacoStr << this->capSaco;
	pesoStr << this->peso;
	valorStr << this->valor;
	printToFile("Capacidad del pirata: " + capSacoStr.str() + ", capacidad utilizada: " + pesoStr.str() + "\n" +
		"Ganancia obtenida: " + valorStr.str() + ", por el robo de: \n" + this->elementos + "\n\n", "robado-no-recursivo.txt");
}

void Pirata::sort(Elemento * a[], int n){
	Elemento *temp;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			if (a[i]->getIndice() < a[j]->getIndice()){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void Pirata::imprimeVector(Elemento** arreglo, int tam){
	for (int i = 0; i < tam; i++){
		cout << arreglo[i]->getID() << ": " << arreglo[i]->getIndice() << endl;
	}
	cout << "\n" << endl;
}


void Pirata::mejorRobo(int peso, int valor, string elementos){
	if (valor > this->valor){
		this->valor = valor;
		this->peso = peso;
		this->elementos = elementos;
	}
}

void Pirata::printToFile(string str, string filename){
	fstream file;
	file.open(filename, ios::in | ios::out | ios::app);
	file << str;
	file.close();
}