
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//sort
#include <string>	//Leer strings
#include <vector>	//Vector
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int resolver(std::vector<int> const &p, std::vector<int> const &s) {
	int suma = 0;
	for (int i = 0; i < p.size(); i++) 
		suma += abs(p[i] - s[i]);
	
	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, L;
	std::cin >> N;

	if (N == 0)
		return false;

	std::vector<int> p,s;
	int aux;
	for (int i = 0; i < N; i++) {
		std::cin >> aux;
		p.push_back(aux);
	}
	for (int i = 0; i < N; i++) {
		std::cin >> aux;
		s.push_back(aux);
	}
	sort(p.begin(), p.end());
	sort(s.begin(), s.end());

	std::cout << resolver(p, s) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}