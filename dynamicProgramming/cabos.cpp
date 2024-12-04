#include <bits/stdc++.h>
using namespace std;
#define int long long
// lis

int numCables;
int find_lis(vector<pair<int,int>>& values) {
    //vector<int> repeat(numCables + 1, 0);
    vector<int> dp; 
    for (pair<int,int> value : values) {
        auto it = lower_bound(dp.begin(), dp.end(), value.second);
        if (it == dp.end()) {
            dp.push_back(value.second);
        } else {
            *it = value.second;
        }
    }
    return dp.size();
}

signed main() {
    int numConnections; 
    cin >> numCables >> numConnections;

   
    vector<pair<int, int>> cables(numConnections);
    for (int i = 0; i < numConnections; i++) {
        int a, b;
        cin >> a >> b;
        cables[i] = {a, b}; 
    }
    
    sort(cables.begin(), cables.end(), [](pair<int, int> &p1, pair<int, int> &p2) {
        if (p1.first == p2.first) {
            return p1.second > p2.second; 
        }
        return p1.first < p2.first;
    });
    cout << find_lis(cables) << endl;

    return 0;
}
