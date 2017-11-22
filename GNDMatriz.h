#ifndef grafonodirigidoMatriz_2017
#define grafonodirigidoMatriz_2017

#include <iostream>
#define M 11

class Grafo {
    private:
      char* vectorEtiquetas;
  		int** matrizPesos;
  		int ultimo;

  		//Generaliza el corrimiento
  		void corrimientoEnMatriz(int,int,int,int,int,int);

    public:
  		typedef int Vertice;

      Grafo();
      ~Grafo();
      void vaciar();
      int vacia();

  		void agrArista(Vertice,Vertice,int);
  		Vertice agrVertice (char);

      void elimVertice(Vertice);
      void elimArista(Vertice,Vertice);

  		char etiqueta(Vertice);
  		int adyacentes(Vertice,Vertice);

      void modificarEtiqueta(Vertice,char);
  		void modificarPeso(Vertice,Vertice,int);

  		int numAristas();
      int numVertices();
      int numVerticesAdy(Vertice);
  		int peso(Vertice,Vertice);

  		Vertice primerVertice();
  		Vertice siguienteVertice(Vertice v);
  		Vertice primerVerticeAdy(Vertice v);
  		Vertice siguienteVerticeAdy(Vertice v1, Vertice v2);

      Vertice buscarVertice(char);
      std::ostream& imprimir(std::ostream&);
};

#endif
