
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <algorithm>	//max y min
#include "Matriz.h"
#include <iomanip> //setw
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void pintar(Matriz<int> const & G) {
	for (int i = 0; i < G.numcols(); i++) {
		for (int j = 0; j < G.numcols(); j++) {
			std::cout << std::setw(2) << G[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int resolver(std::vector<int> const& cubos) {
	Matriz<int> sol(cubos.size(), cubos.size(), 0);
	//Diagonal principal
	for (int i = 0; i < cubos.size(); i++)
		sol[i][i] = cubos[i];

	if (cubos.size() > 1) {
		//Primera diag no principal
		for (int i = 0; i < cubos.size() - 1; i++)
			sol[i][i + 1] = std::max(cubos[i], cubos[i + 1]);
	}

	if (cubos.size() > 2) {
		//Matriz triangular superior
		//Denota lo máximo que puede comer si empieza con los cubos[i,j]
		//Recorremos por diagonales hacia arriba desde la diagonal principal
		for (int diag = 2; diag < cubos.size(); diag++) {
			for (int i = 0; i < cubos.size() - diag; i++) {
				//sol[i][i+diag]
				int j = i + diag;

				int cogeI = cubos[i];
				if (cubos[i + 1] >= cubos[j]) cogeI += sol[i + 2][j];
				else cogeI += sol[i + 1][j - 1];

				int cogeJ = cubos[j];
				if (cubos[i] >= cubos[j - 1]) cogeJ += sol[i + 1][j - 1];
				else cogeJ += sol[i][j - 2];

				sol[i][j] = std::max(cogeI, cogeJ);
			}
		}
	}
	return sol[0][cubos.size() - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0)
		return false;
	
	std::vector<int> cubos(N);
	for (int i = 0; i < N; i++) std::cin >> cubos[i];

	
	std::cout << resolver(cubos) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}