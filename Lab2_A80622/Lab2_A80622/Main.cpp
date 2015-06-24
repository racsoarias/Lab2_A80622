#include "stdafx.h"
#include "Tesoro.h"
#include "Pirata.h"
using namespace std;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

void archivos(){
	ofstream out("tesoro.txt"); out << ""; out.close();
	ofstream out2("robado-recursivo.txt"); out2 << ""; out2.close();
	ofstream out3("robado-no-recursivo.txt"); out3 << ""; out3.close();
	//ofstream out4("sobro.txt"); out4 << "";	out4.close();
	ofstream out5("tiempos.txt"); out5 << "";	out5.close();
}

int _tmain(int argc, _TCHAR* argv[]){
	srand((unsigned int)time(NULL));
	string str = "Llamado\tRecursivo\tNoRecursivo\tTamTesoro\n";


	for (int i = 0; i < 30; i++){
		stringstream nanoStr, nanoStr2, llamadoStr, tamStr;
		llamadoStr << i + 1;
		str += llamadoStr.str() + ":\t";
		archivos();
		Tesoro santoGrial;
		Pirata jack;

		tamStr << santoGrial.getTam();

		auto inicio = std::chrono::high_resolution_clock::now();// Se obtiene el tick de inicio
		// =-= Inicio código a medir =-=
		jack.robe(santoGrial);
		// =-= Fin código a medir =-=	
		auto fin = std::chrono::high_resolution_clock::now();// Se obtiene el tick de final	
		nanoseconds ns = duration_cast<nanoseconds>(fin - inicio);// Se convierte a nanosegundos y se imprime
		nanoStr << ns.count();
		str += nanoStr.str() + "ns \t";

		inicio = std::chrono::high_resolution_clock::now();// Se obtiene el tick de inicio
		// =-= Inicio código a medir =-=
		jack.robeNoRe(santoGrial);
		// =-= Fin código a medir =-=	
		fin = std::chrono::high_resolution_clock::now();// Se obtiene el tick de final	
		nanoseconds ns2 = duration_cast<nanoseconds>(fin - inicio);// Se convierte a nanosegundos y se imprime
		nanoStr2 << ns2.count();
		str += nanoStr2.str() + "ns\t" + tamStr.str() + "\n";
	}

	ofstream out("tiempos.txt");
	out << str;
	out.close();

	system("pause");
	return 0;
}

