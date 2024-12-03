#include<bits/stdc++.h>
using namespace std;

typedef pair<double,double> ponto_t;
 
int main() {

	int quantidade_pontos, indice_ponto_considerado=0; 
	cin >> quantidade_pontos;

	double menor_distancia = 500000.0;

	ponto_t a, b;
	vector<ponto_t> pontos(quantidade_pontos); // (x,y)
	set<ponto_t> pontos_considerados; // (y,x)

	for(ponto_t& ponto : pontos)
		cin >> ponto.first >> ponto.second;
	sort(pontos.begin(), pontos.end());

	for(ponto_t ponto : pontos) {

		double x = ponto.first;
		double y = ponto.second;

		while(x - pontos[indice_ponto_considerado].first > menor_distancia) {
			int x_ponto_considerado = pontos[indice_ponto_considerado].first;
			int y_ponto_considerado = pontos[indice_ponto_considerado].second;
			pontos_considerados.erase({y_ponto_considerado, x_ponto_considerado});
			indice_ponto_considerado++;
		}

		set<ponto_t>::iterator inferior, superior;
		inferior = pontos_considerados.lower_bound({y-menor_distancia, -500000.0});
		superior = pontos_considerados.upper_bound({y+menor_distancia, +500000.0});

		for(set<ponto_t>::iterator atual = inferior; atual != superior; ++atual) {
			double atual_y = atual->first;
			double atual_x = atual->second;
			double distancia_atual = hypot(x-atual_x, y-atual_y);
			if(distancia_atual < menor_distancia) {
				menor_distancia = distancia_atual;
				a = {x,y};
				b = {atual_x,atual_y};
			}
		}

		pontos_considerados.insert({y,x});

	}

	cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << '\n';

	return 0;
}
