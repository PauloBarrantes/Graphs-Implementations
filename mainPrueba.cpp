#include "GNDMatriz.h"
//#include "GNDLista.h"

#include <iostream>
using namespace std;

int main(int argN, char const *argV[]){
  Grafo matriz;

  matriz.agrVertice('a');
  matriz.agrVertice('b');
  matriz.agrVertice('c');
  matriz.agrVertice('d');
  matriz.agrVertice('e');
  matriz.imprimir(cout);

  matriz.agrArista(matriz.buscarVertice('a'),matriz.buscarVertice('b'),10);
  matriz.agrArista(matriz.buscarVertice('a'),matriz.buscarVertice('d'),5);
  matriz.agrArista(matriz.buscarVertice('a'),matriz.buscarVertice('c'),13);
  matriz.agrArista(matriz.buscarVertice('e'),matriz.buscarVertice('c'),20);
  matriz.agrArista(matriz.buscarVertice('b'),matriz.buscarVertice('d'),32);
  matriz.agrArista(matriz.buscarVertice('e'),matriz.buscarVertice('d'),1);
  matriz.imprimir(cout);
  cout << endl;


  matriz.elimVertice(matriz.buscarVertice('a'));
  matriz.elimVertice(matriz.buscarVertice('c'));
  matriz.elimVertice(matriz.buscarVertice('e'));
  matriz.imprimir(cout);
  cout << endl;

  //matriz.elimArista(matriz.buscarVertice('e'),matriz.buscarVertice('d'));
  //matriz.elimArista(matriz.buscarVertice('c'),matriz.buscarVertice('e'));
  //matriz.elimArista(matriz.buscarVertice('a'),matriz.buscarVertice('d'));
  matriz.imprimir(cout);
  cout << endl;

  matriz.elimVertice(matriz.buscarVertice('e'));
  matriz.imprimir(cout);
  cout << endl;

  matriz.modificarEtiqueta(matriz.buscarVertice('e'),'l');
  matriz.modificarPeso(matriz.buscarVertice('l'),matriz.buscarVertice('c'),3);
  matriz.imprimir(cout);
  cout << endl;
}
