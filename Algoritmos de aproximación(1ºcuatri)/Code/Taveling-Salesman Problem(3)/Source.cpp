
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include "GrafoValorado.h"
#include "PriorityQueue.h"



struct arista {
	int u;
	int v;
	int valor;
	bool operator<(const arista& d) const {
		return valor < d.valor;
	}
};

//Algoritmo de Prim para obtener el MST
GrafoValorado<int> primMST(GrafoValorado<int> const & g) {
	GrafoValorado<int> MSP(g.V());	//Grafo que se completará con las aristas necesarias para dar la solución
	std::vector<bool> incluido(g.V(), false);	//Vector para saber que vértices están en nuestro MSP
	PriorityQueue<arista> ady;	
	
	arista aux;
	incluido[0] = true;
	for (auto v : g.ady(0)) {	//Iniciamos el algoritmo con el vértice 0
		aux.u = v.uno();
		aux.v = v.otro(aux.u);
		aux.valor = v.valor();
		ady.push(aux);
	}
	while (!ady.empty()) {
		aux = ady.top();
		ady.pop();
		MSP.ponArista({ aux.u, aux.v, aux.valor });	//Metemos la nueva arista
		 
		int nuevo = aux.u;
		if (incluido[aux.u]) nuevo = aux.v;
		incluido[nuevo] = true;

		//Añadimos las nuevas aristas adyacentes a la PQ
		for (auto v : g.ady(nuevo)) {	//Iniciamos el algoritmo con el vértice 0
			aux.u = v.uno();
			aux.v = v.otro(aux.u);
			aux.valor = v.valor();
			if(!incluido[ady.top().u] || !incluido[ady.top().v]) 
				ady.push(aux);
		}


		//Quitamos, si es que hay, las aristas que ya no sirvan
		while (!ady.empty() && incluido[ady.top().u] && incluido[ady.top().v]) ady.pop();
	}

	return MSP;
}

void preordenAux(GrafoValorado<int> const & g, std::vector<int> & preorden, int act, int padre) {
	for (auto i : g.ady(act)) {
		int hijo = i.otro(act);

		if (hijo != padre) {
			preorden.push_back(hijo);
			preordenAux(g, preorden, hijo, act);
		}
	}
}

//Esta función supone que g es un arbol con raiz en 0
void preorden(GrafoValorado<int> const & g, std::vector<int> & preorden) {
	preorden.push_back(0);
	preordenAux(g, preorden, 0, 0);
}

//Algoritmo solo válido si el grafo cumple la desigualdad triangular
std::vector<int> approxTSPTour(GrafoValorado<int> const & g) {
	//Generamos el arbol de mínimo recubrimiento
	GrafoValorado<int> MSP = primMST(g);
	std::vector<int> TSP;
	//Damos nuestro aproximación del problema del viajante como una lista de vértices
	//Que son el preorden del MSP obtenido anteriormente
	preorden(MSP, TSP);
	
	return TSP;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;

	if (!std::cin)
		return false;

	GrafoValorado<int> g(V);

	int v, w, T;
	for (int i = 0; i < E; i++) {
		std::cin >> v >> w >> T;
		g.ponArista({ v, w, T });
	}

	std::vector<int> TSP = approxTSPTour(g);

	for (int i : TSP)
		std::cout << i << " ";

	std::cout << '\n';

	return true;
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
	return 0;
}