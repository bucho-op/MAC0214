#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Fast input/output
    cin.tie(0); // Decouple cin from cout

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int c = 0; // Counter for strings that fit
        bool can = true;
        while (n--) {
            string s;
            cin >> s;
            
            int size = static_cast<int>(s.size()); // Cast to int
            if (m >= size && can) { // Check if the string fits
                c++;
                // cout << m << " " << size << endl;
                m -= size; // Update remaining capacity
                
            } else {
                can = false;
            }
        }

        cout << c << endl; // Output the total count
    }

    return 0;
}
