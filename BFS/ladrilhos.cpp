#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> lad;
vector<vector<bool>> viz;

int bfs(int i, int j){
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	int cont = 0;
	while (!q.empty()){
		cont++;
		pair<int,int> p = q.front(); q.pop();	
		i = p.first; j = p.second;
		viz[i][j] = true;
		if (lad[i][j] == lad[i+1][j] && !viz[i+1][j]) q.push(make_pair(i+1,j));
		if (lad[i][j] == lad[i-1][j] && !viz[i-1][j]) q.push(make_pair(i-1,j));
		if (lad[i][j] == lad[i][j+1] && !viz[i][j+1]) q.push(make_pair(i, j+1));
		if (lad[i][j] == lad[i][j-1] && !viz[i][j-1]) q.push(make_pair(i, j-1));
	}

	return cont;
}


int main(){
	int n, m; cin >> n >> m; lad.resize(n+2, vector<int>(m+2, -1000000));
	viz.resize(n+2, vector<bool>(m+2, 0));

	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			int v; cin >> v; lad[i][j] = v;
		}
	}
	int v, min_v = 1000000;
	for (int i = 1; i<=n; i++){
		for (int j = 1; j<=m; j++){
			if (!viz[i][j]) v = bfs(i,j);
			min_v = min(min_v, v);
		}
	}
	cout << min_v << endl;


	return 0;
}
