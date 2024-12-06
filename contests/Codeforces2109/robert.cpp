#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;
        vector<int> vs(n+1), es(n+1);
    
        for (int i=0; i<k; i++){
            int a,b;
            cin >> a >> b;
            vs[a]++; es[b]++;
        }
        
        for (int i=0; i<n; i++) vs[i+1] += vs[i];
        for (int i=0; i<n; i++) es[i+1] += es[i];
    
        int max_v = 0, min_v = 1e9;
        int robert = 0, mrs = 0;
        for (int i=d; i<=n; i++){
            int cur = vs[i] - es[i-d];
            if (cur > max_v) max_v = cur, robert = i-d+1;
            if (cur < min_v) min_v = cur, mrs = i-d+1;
        }
    
        cout << robert << " " << mrs << endl;
    }
 
    return 0;
}