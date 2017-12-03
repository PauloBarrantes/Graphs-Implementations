#include "GeneradorDeGrafos.h"
#include "Relaciones1_1.h"
#include <cstdlib>

using namespace std;

GeneradorGrafos::GeneradorGrafos(){
    srand (time(NULL));
}

GeneradorGrafos::~GeneradorGrafos(){}

Grafo* GeneradorGrafos::grafoCompleto(int n){
  Grafo * grafo = new Grafo();
  int peso = 0;
  char inicial = '0';
  for(int i = 0; i < n; ++i){
    grafo->agrVertice(inicial);
    inicial++;
  }
  Grafo::Vertice v1 = grafo->primerVertice();
  Grafo::Vertice v2;

  while(v1 != 0){
    v2 = grafo->siguienteVertice(v1);
    while(v2 != 0){
      peso = rand() % 50 + 1;
      if(!grafo->adyacentes(v1,v2)){
        grafo->agrArista(v1,v2,peso);
      }
      v2 = grafo->siguienteVertice(v2);
    }
    v1 = grafo->siguienteVertice(v1);
  }
  return grafo;
}

Grafo* GeneradorGrafos::grafoCasiCompleto(int n){
  Grafo * grafo = new Grafo();
  grafo = this->grafoCompleto(n);
  Relaciones1_1<int,Grafo::Vertice> R11;
  Grafo::Vertice actual = grafo->primerVertice();
  //Establece Relaciones
  for(int i=0; i<n;++i){
    R11.agregar(i,actual);
    actual = grafo->siguienteVertice(actual);
  }
  cout << "Todo inicializado para borrar aristas" << endl;
  int v1 = 0;
  int v2 = 0;
  //quitamos 1/6 de las aristas
  for(int i = 0; i < (n*(n-1))/12; ++i){
    v1 = rand() % n;
    v2 = rand() % n;
    //cout<<v1<<", "<<v2<<endl;
    if(grafo->adyacentes(R11.imagen(v1),R11.imagen(v2))){
      grafo->elimArista(R11.imagen(v1),R11.imagen(v2));
      cout << "Eliminó arista" << endl;
    }else{
      --i;
    }
  }
  return grafo;
}

Grafo* GeneradorGrafos::grafoMuyIncompleto(int n){
  Grafo * grafo = new Grafo();
  Relaciones1_1<int,Grafo::Vertice> R11;
  //crea vertices
  char inicial = '0';
  for(int i = 0; i < n; ++i){
    grafo->agrVertice(inicial);
    inicial++;
  }

  //Establece Relaciones
  Grafo::Vertice actual = grafo->primerVertice();
  for(int i=0; i<n;++i){
    R11.agregar(i,actual);
    actual = grafo->siguienteVertice(actual);
  }

  int v1 = 0;
  int v2 = 0;
  int peso = 0;
  //quitamos 1/6 de las aristas
  for(int i = 0; n*2; ++i){
    v1 = rand() % n + 1;
    v2 = rand() % n + 1;
    peso = rand() % 50 + 1;
    grafo->agrArista(R11.imagen(v1),R11.imagen(v2),peso);
  }
  return grafo;
}
