#ifndef grafonodirigido_2017
#define grafonodirigido_2017
#include <iostream>
using namespace std;
class Grafo {
    class Caja;
    class Arista;
    private:
        int numeroVertices;
        int numeroAristas;
        class Caja{
            public:
                char etiq;
                Caja* siguienteCaja;
                Arista* sublista;
                int numAdy;
                Caja(char);
                ~Caja();
                ostream& imprimirC(ostream&);
        };
        class Arista{
            public:
                int peso;
                Caja* verticeA;
                Caja* verticeB;

                Arista* siguienteArista;
                Arista(Caja*,Caja*, int);
                ~Arista();
                ostream& imprimirA(ostream&);
        };
        Caja* ultimo;
        Caja* primero;

    public:
        typedef Caja* Vertice;
        Grafo();
        ~Grafo();
        /*!
           \brief "Vacia el grafo"
           \param "Requiere que el grafo este inicializado "
           \return "No retorna nada"
        */
        void vaciar();
        /*!
           \brief "Verifica si el grafo este vacio"
           \param "No recibe"
           \return "Retorna un entero booleano"
        */
        int vacia();
        /*!
           \brief "Agrega un vértice al grafo"
           \param "Recibe un caracter como parametro"
           \return "Retorna el vértice que creamos"
        */
        Vertice agrVertice (char);
        /*!
           \brief "Averigua el peso de una arista"
           \param "Recibe como parametro dos vértices, los dos de la arista"
           \return "Retorna el peso de la arista"
        */
        int peso(Vertice,Vertice);
        /*!
           \brief "Agrega un arista entre dos vértices"
           \param "Recibe 2 vértices donde va estar la arista y un entero que va ser el peso"
           \return "No retorna nada"
        */
        void agrArista(Vertice,Vertice,int);
        /*!
           \brief "Modifica el peso de una arista"
           \param "Recibe 2 vértices donde va estar la arista y un entero que va ser el peso"
           \return "No retorna nada"
        */
        void modificarPeso(Vertice,Vertice, int);
        /*!
           \brief "Elimina el vértice "
           \param "Recibe el vértice que vamos a eliminar"
           \return "No retorna nada"
        */
        void elimVertice(Vertice);
        /*!
           \brief "Elimina la arista entre dos vértices"
           \param "Recibe dos vértices"
           \return "No retorna"
        */
        void elimArista(Vertice, Vertice);
        /*!
           \brief "Modifica la etiqueta de un vértice"
           \param "Recibe un parámetro y una etiqueta "
           \return "No retorna nada"
        */
        void modificarEtiqueta(Vertice, char);
        /*!
           \brief "Retorna la etiqueta de un vértice"
           \param "Recibe un vértice"
           \return "Retorna una etiqueta"
        */
        char etiqueta(Vertice);
        /*!
           \brief "Averigua el número de vértices del grafo"
           \param "No recibe"
           \return "Retorna un entero"
        */
        int numVertices();
        /*!
           \brief "Averigua el número de aristas del grafo"
           \param "No recibe"s
           \return "Retorna un número entero"
        */
        int numAristas();
        /*!
           \brief "Averigua el número de vertices adyacentes a un vértice en específico"
           \param "Recibe el vértice en específico"
           \return "Retorna un entero"
        */
        int numVerticesAdy(Vertice);
        /*!
           \brief "Determina si existe la arista entre dos vértices"
           \param "Recibe los dos vértices"
           \return "No retorna nada"
        */
        int adyacentes(Vertice, Vertice);
        /*!
           \brief "Imprimir"
           \param "Ostream&"
           \return "Ostream&"
        */
        ostream& imprimir(ostream&);
        /*!
           \brief "Busca el primer vértice del grafo"
           \param "No recibe"
           \return "Retorna un vértice"
        */
        Vertice primerVertice();
        /*!
           \brief "Busca el siguiente vértice del grafo con respecto a un vértice específico "
           \param "Recibe un vértice"
           \return "Retorna un vértice"
        */
        Vertice siguienteVertice(Vertice);
        /*!
           \brief "Busca el primer vértice adyacente de un vértice que entra como parámetro"
           \param "Recibe un vértice"
           \return "Retorna un vértice"
        */
        Vertice primerVerticeAdy(Vertice);
        /*!
           \brief "Busca el primer vértice adyacente de un vértice que entra como parámetro"
           \param "Recibe dos vértices"
           \return "Retorna un vértice"
        */
        Vertice siguienteVerticeAdy(Vertice, Vertice);
        /*!
           \brief "Busca el vértice que le pertenece la etiqueta que entra "
           \param "Entra una etiqueta"
           \return "Retorna un vértice"
        */
        Vertice buscarVertice(char);

};

#endif
