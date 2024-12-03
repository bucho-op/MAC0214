#include<bits/stdc++.h>
using namespace std;

typedef array<int,3> evento_t; // [0]: posição x, [1]: altura, [2]: tipo (0: início, 1: fim)

int main() {

	int quantidade_predios, ultimo_x=0, ultima_altura=0, area_total=0; 
	cin >> quantidade_predios;

	vector<evento_t> eventos;
	multiset<int> alturas;

	for(int i=0; i<quantidade_predios; i++) {
		int x1, x2, altura; cin >> x1 >> x2 >> altura;
		if(x1 > x2)
			swap(x1, x2);
		eventos.push_back({x1,altura,0});
		eventos.push_back({x2,altura,1});
	}

	sort(eventos.begin(), eventos.end());

	for(evento_t evento : eventos) {
		int x = evento[0];
		int altura = evento[1];
		int tipo = evento[2];

		area_total += (x-ultimo_x)*ultima_altura;

		if(tipo == 0)
			alturas.insert(altura);
		else if(tipo == 1)
			alturas.erase(alturas.find(altura));

		if(alturas.empty())
			ultima_altura = 0;
		else
			ultima_altura = *alturas.rbegin();

		ultimo_x = x;
	}

	printf("%d\n", area_total);

	return 0;
}

