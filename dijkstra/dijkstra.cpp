#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6;
const ll oo = 1e18;

ll dist[MAX];
int n, m; 
vector<vector<pair<int,ll>>> adj;

void dijkstra(int src){
	for(int i=1; i<=n; i++) dist[i] = oo;
	set<pair<ll,int>> st; // priority queue

	st.insert({0, src}); // root do problema
	dist[src] = 0;

	while(not st.empty()){
		int cur = st.begin()->second; st.erase(st.begin());
		for(auto [viz, c] : adj[cur]){
			
            // relaxa o vertice
            if(dist[cur] + c < dist[viz]){
				st.erase({dist[viz], viz});
				dist[viz] = dist[cur] + c;
				st.insert({dist[viz], viz});
			}
		}
	}
}

int main(){
	cin >> n >> m;
	adj.resize(n+1);
	
    // recebe digrafo com pesos nas arestas
    for(int i=0; i<m; i++){
		int a, b; ll c;
    cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}

    // chamada do algoritmo
	dijkstra(1);
	for(int i=1; i<=n; i++){
		cout << "A distancia de " << i;
		cout << " eh " << dist[i] << '\n';
	}
}