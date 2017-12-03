//g++ main.cpp Generadorgrafo.cpp grafoHMI_HD.cpp Algoritmos.cpp Test.cpp

#include "Test.h"
#include <iostream>
#include <time.h>
#define TIME_THIS(X,Y)                                         \
  {                                                          \
    struct timespec ts1, ts2;                                \
    clock_gettime( CLOCK_REALTIME, &ts1 );                   \
    X;                                                       \
    clock_gettime( CLOCK_REALTIME, &ts2 );                   \
                                                            \
     Y = (float) ( 1.0*(1.0*ts2.tv_nsec - ts1.tv_nsec*1.0)*1e-9 \
      + 1.0*ts2.tv_sec - 1.0*ts1.tv_sec ) ;                 \
  }

#define N1 5
#define N2 25
#define N3 50

#define NV1 3
#define NV2 6
#define NV3 12

using namespace std;

        Test::Test(){
			      algoritmo = new Algoritmos();
			      genGrafos = new GeneradorGrafos();

            //Grafo completo
            grafoN1G1 = 0;
            grafoN2G1 = 0;
            grafoN3G1 = 0;
            //Grafo casi completo
            grafoN1G2 = 0;
            grafoN2G2 = 0;
            grafoN3G2 = 0;
            //Grafo muy incompleto
            grafoN1G3 = 0;
            grafoN2G3 = 0;
            grafoN3G3 = 0;
        }

        Test::~Test(){
			     delete algoritmo;
			     delete genGrafos;
        }
        //Debería enviar a probar el grafo con sus 4 tamaños, y cada uno de sus OB y algoritmos.
        void Test::testGeneral(){
			     this->testCompleto();
			     this->testCasiCompleto();
			     this->testMuyIncompleto();
        }

        //Algoritmos

        //Dijkstra
        void Test::testDijkstra(Grafo* grafo){
            double segundos;
            TIME_THIS(algoritmo->dijkstra(grafo,grafo->primerVertice()), segundos);
            cout << segundos << endl;
        }

        //Floyd
        void Test::testFloyd(Grafo* grafo){
            double segundos = 0.0;
            TIME_THIS(algoritmo->floyd(grafo), segundos);
            cout << segundos << endl;
        }

        //Prim
        void Test::testPrim(Grafo* grafo){
            double segundos = 0.0;
            TIME_THIS(algoritmo->prim(grafo), segundos);
            cout << segundos << endl;
        }

        //Kruskal
        void Test::testKruskal(Grafo* grafo){
            double segundos = 0.0;
            TIME_THIS(algoritmo->floyd(grafo), segundos);
            cout << segundos << endl;
        }

        // //Iguales
        // void Test::testIguales(Grafo* grafo){
        //     double segundos = 0.0;
        //     TIME_THIS(algoritmo->iguales(grafo), segundos);
        //     cout << segundos << endl;
        // }
        //
        // //Copiar
        // void Test::testCopiar(Grafo* grafo){
        //     double segundos = 0.0;
        //     TIME_THIS(algoritmo->copiar(grafo), segundos);
        //     cout << segundos << endl;
        // }

        //Vendedor
        void Test::testVendedor(Grafo* grafo){
            double segundos = 0.0;
            TIME_THIS(algoritmo->problemaDelVendedor(grafo), segundos);
            cout << segundos << endl;
        }

        void Test::testCompleto(){
          // INICIO grafo Completo //
          //grafoCompleto
          grafoN1G1 = genGrafos->grafoCompleto(N1);
          grafoN2G1 = genGrafos->grafoCompleto(N2);
          grafoN3G1 = genGrafos->grafoCompleto(N3);

          //Test de Algoritmos
          // ----- Algorithm 1 --- grafoCompleto //
          cout << "Prueba de los grafos Completo con el algoritmo Dijkstra " <<endl;
          cout << "N1" << endl;
          testDijkstra(grafoN1G1);
          cout << "N2" <<endl;
          testDijkstra(grafoN2G1);
          cout << "N3"<<endl;
          testDijkstra(grafoN3G1);

		  // ----- Algorithm 2 --- grafoCompleto //
          cout << "Prueba de los grafos Completo con el algoritmo Floyd " <<endl;
          cout << "N1" << endl;
          testFloyd(grafoN1G1); //Tiempo de ejecución de Floyd con n1
          cout << "N2" <<endl;
          testFloyd(grafoN2G1);//Tiempo de ejecución de Floyd con n2
          cout << "N3"<<endl;
          testFloyd(grafoN3G1);//Tiempo de ejecución de Floyd con n3


		  // ----- Algorithm 3 --- grafoCompleto //
          cout << "Prueba de los grafos Completo con el algoritmo Prim " <<endl;
          cout << "N1" << endl;
          testPrim(grafoN1G1); //Tiempo de ejecución de Prim con n1
          cout << "N2" <<endl;
          testPrim(grafoN2G1);//Tiempo de ejecución de Prim con n2
          cout << "N3"<<endl;
          testPrim(grafoN3G1);//Tiempo de ejecución de Prim con n3

		  // ----- Algorithm 4 --- grafoCompleto //
          cout << "Prueba de los grafos Completo con el algoritmo Kruskal " <<endl;
          cout << "N1" << endl;
          testKruskal(grafoN1G1); //Tiempo de ejecución de Kruskal con n1
          cout << "N2" <<endl;
          testKruskal(grafoN2G1);//Tiempo de ejecución de Kruskal con n2
          cout << "N3"<<endl;
          testKruskal(grafoN3G1);//Tiempo de ejecución de Kruskal con n3

      // // ----- Algorithm 5 --- grafoCompleto //
      //     cout << "Prueba de los grafos Completo con el algoritmo Iguales " <<endl;
      //     cout << "N1" << endl;
      //     testIguales(grafoN1G1); //Tiempo de ejecución de Iguales con n1
      //     cout << "N2" <<endl;
      //     testIguales(grafoN2G1);//Tiempo de ejecución de Iguales con n2
      //     cout << "N3"<<endl;
      //     testIguales(grafoN3G1);//Tiempo de ejecución de Iguales con n3
      //
      // // ----- Algorithm 6 --- grafoCompleto //
      //     cout << "Prueba de los grafos Completo con el algoritmo Copiar " <<endl;
      //     cout << "N1" << endl;
      //     testCopiar(grafoN1G1); //Tiempo de ejecución de Copiar con n1
      //     cout << "N2" <<endl;
      //     testCopiar(grafoN2G1);//Tiempo de ejecución de Copiar con n2
      //     cout << "N3"<<endl;
      //     testCopiar(grafoN3G1);//Tiempo de ejecución de Copiar con n3

          //liberamos la memoria
          delete grafoN1G1;
          delete grafoN2G1;
          delete grafoN3G1;

          //creamos grafos para el problemaDelVendedor
          grafoN1G1 = genGrafos->grafoCompleto(NV1);
          grafoN2G1 = genGrafos->grafoCompleto(NV2);
          grafoN3G1 = genGrafos->grafoCompleto(NV3);

      // ----- Algorithm 7 --- grafoCompleto //
          cout << "Prueba de los grafos Completo con el algoritmo ProblemaDelVendedor " <<endl;
          cout << "N1" << endl;
          testVendedor(grafoN1G1); //Tiempo de ejecución de ProblemaDelVendedor con n1
          cout << "N2" <<endl;
          testVendedor(grafoN2G1);//Tiempo de ejecución de ProblemaDelVendedor con n2
          cout << "N3"<<endl;
          testVendedor(grafoN3G1);//Tiempo de ejecución de ProblemaDelVendedor con n3

          //liberamos la memoria
          delete grafoN1G1;
          delete grafoN2G1;
          delete grafoN3G1;
        }

        void Test::testCasiCompleto(){
          /// INICIO DEL grafo CasiCompleto

          grafoN1G2 = genGrafos->grafoCasiCompleto(N1);
          grafoN2G2 = genGrafos->grafoCasiCompleto(N2);
          grafoN3G2 = genGrafos->grafoCasiCompleto(N3);

          //Test de Algoritmos
          // ----- Algorithm 1 --- grafoCasiCompleto //
          cout << "Prueba de los grafos CasiCompleto con el algoritmo Dijkstra " <<endl;
          cout << "N1" << endl;
          testDijkstra(grafoN1G2); //Tiempo de ejecución de Dijkstra con n1
          cout << "N2" <<endl;
          testDijkstra(grafoN2G2); //Tiempo de ejecución de Dijkstra con n2
          cout << "N3"<<endl;
          testDijkstra(grafoN3G2); //Tiempo de ejecución de Dijkstra con n3

          // ----- Algorithm 2 --- grafoCasiCompleto //
          cout << "Prueba de los grafos CasiCompleto con el algoritmo Floyd " <<endl;
          cout << "N1" << endl;
          testFloyd(grafoN1G2); //Tiempo de ejecución de Floyd con n1
          cout << "N2" <<endl;
          testFloyd(grafoN2G2);//Tiempo de ejecución de Floyd con n2
          cout << "N3"<<endl;
          testFloyd(grafoN3G2);//Tiempo de ejecución de Floyd con n3

          // ----- Algorithm 3 --- grafoCasiCompleto //
          cout << "Prueba de los grafos CasiCompleto con el algoritmo Prim " <<endl;
          cout << "N1" << endl;
          testPrim(grafoN1G2); //Tiempo de ejecución de Prim con n1
          cout << "N2" <<endl;
          testPrim(grafoN2G2);//Tiempo de ejecución de Prim con n2
          cout << "N3"<<endl;
          testPrim(grafoN3G2);//Tiempo de ejecución de Prim con n3

          // ----- Algorithm 4 --- grafoCasiCompleto //
          cout << "Prueba de los grafos CasiCompleto con el algoritmo Kruskal " <<endl;
          cout << "N1" << endl;
          testKruskal(grafoN1G2); //Tiempo de ejecución de Kruskal con n1
          cout << "N2" <<endl;
          testKruskal(grafoN2G2);//Tiempo de ejecución de Kruskal con n2
          cout << "N3"<<endl;
          testKruskal(grafoN3G2);//Tiempo de ejecución de Kruskal con n3

          // // ----- Algorithm 5 --- grafoCasiCompleto //
          // cout << "Prueba de los grafos CasiCompleto con el algoritmo Iguales " <<endl;
          // cout << "N1" << endl;
          // testIguales(grafoN1G2); //Tiempo de ejecución de Iguales con n1
          // cout << "N2" <<endl;
          // testIguales(grafoN2G2);//Tiempo de ejecución de Iguales con n2
          // cout << "N3"<<endl;
          // testIguales(grafoN3G2);//Tiempo de ejecución de Iguales con n3
          //
          // // ----- Algorithm 6 --- grafoCasiCompleto //
          // cout << "Prueba de los grafos CasiCompleto con el algoritmo Copiar " <<endl;
          // cout << "N1" << endl;
          // testCopiar(grafoN1G2); //Tiempo de ejecución de Copiar con n1
          // cout << "N2" <<endl;
          // testCopiar(grafoN2G2);//Tiempo de ejecución de Copiar con n2
          // cout << "N3"<<endl;
          // testCopiar(grafoN3G2);//Tiempo de ejecución de Copiar con n3

          //liberamos la memoria
          delete grafoN1G2;
          delete grafoN2G2;
          delete grafoN3G2;

          //creamos grafos para el problemaDelVendedor
          grafoN1G2 = genGrafos->grafoCasiCompleto(NV1);
          grafoN2G2 = genGrafos->grafoCasiCompleto(NV2);
          grafoN3G2 = genGrafos->grafoCasiCompleto(NV3);

          // ----- Algorithm 7 --- grafoCompleto //
          cout << "Prueba de los grafos Completo con el algoritmo ProblemaDelVendedor " <<endl;
          cout << "N1" << endl;
          testVendedor(grafoN1G2); //Tiempo de ejecución de ProblemaDelVendedor con n1
          cout << "N2" <<endl;
          testVendedor(grafoN2G2);//Tiempo de ejecución de ProblemaDelVendedor con n2
          cout << "N3"<<endl;
          testVendedor(grafoN3G2);//Tiempo de ejecución de ProblemaDelVendedor con n3

          //liberamos la memoria
          delete grafoN1G2;
          delete grafoN2G2;
          delete grafoN3G2;
        }

        void Test::testMuyIncompleto(){
          /// INICIO DEL GRAFO MUY INCOMPLETO

          grafoN1G3 = genGrafos->grafoMuyIncompleto(N1);
          grafoN2G3 = genGrafos->grafoMuyIncompleto(N2);
          grafoN3G3 = genGrafos->grafoMuyIncompleto(N3);

          //Test de Algoritmos
          // ----- Algorithm 1 --- grafoMuyIncompleto //
          cout << "Prueba de los grafos MuyIncompletos con el algoritmo Dijkstra " <<endl;
          cout << "N1" << endl;
          testDijkstra(grafoN1G3); //Tiempo de ejecución de Dijkstra con n1
          cout << "N2" <<endl;
          testDijkstra(grafoN2G3);//Tiempo de ejecución de Dijkstra con n2
          cout << "N3"<<endl;
          testDijkstra(grafoN3G3);//Tiempo de ejecución de Dijkstra con n3

          // ----- Algorithm 2 --- grafoMuyIncompleto //
          cout << "Prueba de los grafos MuyIncompletos con el algoritmo Floyd " <<endl;
          cout << "N1" << endl;
          testFloyd(grafoN1G3); //Tiempo de ejecución de Floyd con n1
          cout << "N2" <<endl;
          testFloyd(grafoN2G3);//Tiempo de ejecución de Floyd con n2
          cout << "N3"<<endl;
          testFloyd(grafoN3G3);//Tiempo de ejecución de Floyd con n3

          // ----- Algorithm 3 --- grafoMuyIncompleto //
          cout << "Prueba de los grafos MuyIncompletos con el algoritmo Prim " <<endl;
          cout << "N1" << endl;
          testPrim(grafoN1G3); //Tiempo de ejecución de Prim con n1
          cout << "N2" <<endl;
          testPrim(grafoN2G3);//Tiempo de ejecución de Prim con n2
          cout << "N3"<<endl;
          testPrim(grafoN3G3);//Tiempo de ejecución de Prim con n3

          // ----- Algorithm 4 --- grafoMuyIncompleto //
          cout << "Prueba de los grafos MuyIncompletos con el algoritmo Kruskal " <<endl;
          cout << "N1" << endl;
          testKruskal(grafoN1G3); //Tiempo de ejecución de Kruskal con n1
          cout << "N2" <<endl;
          testKruskal(grafoN2G3);//Tiempo de ejecución de Kruskal con n2
          cout << "N3"<<endl;
          testKruskal(grafoN3G3);//Tiempo de ejecución de Kruskal con n3

          // // ----- Algorithm 5 --- grafoMuyIncompleto //
          // cout << "Prueba de los grafos Completo con el algoritmo Iguales " <<endl;
          // cout << "N1" << endl;
          // testIguales(grafoN1G3); //Tiempo de ejecución de Iguales con n1
          // cout << "N2" <<endl;
          // testIguales(grafoN2G3);//Tiempo de ejecución de Iguales con n2
          // cout << "N3"<<endl;
          // testIguales(grafoN3G3);//Tiempo de ejecución de Iguales con n3
          //
          // // ----- Algorithm 6 --- grafoMuyIncompleto //
          // cout << "Prueba de los grafos Completo con el algoritmo Copiar " <<endl;
          // cout << "N1" << endl;
          // testCopiar(grafoN1G3); //Tiempo de ejecución de Copiar con n1
          // cout << "N2" <<endl;
          // testCopiar(grafoN2G3);//Tiempo de ejecución de Copiar con n2
          // cout << "N3"<<endl;
          // testCopiar(grafoN3G3);//Tiempo de ejecución de Copiar con n3

          //liberamos la memoria
          delete grafoN1G3;
          delete grafoN2G3;
          delete grafoN3G3;

          //creamos grafos para el problemaDelVendedor
          grafoN1G3 = genGrafos->grafoMuyIncompleto(NV1);
          grafoN2G3 = genGrafos->grafoMuyIncompleto(NV2);
          grafoN3G3 = genGrafos->grafoMuyIncompleto(NV3);

          // ----- Algorithm 7 --- grafoMuyIncompleto //
          cout << "Prueba de los grafos MuyIncompleto con el algoritmo ProblemaDelVendedor " <<endl;
          cout << "N1" << endl;
          testVendedor(grafoN1G3); //Tiempo de ejecución de ProblemaDelVendedor con n1
          cout << "N2" <<endl;
          testVendedor(grafoN2G3);//Tiempo de ejecución de ProblemaDelVendedor con n2
          cout << "N3"<<endl;
          testVendedor(grafoN3G3);//Tiempo de ejecución de ProblemaDelVendedor con n3

          //liberamos la memoria
          delete grafoN1G3;
          delete grafoN2G3;
          delete grafoN3G3;
        }
