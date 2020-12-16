
// Daniel Valverde Menasalvas
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <iostream>
#include <vector>
#include <algorithm>

//Junta ambos vectores en un vector ordenado, sin repetidos, con elementos menores que t
std::vector<int> mergeListsLessT(std::vector<int> const &A, std::vector<int> const &B, int t) {
	std::vector<int> sol;
	int i = 0;
	int j = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] < B[j]) {
			if (A[i] <= t) {
				sol.push_back(A[i]);
				i++;
			}
			else i = A.size();
		}
		else if (B[j] < A[i]) {
			if (B[j] > t) j = B.size();
			else {
				sol.push_back(B[j]);
				j++;
			}
		}
		else { //Iguales
			if (A[i] > t) {
				i = A.size();
				j = B.size();
			}
			else {
				sol.push_back(A[i]);
				i++;
				j++;
			}
		}
	}
	while (i < A.size()) {
		if (A[i] > t) i = A.size();
		else {
			sol.push_back(A[i]);
			i++;
		}
	}

	while (j < B.size()) {
		if (B[j] > t) j = B.size();
		else {
			sol.push_back(B[j]);
			j++;
		}
	}
	return sol;
}

std::vector<int> suma(std::vector<int>const & S, int x) {
	std::vector<int> sol;
	for (int i : S) 
		sol.push_back(i + x);
	
	return sol;
}

int exactSubsetSum(std::vector<int> & S, int t) {
	std::sort(S.begin(), S.end()); //Ordenamos S
	std::vector<int> L = { 0 };
	for (int i = 0; i < S.size(); i++) 
		L = mergeListsLessT(L, suma(L, S[i]), t);
	return L[L.size() - 1];
}

std::vector<int> trim(std::vector<int> L, double p) {
	std::vector<int> trimmed = { L[0] };
	int last = L[0];
	for (int i = 1; i < L.size(); i++) {
		if (L[i] > last*(1 + p)) {
			trimmed.push_back(L[i]);
			last = L[i];
		}
	}
	return trimmed;
}

int approxSubsetSum(std::vector<int> & S, int t, double p) {
	std::sort(S.begin(), S.end()); //Ordenamos S
	std::vector<int> L = { 0 };
	for (int i = 0; i < S.size(); i++) {
		L = mergeListsLessT(L, suma(L, S[i]), t);
		L = trim(L, p / (2 * S.size()));
	}
	return L[L.size() - 1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::vector<int> S;
	int t, e;
	
	/*La primera linea de la entrada contendrá el vector S, acabado en -1
	La segunda el número t
	*/
	std::cin >> e;
	while (e != -1) {
		S.push_back(e);
		std::cin >> e;
	}

	std::cin >> t;

	std::cout << approxSubsetSum(S, t, 0.4) << '\n';

	return true;
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
	return 0;
}