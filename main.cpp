#include <iostream>
#include "DiccionarioLSE.h"
#include "GNDLista.h"
#include "CDCD.h"
using namespace std;

int main(int argc, char const *argv[]) {


    cout<< "Pruebas del Grafo:" <<endl;
    Grafo* grafito = new Grafo();

    Grafo::Vertice v1  = grafito->agrVertice('a');
    Grafo::Vertice v2  =grafito->agrVertice('b');
    Grafo::Vertice v3  =grafito->agrVertice('c');
    Grafo::Vertice v4  =grafito->agrVertice('d');
    grafito->imprimir(cout);
    cout << "-----------------------------------------------------"<< endl;
    grafito->agrArista(v1, v2, 3);
    grafito->agrArista(v3, v4, 30);
    grafito->agrArista(v2, v4, 10);
    grafito->agrArista(v1, v4, 6);

    grafito->imprimir(cout);

    return 0;

}
