// Danie	l Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include "PriorityQueue.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct paciente {
	std::string nombre;
	int gravedad;
	int n;
	bool operator<(const paciente& p) const {
		return gravedad > p.gravedad || gravedad == p.gravedad && n < p.n;
	}
};

void resolver(int tam) {
	char evento;
	PriorityQueue<paciente> m;
	paciente p;
	std::string nombre;
	int gravedad;
	for (int i = 0; i < tam; i++) {
		std::cin >> evento;
		if (evento == 'I') {
			std::cin >> nombre >> gravedad;
			p.nombre = nombre;
			p.gravedad = gravedad;
			p.n = i;
			m.push(p);
		}
		else if (evento == 'A') {
			std::cout << m.top().nombre << '\n';
			m.pop();
		}
	}
	std::cout << "----" << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int tam;
	
	std::cin >> tam;
	if (tam == 0)
		return false;

	resolver(tam);

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}