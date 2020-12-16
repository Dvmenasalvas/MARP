
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <string>
#include <vector>
#include "Matriz.h"
#include <algorithm>	//max y min
#include <climits>	//INT_MAX
#include <iomanip> //setw

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

//Devuelve lo que cuesta hacer uno de los cortes entre i y j (incluidos)
//si se han hecho todos menos esos
int corte(int i, int j, std::vector<int> const& cortes, int L) {
	int ant, sig;
	if (i == 0) ant = 0;
	else ant = cortes[i - 1];

	if (j == cortes.size() - 1) sig = L;
	else sig = cortes[j + 1];

	return 2 * (sig - ant);
}

void pintar(Matriz<int> const & G) {
	for (int i = 0; i < G.numcols(); i++) {
		for (int j = 0; j < G.numcols(); j++) {
			std::cout << std::setw(2) << G[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int resolver(std::vector<int> const& cortes, int L) {
	//M[i][j] lo que cuestan(forma óptima) hacer los cortes i - j(incluidos)
	//haciéndolos los últimos
	Matriz<int> M(cortes.size(), cortes.size(), 0);

	//Recorremos por diagonales(triangular superior)
	//Caso base diagonal principal
	int ant, sig;
	for (int i = 0; i < cortes.size(); i++)
		M[i][i] = corte(i, i, cortes, L);

	for (int d = 1; d < cortes.size(); d++) {
		for (int i = 0; i < cortes.size() - d; i++) {
			int j = i + d;
			//Buscamos el corte que debe ir el ultimo
			M[i][j] = std::min(M[i + 1][j], M[i][j - 1]);
			for (int m = i + 1; m < j; m++)
				M[i][j] = std::min(M[i][j], M[i][m - 1] + M[m + 1][j]);
			
			//Sumamos el coste del ultimo corte
			M[i][j] += corte(i, j, cortes, L);
		}
	}
	return M[0][cortes.size() - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int L, N;
	std::cin >> L >> N;

	if (L == 0 && N == 0)
		return false;

	std::vector<int> cortes(N);
	for (int i = 0; i < N; i++) std::cin >> cortes[i];


	std::cout << resolver(cortes, L) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}