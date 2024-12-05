#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6;
const ll INF = 1e18;

ll dist[MAX];
ll dist_2[MAX];
int n, m; 
vector<vector<pair<int,ll>>> adj;
vector<vector<pair<int,ll>>> adj_2;
vector<int> v_max;

void dijkstra(int src, ll dist[], vector<vector<pair<int,ll>>>& adj){
    for(int i=1; i<=n; i++) dist[i] = INF;
    set<pair<ll,int>> st;

    st.insert({0, src});
    dist[src] = 0;

    while(!st.empty()){
        int cur = st.begin()->second; st.erase(st.begin());
        for(auto [viz, c] : adj[cur]){    
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
    adj_2.resize(n+1);
    for(int i=0; i<m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj_2[b].push_back({a, c});
    }
    dijkstra(1, dist, adj);
    dijkstra(n, dist_2, adj_2);
    
    ll ans = INF;
    
    for(int i=1;i<=n;i++){
           for(auto viz: adj[i]){
                 
                int to = viz.first; // vertice de chegada do voo a ser descontado (i eh o vertice de ida do voo)
                int c = viz.second; // custo do voo a ser descontado
                
                ans = min(ans, dist[i] + c/2 + dist_2[to]);

           }
    }

    cout << ans << endl;
    return 0;
}
