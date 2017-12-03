#ifndef algoritmos_2017
#define algoritmos_2017

#include "DiccionarioLSE.h"
#include "CPArbol.h"
#include "Relaciones1_1.h"
#include "CDCD.h"
#include "GNDMatriz.h"
//#include "GNDLista.h"

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
		int haySolucion;

		Grafo::Vertice * solucionActual;
		Grafo::Vertice * solucionGanadora;
		DiccionarioLSE<Grafo::Vertice> diccionarioH;
		int numSolucionesFactibles;
		int numSolucionesOptimas;
	public:
		/*!
		   \brief "Constructor de la clase Algoritmos"
		   \param "No recibe parametros"
		   \return "No retorna nada"
		*/
		Algoritmos();
		~Algoritmos();
		/*!
		   \brief "Determina si dos grafos son iguales"
		   \param "Recibe como parametro dos grafos inicializados"
		   \return "Retorna un entero booleano"
		*/
		int iguales(Grafo*, Grafo*);
		/*!
		   \brief "Copia el grafo1 en el grafo2"
		   \param "Recibe dos grafos como parametros"
		   \return "Retorna el grafo2, que es la copia del grafo1"
		*/
		Grafo*  copiar(Grafo*,Grafo*);
		/*!
		   \brief "Encuentra las distancias mínimas de todos los vértices a todos los demás"
		   \param "Recibe como parametro un grafo"
		   \return "No retorna nada"
		*/
		void floyd(Grafo*);
		/*!
		   \brief "Encuentra el árbol de mínimo costo"
		   \param "Recibe un grafo como parametro"
		   \return "No retorna nada"
		*/
		void kruskal(Grafo*);
		/*!
		   \brief "Encuentra el árbol de mínimo costo"
		   \param "Recibe como parametro un grafo"
		   \return "No retorna nada"
		*/
		void prim (Grafo*);
		/*!
		   \brief "Encuentra las distancias mínimas de un vértice a todos los demás "
		   \param "Recibimos como paramétros un grafo y un vértice"
		   \return "No retorna nada"
		*/
		void dijkstra(Grafo*, Grafo::Vertice);
		/*!
		   \brief "Problema del Vendedor no recursivo donde inicializamos las cosas para empezar"
		   \param "Recibe un grafo"
		   \return "No retorna"
		*/
		void problemaDelVendedor(Grafo*);
		/*!
		   \brief "Algoritmo recursivo que crea el ciclo hamilton de menor costo usando búsqueda exhaustiva"
		   \param "Recibe un grafo, un vértice y un número entero"
		   \return "No retorna nada"
		*/
		void problemaDelVendedorR(Grafo*, Grafo::Vertice,int);

};

#endif
