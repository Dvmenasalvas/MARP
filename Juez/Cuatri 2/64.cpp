
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <string>
#include <algorithm>	//max y min
#include <climits>	//INT_MAX
#include "Matriz.h"
#include <map>
#include <iomanip> //setw
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void pintar(Matriz<int> const & G) {
	for (int i = 0; i < G.numcols(); i++) {
		for (int j = 0; j < G.numcols(); j++) {
			std::cout << std::setw(10) << G[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int resolver(Matriz<int> & G) {
	//Calculas los caminos minimos entre cada persona
	for (int k = 0; k < G.numcols(); k++) {
		for (int i = 0; i < G.numcols(); i++) {
			for (int j = 0; j < G.numcols(); j++) {
				if (G[i][k] != INT_MAX && G[k][j] != INT_MAX) {
					int temp = G[i][k] + G[k][j];
					if (temp < G[i][j])
						G[i][j] = temp;
				}
			}
		}
	}

	//Cojemos el máximo de todos
	int max = 0;
	for (int i = 0; i < G.numcols(); i++)
		for (int j = i; j < G.numcols(); j++)
			if (max < G[i][j]) max = G[i][j];
	return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int P, R;
	std::cin >> P >> R;

	if (!std::cin)
		return false;
	Matriz<int>G(P,P,INT_MAX);

	for (int i = 0; i < P; i++) G[i][i] = 0;

	std::map<std::string, int> numero;
	std::string A, B;
	int j = 0;
	for (int i = 0; i < R; i++) {
		std::cin >> A >> B;
		if (numero.count(A) == 0) {
			numero.insert({ A,j });
			j++;
		}
		if (numero.count(B) == 0) {
			numero.insert({ B,j });
			j++;
		}
		G[numero[A]][numero[B]] = 1;
		G[numero[B]][numero[A]] = 1;
	}

	int grado = resolver(G);
	if (grado == INT_MAX) std::cout << "DESCONECTADA\n";
	else std::cout << grado << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}