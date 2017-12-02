#include "Algoritmos.h"
#define infty 100000000
using namespace std;

		Algoritmos::Algoritmos(){
			costoActual = 0;
			costoGlobal = 0;
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
			return g2;
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
						if(!grafo->adyacentes(relaciones.imagen(i),relaciones.imagen(j))){
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
					if(i==j || !grafo->adyacentes(relaciones.imagen(i),relaciones.imagen(j))){
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
      cout<<"Distancias: "<< endl;
			for(int i=0;i<numV; ++i){
				for(int j=0;j<numV; ++j){
					cout << distancias[i][j] << " ";
				}
				cout<<endl;
			}
			//Imprimimos la matriz de caminos.
			cout<<"Caminos: "<<endl;
			for(int i=0;i<numV; ++i){
				for(int j=0;j<numV; ++j){
					if(caminos[i][j] == -1){
						if(i==j){
							cout << "$ ";
						}
						else{
							cout << caminos[i][j] << " ";
						}
					}
					else{
						cout << grafo->etiqueta(relaciones.imagen(caminos[i][j])) << " ";
					}
				}
				cout<<endl;
			}
		}

		void Algoritmos::dijkstra(Grafo* grafo, Grafo::Vertice vertice){
		 	Relaciones1_1<int, Grafo::Vertice> R11;
		 	DiccionarioLSE<Grafo::Vertice> diccionario;
			int numV = grafo->numVertices();
			Grafo::Vertice destinos [numV];
		 	int costos [numV];
			Grafo::Vertice actual = grafo->primerVertice();

			for(int i=0; i<numV;++i){
				R11.agregar(i,actual);
				actual = grafo->siguienteVertice(actual);
			}
			//inicializamos distancias en infinito, primer vertice en 0.
			actual = grafo->primerVertice();
			for(int i=0; i<numV;++i){
				if(actual == vertice){
					costos[i] = 0;
				}else{
					costos[i] = infty;
				}
				actual = grafo->siguienteVertice(actual);
		  }
			//Condición de Dijkstra.
			int costoPivote;
			int indicePivote;
			while(diccionario.numElem() != grafo->numVertices()){
				  //Escogencia del pivote
					costoPivote = infty;
					for(int i=0;i<numV;++i){
						if(!diccionario.pertenece(R11.imagen(i))){
							if(costoPivote > costos[i]){
								costoPivote = costos[i];
								indicePivote = i;
							}
						}
					}
				diccionario.agregar(R11.imagen(indicePivote));
				Grafo::Vertice adyacente = grafo->primerVerticeAdy(R11.imagen(indicePivote));
				while(adyacente!=0){
				 	if(!diccionario.pertenece(adyacente)){
						if(costos[indicePivote] + grafo->peso(R11.imagen(indicePivote), adyacente) < costos[R11.preimagen(adyacente)]){
		 					costos[R11.preimagen(adyacente)] = grafo->peso(R11.imagen(indicePivote), adyacente) + costos[indicePivote];
				 		 	destinos[R11.preimagen(adyacente)] = R11.imagen(indicePivote);
						}
					}
					adyacente = grafo->siguienteVerticeAdy(R11.imagen(indicePivote),adyacente);
				}
	    }
			//Imprimimos el vector de costos.
			cout<<"Costos: "<< endl;
			for(int i=0;i<numV; ++i){
				cout << costos[i] << " | ";
			}
			//Imprimimos el vector de destinos.
			cout<<endl<<"Destinos: "<<endl;
			for(int i=0;i<numV; ++i){
				cout << grafo->etiqueta(destinos[i]) << " | ";
			}
			cout << endl;
		}
		void Algoritmos::kruskal(Grafo* grafo){
			DiccionarioLSE<Grafo::Vertice>diccionario;
			CDCD<Grafo::Vertice> conjunto;
			CPArbol<Tripleta> cola;
			int numAristas = 0;
			// Primero encolamos en el vector heap todas las aristas, usando el peso como prioridad
			// Luego metemos en Conjuntos de Conjuntos todos los vértices

			Grafo::Vertice vertice = grafo->primerVertice();
			Grafo::Vertice ady = 0;
			int i = 1;
			while(vertice != 0){
				ady = grafo->primerVerticeAdy(vertice);
				conjunto.agregarConjunto(i, vertice);
				while(ady != 0){
					Tripleta tripleta =  Tripleta(vertice, ady, grafo->peso(vertice, ady));
					if(!cola.pertenece(tripleta)){ //Preguntar si la arista ya fue guardada
						cola.agregar(tripleta,grafo->peso(vertice, ady));
					}
					ady = grafo->siguienteVerticeAdy(vertice, ady);
				}

				vertice = grafo->siguienteVertice(vertice);
				++i;
			}
			int numeroA = 0;

			// Sacamos la primera Arista de la cola de prioridad, y nos fijamos si V1 y V2, no están en el mismo conjunto, si no están, desplegamos la arista, y unimos estos dos conjuntos.
			// La condición de parada es que numAristas sea numVertices-1
			while(numeroA != grafo->numVertices()-1){
				Tripleta par = cola.sacar();
				if(conjunto.conjuntoAlQuePertenece(par.v1) != conjunto.conjuntoAlQuePertenece(par.v2)){
					cout << grafo->etiqueta(par.v1) << "<---" << grafo->peso(par.v1,par.v2) << "--->" << grafo->etiqueta(par.v2)<<endl;
					conjunto.unirConjuntos(conjunto.conjuntoAlQuePertenece(par.v1),conjunto.conjuntoAlQuePertenece(par.v2));
					++numeroA;
				}
			}
		}

		void Algoritmos::prim (Grafo* grafo){
			int costoTotal = 0;
			Relaciones1_1<int, Grafo::Vertice> R11;
		 	DiccionarioLSE<Grafo::Vertice> diccionario;
			int numV = grafo->numVertices();
			Grafo::Vertice destinos [numV];
		 	int costos [numV];
			Grafo::Vertice actual = grafo->primerVertice();

			for(int i=0; i<numV;++i){
				R11.agregar(i,actual);
				actual = grafo->siguienteVertice(actual);
			}
			//inicializamos distancias en infinito, primer vertice en 0.
			costos[0] = 0;
			actual = grafo->primerVertice();
			for(int i=1; i<numV;++i){
				costos[i] = infty;
		  }
			//Condición de Dijkstra.
			int costoPivote;
			int indicePivote;
			while(diccionario.numElem() != grafo->numVertices()){
				  //Escogencia del pivote
					costoPivote = infty;
					for(int i=0;i<numV;++i){
						if(!diccionario.pertenece(R11.imagen(i))){
							if(costoPivote > costos[i]){
								costoPivote = costos[i];
								indicePivote = i;
							}
						}
					}
				diccionario.agregar(R11.imagen(indicePivote));
				Grafo::Vertice adyacente = grafo->primerVerticeAdy(R11.imagen(indicePivote));
				while(adyacente!=0){
				 	if(!diccionario.pertenece(adyacente)){
						if(grafo->peso(R11.imagen(indicePivote), adyacente) < costos[R11.preimagen(adyacente)]){
		 					costos[R11.preimagen(adyacente)] = grafo->peso(R11.imagen(indicePivote), adyacente);
				 		 	destinos[R11.preimagen(adyacente)] = R11.imagen(indicePivote);
							costoTotal += grafo->peso(R11.imagen(indicePivote), adyacente);
						}
					}
					adyacente = grafo->siguienteVerticeAdy(R11.imagen(indicePivote),adyacente);
				}
	    }
			//Imprimimos el vector de costos.
			for(int i=0;i<numV; ++i){
				if(costos[i]){
					cout << grafo->etiqueta(destinos[i]) << "<---" << costos[i] << "--->" << grafo->etiqueta(R11.imagen(i))<<endl;
				}
			}

			cout << endl;
		}

		void Algoritmos::problemaDelVendedor(Grafo* grafo){
			costoActual = 0;
			costoGlobal = infty;
		 	Grafo::Vertice primerV = grafo->primerVertice();
 			solucionActual = new Grafo::Vertice[grafo->numVertices()];
		 	solucionGanadora = new Grafo::Vertice[grafo->numVertices()];
			solucionActual[0] = primerV;
		 	diccionarioH.agregar(primerV);
		 	problemaDelVendedorR(grafo, primerV,1);

			cout <<"CaminoMásCorto: " <<costoGlobal<<endl;
			for(int i = 0; i < grafo->numVertices();i++){
				cout <<"Vértice -> " << grafo->etiqueta(solucionGanadora[i])<< "->";
			}
		}

		void Algoritmos::problemaDelVendedorR(Grafo* grafo, Grafo::Vertice vertice, int numVertice){

				Grafo::Vertice verticeAdy = grafo->primerVerticeAdy(vertice);

		 		while(verticeAdy != 0){
		 			if(!diccionarioH.pertenece(verticeAdy)){ // Preguntamos por factibilidad
						diccionarioH.agregar(verticeAdy);
		 				costoActual += grafo->peso(vertice, verticeAdy);
						solucionActual[numVertice] = verticeAdy;

		 				if(numVertice == grafo->numVertices()-1){//Preguntamos por condición de parada
								if(costoActual < costoGlobal && grafo->adyacentes(solucionActual[0], verticeAdy)){
			 						costoGlobal = costoActual;
									costoGlobal += grafo->peso(solucionActual[0], verticeAdy);
									for(int i = 1; i < grafo->numVertices();++i){
										solucionGanadora[i] = solucionActual[i];
									}
			 					}


		 				}else{
							problemaDelVendedorR(grafo, verticeAdy, numVertice+1);//Hacemos el llamado recursivo
		 				}

		 				diccionarioH.borrar(verticeAdy);
		 				costoActual -= grafo->peso(vertice, verticeAdy);
		 			}
			verticeAdy = grafo->siguienteVerticeAdy(vertice, verticeAdy);
		 }
	 }
