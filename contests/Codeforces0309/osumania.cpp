#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> vs;
        for (int i = 0; i<n; i++){
            string s; cin >> s;
            for (int j = 0; j<s.length(); j++){
                if (s[j] == '#') vs.push_back(j+1);
            }
        }
        reverse(vs.begin(), vs.end());
        for (int i = 0; i<n; i++){
            cout << vs[i] << " ";
        }
        cout << endl;
    }
}