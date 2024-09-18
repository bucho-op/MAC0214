#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n; cin >> n; vector<int> seq;
    int v_max = 0;
    for (int i = 0; i < n; i++){
        int v; cin >> v; seq.push_back(v);
        v_max = max(v, v_max);
    }

    map<int, int> valores; // change vector to map
    pair<int, int> ind_max = {0, 0};
    for (int i = 0; i < n; i++){
        if (valores[seq[i] - 1] > 0) 
            valores[seq[i]] = valores[seq[i] - 1] + 1;
        else 
            valores[seq[i]] = 1;
        
        if (valores[seq[i]] > ind_max.first) {
            ind_max = {valores[seq[i]], seq[i]}; // save the length and the last element of the max subsequence
        }
    }

    int value = ind_max.second - ind_max.first + 1;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if (seq[i] == value) {
            ans.push_back(i + 1);
            value++;
        }
    }
    
    cout << ind_max.first << endl;
    for (int i = 0; i < ind_max.first - 1; i++) 
        cout << ans[i] << " ";
    cout << ans[ind_max.first - 1] << endl;
    
    return 0;
}

