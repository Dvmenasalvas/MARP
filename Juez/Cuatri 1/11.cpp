// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>
#include "bintree_eda.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

bool resolverAux(bintree<int> const &arbol, int & altura, int &max, int &min) {
	if (arbol.empty()) {
		altura = 0;
		return true;
	}
	else {
		int alturaI = 0, maxI = arbol.root(), minI = arbol.root();
		int alturaD = 0, maxD = arbol.root(), minD = arbol.root();
		bool I = true, D = true;
		bool mayorI = true, menorD = true;
		if (!arbol.left().empty()) {
			I = resolverAux(arbol.left(), alturaI, maxI, minI);
			mayorI = maxI < arbol.root();
		}
		if (!arbol.right().empty()) {
			D = resolverAux(arbol.right(), alturaD, maxD, minD);
			menorD = arbol.root() < minD;
		}
		altura = std::max(alturaI, alturaD) + 1;
		min = std::min(std::min(minI, minD), arbol.root());
		max = std::max(std::max(maxI, maxD), arbol.root());
		return abs(alturaI - alturaD) < 2 && I && D &&
			mayorI && menorD;
	}
}

bool resolver(bintree<int> const &arbol) {
	int a, b, c;
	return resolverAux(arbol, a, b, c);
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> arbol;
	arbol = leerArbol(-1);
	if (resolver(arbol)) std::cout << "SI" << '\n';
	else  std::cout << "NO" << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}