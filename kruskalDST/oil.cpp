#include <bits/stdc++.h>
#define int long long
using namespace std;


int find(vector<int>& ps, int a) {
	vector<int> ms; // armazena elementos no caminho
	while(ps[a] != -1) { // enquanto a não for raiz
		ms.push_back(a); // adiciona elemento ao caminho
		a = ps[a];  // segue para o pai
	}
	for(int m : ms) // comprime o caminho (path compression)
		ps[m] = a;
	return a;
}

void join(vector<int>& ps, vector<int>& ws, int a, int b) {
	vector<int> ms;	// armazena nós para a compressão de caminho
	while(ps[a] != -1) { // encontra a raiz de a
		ms.push_back(a);
		a = ps[a];
	}
	while(ps[b] != -1) { // encontra a raiz de b
		ms.push_back(b);
		b = ps[b];
	}
	if(a != b) { // se a == b, não podemos colocar b como filho de a, ou seja, filho dele mesmo
		if(ws[a] < ws[b]) // adiciona o conjunto menor ao conjunto maior
			swap(a,b);
		ws[a] += ws[b]; // atualiza o peso do novo conjunto
		ms.push_back(b); // b passa a fazer parte do conjunto que tem a como raiz
	}
	for(int m : ms) // comprime o caminho
		ps[m] = a;
}




signed main(){
    int n, m, s; cin >> n >> m >> s; vector<int> ps(n+1, -1), ws(n+1, 0);
    vector<bool> edges(m+1, 0);
    vector<array<int,4>> rs(m); // arestas do grafo

    int i = 1; int custo = 0;
    for(array<int,4>& r : rs) {
		int a, b, c;
		cin >> a >> b >> c;
		r = {c, a, b, i}; // colocamos o custo no começo para podermos ordenar
        i++;
        custo += c;
	}

    sort(rs.begin(), rs.end());
    reverse(rs.begin(), rs.end());
    int cont = m;
    for(array<int,4>& r : rs) {
		if(find(ps, r[1]) != find(ps, r[2])) { // se os vértices pertencem a conjuntos diferentes
			join(ps,ws,r[1],r[2]);
            custo -= r[0];
            edges[r[3]] = 1;
            cont--;
		}
	}
    // cout << custo << endl;
    for (array<int,4>& r : rs){
        if (custo <= s) break;
        if (edges[r[3]] == 0){
            custo -= r[0];
            edges[r[3]] = 1;
            cont--;
        }
    }
    cout << cont << endl;
    for(int i = 1; i<=m; i++){
        if (!edges[i]){
            cout << i << " ";
        }
    }


    return 0;
}