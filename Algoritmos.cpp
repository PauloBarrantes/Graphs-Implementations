#include "Algoritmos.h"
#include <iostream>
#define infty 10000000
using namespace std;

		Algoritmos::Algoritmos(){

		}

		Algoritmos::~Algoritmos(){

		}

		int Algoritmos::iguales(Grafo* g1, Grafo* g2){
			int iguales = 0;

			if(g1->numVertices() == g2->numVertices() && g1->numAristas() == g2->numAristas()){
				iguales = 1;
				Relaciones1_1<Grafo::Vertice,Grafo::Vertice> relaciones;
				Grafo::Vertice v = g1->primerVertice();
				Grafo::Vertice w = 0;

				while(v != 0 && iguales){

					w = g2->primerVertice();
					while(w != 0 && g1->etiqueta(v) != g2->etiqueta(w)){
						w = g2->siguienteVertice(w);
					}

					if(w){
						relaciones.agregar(v,w);
					}else{
						iguales = 0;
					}
					v = g1->siguienteVertice(v);

				}

				v = g1->primerVertice();
				Grafo::Vertice vAdy = 0;
				Grafo::Vertice wAdy = 0;

				while(v != 0 && iguales){
					w = relaciones.imagen(v);
					vAdy = g1->primerVerticeAdy(v);

					while(vAdy != 0 && iguales){
						wAdy = g2->primerVerticeAdy(w);
						while(wAdy != 0 && g1->etiqueta(vAdy) != g2->etiqueta(wAdy)){
							wAdy = g2->siguienteVerticeAdy(w,wAdy);
						}

						if(!wAdy){
							iguales = 0;
						}
						vAdy = g1->siguienteVerticeAdy(v,vAdy);
					}

					v = g1->siguienteVertice(v);
				}
			}
			return iguales;
		}

		Grafo* Algoritmos::copiar(Grafo* g1,Grafo* g2){
			if(g2->numVertices() > 0){
				g2->vaciar();
			}

			Relaciones1_1<Grafo::Vertice,Grafo::Vertice> relaciones;
			char etq;
			Grafo::Vertice actual = g1->primerVertice();

			while(actual){
				etq = g1->etiqueta(actual);
				relaciones.agregar(actual,g2->agrVertice(etq));
				actual = g1->siguienteVertice(actual);
			}

			actual = g1->primerVertice();
			Grafo::Vertice ady;
			Grafo::Vertice imgAct;
			Grafo::Vertice imgAdy;

			while(actual){
				ady = g1->primerVerticeAdy(actual);
				imgAct = relaciones.imagen(actual);

				while(ady){
					imgAdy = relaciones.imagen(ady);
					if(!g2->adyacentes(imgAct,imgAdy)){
						g2->agrArista(imgAct,imgAdy,g1->peso(actual,ady));
					}
					ady = g1->siguienteVerticeAdy(actual,ady);
				}
				actual = g1->siguienteVertice(actual);
			}
		}

		void Algoritmos::floyd(Grafo* grafo){
			int numV = grafo->numVertices();
			int distancias[numV][numV];
			int caminos[numV][numV];
			Relaciones1_1<int,Grafo::Vertice> relaciones;
			//Establecer relaciones
			Grafo::Vertice actual = grafo->primerVertice();
			for(int i=0; i<numV;++i){
				relaciones.agregar(i,actual);
				actual = grafo->siguienteVertice(actual);
			}
			//llenar la matriz de distancias
			for(int i=0;i<numV;++i){
				for(int j=0;j<numV;++j){
					if(i==j){
						distancias[i][j] = 0;
					}
					else{
						if(grafo->peso(relaciones.imagen(i),relaciones.imagen(j)) == 0){
							distancias[i][j] = infty;
						}
						else{
							distancias[i][j] = grafo->peso(relaciones.imagen(i),relaciones.imagen(j));
						}
				  }
				}
			}
			//rellenar la matriz de caminos
			for(int i=0;i<numV;++i){
				for(int j=0;j<numV;++j){
					if(i==j || grafo->peso(relaciones.imagen(i),relaciones.imagen(j)) == 0){
						caminos[i][j] = -1;
					}
					else{
							caminos[i][j] = i;
					}
				}
			}
			//Algoritmo de Floyd n^3 iteraciones, buscando si existe un camino más corto via otros vértices.
			for(int k=0;k<numV; ++k){
				for(int i=0;i<numV; ++i){
					for(int j=0;j<numV; ++j){
						if(distancias[i][j] > distancias[i][k] + distancias[k][j]){
							distancias[i][j] = distancias[i][k] + distancias[k][j];
							caminos[i][j] = caminos[k][j];
						}
					}
				}
			}
		}

		void Algoritmos::dijkstra(Grafo* grafo, Grafo::Vertice vertice){
		// 	Relaciones1_1<Grafo::Vertice, int > R11;
		// 	Diccionarios<Grafo::Vertice> diccionario;
		// 	int distancias [grafo->numeroVertices()];
		// 	Grafo::Vertice destinos [grafo->numeroVertices()];
		// 	Grafo::Vertice v = G->primerVertice();
		// 	int indice = 1;
		// 	while(v!= 0){
		// 		R11.agregar(v, indice);
		// 		distancias[indice] = infty;
		// 		destinos[indice] = vertice
		// 		v = Grafo->siguienteVertice(v);
		// 		indice++;
		// 	}
		// 	distancias[R11.imagen(vertice)] = 0;
    //
		// 	while(diccionario.numeroElementos() != G.numeroVertices();){
		// 		int menor = 1;
		// 	}
    //
		}
		// void Algoritmos::kruskal(Grafo* grafo){
		// 	DiccionarioLSE<Grafo::Vertice>diccionario;
		// 	CdCd<Grafo::Vertice> conjunto;
		// 	CdP<Grafo::Arista> cola;
		// 	int numAristas = 0;
		// 	// Primero encolamos en el vector heap todas las aristas, usando el peso como prioridad
		// 	while(){
    //
		// 	}
		// 	// Luego metemos en Conjuntos de Conjuntos todos los vértices
		// 	Grafo::Vertice vertice = grafo->primerVertice();
		// 	int i = 1;
		// 	while(vertice!=0){
		// 		conjunto.agregarConjunto(i, vertice);
		// 		vertice = grafo->siguienteVertice(vertice);
		// 		++i;
		// 	}
    //
    //
		// 	// Sacamos la primera Arista de la cola de prioridad, y nos fijamos si V1 y V2, no están en el mismo conjunto, si no están, desplegamos la arista, y unimos estos dos conjuntos.
    //
		// 	// La condición de parada es que numAristas sea numVertices-1
		//}

		void Algoritmos::prim (Grafo* grafo){
		// 	Relaciones1_1<Grafo::Vertice, int > R11;
		// 	DiccionarioLSE<Grafo::Vertice> diccionario;
		// 	int costos [grafo->numeroVertices()-1];
		// 	Grafo::Vertice verticesConectados [grafo->numeroVertices()-1];
		// 	Grafo::Vertice v = G->primerVertice();
		// 	// Llenamos los arreglos y creamos las relaciones 1 a 1
		// 	for(int i = 0; grafo->numeroVertices()-1; ++i){
		// 		R11.agregar(v, i);
		// 		costos[i] = infty;
		// 		verticesConectados[i] =	v;
		// 		v = grafo->siguienteVertice(v);
		// 	}
		// 	//Marcamos los adyacentes a A
		// 	v= G->primerVertice();
    //
		// 	while(diccionario.numeroElementos() != G.numeroVertices()-1){
    //
    //
    //
		// 	}
    //
    //
		}

		void Algoritmos::problemaDelVendedor(Grafo* grafo){
		 	this->numeroSolFactibles = 0;
		 	this->numeroSolOptimas = 0;
			caminoMasCorto = 0;
			caminoMasCortoAct = 0;
		 	Grafo::Vertice primerV = grafo->primerVertice();
 			solucionActual = new Grafo::Vertice[grafo->numVertices()];
		 	solucionGanadora = new Grafo::Vertice[grafo->numVertices()];
			solucionActual[0] = primerV;
		 	diccionarioH.agregar(primerV);

		 	problemaDelVendedorR(grafo, primerV, 1);

			cout <<"CaminoMásCorto: " <<caminoMasCorto<<endl;
			for(int i = 0; i < grafo->numVertices();i++){
				cout <<"Vértice -> " << grafo->etiqueta(solucionGanadora[i])<< "->";
			}
		}

		void Algoritmos::problemaDelVendedorR(Grafo* grafo, Grafo::Vertice vertice, int numVerticesAdy){
		 		Grafo::Vertice verticeAdy = grafo->primerVerticeAdy(vertice);
		 		while(verticeAdy != 0){
		 			if(!diccionarioH.pertenece(verticeAdy)){ // Preguntamos por factibilidad

		 				diccionarioH.agregar(verticeAdy);
		 				caminoMasCortoAct += grafo->peso(vertice, verticeAdy);
						solucionActual[numVerticeVisitado] = verticeAdy;
		 				if(numVerticesAdy == grafo->numVertices()){//Preguntamos por condición de parada
		 					if(caminoMasCortoAct < caminoMasCorto){
		 						caminoMasCorto = caminoMasCortoAct;
								for(int i = 1; i < grafo->numVertices();++i){
									solucionGanadora[i] = solucionActual[i];
								}
		 					}
		 				}else{
		 					problemaDelVendedorR(grafo, verticeAdy, numVerticesAdy+1);//Hacemos el llamado recursivo
		 				}
		 				diccionarioH.borrar(verticeAdy);
		 				caminoMasCortoAct -= grafo->peso(vertice, verticeAdy);
		 				verticeAdy = grafo->siguienteVerticeAdy(vertice, verticeAdy);
		 			}
		 }
	 }
