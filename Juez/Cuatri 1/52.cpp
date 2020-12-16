
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

int resolver(std::vector<int> const &B, std::vector<int> const &R) {
	int suma = 0;
	int i = 0, j = 0;
	while (i < B.size()) {
		if (B[i] > R[j]) {
			suma += B[i] - R[j];
			j++;
		}
		i++;
	}
	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, L;
	std::cin >> N;

	if (N == 0)
		return false;

	std::vector<int> R,B;
	int aux;
	for (int i = 0; i < N; i++) {
		std::cin >> aux;
		R.push_back(aux);
	}
	for (int i = 0; i < N; i++) {
		std::cin >> aux;
		B.push_back(aux);
	}
	sort(B.begin(), B.end(), std::greater<int>());
	sort(R.begin(), R.end());

	std::cout << resolver(B, R) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}