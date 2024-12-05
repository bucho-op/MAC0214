#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX =  127;
const int oo = 1e17;

vector<vector<pair<int, int>>> adj(MAX); // Lista de adjacências
vector<vector<int>> dist(MAX, vector<int>(MAX, oo)); // Tabela de distâncias

void dijkstra(int src) {
    set<pair<int, int>> st; // Priority queue
    st.insert({0, src}); // Adiciona a raiz do problema
    dist[src][src] = 0;

    while (!st.empty()) {
        int cur = st.begin()->second; 
        st.erase(st.begin());
        
        for (auto [viz, c] : adj[cur]) {
            // Relaxa o vértice
            if (dist[src][cur] + c < dist[src][viz]) {
                st.erase({dist[src][viz], viz}); // Remove a antiga distância
                dist[src][viz] = dist[src][cur] + c; // Atualiza com a menor distância
                st.insert({dist[src][viz], viz}); // Insere novamente com a nova distância
            }
        }
    }
}

signed main() {
    string s, t; 
    cin >> s >> t;
    int n; 
    cin >> n;

    // Lê as arestas
    while (n--) {
        char f, l; 
        int v; 
        cin >> f >> l >> v;
        adj[f - '!' + 1].push_back({l - '!' + 1, v});
    }

    // Executa o Dijkstra para cada possível letra do alfabeto
    for (int i = 1; i <= 126; i++) {
        dijkstra(i);
    }

    // Calcula o custo total
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - '!' + 1; // Índice da letra em `s`
        int v = t[i] - '!' + 1; // Índice da letra em `t`
        if (dist[u][v] < oo) {
            c += dist[u][v];
        } else {
            cout << -1 << endl; // Se não há caminho possível
            return 0;
        }
    }

    cout << c << endl;
    return 0;
}
