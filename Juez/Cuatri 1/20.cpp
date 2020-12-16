// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>
#include "PriorityQueue.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

long long resolver(PriorityQueue<long long> m) {
	long long aux = 0;
	long long esfuerzo = 0;

	while (m.size() > 1) {
		aux = m.top();
		m.pop();
		aux += m.top();
		m.pop();
		esfuerzo += aux;
		m.push(aux);
	}
	
	return esfuerzo;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	PriorityQueue<long long> m;
	int tam, elem;
	
	std::cin >> tam;
	if (tam == 0)
		return false;

	for (int i = 0; i < tam; i++) {
		std::cin >> elem;
		m.push(elem);
	}

	std::cout << resolver(m) << std::endl;

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}