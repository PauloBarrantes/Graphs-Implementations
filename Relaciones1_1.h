#ifndef relaciones1_1_2017
#define relaciones1_1_2017

template<class T>

class Relaciones1_1{
	class Relacion; //Par de calase relaciones
	private:
		Relacion* primera;
		Relacion* ultima;
	
		class Relacion{
			public:
				T elemento1;
				T elemento2;
				Relacion* siguiente;
				
				
				Relacion(T elemento1, T elemento2){
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

	public:
		Relaciones1_1(){
			primera = 0;
		}
		
		~Relaciones1_1(){
			delete primera;
		}
		
		void agregar(T elemento1, T elemento2){
			Relacion* relacion = new Relacion(elemento1,elemento2);
			
			if(primera){
				ultima->siguiente = relacion;
				ultima = relacion;
			}else{
				primera = relacion;
				ultima = relacion;
			}
		}
		
		T imagen(T elemento){
			T img = primera->elemento2;
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
		
		T preimagen(T elemento){
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
		
};

#endif
