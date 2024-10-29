#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<bool>> viz;
vector<vector<int>> lad;


pair<int,bool> bfs(int i, int j){
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	int cont = 0;
	bool t = 0;
	if (lad[i][j] == 0) t = true;
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

	return make_pair(cont, t);
}






signed main(){
	int n, m; cin >> n >> m; lad.resize(n+2, vector<int>(m+2, -1));
	viz.resize(n+2, vector<bool>(m+2, false));
	for (int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			int v; cin >> v; lad[i][j] = v;
		}
	}

	int max_v = 100000000; int max_z = 10000000;
	for (int i =1; i<=n; i++){
		for(int j = 1; j<=m; j++){
			if (!viz[i][j]) {
				pair<int,bool> cont = bfs(i, j);
				if (cont.first < max_v && !cont.second) max_v = cont.first;
				else if (cont.second){
					max_z = min(max_z, cont.first);
				}			
			}
			
		}
	}

	cout << min(max_v, max_z) << endl;



	return 0;
}
