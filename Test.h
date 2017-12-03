/*!
   \file "Test"
   \brief "Clase que hace un test de tiempo de los algoritmos en ambas implementaciones de GND"
   \author "André Flasterstein"
   \date "1"/"12"/"2017"
*/
#ifndef Test_2017
#define Test_2017
#include <time.h>

//#include "GNDLista.h"
#include "GNDMatriz.h"
#include "GeneradorDeGrafos.h"
#include "Algoritmos.h"

class Test {
    private:
		    Algoritmos * algoritmo;
        //Clase time
        time_t timer;
        //grafo completo
        Grafo * grafoN1G1;
        Grafo * grafoN2G1;
        Grafo * grafoN3G1;
        //grafo casi completo
        Grafo * grafoN1G2;
        Grafo * grafoN2G2;
        Grafo * grafoN3G2;
        //grafo muy incompleto
        Grafo* grafoN1G3;
        Grafo* grafoN2G3;
        Grafo* grafoN3G3;

        GeneradorGrafos* genGrafos;

        void testCompleto();
        void testCasiCompleto();
        void testMuyIncompleto();

    public:
        Test();
        ~Test();
        // Acá realizamos los pruebas y obtenemos los tiempos de los algoritmos
        void testGeneral();
        void testDijkstra(Grafo*);
        void testFloyd(Grafo*);
        void testPrim(Grafo*);
        void testKruskal(Grafo*);
        void testIguales(Grafo*);
        void testCopiar(Grafo*);
        void testVendedor(Grafo*);
};

#endif
