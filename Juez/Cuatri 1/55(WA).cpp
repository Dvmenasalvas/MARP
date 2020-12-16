// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//sort
#include <string>	//Leer strings
#include <functional> //Greater
#include <vector>	//Vector
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

struct hora {
	int h;
	int m;
	bool operator<(const hora& e) const {
		return h < e.h || h == e.h && m < e.m;
	}
	bool operator==(const hora& e) const {
		return h == e.h && m == e.m;
	}
	hora operator+(const int & m2) {
		hora suma;
		suma.h = h;
		suma.m = m + m2;
		suma.ajustar();
		return suma;
	}
	void ajustar() {
		while (m >= 60) {
			h++;
			m -= 60;
		}
	}
};

struct pelicula {
	hora h;
	int duracion;
	bool operator<(const pelicula& e) const {
		return h < e.h || h == e.h && duracion < e.duracion;
	}
};

int resolver(std::vector<pelicula> const &peliculas) {
	int sol = 0;
	hora final;
	final.h = 0;
	final.m = 0;
	for (auto e : peliculas) {
		if (final + 10 < e.h || final + 10 == e.h) {
			final = e.h + e.duracion;
			sol++;
		}
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N;

	if (N == 0)
		return false;

	std::vector<pelicula> peliculas;
	int aux;
	pelicula p;
	char c;
	for (int i = 0; i < N; i++) {
		std::cin >> aux;
		p.h.h = aux;
		std::cin.get(c);
		std::cin >> aux;
		p.h.m = aux;
		std::cin >> aux;
		p.duracion = aux;
		peliculas.push_back(p);
	}
	sort(peliculas.begin(), peliculas.end());

	std::cout << resolver(peliculas) << '\n';

	return true;
}
int main() {
	while (resuelveCaso()) {}

	return 0;
}