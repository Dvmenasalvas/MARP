
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include <vector>	//Vector
#include <queue>	//queue
#include "Grafo.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void dfs(Grafo const & g, int v, std::vector<int> & marcado, bool & bipartito) {
	for (int w : g.ady(v)) {
		if (bipartito) {
			if (marcado[w] == 0) {	//No marcado
				marcado[w] = (marcado[v] % 2) + 1;
				dfs(g, w, marcado, bipartito);
			}
			else if (marcado[w] == marcado[v])
				bipartito = false;
		}
	}
}

int resolver(Grafo const & g) {
	std::vector<int> marcado(g.V(), 0);	//0 no marcado, 1 grupoA, 2 grupoB
	bool bipartito = true;
	for(int v = 0; v < g.V() && bipartito; v++){
		if (marcado[v] == 0) {
			marcado[v] = 1;
			dfs(g, v, marcado, bipartito);
		}
	}
	return bipartito;
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
		g.ponArista(v, w);
	}

	if (resolver(g)) std::cout << "SI" << '\n';
	else  std::cout << "NO" << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}