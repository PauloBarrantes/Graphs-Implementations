#include "Algoritmos.h"
#include <iostream>
using namespace std;

		Algoritmos::Algoritmos(){

		}
		
		Algoritmos::~Algoritmos(){
			
		}
		
		int Algoritmos::iguales(Grafo* g1, Grafo* g2){
			int iguales = 0;
			
			if(g1->numVertices() == g2->numVertices() && g1->numAristas() == g2->numAristas()){
				iguales = 1;
				Relaciones1_1<Grafo::Vertice> relaciones;
				Grafo::Vertice v = g1->primerVertice();
				Grafo::Vertice w = 0;
				while(v != 0 && iguales){
					
					w = g2->primerVertice();
					while(w != 0 && g1->etiqueta(v) != g2->etiqueta(w)){
						w = g2->steVertice(w);
					}
					
					if(w){
						relaciones.agregar(v,w);
					}else{
						iguales = 0;
					}
					v = g1->steVertice(v);
					
				}
				
				v = g1->primerVertice();
				Grafo::Vertice vAdy = 0;
				Grafo::Vertice wAdy = 0;
				
				while(v != 0 && iguales){
					w = relaciones.imagen(v);
					vAdy = g1->primerVertAdy(v);
					
					while(vAdy != 0 && iguales){
						wAdy = g2->primerVertAdy(w);
						while(wAdy != 0 && g1->etiqueta(vAdy) != g2->etiqueta(wAdy)){
							wAdy = g2->steVertAdy(w,wAdy);
						}
						
						if(!wAdy){
							iguales = 0;
						}
						vAdy = g1->steVertAdy(v,vAdy);
					}
					
					v = g1->steVertice(v);
				}
			}
			
			return iguales;
		}
		
		Grafo* Algoritmos::copiar(Grafo* g1,Grafo*g2){
			
		}
		
		void Algoritmos::kruskal(Grafo* grafo){

		}
		
		void Algoritmos::prim (Grafo* grafo){
			
		}
		
		void Algoritmos::problemaDelVendedor(Grafo* grafo){

		}
