#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n; vector<int> vs;
    for (int i = 0; i<n; i++) {
        int v; cin >> v; vs.push_back(v);
    }
    
    vector<int> accum(n,0);
    accum[0] = vs[0];
    for (int i = 1; i<n; i++){
	accum[i] = accum[i-1] + vs[i];
    }	
    
    vector<int> max_substring(n, 0); int sum = 0;
    if (vs[0] > 0){
	    max_substring[0] = vs[0];
	    sum = vs[0];
    }
    else{	   
	    max_substring[0] = 0;
    }
    for (int i = 1; i<n; i++){
	if (sum + vs[i] >= 0) sum += vs[i];
	else sum = 0;

	if (sum > max_substring[i-1]) max_substring[i] = sum;
	else max_substring[i] = max_substring[i-1];
    }
    int best = max_substring[n-1];
    for (int i = 0; i<n; i++){
	best = max(best, max_substring[i] + (accum[n-1] - accum[i]));
    }
    cout << best << endl;


	

    return 0;
}
