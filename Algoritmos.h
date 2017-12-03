#ifndef algoritmos_2017
#define algoritmos_2017

#include "DiccionarioLSE.h"
#include "CPArbol.h"
#include "Relaciones1_1.h"
#include "CDCD.h"
//#include "GNDMatriz.h"
#include "GNDLista.h"

#include <iostream>

struct Tripleta
{
	Grafo::Vertice v1;
	Grafo::Vertice v2;
	int peso;

	Tripleta(){}

	Tripleta(Grafo::Vertice v1, Grafo::Vertice v2, int peso){
		this->v1 = v1;
		this->v2 = v2;
		this->peso = peso;
	}

	int operator==(const Tripleta& otra){
		int iguales = 1;
		if(otra.v1 != this->v1 || otra.v2 != this->v2 ||
		otra.peso != this->peso){
			iguales = 0;
		}
		return iguales;
	}

	Tripleta& operator=(const Tripleta& otra){
		this->v1 = otra.v1;
		this->v2 = otra.v2;
		this->peso = otra.peso;
		return *this;
	}

	std::ostream& operator<<(std::ostream& salida){
		salida << "(" << v1 << "," << v2 << "," << peso << ")";
		return salida;
	}

};

class Algoritmos{

	private:
		int costoActual;
		int costoGlobal;
		int numVertice;

		Grafo::Vertice * solucionActual;
		Grafo::Vertice * solucionGanadora;
		DiccionarioLSE<Grafo::Vertice> diccionarioH;
		int numSolucionesFactibles;
		int numSolucionesOptimas;
	public:
		Algoritmos();
		~Algoritmos();
		int iguales(Grafo*, Grafo*);
		Grafo*  copiar(Grafo*,Grafo*);
		void floyd(Grafo*);
		void kruskal(Grafo*);
		void prim (Grafo*);
		void dijkstra(Grafo*, Grafo::Vertice);
		void problemaDelVendedor(Grafo*);
		void problemaDelVendedorR(Grafo*, Grafo::Vertice,int);

};

#endif
