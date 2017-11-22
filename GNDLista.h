#ifndef grafonodirigido_2017
#define grafonodirigido_2017
#include <iostream>
using namespace std;
class Grafo {
    class Caja;
    class Arista;
    private:
        int numeroVertices;
        int numeroAristas;
        class Caja{
            public:
                char etiq;
                Caja* siguienteCaja;
                Arista* sublista;
                int numAdy;
                Caja(char);
                ~Caja();
                ostream& imprimirC(ostream&);
        };
        class Arista{
            public:
                int peso;
                Caja* verticeA;
                Caja* verticeB;

                Arista* siguienteArista;
                Arista(Caja*,Caja*, int);
                ~Arista();
                ostream& imprimirA(ostream&);
        };
        Caja* ultimo;
        Caja* primero;

    public:
        typedef Caja* Vertice;
        Grafo();
        ~Grafo();
        void vaciar();
        int vacia();
        Vertice agrVertice (char); // Cambiar el return a vértice
        int peso(Vertice,Vertice);
        void agrArista(Vertice,Vertice,int);
        void modificarPeso(Vertice,Vertice, int);
        void elimVertice(Vertice);
        void elimArista(Vertice, Vertice);
        void modificarEtiqueta(Vertice, char);
        char etiqueta(Vertice);
        int numVertices();
        int numAristas();
        int numVerticesAdy(Vertice);
        int adyacentes(Vertice, Vertice);
        ostream& imprimir(ostream&);
        Vertice primerVertice();
        Vertice siguienteVertice(Vertice);
        Vertice primerVerticeAdy(Vertice);
        Vertice siguienteVerticeAdy(Vertice, Vertice);
        Vertice buscarVertice(char);

};

#endif
