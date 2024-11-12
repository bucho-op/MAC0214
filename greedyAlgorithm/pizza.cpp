#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vs;
    vector<int> cum(n, 0);

    for (int i = 0; i < n; i++){
        int v;
        cin >> v;
        vs.push_back(v);
        if (i > 0) cum[i] = v + cum[i-1]; 
        else cum[i] = v;
    }

    vector<int> max_vs(n+1, 0);
    for (int i = 1; i <= n; i++){
        if (max_vs[i-1] + vs[i-1] < 0){
            max_vs[i] = 0;
        }
        else {
            max_vs[i] = max_vs[i-1] + vs[i-1];
        }
    }

    int best = max_vs[n];
    for (int i = 0; i < n; i++){
        if (i>0) best = max(best, max_vs[i] + (cum[n-1] - cum[i]));
	else best = max(best, cum[n-1]);
    }

    cout << best << endl;
    return 0;
}

