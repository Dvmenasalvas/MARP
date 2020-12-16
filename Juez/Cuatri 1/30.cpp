
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include <vector>	//Vector
#include "Grafo.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void dfs(Grafo const & g, int v, int & act, std::vector<bool> & marcado) {
	marcado[v] = true;
	for (int w : g.ady(v)) 
		if (!marcado[w]) {
			act++;
			dfs(g, w, act, marcado);
		}
	
}

int resolver(Grafo const & g) {
	int act = 0, max = 0;
	std::vector<bool> marcado (g.V());
	for (int v = 0; v < g.V(); v++) {
		act = 0;
		if (!marcado[v]) {
			act++;
			dfs(g, v, act, marcado);
		}
		if (act > max) max = act;
	}
	return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;

	if (!std::cin)
		return false;

	Grafo g = Grafo(V);

	int v, w;
	for (int i = 0; i < E; i++) {
		std::cin >> v >> w;
		v--;
		w--;
		g.ponArista(v, w);
	}

	std::cout << resolver(g) << '\n';

	return true;
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
	return 0;
}