
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include <vector>	//Vector
#include <queue>	//queue
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


void relax(AristaDirigida<int> e, std::vector<int> & distTo,IndexPQ<> &cola) {
	int v = e.from(), w = e.to();
	if (distTo[w] > distTo[v] + e.valor()) {
		distTo[w] = distTo[v] + e.valor();
		cola.update(w, distTo[w]);
	}
}

int resolver(GrafoDirigidoValorado<int> const & g) {	
	IndexPQ<> cola(g.V());
	std::vector<int> distTo(g.V(), g.V());

	cola.push(0,0);
	distTo[0] = 0;

	bool fin = false;
	while(!cola.empty() && !fin) {
		int v = cola.top().elem;
		cola.pop();
		
		for (AristaDirigida<int> e : g.ady(v))
			relax(e, distTo, cola);

		fin = cola.top().elem == g.V() - 1;
	}
	return distTo[g.V() - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, K, S, E;
	std::cin >> N >> K >> S >> E;

	if (N == 0 && N == K && K == S && S == E)
		return false;

	GrafoDirigidoValorado<int> g = GrafoDirigidoValorado<int>(N*N);

	int v, w;
	for (int i = 0; i < S + E; i++) {
		std::cin >> v >> w;
		v--;
		w--;
		g.ponArista(AristaDirigida<int>(v, w,0));
	}

	for (int i = 0; i < g.V(); i++) {
		int j = i + 1;
		while (j < g.V() && j - i <= K) {
			g.ponArista(AristaDirigida<int>(i, j,1));
			j++;
		}
	}

	std::cout << resolver(g) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}