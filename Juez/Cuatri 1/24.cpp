// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <algorithm>	//max y min
#include <string>	//Leer strings
#include "PriorityQueue.h"
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

void resolver(int n) {
	PriorityQueue<int, std::greater<int>> p1;
	PriorityQueue<int> p2;
	int elem;

	for (int i = 0; i < n; i++) {
		std::cin >> elem;

		if (i == 0) {
			p1.push(elem);
			std::cout << 2*p1.top() << " ";
		}
		else if (i == 1) {
			if (p1.top() <= elem) p2.push(elem);
			else {
				p2.push(p1.top());
				p1.pop();
				p1.push(elem);
			}
			std::cout << p1.top() + p2.top() << " ";
		}
		else if (i % 2 == 0) {	//Par antes de insertar
			if (elem <= p2.top())
				p1.push(elem);
			else {
				p1.push(p2.top());
				p2.pop();
				p2.push(elem);
			}
			std::cout << 2*p1.top() << " ";
		}
		else {	//Impar antes de insertar
			if (p1.top() <= elem)
				p2.push(elem);
			else {
				p2.push(p1.top());
				p1.pop();
				p1.push(elem);
			}
			std::cout << p1.top() + p2.top() << " ";
		}
	}
	std::cout << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int n;
	std::cin >> n;
	
	if (n == 0)
		return false;


	resolver(n);

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}