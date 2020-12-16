
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include "IndexPQ.h"


void actualizar(IndexPQ<int, std::greater<int>> &noMarcadosPQ, std::vector<int> &noMarcados, std::vector<std::set<int>> const &F, int marcado) {
	//Si el elemento que hemos marcado esta en S, actualizamos noMarcados en consecuencia
	for (int i = 0; i < F.size(); i++) {
		auto p1 = F[i].find(marcado);	
		if (p1 != F[i].end()) {
			noMarcados[i]--;
			noMarcadosPQ.update(i, noMarcados[i]);
		}
	}
}

std::vector<std::set<int>> greedySetCover(std::set<int> const &X, std::vector<std::set<int>> const &F) {
	std::set<int> U = X;
	std::vector<std::set<int>> C;
	/*
	Tendremos un vector indicando cuantos elementos no marcados hay 
	en cada elemento de F. Y una cola indexada para saber cual es el menor.
	*/
	//
	std::vector<int> noMarcados(F.size());
	IndexPQ<int, std::greater<int>> noMarcadosPQ(F.size());

	for (int i = 0; i < F.size(); i++) {
		noMarcadosPQ.push(i, F[i].size());
		noMarcados[i] = F[i].size();
	}
	
	while (!U.empty()) {
		std::set<int> S = F[noMarcadosPQ.top().elem];

		for (int e : S) {
			auto p1 = U.find(e);	//Si e esta en U, lo eliminamos
			if (p1 != U.end()) {
				U.erase(p1);
				actualizar(noMarcadosPQ,noMarcados, F, e); //Actualizamos noMarcados
			}
		}
		C.push_back(S);
	}
	return C;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::set<int> X, aux;
	std::vector<std::set<int>> F;
	int cardF, e;
	
	/*En la primera linea se introducirá X(asumiremos que todos los elementos son positivos
	para poder usar -1 como elemento especial para mostrar el final del conjunto),
	en la siguiente linea se dará |F| 
	y en las demás los elementos de F, cada uno terminado en -1
	*/
	std::cin >> e;
	while (e != -1) {
		X.insert(e);
		std::cin >> e;
	}

	std::cin >> cardF;
	for (int i = 0; i < cardF; i++) {
		aux = std::set<int>();
		std::cin >> e;
		while (e != -1) {
			aux.insert(e);
			std::cin >> e;
		}
		F.push_back(aux);
	}

	std::vector<std::set<int>> sol = greedySetCover(X, F);

	for (auto S : sol) {
		for (int e : S)
			std::cout << e << " ";
		std::cout << '\n';
	}

	std::cout << '\n';

	return true;
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
	return 0;
}