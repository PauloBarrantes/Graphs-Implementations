#ifndef diccionario_2017
#define diccionario_2017
#include <iostream>
using namespace std;
template <class T>
class DiccionarioLSE  {
    private:
        class box;
        box* primero;
        box* ultimo;
        int numeroElementos;
        class box {
            public:
                T elemento;
                box* siguiente;

                box(T elemento){
                    this->elemento = elemento;
                    this->siguiente = 0;
                };
                ~box(){
                    if(this->siguiente != 0){
                        delete this->siguiente;
                    }

                };
                T getElemento(){
                    return this->elemento;
                };
                void print(){
                    cout << elemento << ", ";
                    if(this->siguiente != 0){
                        (this->siguiente)->print();
                    }
                }
        };


    public:
        DiccionarioLSE(){
            this->primero = 0;
            this->ultimo = 0;
            numeroElementos = 0;
        }
        ~DiccionarioLSE(){
            delete primero;
        }
        void vaciar(){
            delete primero;
            numeroElementos = 0;
            this->primero = 0;
            this->ultimo = 0;
        }
        int vacia(){
            return !numeroElementos;
        }
        void agregar(T elemento){
            if(!pertenece(elemento)){
                if(vacia()){
                    box* cajita = new box(elemento);
                    primero = cajita;
                    ultimo = cajita;
                }else{
                    box* cajita = new box(elemento);
                    ultimo->siguiente = cajita;
                    ultimo = cajita;
                }
                ++numeroElementos;
            }else{
                cout << "El elemento que ha querido ingresar, ya pertenece al diccionario entonces no se ha agregado" << endl;
            }
        }
        void borrar(T elemento){
            if(!vacia()){
                int encontrado = 0;
                box* p = primero;
                if(p->elemento == elemento){ // Caso donde el que vamos a borrar es el primero
                    encontrado = 1;
                    primero = p->siguiente;
                    p->siguiente = 0;

                    delete p;
                }else{

                    while(p->siguiente != 0 && !encontrado){ // Si está en el medio de todo, vamos a buscarlo con posición atrasada
                        if((p->siguiente)->elemento == elemento){
                            encontrado = 1;
                        }else{
                            p = p->siguiente;
                        }
                    }
                    if(encontrado){
                        box* victima = p->siguiente;
                        p->siguiente = victima->siguiente;
                        victima->siguiente = 0;
                        delete victima;
                        if(p->siguiente == 0){
                            ultimo = p;
                        }
                    }

                }


                --numeroElementos;
            }else{
                cout << "El elemento que ha querido borrar, no pertenece al diccionario por lo tanto no se ha borrado" << endl;
            }
        }
        int pertenece(T elemento){
            int encontrado = 0;
            if (!vacia()){
                box* p = primero;

                while(p != 0 && !encontrado){
                    if(p->elemento == elemento){
                        encontrado = 1;
                    }else{
                        p = p->siguiente;
                    }
                }
            }
            return encontrado;
        }
        int numElem(){
            return numeroElementos;
        }
        ostream& imprimir (ostream& salida){
            primero->print();
            return salida;
        }
};


#endif
