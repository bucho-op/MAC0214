#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000000;
int dp[101][101][2];

int main() {
    int n, m, k1, k2;
    while (cin >> n >> m >> k1 >> k2) {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = dp[0][0][1] = 1;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k <= k1 && k <= i; k++) {
                    dp[i][j][0] += dp[i - k][j][1];
                    dp[i][j][0] %= MOD;
                }
                for (int k = 1; k <= k2 && k <= j; k++) {
                    dp[i][j][1] += dp[i][j - k][0];
                    dp[i][j][1] %= MOD;
                }
            }
        }
        cout << (dp[n][m][0] + dp[n][m][1]) % MOD << endl;
    }

    return 0;
}

