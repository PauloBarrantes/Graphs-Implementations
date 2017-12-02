#include "GNDMatriz.h"
//#include "GNDLista.h"
#include "Algoritmos.h"

#include <iostream>
using namespace std;

int main(int argN, char const *argV[]){
  Grafo m1;
  Grafo m2;
  Algoritmos algoritmos;

  m1.agrVertice('a');
  m1.agrVertice('b');
  m1.agrVertice('c');
  m1.agrVertice('d');
  m1.agrVertice('e');
  m1.imprimir(cout);
  cout << m1.numVertices() << endl;

  m2.agrVertice('a');
  m2.agrVertice('b');
  m2.agrVertice('c');
  m2.agrVertice('d');
  m2.agrVertice('f');
  m2.imprimir(cout);



  m1.agrArista(m1.buscarVertice('a'),m1.buscarVertice('b'),10);
  m1.agrArista(m1.buscarVertice('a'),m1.buscarVertice('d'),5);
  m1.agrArista(m1.buscarVertice('a'),m1.buscarVertice('c'),13);
  m1.agrArista(m1.buscarVertice('e'),m1.buscarVertice('c'),20);
  m1.agrArista(m1.buscarVertice('b'),m1.buscarVertice('d'),32);
  m1.agrArista(m1.buscarVertice('e'),m1.buscarVertice('d'),1);
  m1.imprimir(cout);
  cout << endl;

  m2.agrArista(m2.buscarVertice('a'),m2.buscarVertice('b'),10);
  m2.agrArista(m2.buscarVertice('a'),m2.buscarVertice('d'),5);
  m2.agrArista(m2.buscarVertice('a'),m2.buscarVertice('c'),13);
  m2.agrArista(m2.buscarVertice('f'),m2.buscarVertice('c'),20);
  m2.agrArista(m2.buscarVertice('b'),m2.buscarVertice('d'),32);
  m2.agrArista(m2.buscarVertice('f'),m2.buscarVertice('d'),1);
  m2.imprimir(cout);
  cout << endl;

  cout << algoritmos.iguales(&m1, &m2) << endl;

  m2.modificarEtiqueta(m2.buscarVertice('f'),'e');

  cout << algoritmos.iguales(&m1, &m2) << endl;

  m2.vaciar();
  m2.imprimir(cout);
  cout << endl;

  algoritmos.copiar(&m1, &m2);
  m2.imprimir(cout);

  //algoritmos.dijkstra(&m1,m1.buscarVertice('a'));
  //algoritmos.prim(&m1);
  //algoritmos.kruskal(&m1);

  //m1.elimVertice(m1.buscarVertice('a'));
  //m1.elimVertice(m1.buscarVertice('c'));
  //m1.elimVertice(m1.buscarVertice('e'));
  //m1.imprimir(cout);
  //cout << endl;

  //m1.elimArista(m1.buscarVertice('e'),m1.buscarVertice('d'));
  //m1.elimArista(m1.buscarVertice('c'),m1.buscarVertice('e'));
  //m1.elimArista(m1.buscarVertice('a'),m1.buscarVertice('d'));
  //m1.imprimir(cout);
  //cout << endl;

  //m1.elimVertice(m1.buscarVertice('e'));
  //m1.imprimir(cout);
  //cout << endl;

  //m1.modificarEtiqueta(m1.buscarVertice('e'),'l');
  //m1.modificarPeso(m1.buscarVertice('l'),m1.buscarVertice('c'),3);
  //m1.imprimir(cout);
  //cout << endl;
}
