#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, x; cin >> n >> x; vector<int> vals; vector<int> dp(x+1,10000000);
	for (int i = 0; i<n; i++){
		int v; cin >> v;
		vals.push_back(v);
	}
	sort(vals.begin(), vals.end());
	
	dp[0] = 0;	
	for (int i = 1; i<=x; i++){
		for(int j = 0; j<n; j++){
			if (vals[j] <= i) dp[i] = min(dp[i], 1 + dp[i-vals[j]]);
		}
		
	}
	if (dp[x] >= 10000000) cout << -1 << endl;	
	else cout << dp[x] << endl;
	return 0;
}
