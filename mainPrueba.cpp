//#include "GNDMatriz.h"
#include "GNDLista.h"
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

  m2.agrVertice('l');
  m2.agrVertice('m');
  m2.agrVertice('n');
  m2.agrVertice('o');
  m2.agrVertice('p');
  m2.agrVertice('q');
  m2.agrVertice('r');
  m2.agrVertice('s');


  m1.agrArista(m1.buscarVertice('a'),m1.buscarVertice('b'),10);
  m1.agrArista(m1.buscarVertice('a'),m1.buscarVertice('d'),5);
  m1.agrArista(m1.buscarVertice('a'),m1.buscarVertice('c'),13);
  m1.agrArista(m1.buscarVertice('e'),m1.buscarVertice('c'),20);
  m1.agrArista(m1.buscarVertice('b'),m1.buscarVertice('d'),32);
  m1.agrArista(m1.buscarVertice('e'),m1.buscarVertice('d'),1);
  //m1.imprimir(cout);
  cout << endl;

  m2.agrArista(m2.buscarVertice('l'),m2.buscarVertice('p'),6);
  m2.agrArista(m2.buscarVertice('l'),m2.buscarVertice('q'),10);
  m2.agrArista(m2.buscarVertice('l'),m2.buscarVertice('s'),12);
  m2.agrArista(m2.buscarVertice('l'),m2.buscarVertice('o'),25);
  m2.agrArista(m2.buscarVertice('m'),m2.buscarVertice('r'),15);
  m2.agrArista(m2.buscarVertice('m'),m2.buscarVertice('n'),10);
  m2.agrArista(m2.buscarVertice('n'),m2.buscarVertice('r'),20);
  m2.agrArista(m2.buscarVertice('n'),m2.buscarVertice('o'),22);
  m2.agrArista(m2.buscarVertice('o'),m2.buscarVertice('s'),4);
  m2.agrArista(m2.buscarVertice('p'),m2.buscarVertice('q'),4);
  m2.agrArista(m2.buscarVertice('p'),m2.buscarVertice('r'),12);
  m2.agrArista(m2.buscarVertice('q'),m2.buscarVertice('r'),1);
  m2.agrArista(m2.buscarVertice('r'),m2.buscarVertice('s'),14);

  /*
  m1.elimArista(m1.buscarVertice('e'),m1.buscarVertice('d'));
  m1.elimArista(m1.buscarVertice('c'),m1.buscarVertice('e'));
  m1.elimArista(m1.buscarVertice('a'),m1.buscarVertice('d'));
  //m1.imprimir(cout);
  cout << endl;

  m1.elimVertice(m1.buscarVertice('e'));
  m1.imprimir(cout);
  cout << endl;
  */
  ///*
  cout << "Este es el grafo 1: " << endl;
  m1.imprimir(cout);
  cout << endl;

  cout << "Floyd inicio" << endl;
  algoritmos.floyd(&m1);
  cout << "Floyd fin" << endl;


  cout << "Kruskal inicio" << endl;
  algoritmos.kruskal(&m1);
  cout << "Kruskal fin" << endl;


  cout << "Prim inicio" << endl;
  algoritmos.prim(&m1);
  cout << "Prim fin" << endl;


  cout << "Dijkstra inicio" << endl;
  algoritmos.dijkstra(&m1, m1.buscarVertice('d'));
  cout << "Dijkstra fin" << endl;
  cout << endl;

  cout << "Problema del vendedor inicion" << endl;
  algoritmos.problemaDelVendedor(&m1);
  cout << "Problema del vendedor fin" << endl;
  cout << endl;
  

  //m2.imprimir(cout);
  cout << endl;

  return 0;
}
