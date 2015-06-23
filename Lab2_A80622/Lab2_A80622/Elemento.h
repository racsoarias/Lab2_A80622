#pragma once
using namespace std;

class Elemento {

private:
	string id;
	int valor, gramos;
	double indice;

public:

	Elemento(string id, int i);
	int getValor();
	void setValor(int);
	int getGramos();
	void setGramos(int);
	double getIndice();
	string getID();
	void setID(string);
	virtual ~Elemento();
	void imprime(int);

	//virtual int compareTo(Elemento *) = 0;
	bool operator<(Elemento &);
	bool operator<=(Elemento &);
	bool operator>(Elemento &);
	bool operator>=(Elemento &);
};