
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <algorithm>	//max y min
#include <climits>		//INT_MAX
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct moneda {
	int valor, cantidad;
};

int resolver(std::vector<moneda> const& monedas,int precio) {
	std::vector<int> sol(precio + 1, INT_MAX);
	sol[0] = 0;
	for (int i = 0; i < monedas.size(); i++) {
		for (int j = precio; j > 0; j--) {
			for (int k = 0; k <= monedas[i].cantidad && monedas[i].valor * k <= j; k++) {
				if (sol[j - monedas[i].valor*k] != INT_MAX) {
					sol[j] = std::min(sol[j], sol[j - monedas[i].valor*k] + k);
				}
			}
		}
	}

	return sol[precio];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (!std::cin)
		return false;
	
	std::vector<moneda> monedas(N);
	for (int i = 0; i < N; i++) std::cin >> monedas[i].valor;
	for(int i = 0; i < N; i++) std::cin >> monedas[i].cantidad;

	int precio;
	std::cin >> precio;
	
	int minMonedas = resolver(monedas, precio);
	if (minMonedas == INT_MAX) std::cout << "NO\n";
	else std::cout << "SI " << minMonedas << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}