// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>
#include "PriorityQueue.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct datos {
	int usuario;
	int periodo;
	int siguiente;
	bool operator<(const datos& d) const {
		return siguiente < d.siguiente || d.siguiente == siguiente && usuario < d.usuario;
	}
};

void resolver(PriorityQueue<datos> &m, int K) {
	datos d;
	for (int i = 0; i < K; i++) {
		std::cout << m.top().usuario << '\n';
		d = m.top();
		m.pop();
		d.siguiente += d.periodo;
		m.push(d);
	}
	std::cout << "----" << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	PriorityQueue<datos> m;
	int tam, u, p, K;
	datos d;
	
	std::cin >> tam;
	if (tam == 0)
		return false;

	for (int i = 0; i < tam; i++) {
		std::cin >> u >> p;
		d.periodo = p;
		d.siguiente = p;
		d.usuario = u;
		m.push(d);
	}

	std::cin >> K;

	resolver(m, K);

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}