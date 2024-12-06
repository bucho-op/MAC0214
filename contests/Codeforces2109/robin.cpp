#include <bits/stdc++.h>
using namespace std;

int main(){
 
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        int ans = 0, gold = 0;
        for (int i=0;i<n;i++){
            int cur;
            cin >> cur;
            if (!cur && gold) gold--, ans++;
            else if (cur >= k) gold += cur; 
    }
    cout << ans << endl;
    }
    return 0;
}