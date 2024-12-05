#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string st; cin >> st;
        
        vector<char> s(st.begin(), st.end()); // Initialize vector from string
        int sum = 0;
        vector<int> s0(n), s1(n);
        if (s[0] == '0') {
            s0[0] = 1;
            s1[0] = 0;
        } else {
            s0[0] = 0;
            s1[0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '0'){
                s0[i] = s0[i-1] + 1;
                s1[i] = s1[i-1];
            } else {
                s1[i] = s1[i-1] + 1;
                s0[i] = s0[i-1];
            }
        
        }
        
        cout << sum << endl;
    }

    return 0;
}
