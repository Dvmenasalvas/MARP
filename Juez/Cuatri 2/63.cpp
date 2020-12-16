
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <string>
#include <vector>
#include"Matriz.h"
#include <algorithm>	//max y min
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


std::string resolver(std::string const & palabra) {
	Matriz<std::string> sol(palabra.length(), palabra.length(), "");
	//Inicializamos la diagonal principal
	for (int i = 0; i < palabra.length(); i++)
		sol[i][i] = palabra[i];

	//Recorremos por diagonales
	for (int d = 1; d < palabra.length(); d++) {
		for (int i = 0; i < palabra.length() - d; i++) {
			int j = i + d;
			
			if (palabra[i] == palabra[j])
				sol[i][j] = palabra[i] + sol[i + 1][j - 1] + palabra[i];
			else if (sol[i + 1][j].length() >= sol[i][j - 1].length())
				sol[i][j] = sol[i + 1][j];
			else 
				sol[i][j] = sol[i][j - 1];
		}
	}


	return sol[0][palabra.length() - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::string palabra;
	std::cin >> palabra;

	if (!std::cin)
		return false;
	
	std::cout << resolver(palabra) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}