#include<bits/stdc++h>
using namespace std;

int find(vector<int>& ps, int a) {
	vector<int> ms;
	while(ps[a] != -1) {
		ms.push_back(a);
		a = ps[a];
	}
	for(int m : ms) 
		ps[m] = a;
	return a;
}

void join(vector<int>& ps, vector<int>& ws, int a, int b) {
	vector<int> ms;	
	while(ps[a] != -1) {
		ms.push_back(a);
		a = ps[a];
	}
	while(ps[b] != -1) {
		ms.push_back(b);
		b = ps[b];
	}
	if(a != b) { // se a == b, não podemos colocar b como filho de a, ou seja, filho dele mesmo
		if(ws[a] < ws[b])
			swap(a,b);
		ws[a] += ws[b];
		ms.push_back(b);
	}
	for(int m : ms) 
		ps[m] = a;
}

signed main() {

	int qv, qr, ct = 0; cin >> qv >> qr;
	vector<int> ps(qv, -1), ws(qv, 1);
	vector<array<int,3>> rs(qr); // arestas do grafo
	vector<array<int,3>> srs; // arestas selecionadas

	for(array<int,3>& r : rs) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		r = {c, a, b}; // colocamos o custo no começo para podermos ordenar
	}

	sort(rs.begin(), rs.end());

	for(array<int,3>& r : rs) {
		if(find(ps, r[1]) != find(ps, r[2])) { // se os vértices pertencem a conjuntos diferentes
			ct += r[0]; // soma o custo da aresta ao custo minimo
			srs.push_back(r); // seleciona a aresta para a MST
			join(ps, ws, r[1], r[2]); // une os conjuntos
			// aqui poderiamos parar quando a quantidade de ruas batesse qv-1
		}
	}

	cout << ct << '\n';
	return 0;
}
