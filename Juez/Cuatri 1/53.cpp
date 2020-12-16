
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

int resolver(std::vector<int> const &p, int V) {
	int coches = 0;
	int i = 0, j = p.size() - 1;
	while (i < j) {
		if (p[i] + p[j] >= V) {
			coches++;
			i++;
		}
		j--;
	}
	return coches;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int P, V;
	std::cin >> P >> V;

	if (!std::cin)
		return false;

	std::vector<int> p;
	int aux;
	for (int i = 0; i < P; i++) {
		std::cin >> aux;
		p.push_back(aux);
	}
	sort(p.begin(), p.end(), std::greater<int>());

	std::cout << resolver(p, V) << '\n';

	return true;
}
int main() {
	int N;
	std::cin >> N;
	for(int i = 0; i < N; i++)
		resuelveCaso();
	return 0;
}