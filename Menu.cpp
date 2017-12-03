#include "Menu.h"
#include <iostream>
#include "Algoritmos.h"
using namespace std;


Menu::Menu(){
    algoritmo = new Algoritmos();
    grafo1 = 0;
    grafo2 = 0;
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
    int seguir = 1;
    do{
        cin >> instruccion;
        switch (instruccion) {
            case 0:
                seguir = 0;
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
                adyacentes();
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
    } while (seguir);
}

void Menu::InstruccionesOB(){
    cout<<"-----Instrucciones para realizar pruebas con los operadores básicos-----" <<endl;
    cout<<" (0) -> Para Salir" <<endl;
    cout<<" (1) -> Iniciar el grafo" <<endl;
    cout<<" (2) -> Destruir el grafo" <<endl;
    cout<<" (3) -> Vaciar el grafo" <<endl;
    cout<<" (4) -> Ver si el grafo está vació" <<endl;
    cout<<" (5) -> Agregar un vértice" <<endl;
    cout<<" (6) -> Agregar una arista" <<endl;
    cout<<" (7) -> Eliminar un vértice" <<endl;
    cout<<" (8) -> Eliminar una arista" <<endl;
    cout<<" (9) -> Modificar la etiqueta de un vértice" <<endl;
    cout<<" (10) -> Modificar el peso de una arista" <<endl;
    cout<<" (11) -> Retornar el peso de una arista" <<endl;
    cout<<" (12) -> Retornar el número de vertices del grafo" <<endl;
    cout<<" (13) -> Retornar el número de vertices adyacentes a un vértice" <<endl;
    cout<<" (14) -> Ver si 2 vertices son adyacentes"<<endl;
    cout<<" (15) -> Para ver el primer Vértice del grafo"<<endl;
    cout<<" (16) -> Para ver el siguiente vértice de otro vértice"<<endl;
    cout<<" (17) -> Para ver el primer Vértice adyacente a un vértice "<<endl;
    cout<<" (18) -> Para ver el siguiente Vértice adyacente a un vértice"<<endl;
}

void Menu::iniciar(){
    grafo1 = new Grafo();
    cout<< "Grafo inicializado correctamente" <<endl;
}
void Menu::destruir(){
    if(grafo1 != 0){
        delete grafo1;
        cout <<"Grafo destruido satisfactoriamente" <<endl;
    }
}
void Menu::vaciar(){
    grafo1->vaciar();
    cout<<"Vaciado Satisfactoriamente" <<endl;
}
void Menu::vacia(){
    if(grafo1->vacia()){
        cout<<"El grafo esta vacio" <<endl;
    }else{
        cout << "El grafo no está vacio" <<endl;
    }
}
void Menu::agrVertice (){
    char etiqueta = ' ' ;
    cout << "Digite el vertice que desea agregar al grafo"<<endl;
    cin >>etiqueta;
    grafo1->agrVertice(etiqueta);
    cout << "Agregado Satisfactoriamente"<<endl;
}
void Menu::peso(){
    char vert1 = ' ';
    char vert2 = ' ';
    Grafo::Vertice vertice1;
    Grafo::Vertice vertice2;
    cout << "Digite los dos vertices donde va la arista que desea" <<endl;
    cout << "Vertice 1:" <<endl;
    cin >>vert1;
    cout << endl << "Vertice 2: " <<endl;
    cin >> vert2;
    cout << endl;

    vertice1 =grafo1->buscarVertice(vert1);
    vertice2 =grafo1->buscarVertice(vert2);
    cout << "El peso de la arista es de:" <<grafo1->peso(vertice1, vertice2) <<endl;
}
void Menu::agrArista(){
    char vert1 = ' ';
    char vert2 = ' ';
    int peso = 0;
    Grafo::Vertice vertice1;
    Grafo::Vertice vertice2;
    cout << "Digite los dos vertices donde desea que vaya la arista " <<endl;
    cout << "Vertice 1:" <<endl;
    cin >>vert1;
    cout << endl << "Vertice 2: " <<endl;
    cin >> vert2;
    cout << endl;
    vertice1 = grafo1->buscarVertice(vert1);
    vertice2 = grafo1->buscarVertice(vert2);
    if( !grafo1->adyacentes(vertice1,vertice2) || !grafo1->adyacentes(vertice1,vertice2)){
        cout << "Digite el peso de la arista" <<endl;
        cin >>peso;
        cout <<endl;

        grafo1->agrArista(vertice1,vertice2, peso);

        cout<< "Arista creada satisfactoriamente de " << vert1 << " <---> " << vert2 << " con peso: " << peso <<endl;

    }else{
        std::cerr << "La arista ya existe" << '\n';
    }

}
void Menu::modificarPeso(){
    char vert1 = ' ';
    char vert2 = ' ';
    int peso = 0;
    Grafo::Vertice vertice1;
    Grafo::Vertice vertice2;
    cout << "Digite los dos vértices donde va la arista " <<endl;
    cout << "Vertice 1:" <<endl;
    cin >>vert1;
    cout << endl << "Vertice 2: " <<endl;
    cin >> vert2;
    cout << endl;
    vertice1 =grafo1->buscarVertice(vert1);
    vertice2 =grafo1->buscarVertice(vert2);
    cout << "Digite el nuevo peso de la arista" <<endl;
    cin >> peso;
    cout <<endl;
    grafo1->modificarPeso(vertice1,vertice2, peso);
}
void Menu::elimVertice(){
    char vert1 = ' ';
    cout << "Digite el vértice que desea eliminar" <<endl;
    cout << "Nota: Tome en cuenta que debe ser un vértice Aislado" <<endl;
    cin >>vert1;
    Grafo::Vertice vertice1;
    vertice1 =grafo1->buscarVertice(vert1);
    grafo1->elimVertice(vertice1);
    cout<< "Vértice Eliminado Satisfactoriamente" <<endl;

}
void Menu::elimArista(){
    char vert1 = ' ';
    char vert2 = ' ';
    int peso = 0;
    Grafo::Vertice vertice1;
    Grafo::Vertice vertice2;
    cout << "Digite los dos vértices donde va la arista " <<endl;
    cout << "Vertice 1:" <<endl;
    cin >>vert1;
    cout << endl << "Vertice 2: " <<endl;
    cin >> vert2;
    cout << endl;
    vertice1 =grafo1->buscarVertice(vert1);
    vertice2 =grafo1->buscarVertice(vert2);

    grafo1->elimArista(vertice1, vertice2);

    cout <<"Arista borrada satisfactoriamente "<<endl;
}
void Menu::modificarEtiqueta(){
    char vert1 = ' ';
    char vertNuev = ' ';
    cout << "Digite el vértice al que le desea cambiar la etiqueta" <<endl;
    cin >>vert1;
    cout <<endl <<"Digite la nueva etiqueta para el vértice "<<endl;
    cin >> vertNuev;
    cout << endl;
    Grafo::Vertice vertice1;

    vertice1 =grafo1->buscarVertice(vert1);
    grafo1->modificarEtiqueta(vertice1, vertNuev);
    cout<< "La etiqueta se ha modificado satisfactoriamente" <<endl;
}

void Menu::numVertices(){
    cout<< "El número de Vértices del grafo es: " <<grafo1->numVertices() <<endl;
}
void Menu::numVerticesAdy(){
    char vert1 = ' ';
    cout << "Digite el vértice que desea ver el número de vértices adyacentes" <<endl;
    cin >>vert1;
    cout <<endl;
    Grafo::Vertice vertice1;
    vertice1 =grafo1->buscarVertice(vert1);


    cout <<"El numero de vertices adyacentes a " << vert1 <<" es " <<grafo1->numVerticesAdy(vertice1);

}
void Menu::adyacentes(){
    char vert1 = ' ';
    char vert2 = ' ';
    Grafo::Vertice vertice1;
    Grafo::Vertice vertice2;
    cout << "Digite los dos vertices donde va la arista " <<endl;
    cout << "Vertice 1:" <<endl;
    cin >>vert1;
    cout << endl << "Vertice 2: " <<endl;
    cin >> vert2;
    cout << endl;
    vertice1 =grafo1->buscarVertice(vert1);
    vertice2 =grafo1->buscarVertice(vert2);

    if(grafo1->adyacentes(vertice1, vertice2)){
        cout<<"Los vertices son adyacentes "<<endl;
    }else{
        cout <<"Los vertices no son adyacentes "<<endl;
    }
}
void Menu::primerVertice(){
    Grafo::Vertice vertice1;

    vertice1 =grafo1->primerVertice();
    char vert1 =grafo1->etiqueta(vertice1);

    cout << "El primer vertices del grafo es: "<< vert1 <<endl;

}
void Menu::siguienteVertice(){
    char vert1 = ' ';
    char vert2 = ' ';
    Grafo::Vertice vertice1;
    Grafo::Vertice vertice2;
    cout << "Digite el vertice que desea saber el siguiente" <<endl;
    cout << "Vertice" <<endl;
    cin >>vert1;
    cout << endl;
    vertice1 =grafo1->buscarVertice(vert1);
    vertice2 =grafo1->siguienteVertice(vertice1);
    vert2 =grafo1->etiqueta(vertice2);

    cout << "El siguiente vertice de " << vert1 << " es "<< vert2 <<endl;

}
void Menu::primerVerticeAdy(){
    char vert1 = ' ';
    char vert2 = ' ';
    Grafo::Vertice vertice1;
    Grafo::Vertice vertice2;
    cout << "Digite el vertice que desea saber el primer vertice adyacente" <<endl;
    cout << "Vertice" <<endl;
    cin >>vert1;
    cout << endl;
    vertice1 =grafo1->buscarVertice(vert1);
    vertice2 =grafo1->primerVerticeAdy(vertice1);
    vert2 =grafo1->etiqueta(vertice2);

    cout << "El primer vértice adyacente de  " << vert1 << " es "<< vert1 <<endl;
}
void Menu::siguienteVerticeAdy(){
    char vert1 = ' ';
    char vert2 = ' ';
    char vert3 = ' ';
    Grafo::Vertice vertice1;
    Grafo::Vertice vertice2;
    Grafo::Vertice vertice3;
    cout << "Digite primero el vertice del cual estamos obteniendo los adyacentes, y luego el vértice que es adyacente a este " <<endl;
    cout << "VerticeA:" <<endl;
    cin >>vert1;
    cout << endl << "Vertice que es adyacente al vérticeA: " <<endl;
    cin >> vert2;
    cout << endl;
    vertice1 =grafo1->buscarVertice(vert1);
    vertice2 =grafo1->buscarVertice(vert2);
    vertice3 =grafo1->siguienteVerticeAdy(vertice1, vertice2);
    vert3 =grafo1->etiqueta(vertice3);
    cout <<"El siguiente vertice adyacente de  " << vert2 << " es " << vert3<<endl;
 }

void Menu::algoritmosGrafos(){
    InstruccionesAlgoritmos();
    int instruccion = 0;
    int seguir = 1;
    do {
    cin >> instruccion;
    switch (instruccion) {
        case 0:
            seguir = 0;
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
        default:
            std::cerr << "Tecla Equivocada" << '\n';
            break;

        }
    }   while(seguir);
}

void Menu::InstruccionesAlgoritmos(){
    cout<<"-----Instrucciones para realizar pruebas con los algoritmos-----" <<endl;
    cout<<" (0) -> Para Salir" <<endl;
    cout<<" (1) -> Aplicar Dijkstra" <<endl;
    cout<<" (2) -> Aplicar Floyd" <<endl;
    cout<<" (3) -> Aplicar Prim" <<endl;
    cout<<" (4) -> Aplicar Kruskal" <<endl;
    cout<<" (5) -> Copiar un grafo" <<endl;
    cout<<" (6) -> Averiguar si dos grafos son iguales" <<endl;
    cout<<" (7) -> Resolver el Problema del Vendedor mediante Búsqueda Exhaustiva Pura" <<endl;
}

void Menu::dijkstra (){
    if(grafo1 != 0){
        algoritmo->dijkstra(grafo1);
    }else{
        cout<<"Grafo no creado" <<endl;
        iniciar();
        grafo1->agrVertice('a');
        grafo1->agrVertice('b');
        grafo1->agrVertice('c');
        agrArista();
        agrArista();
        agrArista();

        algoritmo->dijkstra(grafo1);


    }
}
void Menu::floyd (){
    if(grafo1 != 0){
        algoritmo->floyd(grafo1);
    }else{
        cout<<"Grafo no creado" <<endl;
        iniciar();
        grafo1->agrVertice('a');
        grafo1->agrVertice('b');
        grafo1->agrVertice('c');
        agrArista();
        agrArista();
        agrArista();

        algoritmo->floyd(grafo1);


    }
}
void Menu::prim (){
    if(grafo1 != 0){
        algoritmo->prim(grafo1);
    }else{
        cout<<"Grafo no creado" <<endl;
        iniciar();
        grafo1->agrVertice('a');
        grafo1->agrVertice('b');
        grafo1->agrVertice('c');
        agrArista();
        agrArista();
        agrArista();

        algoritmo->prim(grafo1);


    }
}
void Menu::kruskal (){
    if(grafo1 != 0){
        algoritmo->kruskal(grafo1);
    }else{
        cout<<"Grafo no creado" <<endl;
        iniciar();
        grafo1->agrVertice('a');
        grafo1->agrVertice('b');
        grafo1->agrVertice('c');
        agrArista();
        agrArista();
        agrArista();

        algoritmo->kruskal(grafo1);


    }
}
void Menu::copiar (){
    if(grafo1 != 0){
        if(grafo2 != 0 ){
            grafo2 = new Grafo();
        }
        algoritmo->copiar(grafo1,grafo2);
    }else{
        cout<<"Grafo no creado" <<endl;
        iniciar();
        if(grafo2 !=0){
            grafo2 = new Grafo();
        }
        grafo1->agrVertice('a');
        grafo1->agrVertice('b');
        grafo1->agrVertice('c');
        agrArista();
        agrArista();
        agrArista();

        algoritmo->problemaDelVendedor(grafo1, grafo2);


    }
}
void Menu::iguales (){
    if(grafo1 != 0){
        if(grafo2 != 0){
            grafo2 = new Grafo();
        }
        algoritmo->iguales(grafo1, grafo2);
    }else{

        cout<<"Grafo no creado" <<endl;
        iniciar();
        if(grafo2 != 0){
            grafo2 = new Grafo();
        }
        grafo1->agrVertice('a');
        grafo1->agrVertice('b');
        grafo1->agrVertice('c');
        agrArista();
        agrArista();
        agrArista();

        algoritmo->problemaDelVendedor(grafo1);


    }
}
void Menu::problemaDelVendedor (){
    if(grafo1 != 0){
        algoritmo->problemaDelVendedor(grafo1);
    }else{
        cout<<"Grafo no creado" <<endl;
        iniciar();
        grafo1->agrVertice('a');
        grafo1->agrVertice('b');
        grafo1->agrVertice('c');
        agrArista();
        agrArista();
        agrArista();

        algoritmo->problemaDelVendedor(grafo1);


    }
}
