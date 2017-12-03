#ifndef menu_2017
#define menu_2017
#include "DiccionarioLSE.h"
#include "Algoritmos.h"
//#include "GNDMatriz.h"
#include "GNDLista.h"
class Menu {
    private:
        Grafo* grafo1;
        Grafo* grafo2;
        Algoritmos* algoritmo;

        void iniciarGrafo1();
    public:
        Menu();
        ~Menu();
        /*!
           \brief "Se encarga del flujo del menú"
           \param "No recibe"
           \return "No retorna"
        */
        void controlador();
        /*!
           \brief "Se encarga del flujo del menú de operadores básicos"
           \param "No recibe"
           \return "No retorna"
        */
        void obGrafos();
        /*!
           \brief "Imprime las instrucciones de los algoritmos"
           \param "No recibe"
           \return "No retorna"
        */
        void InstruccionesAlgoritmos();
        /*!
           \brief "Imprime las instrucciones de los operadores básicos"
           \param "No recibe"
           \return "No retorna"
        */
        void InstruccionesOB();
        /*!
           \brief "Se encarga del flujo del menú de algoritmos"
           \param "No recibe"
           \return "No retorna"
        */
        void algoritmosGrafos();
        /*!
           \brief "Hacen llamados a los operadores básicos de los grafos"
           \param "No recibe"
           \return "No retorna"
        */
        void Salir();
        void iniciar();
        void destruir();
        void vaciar();
        void vacia();
        void agrVertice (); // Cambiar el return a vértice
        void peso();
        void agrArista();
        void modificarPeso();
        void elimVertice();
        void elimArista();
        void modificarEtiqueta();
        void numVertices();
        void numVerticesAdy();
        void adyacentes();
        void primerVertice();
        void siguienteVertice();
        void primerVerticeAdy();
        void siguienteVerticeAdy();

        // Algoritmos
        /*!
           \brief "Hacen llamados a los algoritmos de los grafos"
           \param "No recibe"
           \return "No retorna"
        */
        void dijkstra ();
        void floyd ();
        void prim ();
        void kruskal ();
        void copiar ();
        void iguales ();
        void problemaDelVendedor ();


};

#endif
