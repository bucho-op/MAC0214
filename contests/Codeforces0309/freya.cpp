#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        int result = max(2 * ((x + k - 1) / k) - 1, 2 * ((y + k - 1) / k));
        cout << result << endl;
    }
    return 0;
}
