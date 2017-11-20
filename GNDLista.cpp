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


    //Arista
    ostream& Grafo::Arista::imprimirA(ostream& salida){
        salida << "---->"<<(this->verticeA)->etiq<< " Peso: " << this->peso <<endl;
        if(siguienteArista != 0){
            (this->siguienteArista)->imprimirA(salida);
        }
        return salida;
    }

    Grafo::Arista::Arista( Grafo::Vertice v1, int peso){
        this->verticeA = v1;
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
        Arista* arista = ver1->sublista;
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
        Arista* arista1 = new Arista(ver1, peso);
        Arista* arista2 = new Arista(ver2, peso);

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

        if(primero == vertice){
            primero = vertice->siguienteCaja;
            vertice->siguienteCaja = 0;
            delete v;
        }else{
            while(v->siguienteCaja != 0){
                if(v->siguienteCaja == vertice){
                    v->siguienteCaja = (v->siguienteCaja)->siguienteCaja; // Lo brincamos
                    (v->siguienteCaja)->siguienteCaja = 0;
                    delete v->siguienteCaja;
                }else{
                    v = v->siguienteCaja;
                }
            }
            if(v->siguienteCaja != 0){

            }
        }

    }
    void Grafo::elimArista(Grafo::Vertice ver1, Grafo::Vertice ver2){
        Grafo::Vertice v = primero;
        int encontrado = 0;
        while(v!= 0  && !encontrado){
            if(v== ver1 || v == ver2){
                encontrado = 1;
            }else{
                v = v->siguienteCaja;
            }
        }
    }
    void Grafo::modificarEtiqueta(Grafo::Vertice vertice , char etiqueta) {
        Grafo::Vertice v = primero;
        int encontrado = 0;
        while(v!= 0  && !encontrado){
            if( v== vertice ){
                encontrado = 1;
            }else{
                v = v->siguienteCaja;
            }
        }
        if(v == 0){
            std::cerr << "El vértice no está en el grafo" << '\n';
        }else{
            v->etiq = etiqueta;
        }
    }
    char Grafo::etiqueta(Grafo::Vertice vertice){
        char etiqueta = -1 ;
        Grafo::Vertice v = primero;
        int encontrado = 0;
        while(v!= 0  && !encontrado){
            if( v== vertice ){
                encontrado = 1;
            }else{
                v = v->siguienteCaja;
            }
        }

        if(v == 0){
            std::cerr << "El vértice no está en el grafo" << '\n';
        }else{
            etiqueta = v->etiq;
        }
        return etiqueta;
    }
    int Grafo::numVertices(){
        return numeroVertices;
    }

    int Grafo::numVerticesAdy(Grafo::Vertice vertice){
        int numAdy = -1;
        Grafo::Vertice v = primero;
        int encontrado = 0;
        while(v!= 0  && !encontrado){
            if( v== vertice ){
                encontrado = 1;
            }else{
                v = v->siguienteCaja;
            }
        }

        if(v == 0){
            std::cerr << "El vértice no está en el grafo" << '\n';
        }else{
            numAdy = v->numAdy;
        }

        return numAdy;
    }
    int Grafo::adyacentes(Grafo::Vertice vertice1 , Grafo::Vertice vertice2){
        int booleano = 0;

    }

    Grafo::Vertice Grafo::primerVertice(){
        return primero;
    }
    Grafo::Vertice Grafo::siguienteVertice(Grafo::Vertice vertice){
        return vertice->siguienteCaja;
    }
    Grafo::Vertice Grafo::primerVerticeAdy(Grafo::Vertice vertice){
        Grafo::Vertice verticeady = 0;
        Grafo::Vertice v = primero;
        int encontrado = 0;
        while(v!= 0  && !encontrado){
            if( v== vertice ){
                encontrado = 1;
            }else{
                v = v->siguienteCaja;
            }
        }

        if(v == 0){
            std::cerr << "El vértice no está en el grafo" << '\n';
        }else{

        }
    }
    Grafo::Vertice Grafo::siguienteVerticeAdy(Grafo::Vertice vertice){

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
