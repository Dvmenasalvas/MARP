
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include <vector>	//Vector
#include <queue>
#include "Grafo.h"
#include "Matriz.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool conectados(std::pair<int, int> p1, std::pair<int, int> p2, int K) {
	return std::min(abs(p1.first - p2.first), abs(p1.second - p2.second)) <= K;
}

void dfs(Grafo const & g, int v, int & act, std::vector<bool> & marcado) {
	marcado[v] = true;
	for (int w : g.ady(v))
		if (!marcado[w]) {
			act++;
			dfs(g, w, act, marcado);
		}

}

int resolver(Grafo & g, std::vector<std::pair<int,int>> arboles) {
	int i = -1;
	bool alcanzable = true;
	std::string salida;
	while (alcanzable && i < arboles.size()) {
		std::vector<bool> marcado(g.V());
		for (int v = 0; v < g.V(); v++) {
			act = 0;
			if (!marcado[v]) {
				act++;
				dfs(g, v, act, marcado);
			}
			if (act > max) max = act;
		}
	}
	return salida;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, M, K, n;
	std::cin >> N >> M >> K >> n;

	if (!std::cin)
		return false;

	Grafo g = Grafo(n + 2);	//(0,0) -> n ; (N,M) -> n+1
	std::vector<std::pair<int,int>> arboles;

	std::pair<int, int> pos;
	for (int i = 0; i < n; i++) {
		std::cin >> pos.first >> pos.second;
		arboles[i] = pos;
		if (conectados({ 0,0 }, pos, K)) g.ponArista(n, i);
		if (conectados({ N,M }, pos, K)) g.ponArista(n + 1, i);
		for (int j = 0; j < arboles.size(); j++) 
				if (i != j && conectados(pos, arboles[j], K))
					g.ponArista(i, j);
	}

	std::cout << resolver(g, arboles) << '\n';

	return true;
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
	return 0;
}