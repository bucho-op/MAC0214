#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> nums(n);
        map<int, int> b;
        set<pair<int, int>> check;

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            nums[i] = {x, y};
            b[x]++;
            check.insert({x, y});
        }

        int ans = 0;

        for (const auto& entry : b) {
            if (entry.second == 2) {
                ans += n - 2;
            }
        }

        for (const auto& p : check) {
            int x = p.first, y = p.second;
            if (check.count({x - 1, y ^ 1}) && check.count({x + 1, y ^ 1})) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
