#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, n; cin >> k >> n;

    int all = 0;
    vector<int> mins(k), maxs(k);
    for (int i = 0; i < k; i++) {
        cin >> mins[i] >> maxs[i];
        all += maxs[i];
    }

    int i = 0;
    while (i < k && all > n) {
        int required_reduction = all - n;
        int possible_reduction = maxs[i] - mins[i];
        
        if (possible_reduction >= required_reduction) {
            maxs[i] -= required_reduction;
            all -= required_reduction;
        } else {
            maxs[i] -= possible_reduction;
            all -= possible_reduction;
        }
        i++;
    }

    if (all != n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < k; i++) {
            cout << maxs[i] << (i == k - 1 ? "\n" : " ");
        }
    }

    return 0;
}
