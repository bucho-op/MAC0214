#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> adj; int n, m;
void bfs(vector<pair<int,int>>& srcs) {
    queue<pair<int,int>> q;

	for(auto src : srcs){
		q.push(src);
	}

    while(!q.empty()){
        pair<int,int> qu = q.front(); q.pop();
        int i = qu.first; int j = qu.second;
        //cout << i << " " << j << endl;
        if (i < 1 || j < 1 || i > n || j > m) continue;
        if (adj[i][j] == 'o' || adj[i][j] == '#') continue;
        if (i == n && adj[i][j] == '.'){
            adj[i][j] = 'o';
        }
        if (adj[i][j] == '.' && ((adj[i-1][j] == 'o') || (adj[i][j-1] == 'o' && adj[i+1][j-1] == '#') || (adj[i][j+1] == 'o' && adj[i+1][j+1] == '#')))
            {
                adj[i][j] = 'o';
                q.push(make_pair(i+1,j));
                q.push(make_pair(i, j-1));
                q.push(make_pair(i, j+1));
            }

    }

}


int main(){
    cin >> n >> m; adj.resize(n+1, vector<char>(m+1));
    int s_j = 0;
    string s; cin >> s;
    for (int j = 1; j<=m; j++) {
        if (s[j-1] == 'o') s_j = j;
        adj[1][j] = s[j-1];
    }
    vector<pair<int, int>> srcs;
    srcs.push_back(make_pair(2, s_j));
    if (s_j + 1 <= m) srcs.push_back(make_pair(1, s_j-1));
    if (s_j - 1 > 0) srcs.push_back(make_pair(1, s_j+1));

    for (int i = 2; i<=n; i++){
        string s; cin >> s;
        for (int j = 1; j<=m; j++){
                adj[i][j] = s[j-1]; 
        }
    }
    bfs(srcs);


    for (int i = 1; i<=n; i++){
        for (int j = 1; j<=m; j++){
           cout << adj[i][j];
        }
        cout << endl;
    }


    return 0;
}
