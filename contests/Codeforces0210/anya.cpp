#include <bits/stdc++.h>
using namespace std;

string substring = "1100";

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int c = 0;
        string s; 
        cin >> s; 
		vector<bool> starts(s.size());
        if (s.length() < 4) {
            int q; 
            cin >> q;
            while (q--) {
                int a, b; 
                cin >> a >> b;
                cout << "NO" << endl;
            }
            continue;
        }

        // Find all occurrences of "1100" in the initial string
        for (size_t i = 0; i <= s.size() - 4; ++i) {
            if (s.substr(i, 4) == substring) {
                starts[i] = 1;
                c++;
				//cout << "alo" << endl;
            }
        }

        int q; 
        cin >> q;
        while (q--) {
            int a; 
            char b; 
            cin >> a >> b;
            s[a - 1] = b;

            // Check for new occurrences of "1100" around the changed position
            for (int i = a - 1 - 3; i <= a - 1; i++) {
                if (i < 0 || i > s.size() - 4) continue;
                if (s.substr(i, 4) == substring && starts[i] == 0) {
                    c++;
                    starts[i] = 1;
                } else if (s.substr(i, 4) != substring && starts[i] == 1){
					starts[i] = 0;
					c--;
				}
            }


            // Output result based on current count of occurrences
            if (c > 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }

    return 0;
}
