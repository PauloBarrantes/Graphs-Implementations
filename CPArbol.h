#ifndef _coladeprioridadArbol_2017
#define _coladeprioridadArbol_2017

#include <iostream>
#define Q 2000

template<class T>

class CPArbol{
	class Par;

	private:
		int ultimo;
		Par* arbolVecPar;

		class Par{
			public:
				T elemento;
				int prioridad;

				/*!
				   \brief "Constructor de la clase Par"
				   \param "No recibe parametros"
				   \return "No retorna nada"
				*/
				Par(){
					prioridad = 0;
				}

				/*!
				   \brief "Constructor de la clase Par"
				   \param "Recibe el elemento y su prioridad"
				   \return "No retorna nada"
				*/
				Par(T elemento,int prioridad){
					this->elemento = elemento;
					this->prioridad = prioridad;
				}

				/*!
				   \brief "Destructor de la clase Par"
				   \param "No recibe parametros"
				   \return "No retorna nada"
				*/
				~Par(){

				}

				/*!
				   \brief "Metodo sobrecargado de igual"
				   \param "Recibe un objeto tio Par"
				   \return "Retorna un puntero a este Par"
				*/
				Par* operator=(const Par& otro){
					this->elemento = otro.elemento;
					this->prioridad = otro.prioridad;
					return this;
				}
		};


	public:
		/*!
			 \brief "Constructor de la clase CPArbol"
			 \param "No recibe parametros"
			 \return "No retorna nada"
		*/
		CPArbol(){
			ultimo = 0;
			arbolVecPar = new Par[Q];
		}

		/*!
			 \brief "Destructor de la clase CPArbol"
			 \param "No recibe parametros"
			 \return "No retorna nada"
		*/
		~CPArbol(){
			delete arbolVecPar;
		}

		/*!
			 \brief "Vacía la cola de prioridad"
			 \param "No recibe parametros"
			 \return "No retorna nada"
		*/
		void vaciar(){
			ultimo = 0;
		}

		/*!
			 \brief "devuelve verdadero si la cola está vacía"
			 \param "No recibe parametros"
			 \return "No retorna nada"
		*/
		int vacia(){
			return !ultimo;
		}

		/*!
			 \brief "Agrega el elemento en la posición que le corresponde"
			 \param "recibe un elemento y su prioridad"
			 \return "No retorna nada"
		*/
		void agregar(T elemento,int prioridad){
			++ultimo;

			arbolVecPar[ultimo] = *(new Par(elemento, prioridad));
			Par cajaExtra = arbolVecPar[ultimo];

			//Proceso de reacomodamiento
			int posAct = ultimo;
			while(posAct > 1 && arbolVecPar[posAct/2].prioridad > arbolVecPar[posAct].prioridad){
				arbolVecPar[posAct] = arbolVecPar[posAct/2];
				arbolVecPar[posAct/2] = cajaExtra;
				posAct = posAct/2;
			}
		}

		/*!
			 \brief "Devuelve el elemento que tiene la mayor prioridad en la cola"
			 \param "No recibe parametros"
			 \return "Retorna un elemento"
		*/
		T sacar(){
			Par cajaSalida = arbolVecPar[1];
			arbolVecPar[1] = arbolVecPar[ultimo];
			--ultimo;

			//Proceso de reacomodamiento
			int posAct = 1;
			int posCajaEx = 0;
			int acomodado = 0;
			Par cajaExtra = arbolVecPar[1];
			while(posAct*2 <= ultimo && !acomodado){
				cajaExtra = arbolVecPar[posAct*2];
				posCajaEx = posAct*2;

				if(posAct*2 + 1 <= ultimo){
					if(cajaExtra.prioridad > arbolVecPar[posAct*2 + 1].prioridad){
						cajaExtra = arbolVecPar[posAct*2 + 1];
						posCajaEx = posAct*2 + 1;
					}
				}

				if(cajaExtra.prioridad < arbolVecPar[posAct].prioridad){
					arbolVecPar[posCajaEx] = arbolVecPar[posAct];
					arbolVecPar[posAct] = cajaExtra;
					posAct = posCajaEx;
				}else{
					acomodado = 1;
				}
			}

			return cajaSalida.elemento;
		}

		/*!
			 \brief "Dice sí ya el elemento está agregado en la cola"
			 \param "Recibe un elemento"
			 \return "Retorna un int booleano"
		*/
		int pertenece(T elemento){
			int siPert = 0;
			if(!vacia()){
				for(int i = 1; i <= ultimo && !siPert; ++i){
					if(elemento == arbolVecPar[i].elemento){
						siPert = 1;
					}
				}
			}
			return siPert;
		}

		int numElem(){
			return ultimo;
		}

		/*!
			 \brief "Imprime lo que hay en la cola"
			 \param "Recibe un ostream"
			 \return "Retorna un ostream"
		*/
		std::ostream& imprimir(std::ostream& salida){
			for(int i = 1; i <= ultimo; ++i){
				salida << "(" << arbolVecPar[i].elemento << "," << arbolVecPar[i].prioridad << ") - ";
			}
			salida << std::endl;
		}
};

#endif
