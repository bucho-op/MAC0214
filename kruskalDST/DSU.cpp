/* DSU
 * são dadas uma quantidade de elementos (qv), e uma quantidade de informações e perguntas (qq)
 * é dado também um conjunto de qq informações e perguntas
 * informação (a b !): a e b estão no mesmo conjunto
 * pergunta (a b ?): deve ser respondido se a e be estão no mesmo conjunto
 *
 * Entrada:

5 6
1 2 !
3 2 !
4 5 !
1 3 ?
1 5 ?
3 4 !
1 5 ?

 * Saída:

1 3 ? sim
1 5 ? não
1 5 ? sim

 */

#include<bits/stdc++.h>
#include <tuple>
using namespace std;
vector<int> mins, maxs;


tuple<int,int,int> find(vector<int>& ps, int a) {
	vector<int> ms; // armazena elementos no caminho
	while(ps[a] != -1) { // enquanto a não for raiz
		ms.push_back(a); // adiciona elemento ao caminho
		a = ps[a];  // segue para o pai
	}
	for(int m : ms) // comprime o caminho (path compression)
		ps[m] = a;
	return make_tuple(mins[a], maxs[a], a);
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

    int min1 = min(mins[a], mins[b]);
    int max1 = max(maxs[a], maxs[b]);
	if(a != b) { // se a == b, não podemos colocar b como filho de a, ou seja, filho dele mesmo
		if(ws[a] < ws[b]) // adiciona o conjunto menor ao conjunto maior
			swap(a,b);
		ws[a] += ws[b]; // atualiza o peso do novo conjunto
		ms.push_back(b); // b passa a fazer parte do conjunto que tem a como raiz
	}
	for(int m : ms) // comprime o caminho
		ps[m] = a;
    mins[a] = min1;
    maxs[a] = max1;
}

int main() {

	int qv, qq; cin >> qv >> qq; // numero de vertices e requests
	vector<int> ps(qv, -1), ws(qv, 1); 
    for (int i = 0; i<qv; i++){
        mins.push_back(i);
        maxs.push_back(i);
    }
	for(int i=0; i<qq; i++) {
        string c; cin >> c;
		if(c == "union"){
			int a, b; cin >> a >> b; a--; b--;
            join(ps, ws, a, b);
		} else if(c == "get") {
		//	cout << a+1 << ' ' << b+1 << ' ' << c << ' ';
			int a; cin >> a; a--;
            auto values = find(ps, a);
            auto [first, second, third] = values;
            cout << first+1 << " " << second+1 << " " << ws[third] << endl;
		}
	}

	return 0;
}
