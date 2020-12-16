
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//sort
#include <string>	//Leer strings
#include <vector>	//Vector
#include <queue>
#include "Grafo.h"
#include "Matriz.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int resolver(int L, std::vector<int> v) {
	int parches = 0;
	int anterior = -(L + 1);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] > anterior + L) {
			anterior = v[i];
			parches++;
		}
	}
	return parches;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, L;
	std::cin >> N >> L;

	if (!std::cin)
		return false;

	std::vector<int> v;
	int act;
	for (int i = 0; i < N; i++) {
		std::cin >> act;
		v.push_back(act);
	}
	sort(v.begin(), v.end());

	std::cout << resolver(L,v) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}