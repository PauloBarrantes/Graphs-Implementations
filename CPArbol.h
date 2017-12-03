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

				Par(){
					prioridad = 0;
				}

				Par(T elemento,int prioridad){
					this->elemento = elemento;
					this->prioridad = prioridad;
				}

				~Par(){

				}

				Par* operator=(const Par& otro){
					this->elemento = otro.elemento;
					this->prioridad = otro.prioridad;
					return this;
				}
		};


	public:
		CPArbol(){
			ultimo = 0;
			arbolVecPar = new Par[Q];
		}

		~CPArbol(){
			delete arbolVecPar;
		}

		void vaciar(){
			ultimo = 0;
		}

		int vacia(){
			return !ultimo;
		}

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

		std::ostream& imprimir(std::ostream& salida){
			for(int i = 1; i <= ultimo; ++i){
				salida << "(" << arbolVecPar[i].elemento << "," << arbolVecPar[i].prioridad << ") - ";
			}
			salida << std::endl;
		}
};

#endif
