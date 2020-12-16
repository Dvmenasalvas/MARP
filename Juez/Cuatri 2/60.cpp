
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include <vector>	//Vector
#include <stack>	//Pila
#include <climits>
#include "PriorityQueue.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct res {
	PriorityQueue<> elegidos;
	int total = 0;
};

res resolver(std::vector<int> const &p, std::vector<int> const & o, int T) {
	//Inicializamos el vector solucion
	std::vector<res> R(T+1);
	
	for (int i = 0; i < o.size(); i++) {
		for (int j = T; j >= 0; j--) {
			if (j - p[i]*3 >= 0 && R[j].total < R[j - p[i] * 3].total + o[i]) {
				R[j].total = R[j - p[i] * 3].total + o[i];
				R[j].elegidos = R[j - p[i] * 3].elegidos;
				R[j].elegidos.push(i);
			}
		}
	}
	return R[T];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int T, N;
	std::cin >> T >> N;

	if (!std::cin)
		return false;

	std::vector<int> p(N), o(N);

	for (int i = 0; i < N; i++) 
		std::cin >> p[i] >> o[i];
	
	res sol = resolver(p, o, T);

	std::cout << sol.total << '\n';
	std::cout << sol.elegidos.size() << '\n';
	while(!sol.elegidos.empty()) {
		std::cout << p[sol.elegidos.top()] << " " << o[sol.elegidos.top()] << '\n';
		sol.elegidos.pop();
	}
	std::cout << "----" << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}