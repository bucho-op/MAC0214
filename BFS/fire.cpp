#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<char>> ro;
int n, m;
vector<vector<int>> tim;

void print_graph(){
    cout << endl;
    for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << ro[i][j];
            }
            cout << endl;
    }

}


int bfs(vector<pair<int, int>>& srcs) {
    queue<pair<int, int>> q;
    for (pair<int,int>& src : srcs) {
        q.push(src);
        tim[src.first][src.second] = 0;
    }
    
    while (!q.empty()) {
        pair<int, int> p = q.front(); 
        q.pop(); 
        int u = p.first;
        int v = p.second;

        if (ro[u][v] == '@' && (u == n || v == m || u == 1 || v == 1)) {
                //cout << uu << " " << vv  << ro[3][4] << endl;
                return tim[u][v];
        } 

        for (auto dr : vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int uu = u + dr.first;
            int vv = v + dr.second;
        

            if (uu < 1 || uu > n || vv < 1 || vv > m) continue; // Boundary check   
        
            if ((ro[u][v] == '*' ||ro[u][v] == '@') && ro[uu][vv] == '.') {
                ro[uu][vv] = ro[u][v];
                tim[uu][vv] = tim[u][v] + 1;
                q.push({uu, vv});
            } else if (ro[u][v] == '*' && ro[uu][vv] == '@'){
                ro[uu][vv] = ro[u][v];
                tim[uu][vv] = tim[u][v] + 1;
                q.push({uu, vv});
            }
            
            

            //print_graph();
            
        }

    }
    return -1;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;  // Adjust to read m (rows) and n (columns) correctly
        ro.assign(n + 1, vector<char>(m + 1));
        tim.assign(n + 1, vector<int>(m + 1, -1));  // Initialize with -1 for unvisited cells
        
        pair<int, int> save;
        vector<pair<int, int>> srcs;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;
                ro[i][j] = c;
                if (ro[i][j] == '*') srcs.push_back({i, j});
                if (ro[i][j] == '@') save = {i, j};
            }
        }
        srcs.push_back(save);
        reverse(srcs.begin(), srcs.end());
        int res = bfs(srcs);
        
        if (res == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << res+1 << endl;
        }
    }
    return 0;
}
