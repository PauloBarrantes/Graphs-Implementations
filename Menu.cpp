#include "Menu.h"
#include <iostream>
using namespace std;


Menu::Menu(){
    controlador();
}
Menu::~Menu(){
    delete grafo1;
    delete grafo2;
}
void Menu::controlador(){
    int respuesta = 0;
    cout << "Bienvenido al programa de pruebas de grafos" <<endl;
    cout << "Presiona 1 para -Utilizar los operadores básicos del grafo- "<<endl;
    cout << "Presiona 2 para -Utilizar los algoritmos del grafo- "<<endl;

    cin>> respuesta;
    if(respuesta == 1){
        obGrafos();
    }else{
        if(respuesta == 2){
            algoritmosGrafos();
        } else{
            std::cerr << "Número Inválido" << '\n';
            controlador();
        }
    }
}

void Menu::obGrafos(){
    InstruccionesOB();
    int instruccion = 0;
    cin >> instruccion;

    switch (instruccion) {
        case 0:
            Salir();
        break;
        case 1:
            iniciar();
        break;
        case 2:
            destruir();
        break;
        case 3:
            vaciar();
        break;
        case 4:
            vacia();
        break;
        case 5:
            agrVertice();
        break;
        case 6:
            agrArista();
        break;
        case 7:
            elimVertice();
        break;
        case 8:
            elimArista();
        break;
        case 9:
            modificarEtiqueta();
        break;
        case 10:
            modificarPeso();
        break;
        case 11:
            peso();
        break;
        case 12:
            numVertices();
        break;
        case 13:
            numVerticesAdy();
        break;
        case 14:
            adyacentes():
        break;
        case 15:
            primerVertice();
        break;
        case 16:
            siguienteVertice();
        break;
        case 17:
            primerVertice();
        break;
        case 18:
            siguienteVerticeAdy();
        break;
    }
}

void Menu::InstruccionesOB(){
    Cout<<"-----Instrucciones para realizar pruebas con los operadores básicos-----" <<endl;
    Cout<<" (0) -> Para Salir" <<endl;
    Cout<<" (1) -> Iniciar el grafo" <<endl;
    Cout<<" (2) -> Destruir el grafo" <<endl;
    Cout<<" (3) -> Vaciar el grafo" <<endl;
    Cout<<" (4) -> Ver si el grafo está vació" <<endl;
    Cout<<" (5) -> Agregar un vértice" <<endl;
    Cout<<" (6) -> Agregar una arista" <<endl;
    Cout<<" (7) -> Eliminar un vértice" <<endl;
    Cout<<" (8) -> Eliminar una arista" <<endl;
    Cout<<" (9) -> Modificar la etiqueta de un vértice" <<endl;
    Cout<<" (10) -> Modificar el peso de una arista" <<endl;
    Cout<<" (11) -> Retornar el peso de una arista" <<endl;
    Cout<<" (12) -> Retornar el número de vértices del grafo" <<endl;
    Cout<<" (13) -> Retornar el número de vértices adyacentes a un vértice" <<endl;
    Cout<<" (14) -> Ver si 2 vértices son adyacentes"<<endl;
    Cout<<" (15) -> Para ver el primer Vértice del grafo"<<endl;
    Cout<<" (16) -> Para ver el siguiente vértice de otro vértice"<<endl;
    Cout<<" (17) -> Para ver el primer Vértice adyacente a un vértice "<<endl;
    Cout<<" (18) -> Para ver el siguiente Vértice adyacente a un vértice"<<endl;
}
void Menu::Salir(){

}
void Menu::iniciar(){

}
void Menu::destruir(){

}
void Menu::vaciar(){

}
void Menu::vacia(){

}
void Menu::agrVertice (){

}
void Menu::peso(){

}
void Menu::agrArista(){

}
void Menu::modificarPeso(){

}
void Menu::elimVertice(){

}
void Menu::elimArista(){

}
void Menu::modificarEtiqueta(){

}
void Menu::etiqueta(){

}
void Menu::numVertices(){

}
void Menu::numVerticesAdy(){

}
void Menu::adyacentes(){

}
void Menu::primerVertice(){

}
void Menu::siguienteVertice(){

}
void Menu::primerVerticeAdy(){

}
void Menu::siguienteVerticeAdy(){

}

void Menu::algoritmosGrafos(){
    InstruccionesAlgoritmos();
    int instruccion = 0;
    cin >> instruccion;
    switch (instruccion) {
        case 0:
            Salir();
        case 1:
            dijkstra();
        break;
        case 2:
            floyd();
        break;
        case 3:
            prim();
        break;
        case 4:
            kruskal();
        break;
        case 5:
            copiar();
        break;
        case 6:
            iguales();
        break;
        case 7:
            problemaDelVendedor();
        break;
    }
}

void Menu::InstruccionesAlgoritmos(){
    Cout<<"-----Instrucciones para realizar pruebas con los algoritmos-----" <<endl;
    Cout<<" (0) -> Para Salir" <<endl;
    Cout<<" (1) -> Aplicar Dijkstra" <<endl;
    Cout<<" (2) -> Aplicar Floyd" <<endl;
    Cout<<" (3) -> Aplicar Prim" <<endl;
    Cout<<" (4) -> Aplicar Kruskal" <<endl;
    Cout<<" (5) -> Copiar un grafo" <<endl;
    Cout<<" (6) -> Averiguar si dos grafos son iguales" <<endl;
    Cout<<" (7) -> Resolver el Problema del Vendedor mediante Búsqueda Exhaustiva Pura" <<endl;
}

void Menu::dijkstra (){

}
void Menu::floyd (){

}
void Menu::prim (){

}
void Menu::kruskal (){

}
void Menu::copiar (){

}
void Menu::iguales (){

}
void Menu::problemaDelVendedor (){

}
