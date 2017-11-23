#ifndef relaciones1_1_2017
#define relaciones1_1_2017

template<class T, class K>

class Relaciones1_1{
	class Relacion; //Par de calase relaciones
	private:
		Relacion* primera;
		Relacion* ultima;

		class Relacion{
			public:
				T elemento1;
				K elemento2;
				Relacion* siguiente;


				Relacion(T elemento1, K elemento2){
					this->elemento1 = elemento1;
					this->elemento2 = elemento2;
					this->siguiente = 0;
				}

				~Relacion(){
					if(siguiente){
						delete siguiente;
					}
				}
		};

		int esAgregableT(T elemento){
			Relacion* actual = primera;
			int esAgr = 1;

			while(actual != 0 && esAgr){
				if(actual->elemento1 == elemento){
					esAgr = 0;
				}

				actual = actual->siguiente;
			}

			return esAgr;
		}

		int esAgregableK(K elemento){
			Relacion* actual = primera;
			int esAgr = 1;

			while(actual != 0 && esAgr){
				if(actual->elemento2 == elemento){
					esAgr = 0;
				}

				actual = actual->siguiente;
			}

			return esAgr;
		}

	public:
		Relaciones1_1(){
			primera = 0;
		}

		~Relaciones1_1(){
			delete primera;
		}

		void agregar(T elemento1, K elemento2){
			Relacion* relacion = new Relacion(elemento1,elemento2);

			if(esAgregableT(elemento1) && esAgregableK(elemento2)){
				if(primera){
					ultima->siguiente = relacion;
					ultima = relacion;
				}else{
					primera = relacion;
					ultima = relacion;
				}
			}
		}

		K imagen(T elemento){
			K img = primera->elemento2;
			Relacion* actual = primera;
			while(elemento != actual->elemento1 && actual->siguiente != 0){
				actual = actual->siguiente;
				img = actual->elemento2;
			}

			if(elemento != actual->elemento1){
				img = 0; //No se si esto esta bien, creo que no
			}

			return img;
		}

		T preimagen(K elemento){
			T preI = primera->elemento1;
			Relacion* actual = primera;
			while(elemento != actual->elemento2 && actual->siguiente != 0){
				actual = actual->siguiente;
				preI = actual->elemento1;
			}

			if(elemento != actual->elemento2){
				preI = 0; //No se si esto esta bien, creo que no
			}

			return preI;
		}

		int hayRelacion(T elemento1, K elemento2){
			int hayR = 0;
			Relacion* actual = primera;

			while(actual->siguiente != 0 && !hayR){
				if(actual->elemento1 == elemento1 && actual->elemento2 == elemento2){
					hayR = 1;
				}

				actual = actual->siguiente;
			}

			return hayR;
		}

};

#endif
