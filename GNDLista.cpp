#include "GNDLista.h"
#include <iostream>
using namespace std;
    // Vértice
    GNDLista::Vertice::Vertice(char* etiqueta){
        this->etiq = etiqueta;
        this->sublista = 0;
        this->numAdy = 0;
    }
    GNDLista::Vertice::~Vertice(){

    }
    //Arista
    GNDLista::Arista::Arista(Vertice* v1, Vertice* v2, int peso){
        this->VerticeA = v1;
        this->VerticeB = v2;
        this->peso = peso;
    }
    GNDLista::Arista::~Arista(){

    }
    //GrafoNoDirigido
    GNDLista::GNDLista(){
        primerVertice = 0;
        numeroVertices = 0;
    }
    GNDLista::~GNDLista(){
        delete primerVertice;
    }
    void GNDLista::vaciar(){
        delete primerVertice;
    }
    int GNDLista::vacia(){
        return !numeroVertices;
    }
    Vertice* GNDLista::agrVertice (char){

    } // Cambiar el return a vértice
    int GNDLista::peso(Vertice* ver1,Vertice* ver2){

    }
    void GNDLista::agrArista(Vertice* ver1,Vertice* ver2,int peso){

    }
    void GNDLista::modificarPeso(Vertice* ver1,Vertice* ver2, int peso){

    }
    void GNDLista::elimVertice(Vertice* vertice){

    }
    void GNDLista::elimArista(Vertice* ver1, Vertice* ver2){

    }
    void GNDLista::modificarEtiqueta(Vertice* vertice , char* etiqueta) {

    }
    char GNDLista::etiqueta(Vertice* vertice){

    }
    int GNDLista::numVertices(){
        return numeroVertices;
    }
    int GNDLista::numVerticesAdy(){

    }
    int GNDLista::adyacentes(Vertice, Vertice){

    }
