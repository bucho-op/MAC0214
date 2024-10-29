#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> ro;
int n, m;
vector<vector<int>> tim;

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

        for (auto dr : vector<pair<int, int>>{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
            int uu = u + dr.first;
            int vv = v + dr.second;
            
            if (uu < 1 || uu > m || vv < 1 || vv > n) continue; // Boundary check
            
            if (ro[uu][vv] == '.' || ro[uu][vv] == '@') {
                ro[uu][vv] = ro[u][v];
                tim[uu][vv] = tim[u][v] + 1;
                q.push({uu, vv});
            }
            
            if (ro[uu][vv] == '@' && (uu == m || vv == n || uu == 1 || vv == 1)) {
                return tim[uu][vv];
            }
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;  // Adjust to read m (rows) and n (columns) correctly
        ro.assign(m + 1, vector<char>(n + 1));
        tim.assign(m + 1, vector<int>(n + 1, -1));  // Initialize with -1 for unvisited cells
        
        pair<int, int> save;
        vector<pair<int, int>> srcs;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char c;
                cin >> c;
                ro[i][j] = c;
                if (ro[i][j] == '*') srcs.push_back({i, j});
                if (ro[i][j] == '@') save = {i, j};
            }
        }

        srcs.push_back(save);
        int res = bfs(srcs);

        if (res == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}
