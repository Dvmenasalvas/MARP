
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include <vector>	//Vector
#include <stack>	//Pila
#include <climits>
#include "Matriz.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct res {
	int elegida, total = 0;
};

res resolver(Matriz<int> const & M) {
	//Inicializamos el vector solucion
	Matriz<int> R(M.numfils(),M.numcols());
	R[0] = M[0];

	//Calculamos el valor del mejor camino que pasa por esa casilla
	res sol;
	for (int i = 1; i < M.numfils(); i++) {
		for (int j = 0; j < M.numcols(); j++) {
			int elegido = j - 1;
			if (j == 0 || R[i - 1][j - 1] < R[i - 1][j]) elegido = j;
			if (j + 1 < R.numcols() && R[i - 1][elegido] < R[i - 1][j + 1]) 
				elegido = j + 1;
			R[i][j] = M[i][j] + R[i - 1][elegido];
			
			if (R[i][j] > sol.total) {
				sol.total = R[i][j];
				sol.elegida = j;
			}
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (!std::cin)
		return false;

	Matriz<int> M(N,N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> M[i][j];
	
	res sol = resolver(M);

	std::cout << sol.total << " " << sol.elegida + 1 << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}