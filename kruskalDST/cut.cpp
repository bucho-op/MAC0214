#include <bits/stdc++.h>
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
// ideia: computar os resultados na ordem inversa, para podermos usar "join"
// ao inves de cut
int main(){
    int n, m, k; cin >> n >> m >> k; vector<int> ps(n+1, -1), ws(n+1, 0); vector<array<int,3>> ques(k);
    for (int i = 0; i<m; i++){
        int a, b; cin >> a >> b;
    }
    for (int i = 0; i<k; i++){
        string s; int a, b; cin >> s >> a >> b;
        if (s == "cut"){
            ques[i] = {0, a, b};
        } else if (s == "ask") {
            ques[i] = {1, a, b};
        }
        
    }
    vector<string> ans;
    for (int i = k-1; i>=0; i--){
        int a = ques[i][0]; int b = ques[i][1]; int c = ques[i][2];
        if (a == 0){
            join(ps, ws, b, c);
        } else if (a == 1){
            if (find(ps, b) == find(ps, c)){
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        }
    }

    for (int i = ans.size() - 1; i>=0; i--){
        cout << ans[i] << endl;
    }

    return 0;
}