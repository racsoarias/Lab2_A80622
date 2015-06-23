#include "stdafx.h"
#include "Elemento.h"

Elemento::Elemento(string id, int i) {
	stringstream idStr;
	idStr << i + 1001;
	this->id = id + idStr.str();
}

Elemento::~Elemento() {
}
int Elemento::getValor(){
	return this->valor;
}
int Elemento::getGramos(){
	return this->gramos;
}
double Elemento::getIndice(){
	return (getValor()/1.0 / getGramos()/1.0);
}
string Elemento::getID(){
	return this->id;
}
void Elemento::setValor(int valor){
	this->valor=valor;
}
void Elemento::setGramos(int gramos){
	this->gramos=gramos;
}
void Elemento::setID(string id){
	this->id=id;
}
/*
bool Elemento::operator <(Elemento& otro) {
	return this->compareTo(&otro) < 0;
}

bool Elemento::operator <=(Elemento& otro) {
	return this->compareTo(&otro) <= 0;
}

bool Elemento::operator >(Elemento& otro) {
	return this->compareTo(&otro) > 0;
}

bool Elemento::operator >=(Elemento& otro) {
	return this->compareTo(&otro) >= 0;
}
*/