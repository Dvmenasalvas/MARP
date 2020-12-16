// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>
#include "bintree_eda.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(bintree<char> const &arbol, int & altura) {
	if (arbol.empty()) {
		altura = 0;
		return true;
	}
	else {
		int alturaI, alturaD;
		bool I = resolver(arbol.left(), alturaI);
		bool D = resolver(arbol.right(), alturaD);
		altura = std::max(alturaI, alturaD) + 1;
		return abs(alturaI - alturaD) < 2 && I && D;
	}
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<char> arbol;
	arbol = leerArbol('.');
	int altura;
	if (resolver(arbol, altura)) std::cout << "SI" << '\n';
	else  std::cout << "NO" << '\n';
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}