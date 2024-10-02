#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;

    // Read the cables
    vector<pair<int, int>> cabos(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cabos[i] = {a, b}; // Store each cable as (start, end)
    }

    // Sort cables by the starting point (first element of the pair)
    sort(cabos.begin(), cabos.end());

    // DP array to store the maximum number of non-intersecting cables
    vector<int> dp(m + 1, 0); // dp[i] means max cables with first i cables considered

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        dp[i] = dp[i-1]; // Case when we don't include the current cable

        // Find the last cable that does not intersect with the current one
        for (int j = 0; j < i; j++) {
            // Check if the cables do not intersect
            if (cabos[j].second < cabos[i].first) {
                // Update the dp value considering we include the current cable
                dp[i] = max(dp[i - 1], dp[j] + 1);
            }
        }
    }

    // The answer is in dp[m], which is the max number of non-intersecting cables
    cout << dp[m] << endl;

    return 0;
}
