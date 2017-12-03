#ifndef ConjuntoDeConjuntos_2017
#define ConjuntoDeConjuntos_2017
#include <iostream>

using namespace std;

template <class T>
class CDCD{

  class Conjunto;

  private:
    Conjunto* primerConjunto;
    /*!
       \brief "Busca el conjunto al que corresponde una etiqueta"
       \param "Entra la etiqueta del conjunto que se quiere buscar"
       \return "Retorna el conjunto que corresponde a la etiqueta"
    */
    Conjunto* buscarConjunto(int conjId){
      Conjunto* buscado = 0;
      Conjunto* actual = this->primerConjunto;
      bool encontro = false;
      while(actual != 0 && !encontro){
        if(actual->identificador == conjId){
          encontro = true;
          buscado = actual;
        }
        actual = actual->siguiente;
      }
      return buscado;
    }
    /*!
       \brief "Busca el conjunto anterior en la lista a otro"
       \param "Entra el conjunto del que se quiere saber su anterior"
       \return "Retorna el conjunto anterior en la lista al parametro"
    */
    Conjunto* buscarAnterior(Conjunto* conj1){
      Conjunto* anterior = 0;
      Conjunto* actual = this->primerConjunto;
      bool encontro = false;
      if(actual == conj1){
        encontro = true;
        anterior = actual;
      }
      else{
        while(actual != 0 && !encontro){
          if(actual->siguiente == conj1){
            encontro = true;
            anterior = actual;
          }
          actual = actual->siguiente;
        }
      }
      return anterior;
    }

    class CajitaElem {
     public:
      T elemento;
      CajitaElem* siguienteElemento;
      CajitaElem(T elemento){
        this->elemento = elemento;
        this->siguienteElemento = 0;
      }
      ~CajitaElem(){
        if(this->siguienteElemento != 0){
          delete siguienteElemento;
        }
      }
      /*!
         \brief "Imprime el elemento y los siguientes"
         \param "Pasa como parametro el ostream"
         \return "El ostream"
      */
      ostream& imprimir(ostream& salida){
        salida << this->elemento << ", ";
        //this->elemento->imprimir(salida);
        if(this->siguienteElemento != 0){
          this->siguienteElemento->imprimir(salida);
        }
        return salida;
      }
    };

    class Conjunto {
     public:
      int identificador;
      CajitaElem * primerElemento;
      Conjunto* siguiente;
      Conjunto(int id){
        this->identificador = id;
        this->siguiente = 0;
        this->primerElemento = 0;
      }
      ~Conjunto(){
        delete primerElemento;
        if(this->siguiente != 0){
          delete siguiente;
        }
      }
      /*!
         \brief "Agrega un elemento a la sublista de un conjunto"
         \param "Entra el elemento que se quiere agregar"
         \return "No retorna nada"
      */
      void agregarElemento(T elem){
        CajitaElem* nuevoElemento = new CajitaElem(elem);
        nuevoElemento->siguienteElemento = this->primerElemento;
        this->primerElemento = nuevoElemento;
      }
      ostream& imprimir(ostream& salida){
        salida << this->identificador << " {";
        this->primerElemento->imprimir(salida);
        salida << "}" << endl;
        if(this->siguiente != 0){
          this->siguiente->imprimir(salida);
        }
        return salida;
      }
    };

  public:
    CDCD(){
      this->primerConjunto = 0;
    }
    ~CDCD(){
      if(this->primerConjunto != 0){
        delete primerConjunto;
      }
    }
    /*!
       \brief "Vacía el conjunto de conjuntos"
       \param "No tiene parámetros"
       \return "No retorna nada"
    */
    void vaciar(){
      delete this;
      this->primerConjunto = 0;
    }
    /*!
       \brief "Pregunta si el CDCD está vacío"
       \param "No tiene parámetros"
       \return "Retorna 1 si el primerConjunto es no nulo, 0 caso contrario"
    */
    bool vacio(){
      return !primerConjunto;
    }
    /*!
       \brief "Busca el conjunto al que pertenece un elemento"
       \param "Entra el elemento que se quiere buscar"
       \return "Retorna el identificador del conjunto al que pertenece el elemento"
    */
    int conjuntoAlQuePertenece(T elem){
      Conjunto* conjAlQuePertenece = 0;
      bool encontro = false;
      Conjunto* conjActual = this->primerConjunto;
      CajitaElem* CajitaElemActual = 0;
      while (conjActual != 0 && !encontro) {
        CajitaElemActual = conjActual->primerElemento;
        while (CajitaElemActual != 0 && !encontro){
          if(CajitaElemActual->elemento == elem){
            encontro = true;
            conjAlQuePertenece = conjActual;
          }
          CajitaElemActual = CajitaElemActual->siguienteElemento;
        }
        conjActual = conjActual->siguiente;
      }
      return conjAlQuePertenece->identificador;
    }
    /*!
       \brief "Agrega un conjunto a la lista principal de conjuntos"
       \param "Entra el primer elemento que se quiere agregar al conjunto y la etiqueta del nuevo conjunto"
       \return "No retorna nada"
    */
    void agregarConjunto(int nuevoId,T elem){
      Conjunto* nuevoConj = new Conjunto(nuevoId);
      nuevoConj->siguiente = this->primerConjunto;
      this->primerConjunto = nuevoConj;
      nuevoConj->agregarElemento(elem);
    }
    /*!
       \brief "Hace la union de dos conjuntos, el identificador del nuevo conjunto es el del primer parámetro"
       \param "Entran los identificadores de los conjuntos que se quiere unir"
       \return "No retorna nada"
    */
    void unirConjuntos(int conj1,int conj2){
      Conjunto* conjA = buscarConjunto(conj1);
      Conjunto* conjB = buscarConjunto(conj2);
      CajitaElem* actual = conjB->primerElemento;
      while(actual != 0){
        conjA->agregarElemento(actual->elemento);
        actual = actual->siguienteElemento;
      }
      Conjunto* anterior = buscarAnterior(conjB);
      if(conjB == this->primerConjunto){
        this->primerConjunto = conjB->siguiente;
      }
      else{
        anterior->siguiente = conjB->siguiente;
      }
      conjB->siguiente = 0;
      delete conjB;
    }
    ostream& imprimir(ostream& salida){
      salida << "CDCD: " << endl;
      this->primerConjunto->imprimir(salida);
      return salida;
    }
};

#endif
