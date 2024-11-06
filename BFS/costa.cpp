#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n+2, vector<char>(m+2, '.'));
    for(int i = 0; i<n; i++){
        for (int  j = 0; j<m; j++){
            char s; cin >> s; adj[i+1][j+1] = s;
        }
    }
    int c = 0;
    for(int i = 1; i<=n; i++){
        for (int  j = 1; j<=m; j++){
            if (adj[i][j] == '#' && (adj[i+1][j] == '.' || adj[i][j+1] == '.' || adj[i-1][j] == '.' || adj[i][j-1] == '.')) {
                c++;
            }
        }
    }
    cout << c << endl;
}
