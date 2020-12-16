
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <string>
#include <vector>
#include "Matriz.h"
#include <algorithm>	//max y min
#include <climits>	//INT_MAX
#include "PriorityQueue.h"

struct nodo {
	int k, t, tOpt;
	std::vector<bool> asig;
	nodo(){}
	nodo(int N) : asig(N,false) {}
	bool operator<(const nodo& p) const {
		return tOpt < p.tOpt;
	}
};

void estimaciones(Matriz<int> const& tareas, std::vector<int>& opt,
	std::vector<int>& pes) {
	//Calculamos max y min por filas
	std::vector<int> maximos(tareas.numcols());
	std::vector<int> minimos(tareas.numcols());

	for (int i = 0; i < tareas.numcols(); i++) {
		maximos[i] = tareas[i][0];
		minimos[i] = tareas[i][0];
		for (int j = 1; j < tareas.numcols(); j++) {
			maximos[i] = std::max(maximos[i], tareas[i][j]);
			minimos[i] = std::min(minimos[i], tareas[i][j]);
		}
	}
	opt = std::vector<int>(tareas.numcols() + 1, 0);
	pes = std::vector<int>(tareas.numcols() + 1, 0);

	for (int i = tareas.numcols() - 1; i >= 0; i--) {
		opt[i] = opt[i + 1] + minimos[i];
		pes[i] = pes[i + 1] + maximos[i];
	}
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

int resolver(Matriz<int> const & tareas) {
	std::vector<int> opt;
	std::vector<int> pes;
	estimaciones(tareas, opt, pes);

	nodo Y(tareas.numcols());
	Y.k = -1; Y.t = 0; Y.tOpt = opt[0];
	PriorityQueue<nodo> C;
	C.push(Y);
	int tMejor = pes[0];
	nodo X(tareas.numcols());

	while (!C.empty() && C.top().tOpt <= tMejor) {
		Y = C.top(); C.pop();
		//Hijos
		X.k = Y.k + 1;	X.asig = Y.asig;
		for (int t = 0; t < tareas.numcols(); t++) {
			if (!X.asig[t]) {
				X.asig[t] = true;
				X.t = Y.t + tareas[X.k][t];
				X.tOpt = X.t + opt[X.k + 1];
				if (X.tOpt <= tMejor) {
					if (X.k == tareas.numcols() - 1)
						tMejor = X.t;
					else {
						C.push(X);
						tMejor = std::min(tMejor, X.t + pes[X.k + 1]);
					}
				}
				X.asig[t] = false;
			}
		}
	}
	return tMejor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin  >> N;

	if (N == 0)
		return false;

	Matriz<int> tareas(N, N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			std::cin >> tareas[i][j];

	std::cout << resolver(tareas) << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}