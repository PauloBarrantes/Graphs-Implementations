#include "Algoritmos.h"
#include <iostream>
#define infty = 10000000000000
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
		void Algoritmos::dijkstra(Grafo* grafo, Grafo::Vertice vertice){
			Relaciones1_1<Grafo::Vertice, int > R11;
			Diccionarios<Grafo::Vertice> diccionario;
			int distancias [grafo->numeroVertices()];
			Grafo::Vertice destinos [grafo->numeroVertices()];
			Grafo::Vertice v = G->primerVertice();
			int indice = 1;
			while(v!= 0){
				R11.agregar(v, indice);
				distancias[indice] = infty;
				destinos[indice] = vertice
				v = Grafo->siguienteVertice(v);
				indice++;
			}
			distancias[R11.imagen(vertice)] = 0;

			while(diccionario.numeroElementos() != G.numeroVertices();){
				int menor = 1;
			}

		}
		void Algoritmos::kruskal(Grafo* grafo){
			DiccionarioLSE<Grafo::Vertice>diccionario;
			CdCd<Grafo::Vertice> conjunto;
			CdP<Grafo::Arista> cola;
			int numAristas = 0;
			// Primero encolamos en el vector heap todas las aristas, usando el peso como prioridad
			while(){

			}
			// Luego metemos en Conjuntos de Conjuntos todos los vértices
			Grafo::Vertice vertice = grafo->primerVertice();
			int i = 1;
			while(vertice!=0){
				conjunto.agregarConjunto(i, vertice);
				vertice = grafo->siguienteVertice(vertice);
				++i;
			}


			// Sacamos la primera Arista de la cola de prioridad, y nos fijamos si V1 y V2, no están en el mismo conjunto, si no están, desplegamos la arista, y unimos estos dos conjuntos.

			// La condición de parada es que numAristas sea numVertices-1
		}

		void Algoritmos::prim (Grafo* grafo){
			Relaciones1_1<Grafo::Vertice, int > R11;
			DiccionarioLSE<Grafo::Vertice> diccionario;
			int costos [grafo->numeroVertices()-1];
			Grafo::Vertice verticesConectados [grafo->numeroVertices()-1];
			Grafo::Vertice v = G->primerVertice();
			// Llenamos los arreglos y creamos las relaciones 1 a 1
			for(int i = 0; grafo->numeroVertices()-1; ++i){
				R11.agregar(v, i);
				costos[i] = infty;
				verticesConectados[i] =	v;
				v = grafo->siguienteVertice(v);
			}
			//Marcamos los adyacentes a A
			v= G->primerVertice();

			while(diccionario.numeroElementos() != G.numeroVertices()-1){



			}


		}

		void Algoritmos::problemaDelVendedor(Grafo* grafo){

			Grafo::Vertice primerV = grafo->primerVertice();
			diccionarioH.agregar(primerV);
			problemaDelVendedorR(primerV);
		}
		void Algoritmos::problemaDelVendedorR(Grafo* grafo, Grafo::Vertice vertice){
				verticeAdy = grafo->primerVerticeAdy(vertice);
				while(verticeAdy != 0){
					if(!diccionarioH.pertenece(verticeAdy)){ // Preguntamos por factibilidad

						diccionarioH.agregar(verticeAdy);
						caminoMásCortoAct += grafo->peso(vertice, verticeAdy);

						if(){//Preguntamos por condición de parada
							if(caminoMásCortoAct < caminoMásCorto){
								caminoMásCorto = caminoMásCortoAct;
							}
						}else{
							problemaDelVendedorR(grafo, grafo->primerVerticeAdy(verticeAdy));//Hacemos el llamado recursivo
						}
						diccionarioH.borrar(verticeAdy);
						caminoMásCorto -= grafo->peso(vertice, verticeAdy);
						verticeAdy = grafo->siguienteVerticeAdy(vertice, verticeAdy);
					}

				}
		}
