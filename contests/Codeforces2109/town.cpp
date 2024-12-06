#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int sum = 0;
        vector<int> v(n);
        for (auto &c : v) cin >> c, sum += c;
    
        sort(v.begin(),v.end());
    
        if (n < 3){
            cout << -1 << endl;
            continue;
        }
        cout << max(0LL,v[n/2]* 2*n-sum+1) << endl;
    } 
    return 0;
}