
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include <vector>	//Vector
#include <stack>	//Pila
#include "GrafoValorado.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


bool resolver(GrafoValorado<int> const & g, int ini, int fin, int anch) {
	std::vector<bool> marcado(g.V(), false);
	marcado[ini] = true;
	std::stack<int> s;
	s.push(ini);
	bool encontrado = false;
	while (!s.empty() && !encontrado) {
		int v = s.top();
		s.pop();
		for (Arista<int> e : g.ady(v)) {
			if (e.valor() >= anch) {
				int w = e.otro(v);
				if (w == fin) encontrado = true;
				else if (!marcado[w]) {
					s.push(w);
					marcado[w] = true;
				}
			}
		}
	}
	return encontrado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;

	if (!std::cin)
		return false;

	GrafoValorado<int> g = GrafoValorado<int>(V);

	int v, w, valor;
	for (int i = 0; i < E; i++) {
		std::cin >> v >> w >> valor;
		v--;
		w--;
		g.ponArista(Arista<int>(v, w, valor));
	}

	int K, ini, fin, anch;
	std::cin >> K;
	for (int i = 0; i < K; i++) {
		std::cin >> ini >> fin >> anch;
		if (resolver(g, ini - 1, fin - 1, anch))
			std::cout << "SI" << '\n';
		else
			std::cout << "NO" << '\n';

	}
	
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}