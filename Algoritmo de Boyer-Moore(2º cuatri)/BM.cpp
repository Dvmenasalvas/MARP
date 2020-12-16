#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>	
using namespace std;

/*
Funcion que relleana BCT.
Usamos mapa no ordenado para guardar la BCT,
pues un vector del tamanio del alfabeto es una perdida 
de espacio para alfabetos grandes.
*/
unordered_map<char,int> preBCT(string const &x) {
	unordered_map<char, int> BCT;

	for (int i = x.size() - 2; i > 0; i--)
		if (BCT.count(x[i]) == 0) 
			BCT[x[i]] = x.size() - 1 - i;
		
	return BCT;
}

/*
Funcion auxiliar para calcular GST
suff[i] nos da la longitud del sufijo mas largo coincidente
entre el string x y el string x[0 ... i]
*/
vector<int> suffixes(string const &x) {
	int f, g;
	vector<int> suff(x.size());
	suff[x.size() - 1] = x.size();
	g = x.size() - 1;
	for (int i = x.size() - 2; i >= 0; --i) {
		if (i > g && suff[i + x.size() - 1 - f] < i - g)
			suff[i] = suff[i + x.size() - 1 - f];
		else {
			if (i < g)
				g = i;
			f = i;
			while (g >= 0 && x[g] == x[g + x.size() - 1 - f])
				--g;
			suff[i] = f - g;
		}
	}
	return suff;
}

//Funcion que rellena GST usando como auxiliar suffixes
vector<int> preGST(string const & x) {
	int i, j;
	vector<int> suff = suffixes(x);
	vector<int> GST(x.size());

	for (i = 0; i < x.size(); ++i)
		GST[i] = x.size();

	j = 0;
	for (i = x.size() - 1; i >= 0; --i)
		//Si x[0 ... i] == x[x.size() - 1 - i ... x.size - 1]
		if (suff[i] == i + 1)
			for (; j < x.size() - 1 - i; ++j)
				if (GST[j] == x.size())
					GST[j] = x.size() - 1 - i;
	for (i = 0; i <= x.size() - 2; ++i)
		GST[x.size() - 1 - suff[i]] = x.size() - 1 - i;

	return GST;
}

//Algoritmo de Boyer-Moore usando las funciones de preprocesamiento
void BM(string const & x, string const & y) {

	//Preprocesamiento
	vector<int> GST = preGST(x);
	unordered_map<char,int> BCT = preBCT(x);

	//Busqueda
	int j = 0, i;
	while (j <= y.size() - x.size()) {
		for (i = x.size() - 1; i >= 0 && x[i] == y[i + j]; --i);
		if (i < 0) {
			cout << j << " ";
			j += GST[0];
		}
		else {
			int bcs = x.size();
			if (BCT.count(y[i + j]) != 0)
				bcs = BCT[y[i + j]];
			j += max(GST[i], int(bcs - x.size() + 1 + i));
		}
	}
}