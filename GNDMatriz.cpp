#include "GNDMatriz.h"
using namespace std;

void Grafo::corrimientoEnMatriz(int inicioF,int paradaF,int inicioC, int paradaC,int corrF, int corrC){
  for(int f = inicioF; f < paradaF; ++f){
    for(int c = inicioC; c < paradaC; ++c){
      matrizPesos[f][c] = matrizPesos[f + 1*corrF][c + 1*corrC];
    }
  }
}

Grafo::Grafo(){
  ultimo = 0;
  vectorEtiquetas = new char[M];

  matrizPesos = new int* [M];
  for(int f = 1; f < M; ++f){
    matrizPesos[f] = new int[M];
    for(int c = 0; c < M; ++c){
      matrizPesos[f][c] = -1;
    }
  }
}

Grafo::~Grafo(){
  delete vectorEtiquetas;

  for(int f = M-1; f > 0; --f){
    delete [] matrizPesos[f];
  }
  delete  [] matrizPesos;
}

void Grafo::vaciar(){
  ultimo = 0;
}

int Grafo::vacia(){
  return ultimo;
}



void Grafo::agrArista(Vertice v1, Vertice v2, int peso){
  matrizPesos[v1][v2] = peso;
  matrizPesos[v2][v1] = peso;
}

Grafo::Vertice Grafo::agrVertice (char etqt){
  ++ultimo;
  vectorEtiquetas[ultimo] = etqt;

  //Rellena la nueva fila y columna con -1.
  for(int i = 1; i <= ultimo; ++i){
    matrizPesos[ultimo][i] = -1;
    matrizPesos[i][ultimo] = -1;
  }

  return ultimo;
}

void Grafo::elimVertice(Vertice v){
  if(!primerVerticeAdy(v)){
    //Esto es para elminarlo del vector
    for(int i = v; i < ultimo; ++i){
      vectorEtiquetas[i] = vectorEtiquetas[i+1];
    }

    //Hacemos los corrimiento en la matriz.
    //Primer caso especial, filas menores a v, con columna mayores a v
    corrimientoEnMatriz(1,v,v,ultimo,0,1);

    //Segundo caso especial columnas menores a v, con filas mayores a v
    corrimientoEnMatriz(v,ultimo,1,v,1,0);

    //Caso generalizado
    corrimientoEnMatriz(v,ultimo,v,ultimo,1,1);

    --ultimo;
  }
}

void Grafo::elimArista(Vertice v1, Vertice v2){
  matrizPesos[v1][v2] = -1;
  matrizPesos[v2][v1] = -1;
}

char Grafo::etiqueta(Vertice v){
  return vectorEtiquetas[v];
}

int Grafo::adyacentes(Vertice v1, Vertice v2){
  int siExiste = 1;

  if(matrizPesos[v1][v2] == -1){
    siExiste = 0;
  }

  return siExiste;
}

void Grafo::modificarEtiqueta(Vertice v, char etqt){
  vectorEtiquetas[v] = etqt;
}

void Grafo::modificarPeso(Vertice v1, Vertice v2, int peso){
  matrizPesos[v1][v2] = peso;
  matrizPesos[v2][v1] = peso;
}

int Grafo::numAristas(){
  int num = 0;
  for(int f = 1; f <= ultimo; ++f){
    for(int c = 1; c <= ultimo; ++c){
      if(matrizPesos[f][c] != -1){
        ++num;
      }
    }
  }
  return num;
}

int Grafo::numVertices(){
  return ultimo;
}

int Grafo::numVerticesAdy(Vertice v){
  int num = 0;
  for(int c = 1; c <= ultimo; ++c){
    if(matrizPesos[v][c] == -1){
      ++num;
    }
  }
  return num;
}

int Grafo::peso(Vertice v1, Vertice v2){
  return matrizPesos[v1][v2];
}



Grafo::Vertice Grafo::primerVertice(){
  Vertice primero = 0;

  if(ultimo){
    primero = 1;
  }

  return primero;
}

Grafo::Vertice Grafo::siguienteVertice(Vertice v){
  Vertice ste = 0;

  if(v+1 <= ultimo){
    ste = v+1;
  }

  return ste;
}

Grafo::Vertice Grafo::primerVerticeAdy(Vertice v){
  Vertice vAdy = 1;
  while(vAdy <= ultimo && matrizPesos[v][vAdy] == -1){
    ++vAdy;
  }

  if(vAdy > ultimo){
    vAdy = 0;
  }

  return vAdy;
}

Grafo::Vertice Grafo::siguienteVerticeAdy(Vertice v1, Vertice v2){
  Vertice vAdy = v2+1;
  while(vAdy <= ultimo && matrizPesos[v1][vAdy] == -1){
    ++vAdy;
  }

  if(vAdy > ultimo){
    vAdy = 0;
  }

  return vAdy;
}

Grafo::Vertice Grafo::buscarVertice(char etq){
  Vertice posEtq = 0;
  Vertice actual = 1;
  int encontrado = 0;

  while(actual <= ultimo && !encontrado){
    if(vectorEtiquetas[actual] == etq){
      posEtq = actual;
      encontrado = 1;
    }
    ++actual;
  }

  return posEtq;
}

ostream& Grafo::imprimir(ostream& salida){
  Vertice ady = 0;
  for(Vertice f = 1; f <= ultimo; ++f){
    salida << "Vetice: "<< vectorEtiquetas[f] << endl;
    ady = primerVerticeAdy(f);
    if(ady){
      salida << "Vértices adyacentes: ";
      while(ady != 0){
        salida << "- (" << vectorEtiquetas[ady] << "," << matrizPesos[f][ady] << ")";
        ady = siguienteVerticeAdy(f,ady);
      }
      salida << endl;
    }
  }
  return salida;
}
