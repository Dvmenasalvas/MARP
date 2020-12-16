// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//sort
#include <string>	//Leer strings
#include <functional> //Greater
#include <vector>	//Vector
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct edificio {
	int ini;
	int fin;
	bool operator<(const edificio& e) const {
		return fin < e.fin;
	}
};

int resolver(std::vector<edificio> const &edificios) {
	int tuneles = 0, ultimo = 0;
	for (auto e : edificios) {
		if (ultimo <= e.ini) {
			ultimo = e.fin;
			tuneles++;
		}
	}
	return tuneles;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0)
		return false;

	std::vector<edificio> edificios;
	int ini, fin;
	edificio e;
	for (int i = 0; i < N; i++) {
		std::cin >> ini >> fin;
		e.ini = ini;
		e.fin = fin;
		edificios.push_back(e);
	}
	sort(edificios.begin(), edificios.end());

	std::cout << resolver(edificios) << '\n';

	return true;
}
int main() {
	while (resuelveCaso()) {}

	return 0;
}