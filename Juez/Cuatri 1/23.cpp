// Danie	l Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include "PriorityQueue.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct tarea {
	int ini;
	int fin;
	int periodo = 0; 
	bool operator<(const tarea& t) const {
		return ini < t.ini;
	}
};

bool resolver(PriorityQueue<tarea> & m, int T) {
	bool conflicto = false;
	tarea aux;
	aux = m.top();
	m.pop();
	while (m.size() > 0 && !conflicto && m.top().ini < T) {
		conflicto = m.top().ini < aux.fin;
		if (aux.periodo != 0) {
			aux.ini += aux.periodo;
			aux.fin += aux.periodo;
			m.push(aux);
		}
		aux = m.top();
		m.pop();
	}
	return conflicto;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, M, T;
	std::cin >> N >> M >> T;
	
	if (!std::cin)
		return false;

	tarea t;
	PriorityQueue<tarea> m;
	int ini, fin, per;

	for (int i = 0; i < N; i++) {
		std::cin >> ini >> fin;
		t.ini = ini;
		t.fin = fin;
		m.push(t);
	}

	for (int i = 0; i < M; i++) {
		std::cin >> ini >> fin >> per;
		t.ini = ini;
		t.fin = fin;
		t.periodo = per;
		m.push(t);
	}

	if (resolver(m, T)) std::cout << "SI" << '\n';
	else std::cout << "NO" << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}