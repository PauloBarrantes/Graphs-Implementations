#include "GNDLista.h"
#include <iostream>
using namespace std;
    // Vértice
    Grafo::Caja::Caja(char etiqueta){
        this->etiq = etiqueta;
        this->sublista = 0;
        this->siguienteCaja = 0;
        this->numAdy = 0;
    }
    Grafo::Caja::~Caja(){
        if(sublista != 0){
            delete this->sublista;
        }

        if(siguienteCaja!=0){
            delete this->siguienteCaja;
        }
    }

    ostream& Grafo::Caja::imprimirC(ostream& salida){
        salida << "Vertice: " << this->etiq << endl;
        salida << "Adyacentes:"<< endl;
        if(sublista != 0){
            (this->sublista)->imprimirA(salida);
        }

        if(siguienteCaja != 0){
            (this->siguienteCaja)->imprimirC(salida);
        }
        return salida;
    }
    //Arista
    ostream& Grafo::Arista::imprimirA(ostream& salida){
        salida << "---->"<<(this->verticeA)->etiq<< " Peso: " << this->peso <<endl;
        if(siguienteArista != 0){
            (this->siguienteArista)->imprimirA(salida);
        }
        return salida;
    }

    Grafo::Arista::Arista( Grafo::Vertice v1, Grafo::Vertice v2, int peso){
        this->verticeA = v1;
        this->verticeB = v2;

        this->peso = peso;
        this->siguienteArista = 0;
    }
    Grafo::Arista::~Arista(){
        if(siguienteArista!=0){
            delete this->siguienteArista;
        }
    }
    //GrafoNoDirigido
    Grafo::Grafo(){
        primero = 0;
        ultimo = 0;
        numeroVertices = 0;
    }
    Grafo::~Grafo(){
        delete primero;
    }
    void Grafo::vaciar(){
        delete primero;
        primero = 0;
        ultimo = 0;
        numeroVertices = 0;
    }
    int Grafo::vacia(){
        return !numeroVertices;
    }
    Grafo::Vertice Grafo::agrVertice (char etiqueta){
        Grafo::Vertice vertice = new Caja(etiqueta);
        if(vacia()){
            primero = vertice;
            ultimo = vertice;
        }else{
            ultimo->siguienteCaja = vertice;
            ultimo = vertice;
        }

        numeroVertices++;

        return vertice;
    } // Cambiar el return a vértice
    int Grafo::peso(Grafo::Vertice ver1,Grafo::Vertice ver2){
        Grafo::Arista* arista = ver1->sublista;
        int peso = 0; // Asumiendo que el usuario no va colocar un peso de una arista de valores negativos o cero.
        while(arista != 0 && !peso){
            if(arista->verticeA == ver2){
                peso = arista->peso;
            }else{
                arista = arista->siguienteArista;
            }
        }
        return peso;
    }
    void Grafo::agrArista(Grafo::Vertice ver1,Grafo::Vertice ver2,int peso){
            Grafo::Arista* arista1 = new Arista(ver1,ver2, peso);
            Grafo::Arista* arista2 = new Arista(ver2,ver1, peso);

            if(ver1 == 0){
                ver1->sublista = arista2;
            }else{
                arista2->siguienteArista = ver1->sublista;
                ver1->sublista = arista2;
            }

            if(ver2 == 0){
                ver2->sublista = arista1;
            }else{
                arista1->siguienteArista = ver2->sublista;
                ver2->sublista = arista1;
            }
            (ver1->numAdy)++;
            (ver2->numAdy)++;
            numeroAristas++;

    }
    void Grafo::modificarPeso(Grafo::Vertice ver1,Grafo::Vertice ver2, int peso){
        Arista* arista = ver1->sublista;
        while(arista != 0 && !peso){
            if(arista->verticeA == ver2){
                arista->peso = peso;
            }else{
                arista = arista->siguienteArista;
            }
        }
        arista = ver2->sublista;
        while(arista != 0 && !peso){
            if(arista->verticeA == ver1){
                arista->peso = peso;
            }else{
                arista = arista->siguienteArista;
            }
        }
    }
    // Asumiendo que solo vamos a eliminar vértices aislados
    void Grafo::elimVertice(Grafo::Vertice vertice){
        Grafo::Vertice v = primero;
        int eliminado = 0;
        if(primero == vertice){
            primero = vertice->siguienteCaja;
            vertice->siguienteCaja = 0;
            delete v;
        }else{
            while(v->siguienteCaja != 0 && !eliminado){
                if(v->siguienteCaja == vertice){
                    Grafo::Vertice victima = v->siguienteCaja;
                    v->siguienteCaja = (v->siguienteCaja)->siguienteCaja; // Lo brincamos
                    victima->siguienteCaja = 0;
                    delete victima;
                    eliminado = 1;
                }else{
                    v = v->siguienteCaja;
                }
            }
            if(v->siguienteCaja != 0){
                ultimo = v;
            }
        }
        --numeroVertices;
    }
    void Grafo::elimArista(Grafo::Vertice ver1, Grafo::Vertice ver2){
            Grafo::Arista* arista1 = ver1->sublista;
            if(arista1->verticeA == ver2){
                ver1->sublista = arista1->siguienteArista;
                arista1->siguienteArista = 0;
                delete arista1;
            }else{
                if(arista1 != 0){
                    int encontrado = 0;
                    while(arista1->siguienteArista != 0 && !encontrado){

                        if((arista1->siguienteArista)->verticeA == ver2){
                            Grafo::Arista* victima = arista1->siguienteArista;
                            arista1->siguienteArista = (arista1->siguienteArista)->siguienteArista;
                            victima->siguienteArista = 0;
                            encontrado =1;
                            delete victima;
                        }else{
                            arista1 = arista1->siguienteArista;
                        }
                    }

                }

            }

            Grafo::Arista* arista2 = ver2->sublista;
            if(arista2->verticeA == ver1){
                ver2->sublista = arista2->siguienteArista;
                arista2->siguienteArista = 0;
                delete arista2;
            }else{
                if(arista2 != 0 ){
                    int encontrado = 0;
                    while(arista2->siguienteArista != 0 && !encontrado){

                        if((arista2->siguienteArista)->verticeA == ver1){
                            Grafo::Arista* victima =  arista2->siguienteArista;
                            arista2->siguienteArista = victima->siguienteArista; //Saltamos la arista que vamos a eliminar
                            victima->siguienteArista = 0;
                            encontrado =1;
                            delete victima;
                        }else{
                            arista2 = arista2->siguienteArista;
                        }
                    }
                }

            }
        (ver1->numAdy)--;
        (ver2->numAdy)--;
        --numeroAristas;
    }
    void Grafo::modificarEtiqueta(Grafo::Vertice vertice , char etiqueta) {
        vertice->etiq = etiqueta;
    }
    char Grafo::etiqueta(Grafo::Vertice vertice){
        return vertice->etiq;
    }
    int Grafo::numVertices(){
        return numeroVertices;
    }
    int Grafo::numAristas(){
        return numeroAristas;
    }
    int Grafo::numVerticesAdy(Grafo::Vertice vertice){
        return vertice->numAdy;
    }
    int Grafo::adyacentes(Grafo::Vertice vertice1 , Grafo::Vertice vertice2){
        Grafo::Arista* arista = vertice1->sublista;
        int encontrado = 0;
        while(arista!=0  && !encontrado){
            if(arista->verticeA == vertice2){
                encontrado = 1;
            }else{
                arista = arista->siguienteArista;
            }
        }

        return encontrado;
    }

    Grafo::Vertice Grafo::primerVertice(){
        return primero;
    }
    Grafo::Vertice Grafo::siguienteVertice(Grafo::Vertice vertice){
        return vertice->siguienteCaja;
    }
    Grafo::Vertice Grafo::primerVerticeAdy(Grafo::Vertice vertice){
        Grafo::Vertice v = 0;
        if(vertice->sublista){
          v = (vertice->sublista)->verticeA;
        }
        return v;
    }
    Grafo::Vertice Grafo::siguienteVerticeAdy(Grafo::Vertice vertice1, Grafo::Vertice vertice2){
        Grafo::Arista* arista = vertice1->sublista;
        int encontrado = 0;
        while(arista!=0 && !encontrado){
            if(arista->verticeB == vertice2){
                //cout << "1" << endl;
                encontrado=1;
            }else{
                arista = arista->siguienteArista;
            }
        }

        if(encontrado){
          return arista->verticeA;
        }else{
          return 0;
        }
    }
    Grafo::Vertice Grafo::buscarVertice(char etiqueta){
        Grafo::Vertice v = primero;
        int encontrado = 0;
        while(v!= 0  && !encontrado){
            if( v->etiq == etiqueta ){
                encontrado = 1;
            }else{
                v = v->siguienteCaja;
            }
        }

        if(v == 0){
            std::cerr << "El vértice no está en el grafo" << '\n';
        }
        return v;
    }
    ostream& Grafo::imprimir(ostream& salida){
        primero->imprimirC(salida);
        return salida;
    }
