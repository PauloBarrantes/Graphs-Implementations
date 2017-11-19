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

<<<<<<< HEAD
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
=======
    Vertice(char){

    }
    ~Vertice(){

    }

    Arista(Vertice*, Vertice*, int){

    }
    ~Arista(){

    }

    public:
        Grafo(){

        }
        ~Grafo(){

        }
        void vaciar(){

        }
        int vacia(){

        }
        Vertice agrVertice (char) // Cambiar el return a vértice
        int peso(Vertice,Vertice);
        void agrArista(Vertice,Vertice,int);
        void modificarPeso(Vertice,Vertice, int);
        void elimVertice(Vertice);
        void elimArista(Vertice, Vertice);
        void modificarEtiqueta(Vertice, char);
        char etiqueta(Vertice);
        int numVertices();
        int numVerticesAdy();
        int adyacentes(Vertice, Vertice)
>>>>>>> e612b0485cdf065f73c47f32c86f1937b2acf12a
