#include <bits/stdc++.h>
using namespace std;

int main() {
        int t;
        cin >> t;
        while (t--) {
            string num;
        cin >> num;
        int n = num.size();
        vector<vector<int>> dp(n + 1, vector<int>(9, -1)); 
        dp[0][0] = 1; 
        
        for (int i = 0; i < n; ++i) {
            int val = num[i] - '0';
            for (int msum = 0; msum < 9; ++msum) {
                if (dp[i][msum] == -1) continue; 
                dp[i + 1][(msum + val) % 9] = max(dp[i + 1][(msum + val) % 9], dp[i][msum]);        
                if (val >= 2) {
                    int nval = val;
                    while (nval < 10) {
                        dp[i + 1][(msum + nval) % 9] = max(dp[i + 1][(msum + nval) % 9], dp[i][msum]);
                        nval *= nval;
                    }
                }
            }
        }
        
        if (dp[n][0] == 1)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}