#include <bits/stdc++.h>
using namespace std;


int dp(int i, int j, vector<vector<int>>& m, int a, int b) {
    if (i == j) return 0;
    if (m[i][j] != 0) return m[i][j];

    if (i<b && j<a) {
        if (m[i][j] != 0) return m[j][i] = m[i][j];
    }

    int minMoves = INT_MAX;
    for (int k = 1; k < (i/2)+1; k++)
        minMoves = min(minMoves, 1 + dp(k, j, m, a, b) + dp(i - k, j, m, a, b));
    
    for (int k = 1; k < (j/2)+1; k++)
        minMoves = min(minMoves, 1 + dp(i, k, m, a, b) + dp(i, j - k, m, a, b));

    
    return m[i][j] = minMoves;
}

int main(){
    int a, b;
    cin >> a >> b;
    vector<vector<int>> m(a+1, vector<int>(b+1, 0));
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    cout << dp(a, b, m, a, b) << endl;
    return 0;
}
