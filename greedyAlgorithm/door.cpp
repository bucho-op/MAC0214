#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<int> vs;
    int n, m; cin >> n >> m;
    for (int i = 0; i<n; i++){
        int v; cin >> v; vs.push_back(v);
    }
    int i = 0; int res = 0;
    while (i<n){
        if (vs[i] == m) {
            i++;
            continue;
        } else {
            int dif;
            if (m > vs[i]) {
                dif = m - vs[i];
                vs[i+1] += dif;
            }
            else {
                dif = vs[i] - m;
                vs[i+1] -= dif;
            }
            res += dif;
            vs[i] = m;
            
        }
        
    }
    
    cout << res << endl;
    return 0;
}
