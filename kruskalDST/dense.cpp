#include <bits/stdc++.h>
using namespace std;
#define int long long

int find(vector<int>& ps, int a) {
    if (ps[a] != a) {
        ps[a] = find(ps, ps[a]); // Directly apply path compression
    }
    return ps[a];
}

void join(vector<int>& ps, vector<int>& rank, int a, int b) {
    int rootA = find(ps, a);
    int rootB = find(ps, b);
    
    if (rootA != rootB) { // Only join if roots are different
        if (rank[rootA] > rank[rootB]) {
            ps[rootB] = rootA;
        } else if (rank[rootA] < rank[rootB]) {
            ps[rootA] = rootB;
        } else {
            ps[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, a, b}; // Store edge with weight, start, and end
    }

    // Sort edges by weight (ascending)
    sort(edges.begin(), edges.end());

    if (m < n - 1) { // If there are not enough edges for a spanning tree
        cout << "NO" << endl;
        return 0;
    }

    int min_diff = -1;

    // Sliding window approach over edges to find minimum difference
    for (int i = 0; i <= m - (n - 1); i++) {
        vector<int> ps(n + 1); // Initialize parent set
        vector<int> rank(n + 1, 0); // Initialize rank for union by rank
        for (int j = 1; j <= n; j++) ps[j] = j; // Each node is its own parent initially

        int edges_added = 0;
        int j = i;

        // Try to build a spanning tree starting from the i-th edge
        while (j < m && edges_added < n - 1) {
            int u = edges[j][1], v = edges[j][2];
            if (find(ps, u) != find(ps, v)) { // Only join if u and v are in different sets
                join(ps, rank, u, v);
                edges_added++;
            }
            j++;
        }

        // Check if we successfully added enough edges to form a spanning tree
        if (edges_added == n - 1) {
            int current_diff = edges[j - 1][0] - edges[i][0];
            if (min_diff == -1 || current_diff < min_diff) {
                min_diff = current_diff;
            }
        }
    }

    if (min_diff >= 0) {
        cout << "YES" << endl << min_diff << endl;
    } else {
        cout << "NO" << endl;
    }
}
