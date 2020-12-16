
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

void pintar(Matriz<int> const & G) {
	for (int i = 0; i < G.numcols(); i++) {
		for (int j = 0; j < G.numcols(); j++) {
			std::cout << std::setw(2) << G[i][j] << " ";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int resolver(std::vector<std::pair<int,int>> const& peliculas) {
	std::vector<int> V(60 * 24 + 11, 0);

	for (int i = 0; i < peliculas.size(); i++)
		for (int j = 60 * 24 + 10; j > 0; j--)
			if (j >= peliculas[i].first + peliculas[i].second + 10)
				V[j] = std::max(V[j], V[peliculas[i].first] + peliculas[i].second);

	return V[V.size() - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin  >> N;

	if (N == 0)
		return false;

	//Inicio, duracion
	std::vector<std::pair<int,int>> peliculas(N);
	char aux;
	for (int i = 0; i < N; i++) {
		int horas;
		std::cin >> horas >> aux >> peliculas[i].first >> peliculas[i].second;
		peliculas[i].first += horas * 60;
	}

	std::sort(peliculas.begin(), peliculas.end());

	std::cout << resolver(peliculas) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}