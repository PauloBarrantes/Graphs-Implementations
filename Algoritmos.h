#ifndef algoritmos_2017
#define algoritmos_2017

#include "DiccionarioLSE.h"
#include "CPArbol.h"
#include "Relaciones1_1.h"

#include "GNDMatriz.h"
//#include "GNDLista.h"
class Algoritmos{
	private:
		Grafo* grafo1;
		Grafo* grafo2;


		// Variables globales del problema del vendedor
		int nUmeroSolFactibles;
		int numeroSolOptimas;
		int numVerticeVisitado =0;
		Grafo::Vertice * soluciónActual;
		Grafo::Vertice * soluciónGanadora;
		int caminoMásCorto = 0;
		int caminoMásCortoAct = 0;
		DiccionarioLSE<Grafo::Vertice> diccionarioH;

	public:
		Algoritmos();
		~Algoritmos();
		int iguales(Grafo*, Grafo*);
		Grafo*  copiar(Grafo*,Grafo*);
		void floyd(Grafo*);
		void kruskal(Grafo*);
		void prim (Grafo*);
		void Algoritmos::dijkstra(Grafo*, Grafo::Vertice);
		void problemaDelVendedor(Grafo*);
};

#endif
