#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e17;
const int MAX = 10e6;
vector<int>dist(MAX);
int n, m, f; 
vector<vector<pair<int,int>>> adj;



void dijkstra(int src){
	for(int i=1; i<=n; i++) dist[i] = oo;
	set<pair<int,int>> st; // priority queue

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



signed main(){
    cin >> n >> m >> f; vector<pair<int,int>> amigos; adj.resize(n+1);
    
    for (int i = 0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
		adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijkstra(1);
    for (int i = 0; i<f; i++){
        int amigo; cin >> amigo;
        amigos.push_back({amigo, dist[amigo]});
    }
    dijkstra(n);
    int max_v = oo;
    for (int i = 0; i<f; i++){
        amigos[i].second += dist[amigos[i].first];
        max_v = min(amigos[i].second, max_v);
    }

    cout << max_v << endl;
    return 0;
}