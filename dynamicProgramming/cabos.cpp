#include <bits/stdc++.h>
using namespace std;
#define int long long
// lis
int find_lis(vector<int>& values, int max_b) {
    vector<int> dp(max_b+1, 0);
    for (int i = 0; i<values.size(); i++){
        for (int j = values[i]-1; j>=0; j--){
            dp[values[i]] = max(1 + dp[j], dp[values[i]]);
        }
    } 
    return dp[max_b];
}

signed main() {
    int numCables, numConnections; 
    cin >> numCables >> numConnections;

   
    vector<pair<int, int>> cables(numConnections);
    for (int i = 0; i < numConnections; i++) {
        int a, b;
        cin >> a >> b;
        cables[i] = {a, b}; 
    }
    
    
    sort(cables.begin(), cables.end());

    vector<int> bValues; int max_b = 0;
    for (const auto& cable : cables) {
        bValues.push_back(cable.second);
        max_b = max(max_b, cable.second); 
    }
    cout << find_lis(bValues, max_b) << endl;

    return 0;
}
