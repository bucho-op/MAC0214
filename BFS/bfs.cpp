#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
const int oo = 1e9;

int dist[MAX];
int n, m; 
vector<vector<int>> adj;

void bfs(int src){
	vector<bool> mark(n, false);
	queue<int> q;

	q.push(src);
	mark[src] = true;
	dist[src] = 0;

	while(not q.empty()){
		int cur = q.front(); q.pop();
		for(auto viz : adj[cur]){
			if(mark[viz]) continue;
			q.push(viz);
			mark[viz] = true;
			dist[viz] = 1 + dist[cur];
		}
	}
}

int main(){
	cin >> n >> m;
	adj.resize(n+1);
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=1; i<=n; i++) dist[i] = oo;
	bfs(1);
	for(int i=1; i<=n; i++){
		cout << "A distancia do vertice " << i;
		cout << " eh " << dist[i];
		cout << '\n';
	}
}
