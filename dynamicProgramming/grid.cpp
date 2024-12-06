#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main() {
    int ro, co;
    cin >> ro >> co;

    vector<vector<int>> dp(ro, vector<int>(co, 0));
    dp[0][0] = 1;

    for (int i = 0; i < ro; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < co; j++) {
            if (s[j] == '.') {
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= MOD;
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                    dp[i][j] %= MOD;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[ro - 1][co - 1] << endl;

    return 0;
}

