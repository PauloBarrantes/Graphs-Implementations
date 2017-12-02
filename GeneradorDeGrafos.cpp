#include "GeneradorDeGrafos.h"
#include <cstdlib>
rand
using namespace std;

GeneradorGrafos::GeneradorGrafos(){}

GeneradorGrafos::~GeneradorGrafos(){}

Grafo* GeneradorGrafos::grafoCompleto(int n){
  srand (time(NULL));
  Grafo * grafo = new Grafo();
  int peso = 0;
  char inicial = "0";
  for(int i = 0; i < n; ++i){
    grafo->agrVertice(inicial);
    inicial++;
  }
  Grafo::Vertice v1 = grafo->primerVertice();
  Grafo::Vertice v2 = grafo->siguienteVertice(v1);
  for(int i = 0; i < n; ++i){
    for(int j = 0; i < n; ++j){
      peso = rand() % 50 + 1;
      if(!grafo->adyacentes(v1,v2)){
        grafo->agrArista(v1,v2,peso);
      }
      v2 = grafo->siguienteVertice(v2);
    }
    grafo->siguienteVertice(v1);
  }
  return grafo;
}

Grafo* GeneradorGrafos::grafoCasiCompleto(int n){
  Grafo * grafo = new Grafo();

  return grafo;
}

Grafo* GeneradorGrafos::grafoMuyIncompleto(int n){
  Grafo * grafo = new Grafo();

  return grafo;
}
