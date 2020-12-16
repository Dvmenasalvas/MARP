// Daniel Valverde Menasalvas
/*
Ejercicio 20 Dado un grafo G no dirigido y conexo, se llama punto de articulaci´on de G a un v´ertice
tal, que si se suprime el mismo y sus aristas asociadas, el grafo deja de ser conexo. Estudiar la
relaci´on entre dichos v´ertices y la informaci´on que proporciona el algoritmo DFS, y escribir un
algoritmo basado en DFS que determine si un v´ertice v dado es o no un punto de articulaci´on.
Decir cu´al es su coste en tiempo.
*/

/* 
Esta solución se basa en marcar el vertice que queremos saber si es punto de articulación y ejecutar un dfs
a partir de uno de sus adyacentes. Si esa llamada a dfs recorre todo el grafo, entonces el vertice es punto 
de articulación, de lo contrario si lo es.
*/


#include <iostream>
#include <vector>	//Vector
#include "Grafo.h"


void dfs(Grafo const & g, int v, std::vector<bool> & marcado) {
	marcado[v] = true;
	for (int w : g.ady(v)) 
		if (!marcado[w]) 
			dfs(g, w, marcado);
}

bool resolver(Grafo const & g, int P) {	
	if (g.ady(P).size() == 0) return false;	//Si el grafo solo tiene un vertice, al quitarlo es el vacio, que es conexo, por lo que no es punto de articulación
	
	std::vector<bool> marcado(g.V());
	marcado[P] = true;
	dfs(g, g.ady(P)[0], marcado);	//Si tenemos algun adyacente, hacemos un dfs a partir de este
									//Si el grafo es conexo al quitar E, una sola llamada a dfs basta para marcar todos los vértices
	bool art = false;
	int i = 0;
	while (!art && i < g.V()) {	//Si hay algun vertice al que no hemos llegado con una llamada a dfs, entonces E es punto de articulación
		art = !marcado[i];
		i++;
	}
		
	return art;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int V, E, P;
	std::cin >> V >> E >> P;

	if (!std::cin)
		return false;

	Grafo g(V);

	int v, w;
	for (int i = 0; i < E; i++) {
		std::cin >> v >> w;
		v--;
		w--;
		g.ponArista(v, w);
	}

	std::cout << resolver(g,P) << '\n';

	return true;
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
	return 0;
}