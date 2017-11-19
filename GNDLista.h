#ifndef grafonodirigido_2017
#define grafonodirigido_2017

class GNDLista {
    class Vertice;
    class Arista;
    private:
        Vertice primerVertice;
        int numeroVertices;
        class Vertice{
            public:
                char* etiq;
                Arista* sublista;
                int numAdy;
                Vertice(char*);
                ~Vertice();
        }
        class Arista{
            public:
                int peso;
                Vertice* VerticeA;
                Vertice* VerticeB;
                Arista(Vertice*, Vertice*, int);
                ~Arista();
        }
    public:
        GNDLista();
        ~GNDLista();
        void vaciar();
        int vacia();
        Vertice* agrVertice (char); // Cambiar el return a vértice
        int peso(Vertice*,Vertice*);
        void agrArista(Vertice*,Vertice*,int);
        void modificarPeso(Vertice*,Vertice*, int);
        void elimVertice(Vertice*);
        void elimArista(Vertice*, Vertice*);
        void modificarEtiqueta(Vertice*, char);
        char etiqueta(Vertice*);
        int numVertices();
        int numVerticesAdy();
        int adyacentes(Vertice*, Vertice*)
};

#endif
