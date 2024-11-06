// ideia: criar um vetor auxiliar
// esse vetor eh indexado pelos vertices e guarda um sequencia "cronologica"
// dos vertices que fazer parte de um conjunto

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> line; int n;
int join(vector<int>& ps, vector<int>& ws, int a, int b) {
	while(ps[a] != -1) { // encontra a raiz de a
		a = ps[a];
	}
	while(ps[b] != -1) { // encontra a raiz de b
		b = ps[b];
	}
	if (ws[a] < ws[b]) swap(a,b);
    ws[a] += ws[b];
	for(int m : line[b]) {
        ps[m] = a;
        line[a].push_back(m);
    }
    if (ws[a] == n) return a;
    else return 0;
}

int main () {
	cin >> n; vector<int> ps(n+1, -1), ws(n+1, 1); line.resize(n+1);
    for (int i = 0; i<n; i++){
        line[i+1].push_back(i+1);
    }
    for (int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        int ready = join(ps, ws, a, b);
        if (ready > 0){
            for (int i = 0; i<n-1; i++){
                cout << line[ready][i] << " ";
            }
            cout << line[ready][n-1] << endl;
        } 
    }


	return 0;
}
