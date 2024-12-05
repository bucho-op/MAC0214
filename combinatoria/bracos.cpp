#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, m, k;
    cin >> n >> m >> k;


    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

 
    dp[1][0] = m;


    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {

            dp[i][j] = dp[i-1][j];  


            if (j > 0) {
                dp[i][j] = (dp[i][j] + (long long)dp[i-1][j-1] * (m-1)) % MOD;
            }
        }
    }


    cout << dp[n][k] << endl;

    return 0;
}