
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

int resolver(std::string A, std::string B) {
	//Inicializamos el vector solucion
	std::vector<int> sol(A.length(),0);
	
	//Utilizamos la casilla de la izquierda, la de arriba
	//y la diagonal para saber la long de esta cadena
	int diag = 0;
	for (int i = 0; i < B.length(); i++) {
		for (int j = 0; j < A.length(); j++) {
			int aux = sol[j];
			//Distingimos la primera casilla de la fila
			if (j == 0) {
				if (B[i] == A[0]) sol[0] = 1;
			}
			else {
				if (B[i] != A[j]) 
					sol[j] = std::max(sol[j],
						std::max(diag, sol[j - 1]));
				else  
					sol[j] = std::max(sol[j],
						std::max(diag + 1, sol[j - 1]));
			}
			diag = aux;
		}
	}
	return sol[sol.size() - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::string A, B;
	std::cin >> A >> B;

	if (!std::cin)
		return false;

	std::cout << resolver(A,B) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}