
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include <vector>	//Vector
#include <stack>	//Pila
#include <climits>
#include "GrafoValorado.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct res {
	int formas = 0,
		numMin = INT_MAX,
		costMin = INT_MAX;
	bool posible = false;
};

res resolver(std::vector<int> const &l, std::vector<int> const & c, int L) {
	std::vector<res> R(L+1);
	//Inicializamos el vector solucion
	R[0].posible = true;
	R[0].formas = 1;
	R[0].numMin = 0;
	R[0].costMin = 0;

	for (int i = 0; i < l.size(); i++) {
		for (int j = L; j >= 0; j--) {
			if (j - l[i] >= 0 && R[j - l[i]].posible) {
				//Posible
				R[j].posible = true;
				//Formas
				R[j].formas += R[j-l[i]].formas;
				//numMin
				R[j].numMin = std::min(R[j].numMin, R[j - l[i]].numMin + 1);
				//costMin
				R[j].costMin = std::min(R[j].costMin, R[j - l[i]].costMin + c[i]);
			}
		}
	}
	return R[L];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, L;
	std::cin >> N >> L;

	if (!std::cin)
		return false;

	std::vector<int> l(N), c(N);

	for (int i = 0; i < N; i++) 
		std::cin >> l[i] >> c[i];
	
	res r = resolver(l, c, L);

	if (r.posible)
		std::cout << "SI " << r.formas << " " << r.numMin 
		<< " " << r.costMin << '\n';
	else
		std::cout << "NO" << '\n';
	
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}