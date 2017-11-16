#ifndef grafonodirigidoMatriz_2017
#define grafonodirigidoMatriz_2017

#include <iostream>
#define M 11

using namespace std;

class Grafo {
    private:
        char* vectorEtiquetas;
		int** matrizPesos;
		int ultimo;
		
		//Generaliza el corrimiento
		void corrimientoEnMatriz(int inicioF,int paradaF,int inicioC, int paradaC,int corrF, int corrC){
			for(int f = inicioF; f < paradaF; ++f){
				for(int c = inicioC; c < paradaC; ++c){
					matrizPesos[f][c] = matrizPesos[f + 1*corrF][c + 1*corrC];
				}
			}
		}
    public:
		typedef int Vertice;
	
        Grafo(){
			vectorEtiquetas = new char[M];
			
			matrizPesos = new int* [M];
			for(int f = 1; f < M; ++f){
				matrizPesos[f] = new int[M];
				for(int c = 0; c < M; ++c){
					matrizPesos[f][c] = -1;
				}
			}
		}
		
        ~Grafo(){
			delete vectorEtiquetas;
			
			for(int f = M-1; f > 0; ++f){
				delete [] matrizPesos[f]; 
			}
			delete [] matrizPesos;
		}
		
        void vaciar(){
			ultimo = 0;
		}
		
        int vacia(){
			return ultimo;
		}
		
		
		
		void agrArista(Vertice v1, Vertice v2, int peso){
			matrizPesos[v1][v2] = peso;
		}
		
		Vertice agrVertice (char etqt){
			++ultimo;
			vectorEtiquetas[ultimo] = etqt;
		}
        
        void elimVertice(Vertice v){
			
			//Esto es para elminarlo del vector
			for(int i = v; i < ultimo; ++i){
				vectorEtiquetas[i] = vectorEtiquetas[i+1];
			}
			
			//Hacemos los corrimiento en la matriz.
			//Primer caso especial, filas menores a v, con columna mayores a v
			corrimientoEnMatriz(1,v,v,ultimo,0,1);
			
			//Segundo caso especial columnas menores a v, con filas mayores a v
			corrimientoEnMatriz(v,ultimo,1,v,1,0);
			
			//Caso generalizado
			corrimientoEnMatriz(v,ultimo,v,ultimo,1,1);
			
			--ultimo;
		}
		
        void elimArista(Vertice v1, Vertice v2){
			matrizPesos[v1][v2] = -1;
			matrizPesos[v2][v1] = -1;
		}
		
		char etiqueta(Vertice v){
			return vectorEtiquetas[v];
		}
		
		int existeArista(Vertice v1, Vertice v2){
			int siExiste = 1;
			
			if(matrizPesos[v1][v2] == -1){
				siExiste = 0;
			}
			
			return siExiste;
		}
		
        void modificarEtiqueta(Vertice v, char etqt){
			vectorEtiquetas[v] = etqt;
		}
		
		void modificarPeso(Vertice v1, Vertice v2, int peso){
			matrizPesos[v1][v2] = peso;
			matrizPesos[v2][v1] = peso;
		}
        
		int numAristas(){
			int num = 0;
			for(int f = 1; f <= ultimo; ++f){
				for(int c = 1; c <= ultimo; ++c){
					if(matrizPesos[f][c] != -1){
						++num;
					}
				}
			}
			return num;
		}
		
        int numVertices(){
			return ultimo;
		}
		
        int numVerticesAdy(Vertice v){
			int num = 0;
			for(int c = 1; c <= ultimo; ++c){
				if(matrizPesos[v][c] == -1){
					++num;
				}
			}
			return num;
		}
		
		int peso(Vertice v1, Vertice v2){
			return matrizPesos[v1][v2];
		}
		
		
		
		Vertice primerVertice(){
			return 1;
		}
		
		Vertice steVertice(Vertice v){
			return v+1;
		}
		
		Vertice primerVertAdy(Vertice v){
			Vertice vAdy = 1;
			while(vAdy <= ultimo && matrizPesos[v][vAdy] == -1){
				++vAdy;
			}
			
			if(vAdy > ultimo){
				vAdy = -1;
			}
			
			return vAdy;
		}
		
		Vertice steVertAdy(Vertice v1, Vertice v2){
			Vertice vAdy = v2+1;
			while(vAdy <= ultimo && matrizPesos[v1][vAdy] == -1){
				++vAdy;
			}
			
			if(vAdy > ultimo){
				vAdy = -1;
			}
			
			return vAdy;
		}
        
};

#endif
