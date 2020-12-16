
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <set>
#include "Grafo.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

std::set<int> approxVertexCover(Grafo const & g) {
	std::set<int> C;		//Inicializamos C
	Grafo aristas = g;		//Copiamos el grafo
	int u = 0, v;
	while (aristas.E() != 0) {
		//Acaba porque existe alguna arista
		while (aristas.ady(u).size() == 0)		//Buscamos una arista
			u++;

		v = aristas.ady(u)[0];			//Insertamos los vertices en C
		C.insert(u);		
		C.insert(v);

		for (int i : aristas.ady(u))	//Borramos todas las aristas adyacentes a u y v.
			aristas.quitaArista(u, i);
		for (int i : aristas.ady(v))
			aristas.quitaArista(v, i);	
	/*He añadido la función quitaArista a la clase grafo, ya que no estaba implementada.
	Esta no es muy eficiente debido a que ady(v) es un vector. Una posible mejora sería que
	ady(v) fuera un set, de esta forma no habria que recorrerlo linealmente para borrar un elemento.
	*/
	
	}
	return C;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;

	if (!std::cin)
		return false;

	Grafo g = Grafo(V);

	int v, w;
	for (int i = 0; i < E; i++) {
		std::cin >> v >> w;
		v--;
		w--;
		g.ponArista(v, w);
	}
	for(auto i : approxVertexCover(g))
		std::cout << i << " ";

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